#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {  
 public:
  Controller(const SDL_Keycode up, const SDL_Keycode down, const SDL_Keycode right, const SDL_Keycode left):
  	_Up(up),
  	_Down(down),
  	_Right(right),
  	_Left(left)
  {
  }
  
  void HandleInput(bool &running, Snake &lsnake) const;
  
 private:
  void ChangeDirection(Snake &snake, Snake::Direction input, Snake::Direction opposite) const;
  SDL_Keycode _Up;
  SDL_Keycode _Down;
  SDL_Keycode _Right; 
  SDL_Keycode _Left;
  
};

#endif