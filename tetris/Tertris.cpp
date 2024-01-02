#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
using namespace sf;
class well {


public:
	int** board;
	well()
	{
		board = new int* [20];
		for (int i = 0; i < 20; i++)
		{
			board[i] = new int[10];

		}

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				board[i][j] = 0;
			}
			cout << "destructor called";
		}

	}
	~well()
	{
		for (int i = 0; i < 20; i++)
		{
			delete[] board[i];
		}
	}
	void savescore(long score,string nam) {
		std::ifstream fin;
		fin.open("scores.txt");
		int x = 0;
	}
	void drawboard(sf::RenderWindow& window, well& b, long score, int level, int line, int game,string nam,string highscorenames[5],int highscoreints[5])
	{
		if (game == 1)
		{
			savescore(score,nam);

			sf::Texture texture;
			if (!texture.loadFromFile("pics/gameover2.jpg"))
			{
				cout << "Error";
			}
			sf::Sprite sprite;
			sprite.setTexture(texture);
			window.draw(sprite);
			sf::RectangleShape box(sf::Vector2f(250.f, 60.f));
			box.setPosition(500, 500);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Transparent);
			window.draw(box);
			//scoore
		
			sf::Font font;
			string s = to_string(score);

//			if (!font.loadFromFile("fonts/arial.ttf"))
//			{
//				cout << "errore";
//			}
//			
			sf::Text text;
			text.setFont(font);
			text.getString();
			
			text.setString("Score :");
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 510.f);
			window.draw(text);
			string scor = to_string(score);
			text.setFont(font);
			text.getString();
			text.setString(scor);
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(620.f, 510.f);
			window.draw(text);
		}
		else
		{
			sf::Texture texture;
			if (!texture.loadFromFile("pics/background.png"))
			{
				cout << "Error";
			}
			sf::Sprite sprite;
			sprite.setTexture(texture);
			window.draw(sprite);
			int x = 0, y = 0;
			string l = to_string(level);
			string li = to_string(line);
			//boxes
			sf::RectangleShape box(sf::Vector2f(150.f, 60.f));
			box.setPosition(500, 50);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Transparent);
			window.draw(box);
			box.setPosition(500, 200);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Transparent);
			window.draw(box);
			box.setPosition(500, 400);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Transparent);
			window.draw(box);
			box.setPosition(500, 600);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Transparent);
			window.draw(box);
			//text
			sf::Font font;
			string s = to_string(score);

			if (!font.loadFromFile("fonts/arial.ttf"))
			{
				cout << "errore";
			}
			//name 
			sf::Text text;
			text.setFont(font);
			text.getString();
			text.setString("Player :");
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 10.f);
			window.draw(text);

			text.setFont(font);
			text.getString();
			text.setString(nam);
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 60.f);
			window.draw(text);
			//level
			text.setFont(font);
			text.getString();
			text.setString("Level : ");
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 155.f);
			window.draw(text);

			text.setFont(font);
			text.setString(l);
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 210.f);
			window.draw(text);
			score;
			//score
			text.setFont(font);
			text.getString();
			text.setString("Score :");
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 355.f);
			window.draw(text);
			text.setFont(font);
			text.setString(s);
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 410.f);
			window.draw(text);
			//lines
			text.setFont(font);
			text.getString();
			text.setString("Lines :");
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 550.f);
			window.draw(text);
			text.setFont(font);
			text.setString(li);
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::White);
			text.setPosition(510.f, 610.f);
			window.draw(text);

			sf::Text highscoretext[5];
			for (int i = 0; i < 5; i++) {
				highscoretext[i].setString(highscorenames[i]+": " + to_string(highscoreints[i]));
				highscoretext[i].setCharacterSize(30);
				highscoretext[i].setFont(font);
			}
			for (int i = 0,k=0; k<5; i+=40,k++) {
				highscoretext[k].setPosition(700, i);
			}
			for (int i = 0; i < 5; i++) {
				if(highscoreints[i]!=0)
				window.draw(highscoretext[i]);
			}
			
			for (int i = 0; i < 20; i++)
			{
				x = 0;
				for (int j = 0; j < 10; j++, x += 30)
				{
					if (b.board[i][j] == 0)
					{
						sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
						box.setPosition(x, y);
						box.setOutlineThickness(2.f);
						box.setOutlineColor(sf::Color::White);
						box.setFillColor(sf::Color::Transparent);
						window.draw(box);
					}
					if (b.board[i][j] == 1)
					{
						sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
						box.setPosition(x, y);
						box.setOutlineThickness(2.f);
						box.setOutlineColor(sf::Color::White);
						box.setFillColor(sf::Color::Cyan);
						window.draw(box);

					}
					if (b.board[i][j] == 2)
					{
						sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
						box.setPosition(x, y);
						box.setOutlineThickness(2.f);
						box.setOutlineColor(sf::Color::White);
						box.setFillColor(sf::Color::Blue);
						window.draw(box);

					}
					if (b.board[i][j] == 3)
					{

						sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
						box.setPosition(x, y);
						box.setOutlineThickness(2.f);
						box.setOutlineColor(sf::Color::White);
						box.setFillColor(sf::Color(255, 165, 0));
						window.draw(box);
					}
					if (b.board[i][j] == 4)
					{

						sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
						box.setPosition(x, y);
						box.setOutlineThickness(2.f);
						box.setOutlineColor(sf::Color::White);
						box.setFillColor(sf::Color::Yellow);
						window.draw(box);
					}
					if (b.board[i][j] == 5)
					{

						sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
						box.setPosition(x, y);
						box.setOutlineThickness(2.f);
						box.setOutlineColor(sf::Color::White);
						box.setFillColor(sf::Color::Green);
						window.draw(box);
					}
					if (b.board[i][j] == 6)
					{

						sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
						box.setPosition(x, y);
						box.setOutlineThickness(2.f);
						box.setOutlineColor(sf::Color::White);
						box.setFillColor(sf::Color::Magenta);
						window.draw(box);
					}
					if (b.board[i][j] == 7)
					{

						sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
						box.setPosition(x, y);
						box.setOutlineThickness(2.f);
						box.setOutlineColor(sf::Color::White);
						box.setFillColor(sf::Color::Red);
						window.draw(box);
					}
				}
				y += 30;
			}

		}
	}

};
class Tetromino {

public:

	Tetromino() {
	}

	virtual void drawShape(sf::RenderWindow& window, well& b) = 0;
	virtual void rotate(well& b) = 0;
	virtual void moveleft(well& b) = 0;
	virtual void moveright(well& b) = 0;
	virtual void movedown(well& b) = 0;
	virtual bool isbottomtouch(well& b) = 0;
	virtual void reset(well& b) = 0;




};
class IShape : public Tetromino {
private:

	int x_;
	int y_;
	int xcord;
	int ycord;
	int currentrotation;
	int rotation;

public:
	IShape()
	{
		rotation = 0;
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
	}
	virtual void drawShape(sf::RenderWindow& window, well& b)
	{

		if (currentrotation == 0)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Cyan);
			window.draw(box);


			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Cyan);
			window.draw(box);
			box.setPosition(x_, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Cyan);
			window.draw(box);
			box.setPosition(x_, y_ + 90);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Cyan);
			window.draw(box);

		}
		if (currentrotation == 1)
		{




			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Cyan);
			window.draw(box);

			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Cyan);
			window.draw(box);
			box.setPosition(x_ + 60, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Cyan);
			window.draw(box);
			box.setPosition(x_ + 90, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Cyan);
			window.draw(box);

		}
	}
	virtual bool isbottomtouch(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (currentrotation == 0)
		{
			if (y_ + 120 == 600 || b.board[xcord + 4][ycord] != 0)
			{
				b.board[xcord][ycord] = 1;
				b.board[xcord + 1][ycord] = 1;
				b.board[xcord + 2][ycord] = 1;
				b.board[xcord + 3][ycord] = 1;
				return true;
			}

			else
				return false;
		}
		if (currentrotation == 1)
		{
			if (y_ + 30 == 600 || b.board[xcord + 1][ycord] != 0 || b.board[xcord + 1][ycord + 1] != 0 || b.board[xcord + 1][ycord + 2] != 0 || b.board[xcord + 1][ycord + 3] != 0)
			{
				b.board[xcord][ycord] = 1;
				b.board[xcord][ycord + 1] = 1;
				b.board[xcord][ycord + 2] = 1;
				b.board[xcord][ycord + 3] = 1;
				return true;

			}

			else
				return false;
		}

	}
	void rotate(well& b)
	{


		if (isbottomtouch(b) == 0)
		{
			rotation++;
			currentrotation = rotation % 2;
		}
		if (currentrotation == 1)
		{
			if (x_ == 270)
			{
				x_ = 180;
			}

			if (x_ == 240)
			{
				x_ = 150;
			}

			if (x_ == 210)
			{
				x_ = 120;
			}
		}

	}
	void moveleft(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{

				if (x_ - 30 >= 0 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord - 1] == 0 && b.board[xcord + 2][ycord - 1] == 0 && b.board[xcord + 3][ycord - 1] == 0)
				{
					x_ = x_ - 30;
				}

			}

			if (currentrotation == 1)
			{
				if (x_ - 30 >= 0 && b.board[xcord][ycord - 1] == 0)
				{
					x_ = x_ - 30;
				}
			}
		}
	}
	void moveright(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{
				if (x_ + 30 < 300 && b.board[xcord][ycord + 1] == 0 && b.board[xcord + 1][ycord + 1] == 0 && b.board[xcord + 2][ycord + 1] == 0 && b.board[xcord + 3][ycord + 1] == 0)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 1)
			{
				if (x_ + 120 < 300 && b.board[xcord][ycord + 4] == 0)
				{
					x_ = x_ + 30;
				}
			}
		}

	}
	void movedown(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{
				if (y_ + 120 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 1)
			{
				if (y_ + 30 < 600)
				{
					y_ = y_ + 30;
				}
			}
		}
	}
	void reset(well& b)
	{
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
		rotation = 0;

	}






};
class JShape : public Tetromino {
private:
	int x_;
	int y_;
	int xcord;
	int ycord;
	int currentrotation;
	int rotation = 0;

public:
	JShape()
	{
		rotation = 0;
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
	}
	virtual void drawShape(sf::RenderWindow& window, well& b)
	{

		if (currentrotation == 0)
		{

			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);

		}
		if (currentrotation == 1)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_ + 60, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);

		}
		if (currentrotation == 2)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);

		}
		if (currentrotation == 3)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_ + 60, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);
			box.setPosition(x_ + 60, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Blue);
			window.draw(box);

		}
	}
	virtual bool isbottomtouch(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;





		if (currentrotation == 0)
		{
			if (y_ + 90 == 600 || b.board[xcord + 3][ycord] != 0 || b.board[xcord + 3][ycord + 1] != 0)
			{
				b.board[xcord][ycord + 1] = 2;
				b.board[xcord + 1][ycord + 1] = 2;
				b.board[xcord + 2][ycord + 1] = 2;
				b.board[xcord + 2][ycord] = 2;
				return true;
			}
			else
				return false;
		}
		if (currentrotation == 2)
		{
			if (y_ + 90 == 600 || b.board[xcord + 3][ycord] != 0 || b.board[xcord+1][ycord + 1] != 0)
			{
				b.board[xcord][ycord + 1] = 2;
				b.board[xcord][ycord] = 2;
				b.board[xcord + 1][ycord] = 2;
				b.board[xcord + 2][ycord] = 2;

				return true;

			}
			else
				return false;

		}


		if (currentrotation == 1)
		{
			if (y_ + 60 == 600 || b.board[xcord + 2][ycord] != 0 || b.board[xcord + 2][ycord + 1] != 0 || b.board[xcord + 2][ycord + 2] != 0)
			{
				b.board[xcord][ycord] = 2;
				b.board[xcord + 1][ycord] = 2;
				b.board[xcord + 1][ycord + 1] = 2;
				b.board[xcord + 1][ycord + 2] = 2;
				return true;
			}
			else
				return false;
		}
		if (currentrotation == 3)
		{
			if (y_ + 60 == 600 || b.board[xcord + 1][ycord] != 0 || b.board[xcord + 1][ycord + 1] != 0 || b.board[xcord + 2][ycord + 2] != 0)
			{
				b.board[xcord][ycord] = 2;
				b.board[xcord][ycord + 1] = 2;
				b.board[xcord][ycord + 2] = 2;
				b.board[xcord + 1][ycord + 2] = 2;
				return true;
			}
			else
				return false;
		}

	}
	void rotate(well& b)
	{
		if (isbottomtouch(b) == 0)
		{
			rotation++;
			currentrotation = rotation % 4;
		}
		if (currentrotation == 1)
		{
			if (x_ == 240)
			{
				x_ = 210;
			}
		}
		if (currentrotation == 3)
		{
			if (x_ == 240)
			{
				x_ = 210;

			}
		}


	}
	void moveleft(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0);
		{
			if (currentrotation == 0)
			{

				if (x_ - 30 >= 0 && b.board[xcord][ycord] == 0 && b.board[xcord + 1][ycord] == 0 && b.board[xcord + 2][ycord - 1] == 0)
				{
					x_ = x_ - 30;
				}

			}
			if (currentrotation == 2 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord - 1] == 0 && b.board[xcord + 2][ycord - 1] == 0)
			{
				if (x_ - 30 >= 0)
				{
					x_ = x_ - 30;
				}
			}

			if (currentrotation == 1)
			{
				if (x_ - 30 >= 0 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord - 1] == 0)
				{
					x_ = x_ - 30;
				}

			}

			if (currentrotation == 3)
			{
				if (x_ - 30 >= 0 && b.board[xcord + 1][ycord - 1] == 0 && b.board[xcord][ycord + 1] == 0)
				{
					x_ = x_ - 30;
				}
			}
		}
	}
	void moveright(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{
				if (x_ + 60 < 300 && b.board[xcord][ycord + 2] == 0 && b.board[xcord + 1][ycord + 2] == 0 && b.board[xcord + 2][ycord + 2] == 0)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 2)
			{
				if (x_ + 60 < 300 && b.board[xcord][ycord + 2] == 0 && b.board[xcord + 1][ycord + 1] == 0 && b.board[xcord + 2][ycord + 1] == 0)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 1)
			{
				if (x_ + 90 < 300 && b.board[xcord][ycord + 1] == 0 && b.board[xcord][ycord + 3] == 0)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 3)
			{
				if (x_ + 90 < 300 && b.board[xcord][ycord + 3] == 0 && b.board[xcord + 1][ycord + 3] == 0)
				{
					x_ = x_ + 30;
				}
			}

		}

	}
	void movedown(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0 || currentrotation == 2)
			{
				if (y_ + 90 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 1)
			{
				if (y_ + 60 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 3)
			{
				if (y_ + 60 < 600)

					y_ = y_ + 30;
			}


		}
	}
	void reset(well& b)
	{
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
		rotation = 0;

	}


};
class LShape : public Tetromino {
private:
	int x_;
	int y_;
	int xcord;
	int ycord;
	int currentrotation;
	int rotation = 0;

public:
	LShape()
	{
		rotation = 0;
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
	}
	virtual void drawShape(sf::RenderWindow& window, well& b)
	{

		if (currentrotation == 0)
		{

			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 0));
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 0));
			window.draw(box);
			box.setPosition(x_, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 0));
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);

		}
		if (currentrotation == 2)
		{

			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);

		}
		if (currentrotation == 1)
		{
			if (x_ == 270)
			{
				x_ = 180;

			}
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_ + 60, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);

		}
		if (currentrotation == 3)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_ + 60, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);
			box.setPosition(x_ + 60, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color(255, 165, 55));
			window.draw(box);

		}
	}
	virtual bool isbottomtouch(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;

		if (currentrotation == 0)
		{
			if (y_ + 90 == 600 || b.board[xcord + 3][ycord] != 0 || b.board[xcord + 3][ycord + 1] != 0)
			{
				b.board[xcord][ycord] = 3;
				b.board[xcord + 1][ycord] = 3;
				b.board[xcord + 2][ycord] = 3;
				b.board[xcord + 2][ycord + 1] = 3;
				return true;
			}
			else
				return false;
		}
		if (currentrotation == 2)
		{
			if (y_ + 90 == 600 || b.board[xcord + 1][ycord] != 0 || b.board[xcord + 3][ycord + 1] != 0)
			{
				b.board[xcord][ycord] = 3;
				b.board[xcord][ycord + 1] = 3;
				b.board[xcord + 1][ycord + 1] = 3;
				b.board[xcord + 2][ycord + 1] = 3;

				return true;

			}
			else
				return false;

		}


		if (currentrotation == 1)
		{
			if (y_ + 60 == 600 || b.board[xcord + 2][ycord] != 0 || b.board[xcord + 1][ycord + 1] != 0 || b.board[xcord + 1][ycord + 2] != 0)
			{
				b.board[xcord][ycord] = 3;
				b.board[xcord + 1][ycord] = 3;
				b.board[xcord][ycord + 1] = 3;
				b.board[xcord][ycord + 2] = 3;
				return true;
			}
			else
				return false;
		}
		if (currentrotation == 3)
		{
			if (y_ + 60 == 600 || b.board[xcord + 1][ycord] != 0 || b.board[xcord + 1][ycord + 1] != 0 || b.board[xcord + 2][ycord + 2] != 0)
			{
				b.board[xcord + 1][ycord] = 3;
				b.board[xcord + 1][ycord + 1] = 3;
				b.board[xcord + 1][ycord + 2] = 3;
				b.board[xcord][ycord + 2] = 3;
				return true;
			}
			else
				return false;
		}

	}
	void rotate(well& b)
	{
		if (isbottomtouch(b) == 0)
		{
			rotation++;
			currentrotation = rotation % 4;
		}
		if (currentrotation == 1)
		{
			if (x_ == 240)
			{
				x_ = 210;
			}
		}
		if (currentrotation == 3)
		{
			if (x_ == 240)
			{
				x_ = 210;
			}
		}
	}
	void moveleft(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{

				if (x_ - 30 >= 0 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord - 1] == 0 && b.board[xcord + 2][ycord - 1] == 0)
				{
					x_ = x_ - 30;
				}

			}

			if (currentrotation == 2)
			{

				if (x_ - 30 >= 0 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord] == 0 && b.board[xcord + 2][ycord] == 0)
				{
					x_ = x_ - 30;
				}

			}

			if (currentrotation == 1 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord - 1] == 0)
			{
				if (x_ - 30 >= 0)
				{
					x_ = x_ - 30;
				}
			}

			if (currentrotation == 3 && b.board[xcord][ycord + 1] == 0 && b.board[xcord + 1][ycord - 1] == 0)
			{
				if (x_ - 30 >= 0)
				{
					x_ = x_ - 30;
				}
			}

		}
	}
	void moveright(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0 && b.board[xcord][ycord + 1] == 0 && b.board[xcord + 1][ycord + 1] == 0 && b.board[xcord + 2][ycord + 2] == 0)
			{
				if (x_ + 60 < 300)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 2 && b.board[xcord][ycord + 2] == 0 && b.board[xcord + 1][ycord + 2] == 0 && b.board[xcord + 2][ycord + 2] == 0)
			{
				if (x_ + 60 < 300)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 1 && b.board[xcord][ycord + 3] == 0 && b.board[xcord + 1][ycord + 1] == 0)
			{
				if (x_ + 90 < 300)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 3 && b.board[xcord][ycord + 3] == 0 && b.board[xcord + 1][ycord + 3] == 0)
			{
				if (x_ + 90 < 300)
				{
					x_ = x_ + 30;
				}
			}

		}

	}
	void movedown(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0 || currentrotation == 2)
			{
				if (y_ + 90 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 1 || currentrotation == 3)
			{
				if (y_ + 60 < 600)
				{
					y_ = y_ + 30;
				}
			}

		}
	}
	void reset(well& b)
	{
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
		rotation = 0;

	}

};
class OShape : public Tetromino {
private:
	int x_;
	int y_;
	int xcord;
	int ycord;
	int currentrotation;
	int rotation = 0;

public:
	OShape()
	{
		rotation = 0;
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
	}
	virtual void drawShape(sf::RenderWindow& window, well& b)
	{

		if (currentrotation == 0)
		{

			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Yellow);
			window.draw(box);
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Yellow);
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Yellow);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Yellow);
			window.draw(box);

		}



	}
	virtual bool isbottomtouch(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (currentrotation == 0)
		{
			if (y_ + 60 == 600 || b.board[xcord + 2][ycord] != 0 || b.board[xcord + 2][ycord + 1] != 0)
			{
				b.board[xcord][ycord] = 4;
				b.board[xcord][ycord + 1] = 4;
				b.board[xcord + 1][ycord] = 4;
				b.board[xcord + 1][ycord + 1] = 4;
				return true;
			}
			else
				return false;
		}


	}
	void rotate(well& b)
	{
	}
	void moveleft(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord - 1] == 0)
			{

				if (x_ - 30 >= 0)
				{
					x_ = x_ - 30;
				}

			}



		}
	}
	void moveright(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{
				if (x_ + 60 < 300 && b.board[xcord][ycord + 2] == 0 && b.board[xcord + 1][ycord + 2] == 0)
				{
					x_ = x_ + 30;
				}
			}


		}

	}
	void movedown(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0 || currentrotation == 2)
			{
				if (y_ + 60 < 600)
				{
					y_ = y_ + 30;
				}
			}


		}
	}
	void reset(well& b)
	{
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
		rotation = 0;

	}

};
class SShape : public Tetromino {
private:
	int x_;
	int y_;
	int xcord;
	int ycord;
	int currentrotation;
	int rotation = 0;

public:
	SShape()
	{
		rotation = 0;
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
	}
	virtual void drawShape(sf::RenderWindow& window, well& b)
	{

		if (currentrotation == 0)
		{

			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Green);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Green);
			window.draw(box);
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Green);
			window.draw(box);
			box.setPosition(x_ + 60, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Green);
			window.draw(box);

		}

		if (currentrotation == 1)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Green);
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Green);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Green);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Green);
			window.draw(box);

		}

	}
	virtual bool isbottomtouch(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (currentrotation == 0)
		{
			if (y_ + 60 == 600 || b.board[xcord + 2][ycord] != 0 || b.board[xcord + 2][ycord + 1] != 0 || b.board[xcord + 1][ycord + 2] != 0)
			{
				b.board[xcord + 1][ycord] = 5;

				b.board[xcord][ycord + 1] = 5;


				b.board[xcord + 1][ycord + 1] = 5;
				b.board[xcord][ycord + 2] = 5;

				return true;
			}
			else
				return false;
		}
		if (currentrotation == 1)
		{
			if (y_ + 90 == 600 || b.board[xcord + 2][ycord] != 0 || b.board[xcord + 3][ycord + 1] != 0)
			{
				b.board[xcord][ycord] = 5;

				b.board[xcord + 1][ycord] = 5;


				b.board[xcord + 1][ycord + 1] = 5;
				b.board[xcord + 2][ycord + 1] = 5;

				return true;
			}
			else
				return false;
		}

	}
	void rotate(well& b)
	{
		if (isbottomtouch(b) == 0)
		{
			rotation++;
			currentrotation = rotation % 2;
		}
		if (currentrotation == 0)
		{
			if (x_ == 240)
			{
				x_ = 210;
			}
		}
	}
	void moveleft(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{

				if (x_ - 30 >= 0 && b.board[xcord][ycord] == 0 && b.board[xcord + 1][ycord - 1] == 0)
				{
					x_ = x_ - 30;
				}

			}

			if (currentrotation == 1 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord - 1] == 0 && b.board[xcord + 2][ycord] == 0)
			{
				if (x_ - 30 >= 0)
				{
					x_ = x_ - 30;
				}
			}

		}
	}
	void moveright(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0 && b.board[xcord][ycord + 3] == 0 && b.board[xcord + 1][ycord + 2] == 0)
			{
				if (x_ + 90 < 300)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 1 && b.board[xcord][ycord + 1] == 0 && b.board[xcord + 1][ycord + 2] == 0 && b.board[xcord + 2][ycord + 2] == 0)
			{
				if (x_ + 60 < 300)
				{
					x_ = x_ + 30;
				}
			}

		}

	}
	void movedown(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{
				if (y_ + 60 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 1)
			{
				if (y_ + 90 < 600)
				{
					y_ = y_ + 30;
				}
			}

		}
	}
	void reset(well& b)
	{
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
		rotation = 0;

	}


};
class TShape : public Tetromino {
private:
	int x_;
	int y_;
	int xcord;
	int ycord;
	int currentrotation;
	int rotation = 0;

public:
	TShape()
	{
		rotation = 0;
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
	}
	virtual void drawShape(sf::RenderWindow& window, well& b)
	{

		if (currentrotation == 0)
		{

			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_ + 60, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);

		}

		if (currentrotation == 1)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);

		}
		if (currentrotation == 2)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_ + 60, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);

		}
		if (currentrotation == 3)
		{
			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);
			box.setPosition(x_, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Magenta);
			window.draw(box);

		}

	}
	virtual bool isbottomtouch(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (currentrotation == 0)
		{
			if (y_ + 60 == 600 || b.board[xcord + 1][ycord] != 0 || b.board[xcord + 2][ycord + 1] != 0 || b.board[xcord + 1][ycord + 2] != 0)
			{
				b.board[xcord][ycord] = 6;
				b.board[xcord][ycord + 1] = 6;
				b.board[xcord + 1][ycord + 1] = 6;
				b.board[xcord][ycord + 2] = 6;

				return true;
			}
			else
				return false;
		}
		if (currentrotation == 2)
		{
			if (y_ + 60 == 600 || b.board[xcord + 2][ycord] != 0 || b.board[xcord + 2][ycord + 1] != 0 || b.board[xcord + 2][ycord + 2] != 0)
			{
				b.board[xcord + 1][ycord] = 6;
				b.board[xcord + 1][ycord + 1] = 6;
				b.board[xcord][ycord + 1] = 6;
				b.board[xcord + 1][ycord + 2] = 6;
				return true;
			}
			else
				return false;
		}
		if (currentrotation == 1)
		{
			if (y_ + 90 == 600 || b.board[xcord + 2][ycord] != 0 || b.board[xcord + 3][ycord + 1] != 0)
			{
				b.board[xcord][ycord + 1] = 6;
				b.board[xcord + 1][ycord] = 6;
				b.board[xcord + 1][ycord + 1] = 6;
				b.board[xcord + 2][ycord + 1] = 6;
				return true;
			}
			else
				return false;
		}
		if (currentrotation == 3)
		{
			if (y_ + 90 == 600 || b.board[xcord + 3][ycord] != 0 || b.board[xcord + 2][ycord + 1] != 0)
			{
				b.board[xcord][ycord] = 6;
				b.board[xcord + 1][ycord] = 6;
				b.board[xcord + 2][ycord] = 6;
				b.board[xcord + 1][ycord + 1] = 6;
				return true;
			}
			else
				return false;
		}

	}
	void rotate(well& b)
	{
		if (isbottomtouch(b) == 0)
		{
			rotation++;
			currentrotation = rotation % 4;
		}
		if (currentrotation == 2)
		{
			if (x_ == 240)
			{
				x_ = 210;
			}
		}
		if (currentrotation == 0)
		{
			if (x_ == 240)
			{
				x_ = 210;
			}
		}
	}
	void moveleft(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{

				if (x_ - 30 >= 0 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord] == 0)
				{
					x_ = x_ - 30;
				}

			}
			if (currentrotation == 2)
			{

				if (x_ - 30 >= 0 && b.board[xcord][ycord] == 0 && b.board[xcord + 1][ycord - 1] == 0)
				{
					x_ = x_ - 30;
				}

			}
			if (currentrotation == 1)
			{
				if (x_ - 30 >= 0 && b.board[xcord][ycord] == 0 && b.board[xcord + 1][ycord - 1] == 0 && b.board[xcord + 2][ycord] == 0)
				{
					x_ = x_ - 30;
				}
			}
			if (currentrotation == 3 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord - 1] == 0 && b.board[xcord + 2][ycord - 1] == 0)
			{
				if (x_ - 30 >= 0)
				{
					x_ = x_ - 30;
				}
			}

		}
	}
	void moveright(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{
				if (x_ + 90 < 300 && b.board[xcord][ycord + 3] == 0 && b.board[xcord + 1][ycord + 2] == 0)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 2 && b.board[xcord][ycord + 2] == 0 && b.board[xcord + 1][ycord + 3] == 0)
			{
				if (x_ + 90 < 300)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 1 && b.board[xcord][ycord + 2] == 0 && b.board[xcord + 1][ycord + 2] == 0 && b.board[xcord + 2][ycord + 2] == 0)
			{
				if (x_ + 60 < 300)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 3 && b.board[xcord][ycord + 1] == 0 && b.board[xcord + 1][ycord + 2] == 0 && b.board[xcord + 2][ycord + 1] == 0)
			{
				if (x_ + 60 < 300)
				{
					x_ = x_ + 30;
				}
			}

		}

	}
	void movedown(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{
				if (y_ + 60 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 2)
			{
				if (y_ + 60 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 1)
			{
				if (y_ + 90 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 3)
			{
				if (y_ + 90 < 600)
				{
					y_ = y_ + 30;
				}
			}

		}
	}
	void reset(well& b)
	{
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
		rotation = 0;

	}


};
class ZShape : public Tetromino {
private:
	int x_;
	int y_;
	int xcord;
	int ycord;
	int currentrotation;
	int rotation = 0;

public:
	ZShape()
	{
		rotation = 0;
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
	}
	virtual void drawShape(sf::RenderWindow& window, well& b)
	{

		if (currentrotation == 0)
		{

			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Red);
			window.draw(box);
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Red);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Red);
			window.draw(box);
			box.setPosition(x_ + 60, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Red);
			window.draw(box);

		}

		if (currentrotation == 1)
		{

			sf::RectangleShape box(sf::Vector2f(30.f, 30.f));
			box.setPosition(x_ + 30, y_);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Red);
			window.draw(box);
			box.setPosition(x_, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Red);
			window.draw(box);
			box.setPosition(x_ + 30, y_ + 30);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Red);
			window.draw(box);
			box.setPosition(x_, y_ + 60);
			box.setOutlineThickness(2.f);
			box.setOutlineColor(sf::Color::White);
			box.setFillColor(sf::Color::Red);
			window.draw(box);

		}

	}
	virtual bool isbottomtouch(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (currentrotation == 0)
		{
			if (y_ + 60 == 600 || b.board[xcord + 1][ycord] != 0 || b.board[xcord + 2][ycord + 1] != 0 || b.board[xcord + 2][ycord + 2] != 0)
			{
				b.board[xcord][ycord] = 7;
				b.board[xcord][ycord + 1] = 7;
				b.board[xcord + 1][ycord + 1] = 7;
				b.board[xcord + 1][ycord + 2] = 7;
				return true;
			}
			else
				return false;
		}
		if (currentrotation == 1)
		{
			if (y_ + 90 == 600 || b.board[xcord + 3][ycord] != 0 || b.board[xcord + 2][ycord + 1] != 0)

			{
				b.board[xcord][ycord + 1] = 7;
				b.board[xcord + 1][ycord] = 7;
				b.board[xcord + 1][ycord + 1] = 7;
				b.board[xcord + 2][ycord] = 7;


				return true;
			}
			else
				return false;
		}

	}
	void rotate(well& b)
	{
		if (isbottomtouch(b) == 0)
		{
			rotation++;
			currentrotation = rotation % 2;
		}
		if (currentrotation == 0)
		{
			if (x_ == 240)
			{
				x_ = 210;
			}
		}
	}
	void moveleft(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{

				if (x_ - 30 >= 0 && b.board[xcord][ycord - 1] == 0 && b.board[xcord + 1][ycord] == 0)
				{
					x_ = x_ - 30;
				}

			}

			if (currentrotation == 1 && b.board[xcord][ycord] == 0 && b.board[xcord + 1][ycord - 1] == 0 && b.board[xcord + 2][ycord - 1] == 0)
			{
				if (x_ - 30 >= 0)
				{
					x_ = x_ - 30;
				}
			}

		}
	}
	void moveright(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0 && b.board[xcord][ycord + 2] == 0 && b.board[xcord + 1][ycord + 3] == 0)
			{
				if (x_ + 90 < 300)
				{
					x_ = x_ + 30;
				}
			}
			if (currentrotation == 1 && b.board[xcord][ycord + 2] == 0 && b.board[xcord + 1][ycord + 2] == 0 && b.board[xcord + 3][ycord + 1] == 0)
			{
				if (x_ + 60 < 300)
				{
					x_ = x_ + 30;
				}
			}

		}

	}
	void movedown(well& b)
	{
		xcord = y_ / 30;
		ycord = x_ / 30;
		if (isbottomtouch(b) == 0)
		{
			if (currentrotation == 0)
			{
				if (y_ + 60 < 600)
				{
					y_ = y_ + 30;
				}
			}
			if (currentrotation == 1)
			{
				if (y_ + 90 < 600)
				{
					y_ = y_ + 30;
				}
			}

		}
	}
	void reset(well& b)
	{
		x_ = 120;
		y_ = 0;
		xcord = 0;
		ycord = 0;
		currentrotation = 0;
		rotation = 0;

	}

};

class game {
private:
	well b;
	Tetromino* t[7];

public:
	int scores[5];
	string names[5];
	long score;
	int level=1;
	int lines;
	int gameover=0;
	bool scoresaved = 0;
	string name;
	game() :b()
	{

	}
	void gethighscores() {
		for (int i = 0; i < 5; i++)
		{
			scores[i] = 0;
			names[i] = "";
		}
		ifstream fin;
		fin.open("scores.txt");
		int x = 0;
		while (x<5 && fin >> names[x] && fin >> scores[x]) {
			x++;
		}

	}
	void savehighscores() {
		if (!scoresaved) {
			scoresaved = 1;

			if (scores[4] < score) {
				scores[4] = score;
				names[4] = name;
			}
			int largest = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = i+1; j < 5; j++)
					if (scores[j] > scores[largest]) {
						largest = j;
					}
				swap(scores[i], scores[largest]);
				swap(names[i], names[largest]);
			}

			ofstream fout;
			fout.open("scores.txt");
			for (int i = 0; i < 5; i++) {
				fout << names[i] << endl;
				fout << scores[i] << endl;
			}
			fout.close();
		}
	}
	void play(sf::RenderWindow&window)
	{
		double n = 1;
		srand(time(NULL));
		sf::Clock clock;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		sf::Time timePerFrame = sf::seconds(n);
		
	
		
		t[0] = new IShape;
		t[1] = new JShape;
		t[2] = new LShape;
		t[3] = new OShape;
		t[4] = new SShape;
		t[5] = new TShape;
		t[6] = new ZShape;
		int num = rand() % 7;
		gethighscores();
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Up) {
						t[num]->rotate(b);
					}
					if (event.key.code == sf::Keyboard::Left) {
						t[num]->moveleft(b);
					}
					if (event.key.code == sf::Keyboard::Right) {
						t[num]->moveright(b);
					}
					if (event.key.code == sf::Keyboard::Down) {
						t[num]->movedown(b);
					}
					if (event.key.code == sf::Keyboard::Escape)
					{
						window.close();
					}
				}

			}
			timeSinceLastUpdate += clock.restart();
			if (timeSinceLastUpdate >= timePerFrame)
			{
				timeSinceLastUpdate -= timePerFrame;
				t[num]->movedown(b);
			}
			if (t[num]->isbottomtouch(b) == 1)
			{

				
				 gameover = Gameover();
				 
			
			
				
				
				destroy();
				leveldecider();
				
				
				
				
					t[num]->reset(b);
				


				num = rand()%7;

			}
			window.clear();
			b.drawboard(window, b, score, level,lines,gameover,name,names,scores);
			// Draw the board
			if(gameover==0)
			{ 
			t[num]->drawShape(window, b);
			}
			else {
				savehighscores();
			}
			window.display();
		}

	}
	void destroy()
	{
		int n = 0;
		bool check = 1;

		for (int i = 0; i < 20; i++)
		{
			check = 1;
			for (int j = 0; j < 10 && check == 1; j++)
			{
				if (b.board[i][j] != 0)
				{
					check = 1;
				}
				else
					check = 0;
			}
			if (check == 1)
			{
				score = score + 100;
				lines = lines + 1;
				n = i;

				for (int k = n; k >= 1; k--)
				{
					for (int l = 0; l < 10; l++) {
						b.board[k][l] = b.board[k - 1][l];
					}




				}
				for (int l = 0; l < 10; l++) {
					b.board[0][l] = 0;
				}
			}
		}
	}
	bool Gameover()
	{

		for (int i = 0; i < 10; i++)
		{
			if (b.board[0][i])
			{
				return true;
			}
		}
		return false;

	}
	void leveldecider()
	{
		if (lines >= 10 && lines < 20)
		{
			level = 2;
		}
		if (lines >= 20 && lines < 30)
		{
			level = 3;
		}
		if (lines >= 30 && lines < 40)
		{
			level = 4;
		}	
		if (lines >= 40 && lines < 50)
		{
			level = 5;
		}	
		if (lines >= 50 && lines < 60)
		{
			level = 6;
		}
		if (lines >= 60 && lines < 70)
		{
			level = 7;
		}
		if (lines >= 70 && lines < 80)
		{
			level = 8;
		}
		
		if (lines >= 80)
		{
			level = 1;
		}
	}
	void username()
	{
		
		srand(time(NULL));
		sf::Clock clock;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		sf::Time timePerFrame = sf::seconds(1.f);
		sf::RenderWindow window(sf::VideoMode(1280, 720), "Tetris");


		sf::Font font;                                    //Font
		font.loadFromFile("fonts/arial.ttf");

		sf::Texture background;
		background.loadFromFile("pics/username.png");
		sf::Sprite b;
		b.setTexture(background);
		b.setPosition(0, 0);
	
		int x = 700, y = 580;                         //The user's input
		sf::Text playerText(name, font, 50);
		playerText.setPosition(x, y);

		string n = "Please Enter Your Name";         //The Enter your name text
		sf::Text text(n, font, 50);
		text.setPosition(325, 500);

		sf::Vector2f s(980, 720);
		sf::RectangleShape box(s);
		box.setPosition(275, 480);
		box.setOutlineColor(Color::Black);
		box.setFillColor(Color::Black);

		sf::Vector2f size(800, 80);
		sf::RectangleShape box1(size);                  //The Name Box
		box1.setPosition(325, 575);
		box1.setOutlineThickness(5);
		box1.setOutlineColor(Color::Red);
		box1.setFillColor(Color::Transparent);




		while (window.isOpen())
		{
			sf::Event event;
			window.pollEvent(event);
			while (event.key.code != Keyboard::Enter)
			{
				while (window.pollEvent(event))
				{
					if (event.key.code == Keyboard::Escape)
						window.close();
					if (event.key.code == sf::Keyboard::Enter)
					{
						window.close();
					}
					if (event.key.code == sf::Keyboard::Escape)
					{
						window.close();
					}
					if (event.key.code == Keyboard::Enter || event.key.code == Keyboard::BackSpace)  //To remove the last charachter if user presses backspace
					{
						if (event.key.code == Keyboard::BackSpace && name != "")
						{
							name.pop_back();
							x = x + 20;
						}
					}
					if (event.type == sf::Event::TextEntered)
					{
						name += event.text.unicode;
						playerText.setString(name);
						x = x - 20;
						playerText.setPosition(x, y);
					}

					window.clear(Color::Black);
					window.draw(b);
					window.draw(box);
					window.draw(box1);
					window.draw(text);
					window.draw(playerText);
					window.display();
				}
			}
			clock.restart();

			window.clear();

			// Draw the board

			window.draw(text);  // Draw the text object

			window.display();
		}
	}


};
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tetris");
	game G;
	G.username();
	G.play(window);
	system("pause");
	return 0;
}
