//subset.cc

//Write a method that returns all subsets of a set.

#include"header.h"

//return all subset of a given set
void subset(vector<vector<int>>&res,vector<int>nums,int begin){
	vector<int> temp;
	if(begin < 0){
		//res.push_back({});
		return;
	}else{
		subset(res,nums, begin-1);
		int n = res.size();
		for(int i=0;i<n;i++){
			temp = res[i];
			temp.push_back(nums[begin]);
			res.push_back(temp);
		}
		vector<int>sol(1,nums[begin]);
		PrintVector(sol);
		res.push_back(sol);
	}
	return;

}

//return all subset of a given set
void subsetDup(vector<vector<int>>&res,vector<int>nums,int begin,vector<int> &sol)
{
	//res.push_back(sol);
	for(int i=begin;i<nums.size();i++){
		sol.push_back(nums[i]);
		res.push_back(sol);
		subsetDup(res,nums,i+1,sol);
		sol.pop_back();
		//bypass dup
		while(i<nums.size()-1 && nums[i]==nums[i+1])i++;
	}
		
	return;
}


int main(int argc, char *argv[]){
	std::vector<int> v=string2vector(argv[1]);
	PrintVector(v);
	vector<vector<int>>res;
	vector<int>sol;
	res.push_back(sol);
	subsetDup(res,v,0,sol);
	int i=0;
	cout << "subset:\n";
	for(auto v:res){
		cout << i++ <<":\t";
		PrintVector(v);
		
	}
	return 0;
}