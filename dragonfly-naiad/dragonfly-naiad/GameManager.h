#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

//Engine Includes
#include "Manager.h"
#include "ObjectList.h"

namespace df
{
	const int FRAME_TIME_DEFAULT = 33;

	class GameManager : public Manager
	{
	private:
		GameManager();
		GameManager(GameManager const&);
		void operator =(GameManager const&);
		bool game_over;
		int frame_time;
		int step_count;

	public:
		static GameManager& getInstance();
		int startUp() override;
		void shutDown() override;
		void run();
		void setGameOver(bool new_game_over = true);
		bool getGameOver() const;
		int getFrameTime() const;
	};
}
#endif
