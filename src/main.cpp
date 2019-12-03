#include <iostream>
#include <stdio.h>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "rendererLevel1.h"
#include "rendererLevel2.h"
#include "SDL2/SDL.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000/ kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  int level;

  SDL_Init(SDL_INIT_VIDEO);

  std::cout << "LEVELS OF DIFICULTY:" << std::endl;
  std::cout << "        LEVEL EASY : TYPE 1" << std::endl;
  std::cout << "        LEVEL HARD : TYPE 2" << std::endl;
  
  std::cout << "CHOOSE LEVEL OF DIFICULTY:" << std::endl;
  std::cin >> level;

  //Controller controller;
  Renderer *renderer;
  Game *game;

  if (level == 1){
    renderer = new RendererLevel1(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  }else if (level == 2){
    renderer = new RendererLevel2(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  }else{
    std::cout << "Choose an valid Input!" << std::endl;
  }

  game = new Game(kGridWidth, kGridHeight, *renderer);
  game->Run(*renderer, kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game->GetScore() << "\n";
  std::cout << "Size: " << game->GetSize() << "\n";

  delete renderer;
  delete game;
    
  return 0;
}