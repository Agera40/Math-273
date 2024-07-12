#include "spellcheck.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "load_dictionary.h"

int main()
{
	auto words = load_dictionary("dictionary.txt");
	char response = 'y';

	do {
		std::cout << "Enter a word to check. ";
		std::string word;
		std::cin >> word;
		std::cout << "How many suggestions would you like? ";
		int n;
		std::cin >> n;
		std::cout << "Here are your spelling suggestions.\n";	

		auto corrections = suggested_corrections(word, words, n);
		for (auto w : corrections) {
			std::cout << w << " ";
		}
		std::cout << " " << std::endl;
		std::cout << "Try again? (y/n) ";
		std::cin >> response;
	} while (response == 'y' or response == 'Y');

}
