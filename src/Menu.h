#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
void menu(RenderWindow & window ,  int*curentState ); // меню
void menu_choose_GameMode(RenderWindow &, int*currentState, int *gameMode , bool *isGame); // меню вибору режиму
void menu_help(RenderWindow & window, int*currentState, int*helpmode); // меню допомоги