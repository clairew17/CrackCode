#include"header.h"


bool IsPalindrome(string str, int begin, int end){
	int i = begin, j = end;
	while(i<=j){
		if(str[i] != str[j])return false;
		i++;j--;
	}
	return true;
}

string longestPalindrome(string str){

	//string str = argv[1];
	//vector<string>res;
	string longest;

	int i=0, j = str.size()-1;


	
	for(i=str.size();i>0;i--){

		//if(str.size()-i < longest.size())return longest;
		
		for(j = 0; j<= str.size()-i;j++){

			//if(str[i] != str[j])continue;

			//if(j-i+1 < longest.size())break;

			if(IsPalindrome(str,j,i+j-1)){
				return str.substr(j,i);
			}
		}
	}

	return longest;
}

int main(){

	vector<string>testSet = {"a", "aba", "cad","aaa","aabacabddb"};
	cout << "Input\tOutput\n";
	for(auto str:testSet){
		cout << str << '\t' << longestPalindrome(str) <<endl;
	}
	return 0;

}