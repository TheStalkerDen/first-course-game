#include "Menu.h"
#include "Button.hpp"
#include "Text.hpp"

void menu(RenderWindow & window , int *currentState )
{
	Font font;
	font.loadFromFile("font/graphiti.ttf");
	Text text("", font, 92);
	text.setColor(Color(221 , 48 , 11));
	Button bStartGame(window.getSize().x/2-150 , window.getSize().y/2- 150 , "Button.png" , L"Грати"  , "ukraine.otf"); // кнопка для старта игры;
	Button bHelp(window.getSize().x / 2 - 150, window.getSize().y / 2 - 50, "Button.png", L"Допомога", "ukraine.otf"); // кнопка для вызова помощи
	Button bInfo(window.getSize().x / 2 - 150, window.getSize().y / 2 + 50, "Button.png", L"Автор", "ukraine.otf"); // для вызова информации об авторе
	Button bExit(window.getSize().x / 2 - 150, window.getSize().y / 2 + 150, "Button.png", L"Вихід", "ukraine.otf"); // для выхода
	Clock chClock;
	Texture backgroundText; // текструра фона
	backgroundText.loadFromFile("images/background.jpg");
	Sprite backgroundS;
	backgroundS.setTexture(backgroundText);
	chClock.restart();
	while (*currentState == 0)
	{
		Int64 chTime = chClock.getElapsedTime().asMilliseconds();
		Vector2i pixelPos = Mouse::getPosition(window);//забираємо координати курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		window.clear(Color::White);
		bStartGame.IsCursorOnButton(pos);
		bHelp.IsCursorOnButton(pos);
		bInfo.IsCursorOnButton(pos);
		bExit.IsCursorOnButton(pos);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}
			if (Mouse::isButtonPressed(Mouse::Left) && chTime >= 200)
			{
				if (bStartGame.IsClicked(pos)) { *currentState = 1; }
				if (bHelp.IsClicked(pos)) { *currentState = 2; }
				if (bInfo.IsClicked(pos)) { AboutAuthor(window); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
				if (bExit.IsClicked(pos))
				{
					window.close();
					exit(0);
				}
			}
		}
		
		
		window.draw(backgroundS);
		showText(window, text, L"Розташуй 16 літер", window.getSize().x / 2 - 290, 30);
		bStartGame.ShowButton(window);
		bHelp.ShowButton(window);
		bInfo.ShowButton(window);
		bExit.ShowButton(window);

		window.display();
		
	}
}

void menu_choose_GameMode(RenderWindow & window, int*currentState, int *gameMode , bool* isGame)
{
	Button bMode1(window.getSize().x / 2 - 198, window.getSize().y / 2 - 150, "Button2.png", L"З обм. часом", "ukraine.otf"); // кнопка режиму гри 1
	Button bMode2(window.getSize().x / 2 - 198, window.getSize().y / 2 - 50, "Button2.png", L"З обм. спробами", "ukraine.otf"); // кнопка режиму гри 2
	Button bMode3(window.getSize().x / 2 - 198, window.getSize().y / 2 + 50, "Button2.png", L"Вільний", "ukraine.otf"); // кнопка режиму гри 3
	Button bExitToMenu(window.getSize().x / 2 - 150, window.getSize().y / 2 + 150, "Button.png", L"До меню", "ukraine.otf"); // кнопка виходу до меню
	Texture backgroundText; // текструра фона
	Font font;
	font.loadFromFile("font/graphiti.ttf");
	Text text("", font, 92);
	text.setColor(Color::Black);
	backgroundText.loadFromFile("images/background.jpg");
	Sprite backgroundS;
	backgroundS.setTexture(backgroundText);
	Clock chClock;
	chClock.restart();
	while (*currentState == 1)
	{
		Int64 chTime = chClock.getElapsedTime().asMilliseconds();
		Vector2i pixelPos = Mouse::getPosition(window);//забираємо координати курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		window.clear(Color::White);
		bMode1.IsCursorOnButton(pos);
		bMode2.IsCursorOnButton(pos);
		bMode3.IsCursorOnButton(pos);
		bExitToMenu.IsCursorOnButton(pos);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}

			if (Mouse::isButtonPressed(Mouse::Left) && chTime >= 200)
			{
				if (bMode1.IsClicked(pos)) { *gameMode = 1; *currentState = 4; *isGame = true; };
				if (bMode2.IsClicked(pos)) { *gameMode = 2; *currentState = 4; *isGame = true; };
				if (bMode3.IsClicked(pos)) { *gameMode = 3; *currentState = 4; *isGame = true; };
				if (bExitToMenu.IsClicked(pos)) { *currentState = 0; };
			}
		}
		window.draw(backgroundS);
		showText(window, text, L"Виберіть режим", window.getSize().x / 2 - 280, 30);
		bMode1.ShowButton(window);
		bMode2.ShowButton(window);
		bMode3.ShowButton(window);
		bExitToMenu.ShowButton(window);
		window.display();
	}

}


void menu_help(RenderWindow & window, int*currentState, int*helpmode)
{
	Font font;
	font.loadFromFile("font/graphiti.ttf");
	Text text("", font, 92);
	text.setColor(Color::Black);
	Button bHelp1(window.getSize().x / 2 - 198, window.getSize().y / 2 - 150, "Button2.png", L"Як грати", "ukraine.otf");
	Button bHelp2(window.getSize().x / 2 - 198, window.getSize().y / 2 - 50, "Button2.png", L"Про режими ", "ukraine.otf");
	Button bExitToMenu(window.getSize().x / 2 - 150, window.getSize().y / 2 + 50, "Button.png", L"До меню", "ukraine.otf"); // кнопка виходу до меню
	Texture backgroundText; // текструра фона
	backgroundText.loadFromFile("images/background.jpg");
	Sprite backgroundS;
	backgroundS.setTexture(backgroundText);
	Clock chClock;
	chClock.restart();
	while (*currentState == 2 && *helpmode == 0)
	{
		Int64 chTime = chClock.getElapsedTime().asMilliseconds();
		Vector2i pixelPos = Mouse::getPosition(window);//забираємо координати курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		window.clear(Color::White); // очищаємо екран та заповнюємо білим кольором
		bHelp1.IsCursorOnButton(pos);
		bHelp2.IsCursorOnButton(pos);
		bExitToMenu.IsCursorOnButton(pos);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}
			if (Mouse::isButtonPressed(Mouse::Left) && chTime >= 200)
			{
				if (bHelp1.IsClicked(pos)) { Help1Text(window); }
				if (bHelp2.IsClicked(pos)) { Help2Text(window); }
				if (bExitToMenu.IsClicked(pos)) { *currentState = 0; };
			}
		}
		window.draw(backgroundS);
		showText(window, text, L"Допомога", window.getSize().x / 2 - 172, 30);
		bHelp1.ShowButton(window);
		bHelp2.ShowButton(window);
		bExitToMenu.ShowButton(window);
		window.display();
	}
}
