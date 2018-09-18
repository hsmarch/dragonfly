#pragma once

# include "Manager.h"

/*
A manager the starts all other managers and handles basic game functionality
*/
namespace df {
  const int FRAME_TIME_DEFAULT = 33; //Milliseconds

  class GameManager : public Manager {
    public:
      static GameManager& getInstance(); //Return the GameManager
      ~GameManager(); //Destroy the GameManager
      int startUp(); //Start the GameManager and all other managers (returns 0 for success, -1 for error)
      void shutDown(); //Shut down the GameManager and all other managers
      void run(); //Run the game loop until game over is set
      void setGameOver(bool new_game_over=true); //Set the value of game_over
      bool getGameOver() const; // Return the value of game_over
      int getFrameTime() const; // Return the number of milliseconds per frame

    private:
      GameManager();
      GameManager(GameManager const&);
      void operator=(GameManager const&);

      bool game_over;
      int frame_time;
      int loop_count;
  };
}
