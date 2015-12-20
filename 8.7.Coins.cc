//8.7.Coins.cc
#include"header.h"

int value[4] = {25, 10, 5, 1};

void helper(vector<vector<int>> &res, vector<int> &sol, int sum, int coin_type){
	if(coin_type >= 4)return;

	//PrintVector(sol);
	int max_num = sum/value[coin_type];
	//cout << sum << '\t' << max_num << '\t' << coin_type << endl;
	for(int i=0;i <= max_num; i++){
		//traverse of all possible # of current coin_type
		sol[coin_type] = i;

		int temp = sum - i*value[coin_type];
		if(temp == 0){
			res.push_back(sol);
		}else{
			helper(res, sol, temp,coin_type+1);
		}
		
		sol[coin_type] = 0;
	}
	


}

int main(){
	vector<vector<int>>res;
	vector<int>sol(4,0);
	int n = 10;
	helper(res, sol, n, 0);

	cout <<"There are "<< res.size()<<" Ways to get "<< n << " cents:\n";
	for(auto r:res){
		for(int i=0;i<4;i++){
			cout << r[i] <<"*"<< value[i] << '\t';
		}
		cout << endl;
	}
	return 0;
}