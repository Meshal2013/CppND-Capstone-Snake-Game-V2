#include "game.h"
#include <iostream>
#include "SDL2/SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, Renderer &renderer)
    : snake(grid_width, grid_height),
 	  snake2(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)),
      renderer(renderer) {
      snake.setPosition(random_w(engine),random_h(engine));
  snake2.setPosition(random_w(engine),random_h(engine));
  PlaceFood();

}

void Game::Run(Renderer  &renderer, std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  Controller player_1_controller(SDLK_UP, SDLK_DOWN, SDLK_RIGHT, SDLK_LEFT);
  	Controller player_2_controller(SDLK_w, SDLK_s, SDLK_d, SDLK_a);
  
  
  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    //controller.HandleInput(running, snake);
      std::thread player1Input(&Controller::HandleInput, player_1_controller, std::ref(running), std::ref(snake));
    std::thread player2Input(&Controller::HandleInput, player_2_controller, std::ref(running), std::ref(snake2));
    player1Input.join();
    player2Input.join();
    
    Update();
   renderer.Render(snake, snake2, food);

    if(renderer.collision(snake)){
      snake.alive = false;
    }
    if(renderer.collision2(snake2)){
      snake2.alive = false;
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }

  }

}

void Game::PlaceFood() {
  int x, y;
  
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y) && !snake2.SnakeCell(x,y) && !renderer.ObstacleCell(x,y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
   if (!snake.alive || !snake2.alive) return;


  snake.Update(snake2);
  snake2.Update(snake);


  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  int new_x_player2 = static_cast<int>(snake2.head_x);
  int new_y_player2 = static_cast<int>(snake2.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
  
  if(food.x == new_x_player2 && food.y == new_y_player2)
  {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake2.GrowBody();
    snake2.speed += 0.02; 
  }
  
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }