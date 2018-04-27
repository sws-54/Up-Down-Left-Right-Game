#include "GameCore.h"

GameCore::~GameCore()
{
	for(int i = KEY_START;i < KEY_TOTAL;i++)
	{
		SDL_FreeSurface(AllImages[i]);
	}

	SDL_DestroyWindow(Window);
	Window = nullptr;
	SDL_Quit();
}

bool GameCore::Init()
{
	bool Flag = true;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		Flag = false;

	Window = SDL_CreateWindow("Press the right key Game | SWS-54",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
	if(Window == nullptr)
		Flag = false;

	Surface = SDL_GetWindowSurface(Window);
	if(Surface == nullptr)
		Flag = false;

	return Flag;
}

std::string GameCore::GetError()
{
	return SDL_GetError();
}

SDL_Surface * GameCore::LoadSetImage(std::string Path)
{
	SDL_Surface * Sf = SDL_LoadBMP(Path.c_str());

	if(Sf == nullptr)
		printf("Error Cant Load %s\n",Path.c_str());

	return Sf;
}

void GameCore::LoadAllImage()
{
	AllImages[KEY_START] = LoadSetImage("files/press.bmp");
	if(AllImages[KEY_START] == nullptr)
		printf("Cant Load press.bmp\n");

	AllImages[KEY_ERROR] = LoadSetImage("files/error.bmp");
	if(AllImages[KEY_ERROR] == nullptr)
		printf("Cant Load error.bmp\n");

	AllImages[KEY_UP] = LoadSetImage("files/up.bmp");
	if(AllImages[KEY_UP] == nullptr)
		printf("Cant Load up.bmp\n");

	AllImages[KEY_DOWN] = LoadSetImage("files/down.bmp");
	if(AllImages[KEY_DOWN] == nullptr)
		printf("Cant Load down.bmp\n");

	AllImages[KEY_RIGHT] = LoadSetImage("files/right.bmp");
	if(AllImages[KEY_RIGHT] == nullptr)
		printf("Cant Load right.bmp\n");

	AllImages[KEY_LEFT] = LoadSetImage("files/left.bmp");
	if(AllImages[KEY_LEFT] == nullptr)
		printf("Cant Load left.bmp\n");
}

void GameCore::ProssesKey(SDL_Event Event)
{
	std::string KeyPressed = SDL_GetKeyName(Event.key.keysym.sym);

	if(KeyPressed == KEY_NAMES[CurrentKeyToPress] || CurrentKeyToPress == 0 || CurrentKeyToPress == 1)
		printf("Ok\n");
	else{
		printf("Error\n");
		ErrorHappend = true;
	}

}

void GameCore::SetRandomVars()
{
	int range = 5 - 2 + 1;
	int num = rand() % range + 2;

	while(num == CurrentKeyToPress)
	{
		 num = rand() % range + 2;
	}

	if(!ErrorHappend){
		CurrentSurface = AllImages[num];
		CurrentKeyToPress = num;;
	}else
	{
		CurrentSurface = AllImages[1];
		CurrentKeyToPress = 1;
		ErrorHappend = false;
	}

}
