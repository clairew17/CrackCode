//5.3.NextSameOne.cc
/*

Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation.

*/
#include"header.h"

int main(){

	string str = "1010";
	string NextSmall = str, NextLarge=str;
	int i=0, j =0;

	cout << "The next smallest:\n";
	j = str.find_last_of('1');
	if(j != string::npos){
		i = str.substr(0,j).find_last_of('0');
	}
	cout << i << '\t' << j << endl;
	NextSmall[i] = '1';
	NextSmall[j] = '0';
	cout << str << '\n' << NextSmall <<endl;

	cout << "The next largest:\n";
	i = str.find_last_of('0');

	if(i != string::npos){
		j = str.substr(0,i).find_last_of('1');
	}
	cout << i << '\t' << j << endl;
	NextLarge[i] = '1';
	NextLarge[j] = '0';
	cout << str << '\n' << NextLarge <<endl;

	return 0;
}
