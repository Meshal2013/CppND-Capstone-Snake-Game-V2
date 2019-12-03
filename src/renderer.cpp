#include "renderer.h"
#include <iostream>
#include <string>


Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {

  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;
  
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

}

Renderer::~Renderer() {
  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::RenderHead(Snake const snake){

    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;
    if (snake.alive) {
      SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
    }else {
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    
    SDL_RenderFillRect(sdl_renderer, &block);

}

void Renderer::RenderHead2(Snake const snake2){

    block.x = static_cast<int>(snake2.head_x) * block.w;
    block.y = static_cast<int>(snake2.head_y) * block.h;
    if (snake2.alive) {
      SDL_SetRenderDrawColor(sdl_renderer, 0x00, 255, 0xCC, 0xFF);
    }else {
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    
    SDL_RenderFillRect(sdl_renderer, &block);

}

void Renderer::RenderBody(Snake const snake){
    
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (SDL_Point const &point : snake.body) {
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
    }

}

void Renderer::RenderBody2(Snake const snake2){
    
    SDL_SetRenderDrawColor(sdl_renderer, 0, 255, 0xFF, 0xFF);
    for (SDL_Point const &point : snake2.body) {
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
    }

}

void Renderer::RenderFood(SDL_Point const &food){

    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    block.x = food.x * block.w;
    block.y = food.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
    
}
