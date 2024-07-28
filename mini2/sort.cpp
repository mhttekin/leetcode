#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <random>
#include <ranges>
#include <algorithm>

// Function to draw the state of the vector
void draw_state(const std::vector<int>& v, SDL_Renderer* renderer, unsigned int red_index, unsigned int blue_index) {
    int index = 0;
    std::cerr << "Drawing state with red_index: " << red_index << ", blue_index: " << blue_index << std::endl;
    for (int i : v) {
        if (index == red_index) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red
            std::cerr << "Drawing red line at index: " << index << std::endl;
        } else if (index == blue_index) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue
            std::cerr << "Drawing blue line at index: " << index << std::endl;
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // White
        }
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        std::cerr << "Drawing line from (" << index << ", 99) to (" << index << ", " << i << ")" << std::endl;
        index += 1;
    }
}

int SDL_main(int argc, char* argv[]) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 99);
    std::vector<int> v;

    for (int i = 0; i < 100; i++) {
        v.push_back(dist(rd));
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Sorting Visualization", 100, 100, 1000, 1000, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_RenderSetScale(renderer, 10, 10);

    bool running = true;
    SDL_Event event;

    for (unsigned int i = 0; i < v.size(); i++) {
        for (unsigned int j = i + 1; j < v.size(); j++) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                    break;
                }
            }
            if (!running) break;

            if (v[j] < v[i]) {
                std::swap(v[j], v[i]);
            }

            std::cerr << "Rendering state, i: " << i << ", j: " << j << std::endl;

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            draw_state(v, renderer, i, j);

            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
        if (!running) break;
    }

    // Final rendering
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    draw_state(v, renderer, -1, -1);
    SDL_RenderPresent(renderer);

    // Print the sorted vector
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Wait for user to close the window
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

