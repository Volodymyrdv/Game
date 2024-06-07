#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include <array>
using namespace sf;
using namespace std;
class Startplay
{
public:
	Startplay(int numberOfDiscs, Sprite& mainSprite, Font& font, Image& mainIcon);
	void Run();
private:
	RenderWindow newwindow;

	Sprite mainSprite;
	Image mainIcon;

	Font font;
	array<Text, 4> titles;
	array<CircleShape, 3>circle;
	
	int numberOfDiscs;
	int currentMove;

	int firstSelected;
	bool isFirstselected;
	int secondSelected;
	bool isSecondSelected;

	array<Tower, 3> towers;
	string name;
	void HandleInput();
	void Update();
	void Draw();
	void InitText(Text& mtext, Font& font, int x, int y, String str, int size);
	void InitCircle(CircleShape& circle, int x, int y);
	void Selected(int tower);
};

