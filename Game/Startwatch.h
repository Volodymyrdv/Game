#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include <vector>
#include <array>
using namespace sf;
using namespace std;
class Startwatch
{
public:
	Startwatch(int numberOfDiscs, Sprite& mainSprite, Font& font, Image& mainIcon);
	void Run();
private:
	RenderWindow newwindow;

	Sprite mainSprite;
	Image mainIcon;

	Font font;
	array<Text, 3>titles;

	int numberOfDiscs;
	int currentMove;
	Clock myClock;
	array<Tower,3> towers;
	string name;
	vector<vector<int>> result;
	void HandleInput();
	void Update();
	void Draw();
	void SolutionOfGame(int numberOdDiscs, int A, int B, int C, vector<vector<int>>& result);
	void InitText(Text& mtext, Font& font, int x, int y, String str, int size);
};

