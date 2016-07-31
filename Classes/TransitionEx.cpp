#include "TransitionEx.h"

SplitExA* SplitExA::create(float duration)
{
	SplitExA *action = new (std::nothrow) SplitExA();

	if (action)
	{
		if (action->initWithDuration(duration))
		{
			action->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(action);
		}
	}

	return action;
}

bool SplitExA::initWithDuration(float duration)
{
	return TiledGrid3DAction::initWithDuration(duration, Size(1, 2));
}

SplitExA* SplitExA::clone() const
{
	// no copy constructor    
	auto a = new (std::nothrow) SplitExA();
	a->initWithDuration(_duration);
	a->autorelease();
	return a;
}

void SplitExA::startWithTarget(Node *target)
{
	TiledGrid3DAction::startWithTarget(target);
	_winSize = Director::getInstance()->getWinSizeInPixels();
}

void SplitExA::update(float time)
{
	for (unsigned int i = 0; i < _gridSize.height; ++i)
	{
		Quad3 coords = getOriginalTile(Vec2(0, i));
		float    direction = 1;

		if ((i % 2) == 0)
		{
			direction = -1;
		}

		float dy = direction * _winSize.height / 2 * time;
		coords.bl.y += dy;
		coords.br.y += dy;
		coords.tl.y += dy;
		coords.tr.y += dy;

		setTile(Vec2(0, i), coords);
	}
}

SplitExB* SplitExB::create(float duration)
{
	SplitExB *action = new (std::nothrow) SplitExB();

	if (action)
	{
		if (action->initWithDuration(duration))
		{
			action->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(action);
		}
	}

	return action;
}

bool SplitExB::initWithDuration(float duration)
{
	return TiledGrid3DAction::initWithDuration(duration, Size(1, 2));
}

SplitExB* SplitExB::clone() const
{
	// no copy constructor    
	auto a = new (std::nothrow) SplitExB();
	a->initWithDuration(_duration);
	a->autorelease();
	return a;
}

void SplitExB::startWithTarget(Node *target)
{
	TiledGrid3DAction::startWithTarget(target);
	_winSize = Director::getInstance()->getWinSizeInPixels();
}

void SplitExB::update(float time)
{
	for (unsigned int i = 0; i < _gridSize.height; ++i)
	{
		Quad3 coords = getOriginalTile(Vec2(0, i));
		float    direction = -1;

		if ((i % 2) == 0)
		{
			direction = 1;
		}

		float dy = direction * _winSize.height / 2 * (time - 1);
		coords.bl.y += dy;
		coords.br.y += dy;
		coords.tl.y += dy;
		coords.tr.y += dy;

		setTile(Vec2(0, i), coords);
	}
}

TransitionExA::TransitionExA()
{
	_outSceneProxy = NodeGrid::create();
	_outSceneProxy->retain();
}
TransitionExA::~TransitionExA()
{
	CC_SAFE_RELEASE(_outSceneProxy);
}

TransitionExA* TransitionExA::create(float t, Scene* scene)
{
	TransitionExA* newScene = new (std::nothrow) TransitionExA();
	if (newScene && newScene->initWithDuration(t, scene))
	{
		newScene->autorelease();
		return newScene;
	}
	CC_SAFE_DELETE(newScene);
	return nullptr;
}

void TransitionExA::onEnter()
{
	TransitionScene::onEnter();

	_outSceneProxy->setTarget(_outScene);
	_outSceneProxy->onEnter();

	ActionInterval* split = action();

	_outSceneProxy->runAction
		(
			Sequence::create
			(
				split,
				CallFunc::create(CC_CALLBACK_0(TransitionScene::finish, this)),
				StopGrid::create(),
				nullptr
				)
			);
}

void TransitionExA::onExit()
{
	_outSceneProxy->setTarget(nullptr);
	_outSceneProxy->onExit();
	TransitionScene::onExit();
}

void TransitionExA::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	Scene::draw(renderer, transform, flags);

	_inScene->visit(renderer, transform, flags);
	_outSceneProxy->visit(renderer, transform, flags);
}

ActionInterval* TransitionExA::action()
{
	return SplitExA::create(_duration / 2.0f);
}

TransitionExB::TransitionExB()
{
	_inSceneProxy = NodeGrid::create();
	_inSceneProxy->retain();
}
TransitionExB::~TransitionExB()
{
	CC_SAFE_RELEASE(_inSceneProxy);
}

TransitionExB* TransitionExB::create(float t, Scene* scene)
{
	TransitionExB* newScene = new (std::nothrow) TransitionExB();
	if (newScene && newScene->initWithDuration(t, scene))
	{
		newScene->autorelease();
		return newScene;
	}
	CC_SAFE_DELETE(newScene);
	return nullptr;
}

void TransitionExB::onEnter()
{
	TransitionScene::onEnter();

	_inSceneProxy->setTarget(_inScene);
	_inSceneProxy->onEnter();

	ActionInterval* split = action();

	_inSceneProxy->runAction
		(
			Sequence::create
			(
				split,
				CallFunc::create(CC_CALLBACK_0(TransitionScene::finish, this)),
				StopGrid::create(),
				nullptr
				)
			);
}

void TransitionExB::onExit()
{
	_inSceneProxy->setTarget(nullptr);
	_inSceneProxy->onExit();
	TransitionScene::onExit();
}

void TransitionExB::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	Scene::draw(renderer, transform, flags);

	_outScene->visit(renderer, transform, flags);
	_inSceneProxy->visit(renderer, transform, flags);
}

ActionInterval* TransitionExB::action()
{
	return SplitExB::create(_duration / 2.0f);
}


