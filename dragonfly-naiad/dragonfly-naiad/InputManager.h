#ifndef  __INPUTMANAGER_H_
#define __INPUTMANAGER_H_

# include <SFML/Graphics.hpp>

# include "Manager.h"
# include "EventKeyboard.h"

/*
A manager that handles graphics
*/
namespace df
{
	class InputManager : public Manager
	{
	public:
		static InputManager& getInstance(); //Return the InputManager
		int startUp() override; //Start the InputManager
		void shutDown() override; //Shut down the InputManager
		void getInput(); //Get input from the keyboard and mouse, sending to all objects

	private:
		//Singleton stuff
		InputManager();
		InputManager(InputManager const&);
		void operator=(InputManager const&);

		sf::RenderWindow* p_window;
	};
}
#endif
S