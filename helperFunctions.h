#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <array>

int charToInt(char c);
int stringToInt(std::string str);
std::string readEntireFile(const char* filename);
bool isEven(int n);
int abs(int n);

class CharCount{
	int getArrLength() const;
public:
	CharCount(std::string word);
	std::array<int, 256> chars = {};
	bool operator==(const CharCount &other) const;
	bool operator!=(const CharCount &other) const;
};
