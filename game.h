#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

namespace game {

inline constexpr int NUM_GUESSES = 6;
inline constexpr int WORD_LENGTH = 5;
inline constexpr int OUTPUT_LENGTH = 14;
inline constexpr int OUTPUT_MULT = 3;

std::vector<int> init_freq(std::string&);
std::string guess_input();
std::string check_guess(std::string&, std::string&);
bool game_won();
void print_guess(std::string&);
void start_game();

}

#endif // GAME_H
