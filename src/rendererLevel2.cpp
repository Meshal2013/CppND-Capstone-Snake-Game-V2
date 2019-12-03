#include "rendererLevel2.h"
#include <iostream>
#include <string>


void RendererLevel2::Render(Snake const snake, Snake const snake2, SDL_Point const &food) {

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render Obstacle 1
    SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 255, 1.0);
    SDL_RenderFillRect(sdl_renderer, &obstacle1);
    
    // Render Obstacle 2
    SDL_SetRenderDrawColor(sdl_renderer, 128, 0, 0, 0.4);
    SDL_RenderFillRect(sdl_renderer, &obstacle2);

    // Render Obstacle 3
    SDL_SetRenderDrawColor(sdl_renderer,195, 195, 190, 1.0);
    SDL_RenderFillRect(sdl_renderer, &obstacle3);
    
    // Render Obstacle 3
SDL_SetRenderDrawColor(sdl_renderer,0, 0, 255 , 0.4);
    SDL_RenderFillRect(sdl_renderer, &obstacle4);
    // Render food    
    RenderFood(food);

    // Render snake's body
    RenderBody(snake);

    // Render snake's head
    RenderHead(snake);
  
  // Render snake's body
    RenderBody2(snake2);

    // Render snake's head
    RenderHead2(snake2);

    SDL_UpdateWindowSurface(sdl_window);
    
    SDL_RenderPresent(sdl_renderer);
  
}

bool RendererLevel2::collision(Snake snake){

  if((block.w*static_cast<int>(snake.head_x) > obstacle1.x && block.w*static_cast<int>(snake.head_x) < (obstacle1.x + obstacle1.w)) &&
     (block.h*static_cast<int>(snake.head_y) >obstacle1.y && block.h*static_cast<int>(snake.head_y) < (obstacle1.y + obstacle1.h))){
        return true;
    }

  if((block.w*static_cast<int>(snake.head_x) > obstacle2.x && block.w*static_cast<int>(snake.head_x) < (obstacle2.x + obstacle2.w)) &&
     (block.h*static_cast<int>(snake.head_y) > obstacle2.y && block.h*static_cast<int>(snake.head_y) < (obstacle2.y + obstacle2.h))){
        return true;
    }

  if((block.w*static_cast<int>(snake.head_x) > obstacle3.x && block.w*static_cast<int>(snake.head_x) < (obstacle3.x + obstacle3.w)) &&
     (block.h*static_cast<int>(snake.head_y) > obstacle3.y && block.h*static_cast<int>(snake.head_y) < (obstacle3.y + obstacle3.h))){
        return true;
    }

    if((block.w*static_cast<int>(snake.head_x) > obstacle4.x && block.w*static_cast<int>(snake.head_x) < (obstacle4.x + obstacle4.w)) &&
     (block.h*static_cast<int>(snake.head_y) > obstacle4.y && block.h*static_cast<int>(snake.head_y) < (obstacle4.y + obstacle4.h))){
        return true;
    }
  
  return false;

}

bool RendererLevel2::collision2(Snake snake2){

  if((block.w*static_cast<int>(snake2.head_x) > obstacle1.x && block.w*static_cast<int>(snake2.head_x) < (obstacle1.x + obstacle1.w)) &&
     (block.h*static_cast<int>(snake2.head_y) >obstacle1.y && block.h*static_cast<int>(snake2.head_y) < (obstacle1.y + obstacle1.h))){
        return true;
    }

  if((block.w*static_cast<int>(snake2.head_x) > obstacle2.x && block.w*static_cast<int>(snake2.head_x) < (obstacle2.x + obstacle2.w)) &&
     (block.h*static_cast<int>(snake2.head_y) > obstacle2.y && block.h*static_cast<int>(snake2.head_y) < (obstacle2.y + obstacle2.h))){
        return true;
    }

  if((block.w*static_cast<int>(snake2.head_x) > obstacle3.x && block.w*static_cast<int>(snake2.head_x) < (obstacle3.x + obstacle3.w)) &&
     (block.h*static_cast<int>(snake2.head_y) > obstacle3.y && block.h*static_cast<int>(snake2.head_y) < (obstacle3.y + obstacle3.h))){
        return true;
    }

    if((block.w*static_cast<int>(snake2.head_x) > obstacle4.x && block.w*static_cast<int>(snake2.head_x) < (obstacle4.x + obstacle4.w)) &&
     (block.h*static_cast<int>(snake2.head_y) > obstacle4.y && block.h*static_cast<int>(snake2.head_y) < (obstacle4.y + obstacle4.h))){
        return true;
    }
  
  return false;

}

bool RendererLevel2::ObstacleCell(int x, int y){

  if((block.w*x >= obstacle1.x && block.w*x <= (obstacle1.x + obstacle1.w)) &&
     (block.h*y >= obstacle1.y && block.h*y <= (obstacle1.y + obstacle1.h))){
       return true;
     }

  if((block.w*x >= obstacle2.x && block.w*x <= (obstacle2.x + obstacle2.w)) &&
     (block.h*y >= obstacle2.y && block.h*y <= (obstacle2.y + obstacle2.h))){
       return true;
     }

  if((block.w*x >= obstacle3.x && block.w*x <= (obstacle3.x + obstacle3.w)) &&
     (block.h*y >= obstacle3.y && block.h*y <= (obstacle3.y + obstacle3.h))){
       return true;
     }

     if((block.w*x >= obstacle4.x && block.w*x <= (obstacle4.x + obstacle4.w)) &&
     (block.h*y >= obstacle4.y && block.h*y <= (obstacle4.y + obstacle4.h))){
       return true;
     }

  return false;

}