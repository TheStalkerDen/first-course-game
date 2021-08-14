#include "Text.hpp"

void showGameTime(RenderWindow & window, Int64 time, Text text, int mode)
{
	std::ostringstream gameTimeStr;//строка здоровья игрока
	gameTimeStr << time; //заносим в строку здоровье 
	if (mode == 1)
	{
		text.setString(L"Час гри: " + gameTimeStr.str());
		text.setPosition(window.getSize().x - 400, 30);
	}
	else if (mode == 2)
	{
		text.setString(L"Час до кінця: " + gameTimeStr.str());
		text.setPosition(window.getSize().x - 500, 30);
	}
	
	window.draw(text);
	
}

void showText(RenderWindow & window, Text text, String yourtext, int posX, int posY)
{
	text.setString(yourtext);
	text.setPosition(posX, posY);
	window.draw(text);
}


void showTextwithValue(RenderWindow & window, Text text, String yourtext, int number, int posX, int posY)
{
	std::ostringstream numberstr;//строка здоровья игрока
	numberstr << number; //заносим в строку здоровье 
	text.setString(yourtext + numberstr.str());
	text.setPosition(posX, posY);
	window.draw(text);
}

void Help1Text(RenderWindow & window)
{
		while(1)
		{
		window.clear(Color::White);
		Font font;
		font.loadFromFile("font/ukraine.otf");
		Text text("", font, 45);
		text.setColor(Color::Black);
		showText(window, text, L"Ціль гри  ", window.getSize().x/2-20, 10);
		text.setCharacterSize(30);
		showText(window, text, L"Ціль даної гри : на квадратному полі розміром 4*4 розтавити 16 літер (по чотири a\n,b,c,d) таким чином , щоб в кожному горизонтальному і в кожноиу вертикальному \nряду будь-яка літера зустрічалася по одному разу \n\n В клітинки букви a , b , c , d можна заносити після їх виділення.\n Після того як запонвили поле , натискайте кнопку перевірки і якщо все добре , то \n отримаєте бали та перейдете на наступний рівень. Подробниці про режими в іншому \n пункті. \n\n Щоб вийти звідси нажміть ESC ", 20, 60);
		window.display();
		
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				break;
		}
}

void Help2Text(RenderWindow & window)
{
	while (1)
	{
	window.clear(Color::White);
	Font font;
	font.loadFromFile("font/ukraine.otf");
	Text text("", font, 45);
	text.setColor(Color::Black);
	showText(window, text, L"Про режими: ", window.getSize().x / 2 - 20, 10);
	text.setCharacterSize(30);
	showText(window, text, L"Режим з обмеженим часом : у даному режимі на кожному рівні ви  маєте обмеження \n по часу . Перші 6 по 120 секунд  з 6 по 10 80 секунд , а вже далі по 50 . \n Режим з обмеженими спробами: ви маєте обмеження на кількість перевірок , тому \n уважно грайте . Час на кожному рівні не обмежений \n Вільний режим : без ніяких обмежень . Можете вийти в будь-який момент \n\n Щоб вийти звідси нажміть ESC ", 20, 60);
	window.display();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			break;
	}
}

void AboutAuthor(RenderWindow & window)
{
	while (1)
	{
	window.clear(Color::White);
	Font font;
	font.loadFromFile("font/ukraine.otf");
	Text text("", font, 45);
	text.setColor(Color::Black);
	showText(window, text, L"Автор  ", window.getSize().x / 2 - 20, 10);
	text.setCharacterSize(30);
	showText(window, text, L"\nДана гра створена Єрмоленком Денисом з групи КВ-73 \n\n Щоб вийти звідси нажміть ESC ", 20, 60);
	window.display();
	if (Keyboard::isKeyPressed(Keyboard::Escape))
		break;
	}
}