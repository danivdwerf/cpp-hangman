#include "logic.h"
#include <algorithm>

std::string currWord;
std::vector<size_t> guessed;
int chances;

char drawing[6][6] =
{
	{ ' ',' ',' ',' ',' ',' '},
	{ ' ',' ',' ',' ',' ',' '},
	{ ' ',' ',' ',' ',' ',' '},
	{ ' ',' ',' ',' ',' ',' '},
	{ ' ',' ',' ',' ',' ',' '},
	{ ' ',' ',' ',' ',' ',' '}
};

Logic::Logic()
{
	chances = 10;

	std::vector<std::string> words;
	words.push_back("poes");
	words.push_back("tjoep");
	words.push_back("pats");
	words.push_back("cunt");

	srand (time(NULL));
	currWord = words[rand() % words.size()];
}

void Logic::play()
{
	drawGame();
	while(chances > 0)
	{
		char guess;
		std::cout<<"fill in a character: ";
		std::cin>>guess;

		std::size_t found = currWord.find(guess);
		if(found > currWord.length())
		{
			wrongGuess();
			continue;
		}

		std::cout<< guess << " was correct!" << "\n";
		if(std::find(guessed.begin(), guessed.end(), guess) == guessed.end())
		{
			guessed.push_back(found);
		}

		drawGame();
		if(guessed.size()==currWord.size())
		{
			std::cout<< "The word was: " << currWord<< ". You guessed it!"<<"\n";
			chances = 0;
		}
	}
}

void Logic::drawGame()
{

	for(int i = 0; i<6; i++)
	{
		for(int j = 0; j<6; j++)
		{
			std::cout<<drawing[i][j];
		}
		std::cout<<'\n';
	}
	for(int i = 0; i < currWord.length(); i++)
	{
		if(std::find(guessed.begin(), guessed.end(), i) != guessed.end())
		{
			std::cout<<currWord[i];
			continue;
		}
		std::cout<< "_";
	}
	std::cout<<"\n";
}

void Logic::wrongGuess()
{
	chances--;
	switch (chances)
	{
		case 9:
			for(int i = 1; i<6; i++)
			{
				drawing[i][0] = '|';
			}
		break;
		case 8:
			for(int i = 0; i<6; i++)
			{
				drawing[0][i] = '-';
			}
		break;
		case 7:
			for(int i = 0; i < 2; i++)
			{
				drawing[i][4] =  '|';
			}
		break;
		case 6:
			drawing[2][4] = 'o';
		break;
		case 5:
			drawing[3][4] = '|';
		break;
		case 4:
			drawing[3][5] = '\\';
		break;
		case 3:
			drawing[3][3] = '/';
		break;
		case 2:
			drawing[4][5] = '\\';
		break;
		case 1:
			drawing[4][3] = '/';
		break;
	}
	drawGame();
}
