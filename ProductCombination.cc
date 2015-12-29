//ProductCombination.cc
/*
print all possible product combination of a number
*/

#include"../CC/header.h"


vector<pair<int, int>>ProductCombination(int n){
	vector<pair<int, int>>res;
	int m = sqrt(n);
	pair<int, int>temp;
	for(int i=1;i<=m;i++){
		int a = n/i;
		if(a*i == n){
			temp.first = i;
			temp.second = a;
			res.push_back(temp);
		}
	}
	return res;
}

int main(int argc, char *argv[]){

	int n = stoi(argv[1]);

	vector<pair<int, int>>res = ProductCombination(n);
	for(auto r:res){
		cout << r.first <<','<<r.second <<endl;
	}
	return 0;

}