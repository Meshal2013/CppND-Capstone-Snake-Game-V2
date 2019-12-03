#ifndef RENDERER_LEVEL1_H
#define RENDERER_LEVEL1_H

#include <vector>
#include "SDL2/SDL.h"
#include "snake.h"
#include "renderer.h"

class RendererLevel1 : public Renderer {
 public:

  RendererLevel1(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height):
                   Renderer(screen_width, screen_height, grid_width, grid_height){}

  void Render(Snake const snake, Snake const snake2, SDL_Point const &food);
  bool collision(Snake snake);
  bool collision2(Snake snake2);
  bool ObstacleCell(int, int);
  
};

#endif