//
// Create Window
//
#include <SDL.h>
#include <SDL_events.h>
#include <stdio.h>
#include <unistd.h>
#ifdef PLATFORM_EMCC
#include <emscripten.h>
#endif
int _isQuit = 0;
int x = 0;
int y = 0;
SDL_Surface *screen;
void main_loop() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
//  while (SDL_WaitEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT: x++; break;
            case SDLK_LEFT: x--; break;
            case SDLK_UP: y--; break;
            case SDLK_DOWN: y++; break;
            default: printf("Other key"); break;
        }
      case SDL_QUIT:
        _isQuit = 1;
    }
    printf("loop %d %d %d %f %f %d\r\n", x, y, event.type, event.tfinger.x, event.tfinger.y, event.key.keysym.sym);
  }

}

int isQuit() {
  return _isQuit;
}

void main_init() {
  printf("called main_init() s\r\n");
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_CreateWindowAndRenderer(600, 400, 0, &window, &renderer);

  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);
  printf("called main_init() e\r\n");
}

int main( int argc, char* args[] )
{
  printf("main\r\n");
  main_init();
  printf("main 2\r\n");

  do {
    main_loop();
  } while(_isQuit == 0);

  printf("main 3 \r\n");
  return 0;
}
