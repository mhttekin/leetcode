#include <SDL2/SDL.h>


int SDL_main(int argc, char** argv)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_CreateWindowAndRenderer(500, 700, 0, &window, &renderer);
  
  SDL_Event event;

  while(true)
  {
    while()
  }



  return 0; 
}
