#include <SDL2/SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

namespace {
const int kFps = 60;
}

//static
int Game::kTileSize = 32;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_ShowCursor(SDL_DISABLE);
	eventLoop();
}

Game::~Game() {
	SDL_Quit();
}

void Game::eventLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	bool isRunning = true;
	int last_update_time = SDL_GetTicks();
	while (isRunning) {
		const int start_time_ms = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
            case SDL_KEYDOWN:
            	if (!event.key.repeat)
					input.keyDownEvent(event);
			   //if (event.key.keysym.sym == SDLK_ESCAPE)
                  //running = false;
            	break;
			case SDL_KEYUP:
			   input.keyUpEvent(event);
				break;
            default:
            	break;
			}
      } // while (SDL_PollEvent(&event))

	  	if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE))
	  		isRunning = false;

      	const int current_time_ms = SDL_GetTicks();
      	update(current_time_ms - last_update_time);
	  	last_update_time = current_time_ms;

		draw(graphics);
		const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
		SDL_Delay(1000/*ms*/ / kFps - elapsed_time_ms/*ms*/);
	} // while (isRunning)
}

void Game::update(int elapsed_time_ms) {
}

void Game::draw(Graphics& graphics) {
	graphics.flip();
}
