#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include "../helperFunctions.h"

using namespace std;

#define inputFileName "checksumInput.txt"

void calculateSums(vector<int> v, int *difSum, int *divSum);

int main(){
	/* Small input so doesn't matter if reading the input takes 2n time */
	string input = readEntireFile(inputFileName);

	int inputIndex = 0;
	int subStrLen;
	int difSum = 0, divSum = 0;
	vector<int> row;
	for(size_t i = 0; i < input.length(); i++){
		/* Every number is spaced with tab, so add that into the vector */
		if(input[i] == '\t'){

			subStrLen = i - inputIndex;
			try{
				row.push_back(stringToInt(input.substr(inputIndex, subStrLen)));
			}
			catch(const invalid_argument& e){
				cout << e.what() << endl;
				return 1;
			}

			inputIndex = i + 1;
		}

		/* eol means last int, so add that to the vector than add to the sums */
		else if(input[i] == '\n'){

			subStrLen = i - inputIndex;
			try{
				row.push_back(stringToInt(input.substr(inputIndex, subStrLen)));
			}
			catch(const invalid_argument& e){
				cout << e.what();
				return 1;
			}

			calculateSums(row, &difSum, &divSum);

			row.clear();

			inputIndex = i + 1;
		}
	}

	cout << "The sum of the differences is: " << difSum << endl;
	cout << "The sum of the even divisions is " << divSum << endl;

	return 0;
}

void calculateSums(vector<int> v, int *difSum, int *divSum){
	int max = INT_MIN, min = INT_MAX, n, m;
	bool evenDivFound = false;

	for(size_t i = 0; i < v.size(); i++){
		n = v[i];
		if(n < min)
			min = n;
		if(n > max)
			max = n;

		for(size_t j = i + 1; j < v.size() && !evenDivFound; j++){
			m = v[j];
			if(n > m){
				if(n % m == 0){
					*divSum += n / m;
					evenDivFound = true;
				}
			}
			else{
				if(m % n == 0){
					*divSum += m / n;
					evenDivFound = true;
				}
			}
		}
	}

	*difSum += max - min;
}
