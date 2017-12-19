#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../helperFunctions.h"

using namespace std;

#define inputFileName "jmpInput.txt"

int main(){
	/* Read the contents from file and store it in a vector */
	ifstream input(inputFileName);

	string jmpOffset;
	/* Create one vector for problem a and another one for problem b */
	vector<int> jmpInstructions1;
	vector<int> jmpInstructions2;
	int n;
	while(getline(input, jmpOffset)){
		/* Both vectors start with the same value */
		n = stringToInt(jmpOffset);
		jmpInstructions1.push_back(n);
		jmpInstructions2.push_back(n);
	}

	input.close();

	int vctLen = jmpInstructions1.size();
	int steps1 = 0, steps2 = 0, index1 = 0, index2 = 0;

	bool incomplete1 = true, incomplete2 = true;
	while(incomplete1 || incomplete2){
		/* Problem a */
		if(incomplete1){
			index1 += jmpInstructions1[index1]++;
			incomplete1 = index1 >= 0 && index1 < vctLen;
			steps1++;
		}
		/* Problem b */
		if(incomplete2){
			if(jmpInstructions2[index2] >= 3)
				index2 += jmpInstructions2[index2]--;
			else
				index2 += jmpInstructions2[index2]++;

			incomplete2 = index2 >= 0 && index2 < vctLen;
			steps2++;
		}
	}


	cout << "First problem, Steps taken: " << steps1 << endl;
	cout << "Index ended up at: " << index1 << ", and the total number of instructions are: " << vctLen << endl;

	cout << endl << "Second problem, Steps taken: " << steps2 << endl;
	cout << "Index ended up at: " << index2 << ", and the total number of instructions still are: " << vctLen << endl;

	return EXIT_SUCCESS;
}
