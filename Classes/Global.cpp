#include "Global.h"

bool g_keyUp = false;
bool g_keyRight = false;
bool g_keyDown = false;
bool g_keyLeft = false;
bool g_keySelect = false;
bool g_keyStart = false;
bool g_keyB = false;
bool g_keyA = false;
bool g_KeyBack = false;

/* 获取地图某行某列所对应的坐标 */
Vec2 getPos(int row, int col)
{
	Vec2 pos;
	pos.x = col*CELL_WIDTH;
	pos.y = (MAP_ROW - row)*CELL_HEIGHT;
	return pos;
}
