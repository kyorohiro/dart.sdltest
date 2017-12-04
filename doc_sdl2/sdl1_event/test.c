//
// Create Window
//
#include <SDL.h>
#include <stdio.h>

#ifdef PLATFORM_EMCC
#include <SDL_touch.h>
#include <emscripten.h>
#endif


int fpsCount = 0;
int debugCount = 0;
double debugTime = 0.0;
int _isQuit = 0;
int fps;

double capp_currentMilliSecound() {
    return SDL_GetTicks();
}

void main_loop() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        _isQuit = 1;
      case SDL_MOUSEMOTION:
        printf("mouse motion : %d %d\r\n", event.motion.x, event.motion.y);
        break;
      case SDL_MOUSEBUTTONDOWN:
        printf("mouse down\r\n");
        break;
      case SDL_MOUSEBUTTONUP:
        printf("mouse up\r\n");
        break;
    }
  }

  //
  // fps
  //
  if(debugCount > 100) {
    debugCount = 0;
    double t = capp_currentMilliSecound();
    double v = t - debugTime;
    double x = v/1000.0;
    fps = (int)100/x;
    debugTime = t;
    printf("FPS = %d\r\n", fps);
  }
  debugCount++;
}

void main_init() {
  printf("called main_init() s\r\n");
  SDL_Init( SDL_INIT_EVERYTHING );
  SDL_Surface* screen = NULL;
  screen = SDL_SetVideoMode( 640, 480, 0, SDL_HWSURFACE | SDL_DOUBLEBUF );
  SDL_WM_SetCaption( "title", 0 );
  SDL_Flip( screen );
  printf("called main_init() e\r\n");
}

int isQuit() {
  return _isQuit;
}

int main( int argc, char* args[] )
{
  main_init();
  int prevTime = SDL_GetTicks();
  int currentTime = SDL_GetTicks();
  int interval = 1000/60;

  while(_isQuit == 0) {
    main_loop();
    if((currentTime-prevTime) < interval) {
      SDL_Delay(interval-(currentTime-prevTime));
    } else {
      SDL_Delay(1);
    }
  }
  SDL_Quit();
  return 0;
}
