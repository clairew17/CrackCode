// ReadFileEnd.cc

/*

	read file from the end

*/

#include"header.h"

int main(){

	string name = "Card.h";
	string line;

	ifstream in(name);
	if(in.is_open()){
	
		stack<string>buffer;
		
		if(in.is_open()){
			while(getline(in, line)){
				buffer.push(line);
			}
		}
		while(!buffer.empty()){
			string str = buffer.top();
			buffer.pop();
			cout << str<< endl;
		}
	}
	return 0;
}