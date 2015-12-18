//ReplaceSpace.cc
//Write a method to replace all spaces in a string with ‘%20’.

#include"header.h"

int main(int argc, char *argv[]){
	string str = argv[1];
	string str2;
	for(auto iter = str.begin(); iter !=str.end(); iter++){
		if(*iter ==  ' '){
			str2 += "%20";
		}else{
			str2 += *iter;
		}
	}
	cout << str << "\n" << str2 << endl;

}