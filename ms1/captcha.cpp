#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;
#include "../helperFunctions.h"

#define inputFileName "captchaInput.txt"

int main(){
	/* Read input from file */
	string input = readEntireFile(inputFileName);
	int inputLen = input.length();

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
