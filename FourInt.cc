//FourInt.cc
#include"../CC/header.h"

int sum(vector<int>S){
	return abs(S[0]-S[1]) + abs(S[1]-S[2]) + abs(S[2]-S[3]);
}

int main(){
	vector<int>nums = GenerateRandomVector(4);
	sort(nums.begin(),nums.end());
	PrintVector(nums);
	vector<vector<int>>res;
	Permute(nums, res, 0);
	for(auto r:res){
		PrintVector(r);
	}

	return 0;
}

void Permute(vector<int>nums,vector<vector<int>>&res,int begin){
	if(begin == nums.size()){
		res.push_back(nums);
	}
	for(int i=begin;i<nums.size();i++){
		swap(nums[i],nums[begin]);
		Permute(nums, res, begin+1);
		swap(nums[i],nums[begin]);
	}
}