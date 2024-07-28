#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <cstdlib>

class Screen {
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_FPoint> points;
    public:
    Screen() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        window = SDL_CreateWindow("SDL2 Line Drawing",
                                  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  400 * 2, 400 * 2, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        SDL_RenderSetScale(renderer, 2, 2);
    }

    ~Screen() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
    void pixel(float x, float y)
    {
      points.emplace_back(x,y);
    }
    void show()
    {
      SDL_SetRenderDrawColor(renderer,0,0,0,255);
      SDL_RenderClear(renderer);
      SDL_SetRenderDrawColor(renderer, 255,255,255,255);
      for (auto& point : points)
      {
          SDL_RenderDrawPointF(renderer,point.x, point.y);
      }
      SDL_RenderPresent(renderer);
    }
    void clear()
    {
      points.clear();
    }
    void input()
    {
        while(SDL_PollEvent(&e))
        {
          if(e.type == SDL_QUIT)
          {
            SDL_Quit();
            exit(0);
          }
        }
    }
    
  
};
