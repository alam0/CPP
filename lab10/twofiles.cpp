//twofiles.cpp takes in two files, counts the amount of unique words in each, and displays the result
//uses any two word files

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cctype>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void toLowerCase(string &str) {
	const int length = str.length();
	for (int i=0; i < length; ++i){
		str[i] = tolower(str[i]);
	}
} 

int main() {
	char file1[30];
	char file2[30];
	//Ask user for names of two plain text files
	cout << "Enter the name of the first plain text file: " << endl;
	cin >> file1;
	cout << "Enter the name of the second plain text file: " << endl;
	cin >> file2;
	
	//create map
	map<string, int> Map1; //map where key, value is string, int
	map<string, int> Map2;
	
	ifstream infile1(file1);
	ifstream infile2(file2);
	//read input, keeping track of each word and how often it appears
	string s, t;
	while(infile1 >> s){
		toLowerCase(s);
		Map1[s]++;
	}
	
	while(infile2 >> t){
		toLowerCase(t);
		Map2[t]++;
	}
	
	//cout Map1
	map<string, int>::const_iterator it;
	cout << "Map of unique words for 1st text file:" << endl;
	for (it = Map1.begin(); it != Map1.end(); it++) {
		cout << it->first << "\t" << it->second << endl;
	}	
	//cout Map2
	cout << "Map of unique words for 2nd text file:" << endl;
	for (it = Map2.begin(); it != Map2.end(); it++) {
		cout << it->first << "\t" << it->second << endl;
	}
	
	//cout << Map1.size() << endl;
	
	//closing file
	infile1.close();
	infile2.close();
	
	return 0;
}
