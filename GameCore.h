#pragma once
#include <SDL.h>
#include <string>
#include <iostream>


class GameCore
{
public:

	//const & dist
	~GameCore();

	//keys
	enum KEY_SET
	{
		KEY_START,
		KEY_ERROR,
		KEY_UP,
		KEY_DOWN,
		KEY_RIGHT,
		KEY_LEFT,
		KEY_TOTAL
	};

	std::string KEY_NAMES[KEY_TOTAL+1] = {"START","ERROR","Up","Down","Right","Left","Total"};

	//opration functions
	bool Init();
	
	std::string GetError();

	SDL_Surface *LoadSetImage(std::string Path);

	void LoadAllImage();

	void ProssesKey(SDL_Event Event);

	void SetRandomVars();


	// Variables
	SDL_Window  *Window = nullptr;
	SDL_Surface *Surface = nullptr;
	SDL_Surface *CurrentSurface = nullptr;

	int CurrentKeyToPress = 0;

	SDL_Surface *AllImages[KEY_TOTAL];

	bool ErrorHappend = false;
};

