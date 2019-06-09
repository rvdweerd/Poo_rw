#include "Poo.h"
#include "Graphics.h"
#include <assert.h>
#include "SpriteCodex.h"

void Poo::Init( float in_x,float in_y,float in_vx,float in_vy )
{
	assert( initialized == false );
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	initialized = true;
}

void Poo::Update()
{
	assert( initialized == true );
	x += vx;
	y += vy;

	const float right = x + width;
	if( x < 0 )
	{
		x = 0;
		vx = -vx;
	}
	else if( right >= float(Graphics::ScreenWidth) )
	{
		x = float(Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	}

	const float bottom = y + height;
	if( y < 0 )
	{
		y = 0;
		vy = -vy;
	}
	else if( bottom >= float(Graphics::ScreenHeight) )
	{
		y = float(Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}
}

bool Poo::TestCollision( const Dude& dude ) const
{
	assert( initialized == true );
	const float duderight = dude.GetX() + dude.GetWidth();
	const float dudebottom = dude.GetY() + dude.GetHeight();
	const float pooright = x + width;
	const float poobottom = y + height;

	return
		duderight >= x &&
		dude.GetX() <= pooright &&
		dudebottom >= y &&
		dude.GetY() <= poobottom;
}

void Poo::Draw( Graphics& gfx ) const
{
	assert( initialized == true );

	//const int x_int = int(x);
	//const int y_int = int(y);
	//SpriteCodex scod;
	//scod.DrawPooPic(x_int, y_int, gfx);
	SpriteCodex::DrawPooPic(int(x), int(y), gfx);

}