#ifndef GRAPHICS_H_
#define GRAPHICS_H_

struct SDL_Surface;
struct SDL_Rect;
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

struct Graphics {
	Graphics();
	~Graphics();

	void blitSurface(
		SDL_Texture* source,
		SDL_Rect* source_rectangle,
		SDL_Rect* destination_rectangle);

	void flip();

	private:
		SDL_Renderer* renderer_;
		SDL_Surface* screen_;
		SDL_Window* window_;
};

#endif // GRAPHICS_H_
