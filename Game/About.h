#pragma once
#include <SFML/Graphics.hpp>
#include <array>
using namespace sf;
using namespace std;
class About
{
public:
	About(Sprite& mainSprite,Font& font,Image& mainIcon);
	void Run();
private:
	RenderWindow newwindow;

	Sprite mainSprite;
	Image mainIcon;

	Font font;
	array<Text, 5> titles;
	void HandleInput();
	void Update();
	void Draw();
	void InitText(Text& mtext, Font& font, int x, int y, String str, int size);
};

