#pragma once
#include <SFML/Graphics.hpp>
#include <array>
using namespace sf;
using namespace std;
class Settings
{
public:
	Settings(int numberOfDiscs, Sprite& mainSprite, Font& font, Image& mainIcon);
	void Run();
	int getNumberofDiscs();
private:
	RenderWindow newwindow;

	Sprite mainSprite;
	Image mainIcon;

	Font font;
	array<Text, 5>titles;

	int numberOfDiscs;
	string name;
	void HandleInput();
	void Update();
	void Draw();
	void InitText(Text& mtext, Font& font, int x, int y, String str, int size);
};

