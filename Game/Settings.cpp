#include "Settings.h"
#include <iostream>
Settings::Settings(int numberOfDiscs, Sprite& mainSprite, Font& font, Image& mainIcon):newwindow(VideoMode(1280, 720), L"Курсова робота")
{

	this->numberOfDiscs = numberOfDiscs;
	this->mainSprite = mainSprite;
	this->font = font;
	this->mainIcon = mainIcon;
	newwindow.setIcon(512, 512, mainIcon.getPixelsPtr());

	InitText(titles[0], font, 56, 169, "Number of discs: 3", 50);
	InitText(titles[1], font, 56, 239, "+", 65);
	InitText(titles[2], font, 259, 239, "-", 65);
	InitText(titles[3], font, 56, 320, "Exit", 50);
	InitText(titles[4], font, 1280 / 2, 75, "Settings", 55);
	titles[4].setOrigin(titles[4].getLocalBounds().width / 2, titles[4].getLocalBounds().height / 2);
	titles[4].setFillColor(Color(102, 254, 250));
}

void Settings::Run()
{
	while (newwindow.isOpen())
	{
		HandleInput();
		Update();
		Draw();
	}
}

int Settings::getNumberofDiscs()
{
	return numberOfDiscs;
}

void Settings::HandleInput()
{
	Event Startevent;
	while (newwindow.pollEvent(Startevent))
	{
		switch (Startevent.type)
		{
		case Event::MouseButtonPressed:
			if (Startevent.mouseButton.button == Mouse::Left)
			{
				Vector2i mousePosition = Mouse::getPosition(newwindow);
				if (titles[1].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					if (numberOfDiscs >= 6)
					{
						numberOfDiscs = 1;
					}
					else
					{
						numberOfDiscs++;
					}
				}
				if (titles[2].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					if (numberOfDiscs <= 1)
					{
						numberOfDiscs = 6;
					}
					else
					{
						numberOfDiscs--;
					}
				}
				if (titles[3].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					newwindow.close();
					break;
				}
				break;
			}
		}
		

	}

}

void Settings::Update()
{
	Vector2i mousePosition = Mouse::getPosition(newwindow);
	titles[1].setFillColor(Color::White);
	titles[2].setFillColor(Color::White);
	titles[3].setFillColor(Color::White);
	if (titles[1].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
	{
		titles[1].setFillColor(Color::Blue);
	}
	if (titles[2].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
	{
		titles[2].setFillColor(Color::Blue);
	}
	if (titles[3].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
	{
		titles[3].setFillColor(Color::Red);
	}
	name = "Number of discs: " + to_string(numberOfDiscs);
	titles[0].setString(name);
}

void Settings::Draw()
{
	newwindow.clear();
	newwindow.draw(mainSprite);
	for (int i = 0; i < titles.size(); i++)
	{
		newwindow.draw(titles[i]);
	}
	newwindow.display();
}

void Settings::InitText(Text& mtext, Font& font, int x, int y, String str, int size)
{
	mtext.setFont(font);
	mtext.setCharacterSize(size);
	mtext.setPosition(Vector2f(x, y));
	mtext.setString(str);
	mtext.setFillColor(Color::White);
	mtext.setOutlineThickness(4);
	mtext.setOutlineColor(Color(197, 106, 103));
}
