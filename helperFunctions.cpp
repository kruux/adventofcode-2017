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
