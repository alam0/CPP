//preprocessor.cpp is a simple program that guesses which language the text file is written in 
//I used English and Chinese as the two dictionaries (english.txt and chinese.txt)

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void toLowerCase(string &str) {
	const int length = str.length();
	for (int i=0; i < length; ++i){
		str[i] = tolower(str[i]);
	}
} 


int main() {
	char dict1[30];
	char dict2[30];
	char file[30];
	cout << "Enter the name of the 1st dictionary: " << endl;
	cin >> dict1;
	cout << "Enter the name of the 2nd dictionary: " << endl;
	cin >> dict2;
	cout << "Enter the name of the file to be used: " << endl;
	cin >> file;
	
	set<string> Dict1; //English
	set<string> Dict2; //Chinese
	map<string, int> fileWords;
	
	ifstream indict1(dict1);
	ifstream indict2(dict2);
	ifstream infile(file);
	
	string s, t, u;
	while(indict1 >> s){
		toLowerCase(s);
		Dict1.insert(s);
	}
	
	while(indict2 >> t){
		toLowerCase(t);
		Dict2.insert(t);
	}
	
	while(infile >> u){
		toLowerCase(u);
		fileWords[u]++;
	}
	
	map<string, int>::const_iterator it;
	int englishWords = 0;
	int chineseWords = 0;
	for(it = fileWords.begin(); it != fileWords.end(); it++) {
		if(Dict1.find(it->first) != Dict1.end())
			englishWords++;
		else if(Dict2.find(it->first) != Dict2.end())
			chineseWords++;
	}	
	if(englishWords > chineseWords)
		cout << "The given text file is in English." << endl;
	else 
		cout << "The given text file is in Chinese." << endl;
	
	
	
	indict1.close();
	indict2.close();
	infile.close();
	
	return 0;	
}
	
	
	
