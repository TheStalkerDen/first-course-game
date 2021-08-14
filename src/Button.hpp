#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Button
{
private:
	int posX;  // позиція кнопки по x
	int posY;  // позиція кнопки по y
	Texture ButtonTexture; // текстура кнопки
	Sprite ButtonSprite; // спрайт кнопки
	bool isPressed; // чи нажата кнопка
	bool isActivated; // чи активна
	String ButtonText; // текст кнопки
	Font font;
	Text text;
public:
	Button(int posX, int posY, String ButtonTexture, String ButtonText , String ButtonFont);
	void ShowButton(RenderWindow & window); // показує кнопку
	void IsCursorOnButton(Vector2f MousePos); // якщо курсор на кнопці , то виділяє його
	void IsButtonActivated(); // функція , що зафарбовує клавішу сірим кольором , якщо вона неактивна
	bool IsClicked(Vector2f MousePos); // функція , що повертає true якщо клавіша нажата
	void setButtonActivated(bool isActivated); // функція , що дозволяє змінити стан клавіши
	bool getButtonActivated(); // функція , що дозволяє отримати стан активації клавіши
};