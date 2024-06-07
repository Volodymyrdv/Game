#include "Game.h"
#include "Settings.h"
#include "About.h"
#include "Startplay.h"
#include "Startwatch.h"
Game::Game() :window(VideoMode(1280, 720), L"Курсова робота")
{
	numberOfDiscs = 3;
	font[0].loadFromFile("Fonts/SnesItalic-1G9Be.ttf");
	font[1].loadFromFile("Fonts/Deledda Open Light.ttf");

	mainTexture[0].loadFromFile("Images/main1.jpg");
	mainTexture[1].loadFromFile("Images/main2.jpg");
	mainTexture[2].loadFromFile("Images/main3.png");

	for (int i = 0; i < mainSprite.size(); i++)
	{
		mainSprite[i].setTexture(mainTexture[i]);
	}
	
	mainIcon.loadFromFile("Icons/123.png");
	window.setIcon(512, 512, mainIcon.getPixelsPtr());

	InitText(titles[0], font[0], 1280 / 2, 200, "Play", 80);
	InitText(titles[1], font[0], 1280 / 2, 300, "Watch", 80);
	InitText(titles[2], font[0], 1280 / 2, 400, "Settings", 80);
	InitText(titles[3], font[0], 1280 / 2, 500, "About me", 80);
	InitText(titles[4], font[0], 1280 / 2, 600, "Exit", 80);
	InitText(titles[5], font[0], 1280 / 2, 50, "The Tower of Hanoi", 90);
	titles[5].setFillColor(Color(102, 254, 250));
}
void Game::HandleInput()
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::MouseButtonPressed:
			if (event.mouseButton.button == Mouse::Left)
			{
				Vector2i mousePosition = Mouse::getPosition(window);
				if (titles[0].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					window.close();
					Startplay start(numberOfDiscs, mainSprite[2], font[1], mainIcon);
					start.Run();
					window.create(VideoMode(1280, 720), L"Курсова робота");
					window.setIcon(512, 512, mainIcon.getPixelsPtr());
					break;
				}
				if (titles[1].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					window.close();
					Startwatch start(numberOfDiscs, mainSprite[2], font[1], mainIcon);
					start.Run();
					window.create(VideoMode(1280, 720), L"Курсова робота");
					window.setIcon(512, 512, mainIcon.getPixelsPtr());
					break;
				}
				if (titles[2].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					window.close();
					Settings setting(numberOfDiscs, mainSprite[1], font[1], mainIcon);
					setting.Run();
					numberOfDiscs = setting.getNumberofDiscs();
					window.create(VideoMode(1280, 720), L"Курсова робота");
					window.setIcon(512, 512, mainIcon.getPixelsPtr());
					break;
				}
				if (titles[3].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					window.close();
					About about(mainSprite[1], font[1], mainIcon);
					about.Run();
					window.create(VideoMode(1280, 720), L"Курсова робота");
					window.setIcon(512, 512, mainIcon.getPixelsPtr());
					break;
				}
				if (titles[4].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
				{
					window.close();
					break;
				}
			}
		}
	}
}

void Game::Update()
{
	Vector2i mousePosition = Mouse::getPosition(window);
	for (int i = 0; i < titles.size()-1; i++)
	{
		if (titles[i].getGlobalBounds().contains(Vector2f(mousePosition.x, mousePosition.y)))
		{
			titles[i].setFillColor(Color::Red);
		}
		else
		{
			titles[i].setFillColor(Color::White);
		}
	}
}



void Game::Draw()
{
	window.clear();
	window.draw(mainSprite[0]);
	for (int i = 0; i < titles.size(); i++)
	{
		window.draw(titles[i]);
	}
	window.display();
}

void Game::InitText(Text& mtext,Font& font, int x, int y, String str,int size)
{
	mtext.setFont(font);
	mtext.setCharacterSize(size);
	mtext.setPosition(Vector2f(x,y));
	mtext.setString(str);
	mtext.setOrigin(mtext.getLocalBounds().width / 2, mtext.getLocalBounds().height / 2);
	mtext.setFillColor(Color::White);
	mtext.setOutlineThickness(4);
	mtext.setOutlineColor(Color(197, 106, 103));
}

void Game::Run()
{
	while (window.isOpen())
	{
		HandleInput();
		Update();
		Draw();
	}
}

