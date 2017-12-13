#include "helperFunctions.h"

int charToInt(char c){
	int i = (int)c - 48;
	if(i < 0 || i > 9){
		std::string msg = "Expected a character, 0-9, '";
		msg.append(&c);
		msg.append("' was recieved");
		throw std::invalid_argument(msg);
	}
	return i;
}

int stringToInt(std::string str){
	int total = 0;
	for(size_t i = 0; i < str.length(); i++){
		total *= 10;
		try{
			total += charToInt(str[i]);
		}
		catch(const std::invalid_argument& e){
			throw;
		}
	}

	return total;
}

std::string readEntireFile(const char* filename){
	std::string content;
	std::ifstream file(filename);
	content.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

	return content;
}

bool isEven(int n){
	return n % 2 == 0;
}

int abs(int n){
	return n < 0 ? n *-1 : n;
}


CharCount::CharCount(std::string word){
	for(size_t i = 0; i < word.length(); i++){
		chars[(int) word[i]]++;
	}
}
int CharCount::getArrLength() const{
	return sizeof(chars) / sizeof(chars[0]);
}

bool CharCount::operator==(const CharCount &other) const {
	bool eq = true;
	for(int i = 0; i < getArrLength(); i++){
		if(chars[i] != other.chars[i]){
			eq = false;
			break;
		}
	}

	return eq;
}

bool CharCount::operator!=(const CharCount &other) const{
	return !(*this == other);
}
