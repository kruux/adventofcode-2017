#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../helperFunctions.h"

using namespace std;

#define inputFileName "passphraseInput.txt"

int searchForAnagram(vector<CharCount> v, CharCount c);

int main(){
	ifstream inputFile(inputFileName);

	string phrase, word;
	size_t nextSpace, nextIndex;
	unordered_map<string,string> words;
	unordered_map<string,string>::iterator it;
	vector<CharCount> anagrams;
	bool wordsValid, anagramsValid;
	int validWordPhrases = 0;
	int validAnagramPhrases = 0;
	while(getline(inputFile, phrase)){

		wordsValid = anagramsValid = true;
		nextIndex = 0;
		/* Continue until eol, or until it is known that there are anagrams */
		while((nextSpace = phrase.find(' ', nextIndex)) != string::npos && anagramsValid){
			word = phrase.substr(nextIndex, nextSpace-nextIndex);

			/* Make sure the word isn't already present in the table */
			it = words.find(word);
			if(it == words.end() && wordsValid)
				/* Add word to hashmap */
				words.emplace(word, word);

			else
				wordsValid = false;

			/* Look for anagrams */
			CharCount anagram(word);
			if(searchForAnagram(anagrams, anagram) == -1)
				/* Add this CharCount to the list so the next words will compare with this aswell */
				anagrams.push_back(anagram);
			else
				anagramsValid = false;

			nextIndex = nextSpace + 1;
		}
		/* Check last word. */
		word = phrase.substr(nextIndex);
		if(wordsValid){
			it = words.find(word);
			if(it == words.end())
				validWordPhrases++;
		}
		words.clear();

		/* Last anagram check */
		if(anagramsValid){
			CharCount anagram(word);
			if(searchForAnagram(anagrams, anagram) == -1)
				validAnagramPhrases++;
		}
		anagrams.clear();

	}

	cout << "Valid word phrases: " << validWordPhrases << endl;
	cout << "Valid anagram phrases: " << validAnagramPhrases << endl;

	return 0;
}

int searchForAnagram(vector<CharCount> v, CharCount c){
	for(size_t i = 0; i < v.size(); i++){
		if(v[i] == c)
			return i;
	}

	/* No match found. */
	return -1;
}
