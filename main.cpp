#include <iostream>
#include <vector>
#include "game.h"
#include "words.h"

int main()
{
	std::string guess {};
	std::string guess_output {};
	std::string new_answer = words::rand_word();
	game::start_game();
	int guess_num {0};
	bool continue_playing {true};

//	std::cout << new_answer << "\n";

	while (guess_num < game::NUM_GUESSES && continue_playing) // Take input check guess for NUM_GUESSES
	{
		guess = game::guess_input();
		guess_output = game::check_guess(guess, new_answer);
		game::print_guess(guess_output);
		++guess_num;
		if (guess == new_answer)
		{
			continue_playing = game::game_won();
			if (continue_playing)
			{
				guess_num = 0;
				new_answer = words::rand_word();
//				std::cout << new_answer << "\n";
			}
		}
	}

	return 0;
}
