#define _CRT_RAND_S

#include <locale.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

char mostFrequentCharacter(char* str, int size)
{
	if (size == 0)
	{
		std::cout << "No Character";
		return 0;
	}

	std::unordered_map<char, int> characters;
	characters.reserve(256);

	for (int i = 0; i < size; ++i)
		++characters[str[i]];

	int centerPos = size / 2;

	int count = -1;
	char resChar = 0;

	const auto result = std::min_element(characters.cbegin(), characters.cend(), [](const std::pair<char, int>& elem1, const std::pair<char, int>& elem2) -> bool{
		return elem1.second < elem2.second;
	});

	return result->first;
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");

	unsigned int number = 1;

	int size = 50;
	char* std = new char[size];

	for (int i = 0; i < size; ++i)
	{
		rand_s(&number);
		std[i] = (unsigned int)(((double)number / (double)UINT_MAX) * 256.0) + CHAR_MIN;
	}

	std::copy(&std[0], &std[size - 1], std::ostreambuf_iterator<char>(std::cout));
	std::cout << std::endl;

	char character = mostFrequentCharacter(std, size);

	std::cout << "most frequent character is " << character;

	delete[] std;
	return 0;
}
