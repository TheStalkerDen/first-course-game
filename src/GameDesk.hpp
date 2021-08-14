#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;


// клас ігрового поля
class GameDesk
{
private:
	String texture;
	int DeskStatus[4][4];   // зберігає стан клітинок поля (0 - якщо пуста , а якщо ні , то зберігає код літери)
	Texture GameDeskTexture; // зберігає текстуру клітинки поля
	Sprite GameDeskSprite[16];  // зберігає спрайти ігрового поля
	bool isSelected; // чи вибрана якась клітинка
	int SelectCellNum; // зберігає номер виділенної клітинки
	Font font;
	Text text;
	
public:
	GameDesk(String pathtoTexture , RenderWindow& window); // конструктор , що приймає шлях до текстури поля
	void ShowDesk(RenderWindow& window); // відображує поле гри , в параметрах приймає вікно
	void SelectCell(Vector2f pos); // виділяємо клітку
	void UpdateGameDeskStatus(Event event); // оновлюємо матрицю стану
	void ReloadGameDesk(); // очищає ігрове поле
	bool IsCellSelect(); // повертає значення isSelected
	bool isDeskFull(); // чи заповнене поле до кінця
	bool isWin(); // функця , що повертає  true якщо користувач виграв


};

// повертає час для режиму гри 1 відповідно до рівня гри
int ReurnYourGameTime(int level);
