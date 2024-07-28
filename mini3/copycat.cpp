#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <vector>
#include <random>

int SDL_main(int argc, char* argv[])
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_CreateWindowAndRenderer(1700, 500, 0, &window, &renderer);
  SDL_Event event;

  SDL_Point point;
  std::random_device rd;
  std::uniform_int_distribution<int> dist(1, 499);
  std::uniform_int_distribution<int> distx(1, 1699);
  std::vector<SDL_Point> vector_points;
  

  while (true)
  {
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        SDL_Quit();
        exit(0);
      }
    }
    int x, y;
    for (int i = 0; i < 20; i++)
    {
        x = distx(rd);
        y = dist(rd);
        vector_points.emplace_back(SDL_Point{x, y});
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    for(auto point : vector_points)
            {
                for(auto point2: vector_points)
                {
                    SDL_RenderDrawLine(renderer, point.x, point.y, point2.x, point2.y);
                }
            }

    SDL_RenderPresent(renderer);
    SDL_Delay(200);
    vector_points.clear();
  }

  return 0;
}
