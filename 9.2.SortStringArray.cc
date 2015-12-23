//9.2.SortStringArray.cc
/*

     Write a method to sort an array of strings so that all the anagrams are next to each other.
*/


#include"header.h"

int main(){

	vector<string> input={"abc","fac","fca","abf","acb","bca"};
	sort(input.begin(),input.end(),
		[](const string a, const string b)
		{	
			string aa = a, bb =b;
			sort(aa.begin(), aa.end());
			sort(bb.begin(), bb.end());
			return aa<bb;
		}
		);
	cout << "after sorted \n";
	for(auto s:input){
		cout << s <<endl;
	}

	return 0;
}