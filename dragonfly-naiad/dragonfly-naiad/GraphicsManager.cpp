//
// Dragonfly GraphicsManager.cpp - Harrison March
//
#include "GraphicsManager.h"
#include "LogManager.h"

df::GraphicsManager::GraphicsManager()
{
	setType("GraphicsManager");
	window_horizontal_pixels = WINDOW_HORIZONTAL_PIXELS_DEFAULT;
	window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;
	window_horizontal_chars = WINDOW_HORIZONTAL_CHARS_DEFAULT;
	window_vertical_chars = WINDOW_VERTICAL_CHARS_DEFAULT;
	window_style = WINDOW_STYLE_DEFAULT;
	window_background_color = WINDOW_BACKGROUND_COLOR_DEFAULT;
	window_title = WINDOW_TITLE_DEFAULT;
	font_file = FONT_FILE_DEFAULT;
	opaque_text = TEXT_OPAQUE_DEFAULT;
}

df::GraphicsManager::~GraphicsManager()
{
	if (p_window != nullptr) delete p_window;
}

df::GraphicsManager& df::GraphicsManager::getInstance()
{
	static GraphicsManager graphics_manager;
	return graphics_manager;
}

int df::GraphicsManager::startUp()
{
	if (p_window != nullptr) return 0;

	//Create and set up SFML window
	sf::VideoMode video_mode = sf::VideoMode(window_horizontal_pixels, window_vertical_pixels);
	p_window = new sf::RenderWindow(video_mode, window_title, window_style);
	if (p_window == nullptr)
	{
		LogManager::getInstance().writeLog("GraphicsManager: Failed to make SFML window\n");
		return -1;
	}

	p_window->setMouseCursorVisible(false);
	p_window->setVerticalSyncEnabled(true);

	//Load font
	font = new sf::Font();
	if (!font->loadFromFile(font_file))
	{
		LogManager::getInstance().writeLog("GraphicsManager: Failed to load font \"%s\"\n", font_file.c_str());
		return -1;
	}

	Manager::startUp();
	LogManager::getInstance().writeLog("GraphicsManager: Graphics manager succesfully started\n");
	return 0;
}

void df::GraphicsManager::shutDown()
{
	p_window->close();
	delete p_window;
	delete font;
	Manager::shutDown();
}

int df::GraphicsManager::swapBuffers()
{
	if (p_window == nullptr) return -1;
	p_window->display();
	p_window->clear();
	return 0;
}

int df::GraphicsManager::drawCh(Vector world_pos, char ch, Color color) const
{
	if (p_window == nullptr || font == nullptr)
	{
		LogManager::getInstance().writeLog(
			"GraphicsManager: Failed to drawCh(pos(%f, %f), %c): null window? %s, null font? %s\n",
			world_pos.getX(), world_pos.getY(), ch,
			p_window == nullptr ? "true" : "false",
			font == nullptr ? "true" : "false"
		);
		return -1;
	}

	Vector pixel_loc = charSpacesToPixels(world_pos);

	//Draw background rectangle.
	if (opaque_text)
	{
		static sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
		rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
		rectangle.setPosition(pixel_loc.getX() - charWidth() / 10,
		                      pixel_loc.getY() + charHeight() / 5);
		p_window->draw(rectangle);
	}

	//Make character
	static sf::Text text("", *font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold);

	//Scale character
	if (charWidth() < charHeight())
	{
		text.setCharacterSize(charWidth() * 2);
	}
	else
	{
		text.setCharacterSize(charHeight() * 2);
	}

	//Set color
	switch (color)
	{
	case BLACK:
		text.setColor(sf::Color::Black);
		break;
	case RED:
		text.setColor(sf::Color::Red);
		break;
	case GREEN:
		text.setColor(sf::Color::Green);
		break;
	case YELLOW:
		text.setColor(sf::Color::Yellow);
		break;
	case BLUE:
		text.setColor(sf::Color::Blue);
		break;
	case MAGENTA:
		text.setColor(sf::Color::Magenta);
		break;
	case CYAN:
		text.setColor(sf::Color::Cyan);
		break;
	case WHITE:
		text.setColor(sf::Color::White);
		break;
	default:
		text.setColor(sf::Color::White);
		break;
	}

	//Set position
	text.setPosition(pixel_loc.getX(), pixel_loc.getY());

	//Draw
	p_window->draw(text);

	return 0;
}

int df::GraphicsManager::drawString(Vector pos, std::string str, Justification just, Color color)
{
	Vector starting_pos = pos;

	switch (just)
	{
	case CENTER_JUSTIFIED:
		starting_pos.setX(pos.getX() - str.size() / 2);
		break;
	case RIGHT_JUSTIFIED:
		break;
	case LEFT_JUSTIFIED:
		starting_pos.setX(pos.getX() - str.size());
		break;
	}

	int success = 0;
	//uint to avoid compiler warning...
	for (uint i = 0; i < str.size(); i++)
	{
		Vector temp(starting_pos.getX() + i, starting_pos.getY());
		success += drawCh(temp, str.at(i), color);
	}

	if (success == 0)
	{
		return 0;
	}
	LogManager::getInstance().writeLog("GraphicsManager: Failed to draw one or more characters in string\n");
	return -1;
}


float df::GraphicsManager::charHeight() const
{
	return getVerticalPixels() / (float)getVertical();
}

float df::GraphicsManager::charWidth() const
{
	return getHorizontalPixels() / (float)getHorizontal();
}

df::Vector df::GraphicsManager::charSpacesToPixels(Vector spaces) const
{
	return df::Vector(spaces.getX() * charWidth(),
	                  spaces.getY() * charHeight());
}

df::Vector df::GraphicsManager::PixelsTocharSpaces(Vector pixels) const
{
	return df::Vector(pixels.getX() / charWidth(),
	                  pixels.getY() / charHeight());
}

int df::GraphicsManager::getHorizontal() const
{
	return window_horizontal_chars;
}

int df::GraphicsManager::getVertical() const
{
	return window_vertical_chars;
}

int df::GraphicsManager::getHorizontalPixels() const
{
	return window_horizontal_pixels;
}

int df::GraphicsManager::getVerticalPixels() const
{
	return window_vertical_pixels;
}

sf::RenderWindow* df::GraphicsManager::getWindow() const
{
	return p_window;
}
