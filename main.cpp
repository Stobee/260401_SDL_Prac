#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

#include <vector>


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("Test", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	int X = 500;
	int Y = 380;
	int Size = 20;
	int MovementSpeed = 1;
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

		if (currentKeyStates[SDL_SCANCODE_W])
		{
			Y -= MovementSpeed;
		}
		if (currentKeyStates[SDL_SCANCODE_S])
		{
			Y += MovementSpeed;
		}
		if (currentKeyStates[SDL_SCANCODE_A])
		{
			X -= MovementSpeed;
		}
		if (currentKeyStates[SDL_SCANCODE_D])
		{
			X += MovementSpeed;
		}

		// ESC는 이벤트 루프에서 처리하거나 여기서 처리해도 됩니다.
		if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		{
			isRunning = false;
		}
		SDL_RenderPresent(MyRenderer);
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	return 0;
}