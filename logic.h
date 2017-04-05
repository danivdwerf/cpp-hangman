#ifndef logic_H
#define logic_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
class Logic
{
	public:
	 	Logic();
		void play();
		std::vector<size_t> guessed;

	private:
		std::string currWord;
		int chances;
		void drawGame();
		void wrongGuess();
};
#endif
