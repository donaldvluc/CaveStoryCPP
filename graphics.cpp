// graphics.cpp : Holds all information dealing with graphics for the game.

#include <SDL.h>
#undef main
#include "graphics.h"



Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cave Story");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}