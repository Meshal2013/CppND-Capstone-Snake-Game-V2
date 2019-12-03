#ifndef RENDERER_LEVEL2_H
#define RENDERER_LEVEL2_H

#include <vector>
#include "SDL2/SDL.h"
#include "snake.h"
#include "rendererLevel1.h"

class RendererLevel2 : public RendererLevel1 {
 
 public:

     RendererLevel2(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height):
                   RendererLevel1(screen_width, screen_height, grid_width, grid_height){

                        obstacle1.w = 80;
                        obstacle1.h = 25;
                        obstacle1.x = 100;
                        obstacle1.y = 100;

                        obstacle2.w = 25;
                        obstacle2.h = 80;
                        obstacle2.x = 100;
                        obstacle2.y = 500;

                        obstacle3.w = 80;
                        obstacle3.h = 25;
                        obstacle3.x = 400;
                        obstacle3.y = 200;

                        obstacle4.w = 25;
                        obstacle4.h = 80;
                        obstacle4.x = 500;
                        obstacle4.y = 100;
          
                   }

     void Render(Snake const snake, Snake const snake2, SDL_Point const &food);
     bool collision(Snake);
     bool collision2(Snake);
     bool ObstacleCell(int, int);
};

#endif