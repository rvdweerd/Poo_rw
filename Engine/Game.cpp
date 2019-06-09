/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng( rd() ),
	xDist( 0,770 ),
	yDist( 0,570 ),
	goal( xDist( rng ),yDist( rng ) ),
	meter( 20,20 )
{
	std::uniform_real_distribution<float> vDist( -2.5f , 2.5f );
	for( int i = 0; i < nPoo; ++i )
	{
		poos[i].Init( xDist( rng ),yDist( rng ), vDist(rng), vDist(rng));
	}
	title.Play();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	goal.UpdateColor();
	if( isStarted && !isGameOver )
	{
		dude.Update( wnd.kbd );
		dude.ClampToScreen();

		for( int i = 0; i < nPoo; ++i )
		{
			poos[i].Update();
			if( poos[i].TestCollision( dude ) )
			{
				isGameOver = true;
				fart.Play( rng );
			}
		}

		if( goal.TestCollision( dude ) )
		{
			goal.Respawn( xDist( rng ),yDist( rng ) );
			meter.IncreaseLevel();
			pickup.Play( rng );
		}
	}
	else
	{
		if( wnd.kbd.KeyIsPressed( VK_RETURN ) )
		{
			isStarted = true;
		}
	}
}

/*void Game::DrawGameOver( int x,int y )
{
	//SpriteCodex scod;
	//scod.DrawGameOverPic(x, y, gfx);
	SpriteCodex::DrawGameOverPic(x, y, gfx);
}*/

/*void Game::DrawTitleScreen( int x,int y )
{
	//SpriteCodex scod;
	//scod.DrawTitleScreenPic(x, y, gfx);
	SpriteCodex::DrawTitleScreenPic(x, y, gfx);
}*/

void Game::ComposeFrame()
{
	if( !isStarted )
	{
		//DrawTitleScreen( 325,211 );
		SpriteCodex::DrawTitleScreenPic(325, 211, gfx);
	}
	else
	{
		goal.Draw( gfx );
		for( int i = 0; i < nPoo; ++i )
		{
			poos[i].Draw( gfx );
		}
		dude.Draw( gfx );
		if( isGameOver )
		{
			SpriteCodex::DrawGameOverPic(358, 268, gfx); 
			//DrawGameOver(358, 268);
		}
		meter.Draw( gfx );
	}
}
