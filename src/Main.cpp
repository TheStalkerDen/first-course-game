
#include <SFML/Graphics.hpp>
#include "GameDesk.hpp"
#include "Text.hpp"
#include "Button.hpp"
#include "Menu.h"
#include <iostream>

using namespace sf;

int main()
{

	RenderWindow window(VideoMode(1280, 720), "Game" , Style::Close);
	GameDesk gDesk("Cell.png" , window); //створюємо ігрове поле 
	Clock gameClock; // час гри
	Font font;// шрифт времени игры
	font.loadFromFile("font/ukraine.otf");
	Text text("" , font , 50); // текст для 
	text.setColor(Color::Black);
	Text warntext("", font, 35);
	warntext.setColor(Color::Red);

	int score = 0; // зберігає кількість зароблених балів
	int level = 1; // теперішній рівень 

	Button CheckBut(window.getSize().x/2  -150 , window.getSize().y/2+220, "Button.png", L"Перевірка", "ukraine.otf");
	Button EXIT(window.getSize().x / 2 - 500, window.getSize().y / 2 + 220, "Button.png", L"Закінчити", "ukraine.otf");
	Button HELP(window.getSize().x / 2 + 200 , window.getSize().y / 2 + 220, "Button.png", L"Правила", "ukraine.otf");
	CheckBut.setButtonActivated(false);
	Texture InfoText;
	InfoText.loadFromFile("images/Inform.png");
	Sprite InfoSprite;
	InfoSprite.setTexture(InfoText);
	InfoSprite.setPosition(window.getSize().x / 2 - 300, window.getSize().y / 2 -300);
	bool isGame = true;
	bool isPause = false; // чи є пауза
	bool isBad = false; // чи заповним гравецб поле неправильно
	bool isMenu = true; // чи в меню
	bool isWin = false; // чи є перемога на рівні
	bool SelfEndGame = false; // чи закінчив гру гравець по своїй волі
	int currentState = 0; // зберігає стан програми
	int helpmode = 0;
	int gameMode = 0; // зберігає режим гри
	int attempt = 15; // зберігає кількість спроб
	int YourGameTime = 0; // зберігає кількість секунд гри для режиму гри 1 
	Int64 savemoment; // для збереження часу 
	Int64 dif = 0; // для встановлення різниці в часі в період , коли гравець знаходиться в пункті допомога під час гри
	
	while (window.isOpen())
	{
		menu(window , &currentState ); // меню
		menu_choose_GameMode(window, &currentState, &gameMode , &isGame); // меню вибору режиму
		menu_help(window, &currentState, &helpmode); // меню допомоги
		gameClock.restart();
		gDesk.ReloadGameDesk();
		dif = 0;
		while(currentState == 4)
		{
			Vector2i pixelPos = Mouse::getPosition(window);//забираємо координати курсора
			Vector2f pos = window.mapPixelToCoords(pixelPos); //переводимо їх в ігрові координати
			Int64 GameTime;
			Clock wait;
			YourGameTime = ReurnYourGameTime(level); // встановлюємо час гри для режиму 1 
			if (isGame)
			{
				GameTime = gameClock.getElapsedTime().asSeconds();
			}


			
			if (isGame)
			{
				if (gDesk.isDeskFull())
					CheckBut.setButtonActivated(true);
				else
					CheckBut.setButtonActivated(false);
				CheckBut.IsButtonActivated();
				if (CheckBut.getButtonActivated())
					CheckBut.IsCursorOnButton(pos);
			}
	
			EXIT.IsCursorOnButton(pos);
			HELP.IsCursorOnButton(pos);

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					exit(0);
				}
				if (event.type == Event::MouseButtonPressed)
					if (event.key.code == Mouse::Left)
					{
						gDesk.SelectCell(pos);
						if (CheckBut.getButtonActivated() && isGame)
						{
							if (CheckBut.IsClicked(pos))
							{
								isWin = gDesk.isWin();
								if (isWin)
								{
									isPause = true;
									isGame = false;
									level++;
									score += 200;
								}
								else if (isWin == false)
								{
									savemoment = gameClock.getElapsedTime().asSeconds();
									isBad = true;
									if (gameMode == 2)
										attempt--;
								}
							}
						}
						else if (!isGame && isWin == true )
						{
							isGame = true;
							gDesk.ReloadGameDesk();
							dif = 0;
							gameClock.restart();
							savemoment = 0;
						}
						else if (!isGame && isWin == false)
						{
							score = 0;
							currentState = 0;
							attempt = 15;
							level = 1;
							SelfEndGame = false;
						}
						if (EXIT.IsClicked(pos))
						{
							isGame = false;
							SelfEndGame = true;
							isWin = false;
						}
						if (HELP.IsClicked(pos))
						{
							Int64 wait1 = GameTime;
							Help1Text(window); 
							dif += gameClock.getElapsedTime().asSeconds() - wait1;
						}

					}
				if (event.type == Event::KeyPressed)
					if (gDesk.IsCellSelect())
					{
						gDesk.UpdateGameDeskStatus(event);
						wait.restart();
					}
			}

			if (gameMode == 1 && (YourGameTime - GameTime + dif <= 0))
			{
				isGame = false;
				isWin = gDesk.isWin();
			}
			if (gameMode == 2 & attempt <= 0)
			{
				isGame = false;
				isWin = false;
			}


			window.clear(Color::White);

			gDesk.ShowDesk(window);
			if (gameMode == 1)
				showGameTime(window, YourGameTime - GameTime + dif, text , 2);
			else if(gameMode == 2 || gameMode == 3)
				showGameTime(window, GameTime - dif, text , 1);
			if (gameMode == 2)
				showTextwithValue(window, text, L"Спроби: ", attempt, window.getSize().x - 400, 100);
			showTextwithValue(window, text, L"Бали: ", score, 20, 20);
			showTextwithValue(window, text, L"Рівень: ", level, 20, 70);

			CheckBut.ShowButton(window);
			HELP.ShowButton(window);
			EXIT.ShowButton(window);

			if (isBad == true && gameClock.getElapsedTime().asSeconds() - savemoment <= 2)
			{
				showText(window, warntext, L"Неправильно заповнене\nполе!!!", 20, 140);

			}
			else if (gameClock.getElapsedTime().asSeconds() - savemoment > 2)
			{
				isBad = false;
			}

			if (!isGame)
			{
				
				window.draw(InfoSprite);
				if (SelfEndGame == false)
				{
					if (isWin)
					{
						showText(window, text, L"Ви виграли !!!", InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 100);
						showTextwithValue(window, text, L"Ваші теперішні бали :\n", score, InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 150);
					}
					else if (isWin == false)
					{
						showText(window, text, L"Нажаль ви програли!!!", InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 100);
						showTextwithValue(window, text, L"Ваші бали: ", score, InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 170);
						showTextwithValue(window, text, L"Ваш рівень: ", level, InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 220);
						showText(window, text, L"Дякуємо вам за гру!", InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 280);
					}
				}
				else
				{
					showText(window, text, L"Дякуємо вам за гру!", InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 100);
					showTextwithValue(window, text, L"Ваші бали: ", score, InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 170);
					showTextwithValue(window, text, L"Ваш рівень: ", level, InfoSprite.getPosition().x + 40, InfoSprite.getPosition().y + 220);
				}
			}
			


			window.display();
		}
	}

	return 0;
}