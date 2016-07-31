#include "math.h"
#include "Bullet.h"
#include "GameScene.h"
#include "AudioM.h"

Bullet::Bullet() :
_bomb(false),
_dt(0)
{
}

Bullet::~Bullet()
{
}

Bullet* Bullet::create(void* owner, float speed, int power, Vec2 pos, Direction direction)
{
	Bullet *pRet = new Bullet(); 
    if (pRet && pRet->init(owner, speed, power, pos, direction))
    {
        pRet->autorelease();
        return pRet; 
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool Bullet::init(void* owner, float speed, int power, Vec2 pos, Direction direction)
{
	bool bRet = false;
	do
	{
		this->initWithFile("bullet.png");
		_owner = owner;
        _speed = speed;
		_power = power;
		_direction = direction;
		this->setPosition(pos);
		this->setRotation((direction - 1) * 90);
		_newPos = pos;

		this->scheduleUpdate();

		bRet = true;
	}while(false);
	return bRet;
}

void Bullet::update(float dt)
{
	_dt = dt;
	if (GameScene::getGameState() == kPause) return;
	if (_visible)
	{
		this->move();
		this->collide();
	}
	if (_visible)
	{
		this->setPosition(_newPos);
	}
	else
	{
		if (_bomb)
		{
			GameScene::getBombM()->createBomb(kBulletBomb, _bombPos);
		}
		this->removeFromParent();
	}
}

void Bullet::move()
{
	if (_direction == UP)
	{
		/* 按照时间来移动会导致帧数低的时候会穿墙，逻辑复杂所以没处理穿墙，改用按帧移动 */
		//_newPos.y = _position.y + _speed * 60 * _dt;
		_newPos.y = _position.y + _speed;
	}
	else if (_direction == DOWN)
	{
		//_newPos.y = _position.y - _speed * 60 * _dt;
		_newPos.y = _position.y - _speed;
	}
	else if (_direction == LEFT)
	{
		//_newPos.x = _position.x - _speed * 60 * _dt;
		_newPos.x = _position.x - _speed;
	}
	else if (_direction == RIGHT)
	{
		//_newPos.x = _position.x + _speed * 60 * _dt;
		_newPos.x = _position.x + _speed;
	}
}
	
void Bullet::collide()
{
	this->collideMap();			// 与地图的碰撞检测 
	this->collideBullet();		// 与子弹的碰撞检测 
	this->collideTank();		// 与坦克的碰撞检测 
}
	
void Bullet::collideBullet()
{
	auto &bullets = GameScene::getBulletM()->getChildren();
	for (auto bullet : bullets)
	{
		auto collide = false;
		if (bullet == this || !bullet->isVisible()) continue;
		auto playTank = GameScene::getTankM()->getPlayerTank();
		/* 两个子弹都不是玩家坦克发射的，即都是敌人坦克发射的子弹，敌人坦克的子弹互相之间不消除 */
		if (((Bullet*)bullet)->getOwner() != playTank && _owner != playTank) continue;  
		/* 判断两个子弹是否相交 */
		if (this->getBoundingBox().intersectsRect(bullet->getBoundingBox()))
		{
			collide = true;
		}
		else
		{
			/* 对面相向的子弹可能没相交直接穿过，所以根据两帧之间的坐标关系判断 */
			auto otherPos = bullet->getPosition();
			if (abs(_newPos.x - otherPos.x) < 1)  // 判断是否同列（float由于精度问题，当相差小于很小的一个数的时候认为相等）  
			{
				if (_position.y < otherPos.y && _newPos.y >= otherPos.y)
				{
					collide = true;
				}
				else if (_position.y > otherPos.y && _newPos.y <= otherPos.y)
				{
					collide = true;
				}
			}
			if (abs(_newPos.y - otherPos.y) < 1)  // 判断是否同行 
			{
				if (_position.x < otherPos.x && _newPos.x >= otherPos.x)
				{
					collide = true;
				}
				else if (_position.x > otherPos.x && _newPos.x <= otherPos.x)
				{
					collide = true;
				}
			}
		}
		if (collide)
		{
			this->setVisible(false);
			bullet->setVisible(false);
		}
	}
}
	
void Bullet::collideTank()
{
	Vector<Tank*> &tanks =  GameScene::getTankM()->getAllTanks();
	PlayerTank* playerTank = GameScene::getTankM()->getPlayerTank();
	for(auto tank : tanks)
	{
		/* 判断是否是玩家坦克子弹打到敌人坦克或敌人坦克子弹打到玩家坦克的情况 */
		if ((_owner == playerTank && tank != playerTank) || (_owner != playerTank && tank  == playerTank))
		{
			auto otherPos = tank->getPosition();
			if (_newPos.x <= otherPos.x + CELL_WIDTH && _position.x >= otherPos.x - CELL_WIDTH &&
				_newPos.y <= otherPos.y + CELL_HEIGHT && _position.y >= otherPos.y - CELL_HEIGHT)
			{
				tank->hit();
				this->setVisible(false);
				_bomb = true;
				_bombPos.x = _newPos.x;
				_bombPos.y = _newPos.y;
				break;
			}
		}				                        
	}
}
	
void Bullet::collideMap()
{
	collideBorder();
	collideObstacle();
}
	
void Bullet::collideObstacle()
{
	if (!_visible) return;
	auto col = (int)(_newPos.x / CELL_WIDTH);
	auto row = (int)(MAP_ROW - _newPos.y / CELL_HEIGHT);
	auto grid = false;
	auto stage = GameScene::getStage();
	int(*map)[MAP_COL] = NULL;
	stage->getMap(map);
	auto dx = 0.0f, dy = 0.0f;
	if (_direction == UP || _direction == DOWN)
	{
		if (!stage->isCanHit(row, col) && !stage->isCanHit(row, col - 1)) return;
		_bomb = true;
		if (_power == 1)	// 可打破铁，可打破整块砖 
		{
			if (map[row][col] == GRID || (map[row][col] & 0x0f) == BRICK)
			{
				map[row][col] = LAND;
			}
			if (map[row][col - 1] == GRID || (map[row][col - 1] & 0x0f) == BRICK)
			{
				map[row][col - 1] = LAND;
			}
		}
		else if (_power == 0) // 不可打破铁，可打破半块砖 
		{
			if(map[row][col] == GRID || map[row][col - 1] == GRID)
			{
				grid = true;
			}
			if (_direction == UP && ((map[row][col] & 0x30) != 0 || (map[row][col - 1] & 0x30) != 0)) // 子弹向上且两边有砖下半部不为空 
			{
				map[row][col] &= 0xcf;		// 消除砖块下半部分 
				map[row][col - 1] &= 0xcf;
			}
			else if (_direction == DOWN && ((map[row][col] & 0xc0) != 0 || (map[row][col - 1] & 0xc0) != 0)) // 子弹向上且两边有砖上半部不为空 
			{
				map[row][col] &= 0x3f;		// 消除砖块上半部分 
				map[row][col - 1] &= 0x3f;		
			}
			else
			{
				if (!grid) // 左右两边其中有一边是铁的话，没法打到后半块砖 
				{
					/* 打破后面半块砖的时候，修改子弹爆炸的位置 */
					if (_direction == UP)
					{
						dy = CELL_HEIGHT / 2;
					}
					else
					{
						dy = -CELL_HEIGHT / 2;
					}
					/* 打破后面半块砖（因为前半块砖已打破才能打到后半块砖，所以相当于该砖全部打破） */
					map[row][col] &= 0x0f;
					map[row][col - 1] &= 0x0f;
				}
			}
			/* 砖四角全破的时候，修改类型为地 */
			if (map[row][col] == BRICK)
			{
				map[row][col] = LAND;
			}
			if (map[row][col - 1] == BRICK)
			{
				map[row][col - 1] = LAND;
			}
		}
		if (map[row][col] == HOME3 || map[row][col] == HOME4 || map[row][col - 1] == HOME3 || map[row][col - 1] == HOME4)
		{
			map[24][12] = HOME2;
			map[24][13] = HOME1;
			map[25][12] = HOME1;
			map[25][13] = HOME1;
			AudioM::play2d(A_PLAYER_BOMB);
			GameScene::getStage()->updateMapCell(24, 12);
			GameScene::getBombM()->createBomb(kStrongholdBomb, getPos(25, 13));
		}
		GameScene::getStage()->updateMapCell(row, col);
		GameScene::getStage()->updateMapCell(row, col - 1);
	}
	else if (_direction == LEFT || _direction == RIGHT)
	{
		if (!stage->isCanHit(row, col) && !stage->isCanHit(row - 1, col)) return;
		_bomb = true;
		if (_power == 1)
		{
			if (map[row][col] == GRID || (map[row][col] & 0x0f) == BRICK)
			{
				map[row][col] = LAND;
			}
			if (map[row - 1][col] == GRID || (map[row - 1][col] & 0x0f) == BRICK)
			{
				map[row - 1][col] = LAND;
			}
		}
		else if (_power == 0)
		{
			if (map[row][col] == GRID || map[row - 1][col] == GRID )
			{
				grid = true;
			}
			if (_direction == RIGHT && ((map[row][col] & 0xa0) != 0 || (map[row - 1][col] & 0xa0) != 0))
			{
				map[row][col] &= 0x5f;		// 消除砖块左半部分 
				map[row - 1][col] &= 0x5f;
			}
			else if (_direction == LEFT && ((map[row][col] & 0x50) != 0 || (map[row - 1][col] & 0x50) != 0))
			{
				map[row][col] &= 0xaf;		// 消除砖块右半部分 
				map[row - 1][col] &= 0xaf;
			}
			else
			{
				if (!grid)
				{
					if (_direction == RIGHT)
					{
						dx = CELL_WIDTH / 2;
					}
					else
					{
						dx = -CELL_WIDTH / 2;
					}
					map[row][col] &= 0x0f;
					map[row - 1][col] &= 0x0f;
				}	
			}
			if (map[row][col] == BRICK)
			{
				map[row][col] = LAND;
			}
			if (map[row - 1][col] == BRICK)
			{
				map[row - 1][col] = LAND;
			}
		}
		if (map[row][col] == HOME3 || map[row][col] == HOME4 || map[row - 1][col] == HOME3 || map[row - 1][col] == HOME4)
		{
			map[24][12] = HOME2;
			map[24][13] = HOME1;
			map[25][12] = HOME1;
			map[25][13] = HOME1;
			AudioM::play2d(A_PLAYER_BOMB);
			GameScene::getStage()->updateMapCell(24, 12);
			GameScene::getBombM()->createBomb(kStrongholdBomb, getPos(25,13));
		}
		GameScene::getStage()->updateMapCell(row, col);
		GameScene::getStage()->updateMapCell(row - 1, col);
	}
	if (_bomb)
	{
		this->setVisible(false);
		_bombPos.x = _newPos.x + dx;
		_bombPos.y = _newPos.y + dy;
	}
	if (_owner == GameScene::getTankM()->getPlayerTank())
	{
		if (_power == 0 && grid)
		{
			/* 打到铁上且打不破时的音效 */
			AudioM::play2d(A_HIT_OBSTACLE);
		}
		else
		{
			/* 打破砖或铁时的音效 */
			AudioM::play2d(A_OBSTACLE_BOMB);
		}
	}
}
	
void Bullet::collideBorder()
{
	int(*map)[MAP_COL] = NULL;
	GameScene::getStage()->getMap(map);
	if (_newPos.x < 0 || _newPos.x >= MAP_WIDTH ||
		_newPos.y <= 0 || _newPos.y > MAP_HEIGHT)
	{
		if (_owner == GameScene::getTankM()->getPlayerTank())
		{
			AudioM::play2d(A_HIT_OBSTACLE);
		}
		_bomb = true;
		this->setVisible(false);
		if (_newPos.x < 0)
		{
			_bombPos.x = 0;
		}
		else if (_newPos.x > MAP_WIDTH)
		{
			_bombPos.x = MAP_WIDTH;
		}
		else
		{
			_bombPos.x = _newPos.x;
		}
		if (_newPos.y < 0)
		{
			_bombPos.y = 0;
		}
		else if (_newPos.y > MAP_HEIGHT)
		{
			_bombPos.y = MAP_HEIGHT;
		}
		else
		{
			_bombPos.y = _newPos.y;
		}
	}
}
