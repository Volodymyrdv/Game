#include "Startplay.h"
#include <iostream>
Startplay::Startplay(int numberOfDiscs, Sprite& mainSprite, Font& font, Image& mainIcon) :newwindow(VideoMode(1280, 720), L"Курсова робота")
{
	this->numberOfDiscs = numberOfDiscs;
	this->mainSprite = mainSprite;
	this->font = font;
	this->mainIcon = mainIcon;
	newwindow.setIcon(512, 512, mainIcon.getPixelsPtr());

	currentMove = 0;
	isFirstselected = false;
	isSecondSelected = false;

	towers[0].setPositionTower(Vector2f(369, 526));
	towers[1].setPositionTower(Vector2f(650, 526));
	towers[2].setPositionTower(Vector2f(928, 526));

	InitCircle(circle[0], 369, 576);
	InitCircle(circle[1], 650, 576);
	InitCircle(circle[2], 928, 576);

	InitText(titles[0], font, 1280 / 2, 75, "The Tower of Hanoi", 55);
	titles[0].setFillColor(Color(102, 254, 250));
	InitText(titles[1], font, 146, 250, "Number of\nmoves: 0", 45);
	InitText(titles[2], font, 1280 / 2, 140, "Congratulations!!!", 35);
	titles[2].setString("");
	InitText(titles[3], font, 86 , 350, "Exit", 45);

}

void Startplay::Run()
{
	towers[0].firstStep(numberOfDiscs);
	while (newwindow.isOpen())
	{
		HandleInput();
		Update();
		Draw();
	}
}

void Startplay::HandleInput()
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
				if (titles[3].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					newwindow.close();
					break;
				}
				if (FloatRect(268, 268, 200, 280).contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					Selected(0);
				}
				if (FloatRect(555, 268, 200, 280).contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					Selected(1);
				}
				if (FloatRect(825, 268, 200, 280).contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					Selected(2);
				}
			}
			break;
		}

	}
}

void Startplay::Update()
{
	Vector2i mousePosition = Mouse::getPosition(newwindow);
	if (titles[3].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
	{
		titles[3].setFillColor(Color::Red);
	}
	else
	{
		titles[3].setFillColor(Color::White);
	}

	if (towers[2].sizeTower() < numberOfDiscs)
	{
		if (isFirstselected)
		{
			circle[firstSelected].setFillColor(Color::Green);
		}
		if (isFirstselected && isSecondSelected)
		{
			if (towers[firstSelected].checkRules(towers[secondSelected]))
			{
				newwindow.close();
			}
			else
			{
				towers[firstSelected].movedDisk(towers[secondSelected]);
			}
			isFirstselected = false;
			isSecondSelected = false;
			circle[firstSelected].setFillColor(Color::Red);
			currentMove++;
			name = "Number of\nmoves: " + to_string(currentMove);
			titles[1].setString(name);
		}
	}
	if (towers[2].sizeTower() == numberOfDiscs)
	{
		titles[2].setString("Congratulations!!!");
	}
}

void Startplay::Draw()
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
	for (int i = 0; i < circle.size(); i++)
	{
		newwindow.draw(circle[i]);
	}
	newwindow.display();
}

void Startplay::InitText(Text& mtext, Font& font, int x, int y, String str, int size)
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

void Startplay::InitCircle(CircleShape& circle, int x, int y)
{
	circle.setRadius(10);
	circle.setFillColor(Color::Red);
	circle.setOrigin(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2);
	circle.setOutlineThickness(2);
	circle.setOutlineColor(Color::White);
	circle.setPosition(Vector2f(x,y));
}

void Startplay::Selected(int tower)
{
	if (!isFirstselected)
	{
		firstSelected = tower;
		isFirstselected = true;
		return;
	}
	if (!isSecondSelected)
	{
		secondSelected = tower;
		isSecondSelected = true;
		return;
	}
}
