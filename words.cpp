#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include "words.h"

namespace words {

std::string rand_word()
{
	std::vector<std::string> word_list {};
	std::ifstream file("words.txt");
	std::string line {};
	while (getline(file, line)) word_list.push_back(line);

	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, word_list.size() - 1);
	return word_list[dist(gen)];
}

}
