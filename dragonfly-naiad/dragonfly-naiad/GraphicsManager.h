#pragma once


#include <SFML/Graphics.hpp>
#include <string>

#include "Manager.h"
#include "Color.h"
#include "Vector.h"

/*
A manager that handles graphics
*/
namespace df
{
	enum Justification
	{
		LEFT_JUSTIFIED,
		CENTER_JUSTIFIED,
		RIGHT_JUSTIFIED,
	};

	const int WINDOW_HORIZONTAL_PIXELS_DEFAULT = 1024;
	const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
	const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
	const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
	const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar;
	const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
	const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
	const std::string FONT_FILE_DEFAULT = "df-font.ttf";
	const bool TEXT_OPAQUE_DEFAULT = true;


	class GraphicsManager : public Manager
	{
	public:
		static GraphicsManager& getInstance(); //Return the GraphicsManager
		~GraphicsManager(); //Destroy the GraphicsManager
		int startUp() override; //Start the GraphicsManager
		void shutDown() override; //Shut down the GraphicsManager
		int drawCh(Vector world_pos, char ch, Color color) const; //Draw a character the passed pos
		int drawString(Vector pos, std::string str, Justification just, Color color); //Draw a whole string
		int getHorizontal() const; //Get horizonal max (in chars)
		int getVertical() const; //Get vertical max (in chars)
		int getHorizontalPixels() const; //Get horizonal max (in pixels)
		int getVerticalPixels() const; //Get vertical max (in pixels)
		int swapBuffers(); //render the window buffer
		sf::RenderWindow* getWindow() const; //Return the SFML drawing surface

	private:
		//Singleton stuff
		GraphicsManager();
		GraphicsManager(GraphicsManager const&);
		void operator=(GraphicsManager const&);

		//Helper methods
		float charHeight() const;
		float charWidth() const;
		Vector charSpacesToPixels(Vector spaces) const;
		Vector PixelsTocharSpaces(Vector spaces) const;

		//Instance vars
		sf::Font* font;
		sf::RenderWindow* p_window;
		int window_horizontal_pixels;
		int window_vertical_pixels;
		int window_horizontal_chars;
		int window_vertical_chars;
		int window_style;
		sf::Color window_background_color;
		std::string window_title;
		std::string font_file;
		bool opaque_text;
	};
}
