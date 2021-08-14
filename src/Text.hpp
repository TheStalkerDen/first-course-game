#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>
using namespace sf;

void showGameTime(RenderWindow & window, Int64 time, Text text , int mode); // показує час гри , через mode передається режим виводу (2 - для режиму 1 , та 1 для інших)
void showText(RenderWindow & window, Text text, String yourtext, int posX, int PosY); // демонструє текст за певними координатами
void showTextwithValue(RenderWindow & window, Text text, String yourtext, int number, int posX, int PosY); // демонструє текст зі змінюваним елементом
void Help1Text(RenderWindow & window); // вивод тексту допомоги 1
void Help2Text(RenderWindow & window); // вивод тексту допомоги 2
void AboutAuthor(RenderWindow & window); // вивод тексту про автора