// game.cpp : This class holds all information for our main game loop.

#include <SDL.h>
#undef main
#include <algorithm>
#include "game.h"
#include "graphics.h"
#include "input.h"


namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;									// Think of this as the event for gfx_event_waiting().

	int LAST_UPDATE_TIME = SDL_GetTicks();
	// Start the game loop.
	while (true) {
		input.beginNewFrame();

		// Switch through SDL events.
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.repeat == 0)		// Make sure that user is not holding down a key.
					input.keyDownEvent(event);
				break;
			case SDL_KEYUP:
				input.keyUpEvent(event);
				break;
			case SDL_QUIT:
				return;
			}
		}

		// Quits the program when esc is pressed.
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		// Limit frames to keep game physics the same across all computers.
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));				// Use ELAPSED_TIME_MS if it is less than MAX_FRAME_TIME to keep game physics standardardize.

		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Game::draw(Graphics &graphics) {

}

void Game::update(float elapsedTime) {

}