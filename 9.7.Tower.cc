//9.7.Tower.cc

#include"header.h"


vector<pair<int,int>>input = {{65, 100},{70, 150} ,{56, 90},{75, 190} ,{60, 95} ,{68, 110}};

int main(){

	sort(input.begin(), input.end(),
		[](pair<int, int>a, pair<int, int>b)
		{return a.first < b.first;}
		);

	sort(input.begin(), input.end(),
		[](pair<int, int>a, pair<int, int>b)
		{return a.second < b.second;}
		);

	vector<pair<int,int>>max_seq;

	for(auto i)


	return 0;
}