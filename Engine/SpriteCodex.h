#pragma once
#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawPooPic(int x, int y, Graphics& gfx);
	static void DrawDudePic(int x, int y, Graphics& gfx);
	static void DrawGameOverPic(int x, int y, Graphics& gfx);
	static void DrawTitleScreenPic(int x, int y, Graphics& gfx);
};
