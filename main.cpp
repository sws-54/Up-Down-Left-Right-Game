#include "GameCore.h"
/*
 * SWS-54 
 * 2018-4-27
 * UP DOWN LEFT RIGHT Game
 * Version 1.0
 */
int main(int argc, char* argv[])
{
	GameCore Game;

	if(!Game.Init())
		printf("ERROR %s",Game.GetError().c_str());

	Game.LoadAllImage();

	bool GameEnd = false;

	SDL_Event Event;

	Game.CurrentSurface = Game.AllImages[Game.KEY_START];

	while(!GameEnd)
	{
		while(SDL_PollEvent(&Event))
		{
			if(Event.type == SDL_QUIT)
				GameEnd = true;

			if(Event.type == SDL_KEYDOWN)
			{
			
				Game.ProssesKey(Event);
				
				Game.SetRandomVars();
			
			}

		}
		SDL_BlitSurface(Game.CurrentSurface,nullptr,Game.Surface,nullptr);
		SDL_UpdateWindowSurface(Game.Window);
	}

	return 0;
}
