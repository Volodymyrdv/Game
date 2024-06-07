#include "About.h"

About::About(Sprite& mainSprite, Font& font, Image& mainIcon):newwindow(VideoMode(1280, 720), L"Курсова робота")
{
	this->mainSprite = mainSprite;
	this->font = font;
	this->mainIcon = mainIcon;
	newwindow.setIcon(512, 512, mainIcon.getPixelsPtr());
 
	InitText(titles[0], font, 56, 169, "Pib: Dvorkoviy Volodymyr Volodymyrovych", 45);
	InitText(titles[1], font, 56, 269, "Group: KN-22", 45);
	InitText(titles[2], font, 56, 369, "(I hope this game cheers you up for a while)", 45);
	InitText(titles[3], font, 56, 469, "Exit", 45);
	InitText(titles[4], font, 1280 / 2, 75, "About me", 55);
	titles[4].setFillColor(Color(102, 254, 250));
	titles[4].setOrigin(titles[4].getLocalBounds().width / 2, titles[4].getLocalBounds().height / 2);
}

void About::Run()
{
	while (newwindow.isOpen())
	{
		HandleInput();
		Update();
		Draw();
	}
}

void About::HandleInput()
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
			}
		}

	}
}

void About::Update()
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
}

void About::Draw()
{
	newwindow.clear();
	newwindow.draw(mainSprite);
	for (int i = 0; i < titles.size(); i++)
	{
		newwindow.draw(titles[i]);
	}
	newwindow.display();
}

void About::InitText(Text& mtext, Font& font, int x, int y, String str, int size)
{
	mtext.setFont(font);
	mtext.setCharacterSize(size);
	mtext.setPosition(Vector2f(x, y));
	mtext.setString(str);
	mtext.setFillColor(Color::White);
	mtext.setOutlineThickness(4);
	mtext.setOutlineColor(Color(197, 106, 103));
}
