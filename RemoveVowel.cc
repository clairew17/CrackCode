//RemoveVowel.cc
//remove all vowel of a string

set<char>vowel={'a','e','i','o','u','A','E','I','O','U'};

#include"../CC/header.h"

int main(){
	string str = "abcde asdf wer";
	string res;
	for(int i=0;i<str.size();i++){
		if(vowel.find(str[i]) == vowel.end())res += str[i];
	}
	cout << str << endl;
	cout << res << endl;
	return 0;


}