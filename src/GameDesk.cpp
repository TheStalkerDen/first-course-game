#include "GameDesk.hpp"
#include <iostream>

GameDesk::GameDesk(String	DeskTexture , RenderWindow& window)
{
	texture = DeskTexture;
	GameDeskTexture.loadFromFile("images/" + texture);
	SelectCellNum = -1;
	isSelected == false;
	font.loadFromFile("font/ubuntu.ttf");
	text.setFont(font);
	text.setColor(Color::Black);
	text.setCharacterSize(80);
	int tmpi = -2, tmpj = 3;
	// у подальшій конструкції ініціалізуються спрайти та виставляються на свої позиції
	for (int i = 1; i <= 16; i++)
	{
		if (i % 4 == 1)
		{
			tmpi = -2;
			tmpj--;
		}
		GameDeskSprite[i-1].setTexture(GameDeskTexture);
		GameDeskSprite[i-1].setPosition(window.getSize().x/2 +tmpi*100 , window.getSize().y/2 - tmpj*100);
		tmpi++;
	}
	// ініціалізується матриця стану клітинок
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			DeskStatus[i][j] = 0;
}
 
// Відображає ігрове поле
void GameDesk::ShowDesk(RenderWindow& window)
{
	
	for (int i = 0; i < 16; i++)
	{
		int row = i / 4;  // отримуємо номер рядка
		int col = i % 4; // номер колонки
		window.draw(GameDeskSprite[i]);
		Vector2f posofSprite = GameDeskSprite[i].getPosition();
		posofSprite.x += 23;
		posofSprite.y;
		if (DeskStatus[row][col] == 'a')
		{
			text.setPosition(posofSprite);
			text.setString("A");
			window.draw(text);
		}
		else if (DeskStatus[row][col] == 'b')
		{
			text.setPosition(posofSprite);
			text.setString("B");
			window.draw(text);
		}
		else if (DeskStatus[row][col] == 'c')
		{
			text.setPosition(posofSprite);
			text.setString("C");
			window.draw(text);
		}
		else if (DeskStatus[row][col] == 'd')
		{
			text.setPosition(posofSprite);
			text.setString("D");
			window.draw(text);
		}
	}
	
}

void GameDesk::SelectCell(Vector2f pos)
{
		for (int i = 0; i < 16; i++)
		{
			if (GameDeskSprite[i].getGlobalBounds().contains(pos.x, pos.y))
			{
				if (SelectCellNum != i)
				{
					
					GameDeskSprite[i].setColor(Color::Blue); // розфарбовуємо в потрібний колір теперішню клітинку
					if (SelectCellNum != -1)
						GameDeskSprite[SelectCellNum].setColor(Color::White); //знімаємо виділення з попередньої клітинки
					SelectCellNum = i;
					isSelected = true;
				}
			}
		}
}

void GameDesk::UpdateGameDeskStatus(Event event)
{
	int row = SelectCellNum / 4;  // отримуємо номер рядка
	int col = SelectCellNum % 4; // номер колонки
	if(event.key.code == Keyboard::A)
	{
		DeskStatus[row][col] = 'a';
	}
	else if (event.key.code == Keyboard::B)
	{
		DeskStatus[row][col] = 'b';
	}
	else if (event.key.code == Keyboard::C)
	{
		DeskStatus[row][col] = 'c';
	}
	else if (event.key.code == Keyboard::D)
	{
		DeskStatus[row][col] = 'd';
	}
	else if (event.key.code == Keyboard::BackSpace)
	{
		DeskStatus[row][col] = 0;
	}
}

bool GameDesk::IsCellSelect()
{
	return isSelected;
}

bool GameDesk::isDeskFull()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (DeskStatus[i][j] == 0)
				return false;
		}
	}
	return true;
}



bool GameDesk::isWin()
{
	//Логіка перевірки така - кожній букві присвоюється певне число . Під час кожного проходу по стовпчиках та рядках буде отримуватись певний добуток , якщо 
	//він під час якогось проходу відрізняється від потрібного , то тоді виходить що користувач неправильно заповнив поле
	//Значення для букв підбирались так , щоб отримати певний добуток можна було отримати  однозначно . Викоростовувались значення простих чисел та основна властивість арифметики
	int dobutok; // зберігає добуток
	// прохід по рядках
	for (int i = 0; i < 4; i++)
	{
		dobutok = 1; 
		for (int j = 0; j < 4; j++)
		{
			if (DeskStatus[i][j] == 'a')
				dobutok *= 2;
			else if (DeskStatus[i][j] == 'b')
				dobutok *= 3;
			else if (DeskStatus[i][j] == 'c')
				dobutok *= 5;
			else if (DeskStatus[i][j] == 'd')
				dobutok *= 7;
		}
		if (dobutok != 210)
			return false;
	}
	//прохід по стовпчиках
	for (int j = 0; j < 4; j++)
	{
		dobutok = 1;
		for (int i = 0; i < 4; i++)
		{
			if (DeskStatus[i][j] == 'a')
				dobutok *= 2;
			else if (DeskStatus[i][j] == 'b')
				dobutok *= 3;
			else if (DeskStatus[i][j] == 'c')
				dobutok *= 5;
			else if (DeskStatus[i][j] == 'd')
				dobutok *= 7;
		}
		if (dobutok != 210)
			return false;
	}
	return true;
}

void GameDesk::ReloadGameDesk()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			DeskStatus[i][j] = 0;
		}
	}
}

int ReurnYourGameTime(int level)
{
	if (level <= 6)
		return 120;
	else if (level <= 10)
		return 80;
	else if (level <= 14)
		return 50;
}