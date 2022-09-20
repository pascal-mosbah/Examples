#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cstring>

int main()
{
	std::ifstream my_file("TP2_3.cpp");
	std::map<char, int> my_count;
	constexpr int size = (1 << (sizeof(char) * 8)) - 1;
	std::cout << size << std::endl;
	if (my_file.is_open()) {
		int my_caracters[size] = {0};
		for (int c = 0; c < size;++c){
			std::cout << c << " "<< my_caracters[c]<<std::endl;
		}
		std::string line;
		int number_of_characters = 0, number_of_words = 0, number_of_lines = 0;
		while (std::getline(my_file, line)) {
			++number_of_lines;
			std::string word;
			std::stringstream ss(line);
			while (ss >> word) {
				++number_of_words;
				number_of_characters += word.size();
				for (auto icar : word) {
					++my_count[std::tolower(icar)];
					++my_caracters[std::tolower(icar)];
				}
				std::cout << word << std::endl;
			}
		}
		std::cout << "number of lines " << number_of_lines << std::endl;
		std::cout << "number of words " << number_of_words << std::endl;
		std::cout << "number of characters " << number_of_characters << std::endl;
		for (auto inum : my_count) {
			std::cout << inum.first << " " << inum.second << std::endl;
		}
		for (int c = 0; c < size;++c){
			if (my_caracters[c]) {
				std::cout << c << " "<< my_caracters[c]<<std::endl;
			}
		}
	}
}
