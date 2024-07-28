#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <vector>
#include <iostream>

#ifdef __cplusplus
extern "C"
#endif
int SDL_main(int argc, char* argv[]) 
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(700,700,0,&window,&renderer);
    SDL_Event event;

    SDL_Point current;

    std::vector<SDL_Point> vector_of_points;

    int type = 0;

    while (true)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                SDL_Quit();
                exit(0);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                auto button = SDL_GetMouseState(&x, &y);
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    vector_of_points.emplace_back(SDL_Point{x,y}); // Fixed initialization
                }
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&current.x, &current.y);
            }
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_c)
            {
                vector_of_points.clear();
            }
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m)
            {
                type = 1;    
            }
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_l)
            {
                type = 0;    
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        
        if(type == 0)
        {
            for(auto point : vector_of_points)
            {
                for(auto point2: vector_of_points)
                {
                    SDL_RenderDrawLine(renderer, point.x, point.y, point2.x, point2.y);
                }
            }
        }
        if(type == 1)
        {
            SDL_RenderDrawLines(renderer, vector_of_points.data(), vector_of_points.size());
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(150);
    }

    return 0;
}
