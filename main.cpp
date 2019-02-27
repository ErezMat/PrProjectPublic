#include <SFML/Graphics.hpp>
#include <cmath>
#include "Game.h"

int main()
{
	
	gamePR::Game game(1200, 900, "TYTUL");
	game.run();
	return 0;
}