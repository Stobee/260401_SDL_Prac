#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

#include <vector>


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("Test", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, 0);
	int X = 500;
	int Y = 380;
	int Size = 20;
	int MovementSpeed = 5;
	bool isRunning = true;

	while (isRunning)
	{
		SDL_Event MyEvent;
		SDL_PollEvent(&MyEvent);

		if (MyEvent.type == SDL_QUIT)
		{
			break;
		}

		SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
		SDL_RenderClear(MyRenderer);

		SDL_Rect MyRect = { X, Y, Size, Size };
		
		SDL_SetRenderDrawColor(MyRenderer, 255, 0, 0, 0);
		SDL_RenderFillRect(MyRenderer, &MyRect);

		if (MyEvent.type == SDL_KEYDOWN)
		{
			// 동시입력만 처리되는 문제가..
			std::vector<SDL_Keycode>KeyCodes;
			KeyCodes.push_back(MyEvent.key.keysym.sym);

			for  ( SDL_Keycode Key : KeyCodes)
			{
				if (Key == SDLK_w)
				{
					Y -= MovementSpeed;
				}
				else if (Key == SDLK_s)
				{
					Y += MovementSpeed;
				}
				else if (Key == SDLK_a)
				{
					X -= MovementSpeed;
				}
				else if (Key == SDLK_d)
				{
					X += MovementSpeed;
				}
				else if (Key == SDLK_ESCAPE)
				{
					isRunning = false;
				}
			}
		}
		SDL_RenderPresent(MyRenderer);
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);


	return 0;
}