//8.5.Parenthes.cc

//Implement an algorithm to print all valid (e.g., properly opened and closed combi- nations of n-pairs of parentheses.
#include"header.h"

void parent(
	vector<string> &res, 
	string &sol, 
	int left, 
	int right, 
	int n)
{
	if(right ==n && left==n){
		res.push_back(sol);
		return;
	}
	if(right>left)return;
	if(left < n)
	{
		sol.push_back('(');
		parent(res, sol, left+1,right, n);
		sol.pop_back();
	}
	if(right < n)
	{
		sol.push_back(')');
		parent(res, sol, left,right+1, n);
		sol.pop_back();
	}

}

int main(){
	int n=3;
	vector<string>res;
	string sol;
	parent(res,sol,0,0,n);
	for(auto v : res){
		cout << v << endl;
	}

}

