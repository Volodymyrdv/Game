#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "About.h"
using namespace sf;
using namespace std;
class Game
{
public:
	Game();
	void Run();
private:
	RenderWindow window;

	array<Texture, 3>mainTexture;
	array<Sprite, 3>mainSprite;
	Image mainIcon;

	array<Font, 2> font;
	array<Text, 6> titles;
	int numberOfDiscs;
	void HandleInput();
	void Update();
	void Draw();
	void InitText(Text& mtext, Font& font, int x, int y, String str, int size);
};

