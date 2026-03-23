#include <iostream>
#include <vector>
#include <string>
#include "game.h"

namespace game {

bool game_won()
{
	std::cout << "You won! Play again? Enter yes/no" << "\n";
	std::string continue_playing {""};

	while (continue_playing != "yes" && continue_playing != "no")
	{
		std::cin >> continue_playing;
	}
	if (continue_playing == "yes")
		return true;
	else
		return false;
}

std::string guess_input()
{
        std::string guess {""};
        while (guess.size() != WORD_LENGTH)
                std::cin >> guess;

        return guess;
}

std::string check_guess(std::string& guess, std::string& new_answer)
{
        std::string guess_output(OUTPUT_LENGTH, ' ');
        std::vector<int> freq = init_freq(new_answer);

        for (int i = 0; i < WORD_LENGTH; i++)
        {
                if (guess[i] == new_answer[i])
                {
                        freq[guess[i] - 'a']--;
                        guess_output[i * OUTPUT_MULT] = guess[i];
                        guess_output[i * OUTPUT_MULT + 1] = '*';
                }
        }

        for (int i = 0; i < WORD_LENGTH; i++)
        {
                if (guess_output[i * 3 + 1] == '*')
                {
                        continue;
                }
                else
                {
                        guess_output[i * 3] = guess[i];
                        if (freq[guess[i] - 'a'] > 0)
                        {
                                guess_output[i * 3 + 1] = '+';
                        }
                        else
                        {
                                guess_output[i * 3 + 1] = '-';
                        }
                }
        }
        return guess_output;
}

void print_guess(std::string& guess_output)
{
        std::cout << guess_output << std::endl;
}

void start_game()
{
        std::cout << "* Correct letter and correct location." << std::endl;
        std::cout << "+ Correct letter and incorrect location." << std::endl;
        std::cout << "- Incorrect letter and incorrect location." << std::endl;
        std::cout << "Enter a five letter word." << std::endl;
}

std::vector<int> init_freq(std::string& new_answer)
{
	std::vector<int> freq(26, 0);
        for (char c : new_answer)
        {
                freq[c - 'a']++;
        }
        return freq;
}

}

