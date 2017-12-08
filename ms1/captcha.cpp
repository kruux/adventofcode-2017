#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

#define inputFileName "captchaInput.txt"

int charToInt(char c);

int main(){
	/* Read input from file */
	string input;
	ifstream inputFile(inputFileName);
	input.assign(istreambuf_iterator<char>(inputFile), istreambuf_iterator<char>());
	size_t inputLen = input.length();

	/* Trim trailing whitespace if there is one */
	if(isspace(input[inputLen-1])){
		input.erase(inputLen-1);
		inputLen--;
	}

	/* Calculate the sums for the captchas */
	int sum1 = 0, sum2 = 0;
	int curDigit, cp1Digit, cp2Digit;
	for(int i = 0; i < inputLen; i++){
		try{
			/* modulo makes the array circular */
			curDigit = charToInt(input[i]);
			cp1Digit = charToInt(input[(i + 1) % inputLen]);
			cp2Digit = charToInt(input[(i + inputLen/2) % inputLen]);
		}
		catch(const invalid_argument& e){
			cout << e.what() << endl;
			return 1;
		}

		if(curDigit == cp1Digit)
			sum1 += curDigit;

		if(curDigit == cp2Digit)
			sum2 += curDigit;
	}

	cout << "The sum of the first captcha is: " << sum1 << endl;
	cout << "The sum of the second captcha is: " << sum2 << endl;

	return 0;
}

int charToInt(char c){
	int i = (int)c - 48;
	if(i < 0 || i > 9){
		string msg = "Expected a character, 0-9, '";
		msg.append(&c);
		msg.append("' was recieved");
		throw invalid_argument(msg);
	}
	return i;
}
