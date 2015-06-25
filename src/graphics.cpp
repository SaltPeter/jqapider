#include "graphics.h"

#include <SDL2/SDL.h>

namespace {
const int kScreenWidth = 640;
const int kScreenHeight = 480;
const int kBitsPerPixel = 32;
}

Graphics::Graphics() {
	window_ = SDL_CreateWindow(
					"Test",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					kScreenWidth,
					kScreenHeight,
					SDL_WINDOW_SHOWN);
}

Graphics::~Graphics() {
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	window_ = NULL;
}

void Graphics::blitSurface(
				SDL_Texture* source,
      			SDL_Rect* source_rectangle,
      			SDL_Rect* destination_rectangle) {
	SDL_RenderCopy(renderer_, source, source_rectangle, destination_rectangle);
}

void Graphics::flip() {
	SDL_RenderPresent(renderer_);
}
