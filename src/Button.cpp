#include "Button.hpp"

 Button::Button(int posX, int posY, String ButtonTexture, String ButtonText , String ButtonFont)
{
	this->posX = posX;
	this->posY = posY;
	this->ButtonText = ButtonText;
	isPressed = false;
	this->ButtonTexture.loadFromFile("images/" + ButtonTexture);
	ButtonSprite.setTexture(this->ButtonTexture);
	ButtonSprite.setPosition(this->posX, this->posY);
	font.loadFromFile("font/" + ButtonFont);
	text.setFont(font);
	text.setString(ButtonText);
	text.setPosition(this->posX + 30, this->posY + 20);
	text.setCharacterSize(45);
	text.setColor(Color::Black);
	isActivated = true;
}

void Button::ShowButton(RenderWindow & window)
 {
	window.draw(ButtonSprite);
	window.draw(text);
 }

void Button::IsCursorOnButton(Vector2f MousePos )
{
	if (ButtonSprite.getGlobalBounds().contains(MousePos.x, MousePos.y))
		ButtonSprite.setColor(Color(129 , 163 , 220));
	else
		ButtonSprite.setColor(Color::White);
}

void Button::IsButtonActivated()
{
	if (isActivated == true)
		ButtonSprite.setColor(Color::Green);
	else
		ButtonSprite.setColor(Color(127,127,127));
}

void Button::setButtonActivated(bool isActivated)
{
	this->isActivated = isActivated;
}

bool Button::getButtonActivated()
{
	return isActivated;
}

bool Button::IsClicked(Vector2f MousePos)
{
	if (ButtonSprite.getGlobalBounds().contains(MousePos.x, MousePos.y))
		return true;
	else
		return false;
}