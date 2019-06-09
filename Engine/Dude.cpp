#include "Dude.h"
#include "Graphics.h"
#include "SpriteCodex.h"

void Dude::ClampToScreen()
{
	const float right = x + width;
	if( x < 0 )
	{
		//x = 0;
		x = float(Graphics::ScreenWidth - 1) - width;
	}
	else if( right >= float(Graphics::ScreenWidth) )
	{
		//x = (Graphics::ScreenWidth - 1) - width;
		x = 0;
	}

	const float bottom = y + height;
	if( y < 0 )
	{
		y = 0;
	}
	else if( bottom >= float(Graphics::ScreenHeight) )
	{
		y = float(Graphics::ScreenHeight - 1) - height;
	}
}

void Dude::Draw( Graphics& gfx ) const
{
	//const int x_int = int(x);
	//const int y_int = int(y);
	//SpriteCodex scod;
	//scod.DrawDudePic(x_int, y_int, gfx);
	SpriteCodex::DrawDudePic( int(x), int(y), gfx);
	
}

void Dude::Update( const Keyboard & kbd )
{
	if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		x += speed;
	}
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		x -= speed;
	}
	if( kbd.KeyIsPressed( VK_DOWN ) )
	{
		y += speed;
	}
	if( kbd.KeyIsPressed( VK_UP ) )
	{
		y -= speed;
	}
}

float Dude::GetX() const
{
	return x;
}

float Dude::GetY() const
{
	return y;
}

float Dude::GetWidth() const
{
	return width;
}

float Dude::GetHeight() const
{
	return height;
}
