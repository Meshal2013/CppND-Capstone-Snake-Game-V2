#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL2/SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer();  
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
                const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void UpdateWindowTitle(int score, int fps);
  virtual void Render(Snake const snake, Snake const snake2, SDL_Point const &food){};
  virtual bool collision(Snake){};
   virtual bool collision2(Snake){};
  virtual bool ObstacleCell(int, int){};

  SDL_Rect obstacle1;
  SDL_Rect obstacle2;
  SDL_Rect obstacle3;
  SDL_Rect obstacle4;

  SDL_Rect block;
 protected:

  void RenderHead(Snake const snake);
  void RenderBody(Snake const snake);
  
   void RenderHead2(Snake const snake2);
  void RenderBody2(Snake const snake2);
  
  void RenderFood(SDL_Point const &);
 
  SDL_Window* sdl_window;
  SDL_Renderer* sdl_renderer;

  int factor;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

};

#endif