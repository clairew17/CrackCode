//ReplaceSpace.cc
//Write a method to replace all spaces in a string with ‘%20’.

#include"header.h"

int main(){
	string str = "a b c c e";
	string str2;
	int n = str.size();
	for(auto iter = str.begin(); iter !=str.end(); iter++){
		if(*iter == " "){
			str2 += '%20'
		}else{
			str2 += *iter;
		}
	}
	cout << str << "\n" << str2 << endl;

}