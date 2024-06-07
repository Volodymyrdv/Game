#include "Startwatch.h"
#include <iostream>
Startwatch::Startwatch(int numberOfDiscs, Sprite& mainSprite, Font& font, Image& mainIcon) :newwindow(VideoMode(1280, 720), L"Курсова робота")
{
	this->numberOfDiscs = numberOfDiscs;
	this->mainSprite = mainSprite;
	this->font = font;
	this->mainIcon = mainIcon;
	newwindow.setIcon(512, 512, mainIcon.getPixelsPtr());
	
	towers[0].setPositionTower(Vector2f(369, 526));
	towers[1].setPositionTower(Vector2f(650, 526));
	towers[2].setPositionTower(Vector2f(928, 526));
	currentMove = 0;

	InitText(titles[0], font, 1280 / 2, 75, "The Tower of Hanoi", 55);
	titles[0].setFillColor(Color(102, 254, 250));
	InitText(titles[1], font, 146, 250, "Number of\nmoves: 0", 45);
	InitText(titles[2], font, 86, 350, "Exit", 45);
}

void Startwatch::Run()
{
	SolutionOfGame(numberOfDiscs, 0, 1, 2, result);
	towers[0].firstStep(numberOfDiscs);
	while (newwindow.isOpen())
	{
		HandleInput();
		Update();
		Draw();
	}
}

void Startwatch::HandleInput()
{
	Event startevent;
	while (newwindow.pollEvent(startevent))
	{
		switch (startevent.type)
		{
		case Event::MouseButtonPressed:
			if (startevent.mouseButton.button == Mouse::Left)
			{
				Vector2i mousePosition = Mouse::getPosition(newwindow);
				if (titles[2].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					newwindow.close();
					break;
				}
			}
		}
	}
}

void Startwatch::Update()
{
	Vector2i mousePosition = Mouse::getPosition(newwindow);
	if (titles[2].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
	{
		titles[2].setFillColor(Color::Red);
	}
	else
	{
		titles[2].setFillColor(Color::White);
	}
	if (currentMove < result.size()&&myClock.getElapsedTime()>seconds(0.75))
	{
		vector<int>move = { result[currentMove][0],result[currentMove][1] };
		towers[move[0]].movedDisk(towers[move[1]]);
		currentMove++;
		name = "Number of\nmoves: " + to_string(currentMove);
		titles[1].setString(name);
		myClock.restart();
	}
}

void Startwatch::Draw()
{
	newwindow.clear();
	newwindow.draw(mainSprite);
	for (int i = 0; i < titles.size(); i++)
	{
		newwindow.draw(titles[i]);
	}
	for (int i = 0; i < towers.size(); i++)
	{
		towers[i].drawTower(newwindow);
	}
	newwindow.display();
}

void Startwatch::SolutionOfGame(int numberOdDiscs, int A, int B, int C, vector<vector<int>>& result)
{
	if (numberOdDiscs == 1)
	{
		result.push_back({A,C});
		return;
	}
	SolutionOfGame(numberOdDiscs - 1, A, C, B, result);
	result.push_back({ A,C });
	SolutionOfGame(numberOdDiscs - 1, B, A, C, result);
}

void Startwatch::InitText(Text& mtext, Font& font, int x, int y, String str, int size)
{
	mtext.setFont(font);
	mtext.setCharacterSize(size);
	mtext.setPosition(Vector2f(x, y));
	mtext.setString(str);
	mtext.setOrigin(mtext.getLocalBounds().width / 2, mtext.getLocalBounds().height / 2);
	mtext.setFillColor(Color::White);
	mtext.setOutlineThickness(4);
	mtext.setOutlineColor(Color(197, 106, 103));
}
