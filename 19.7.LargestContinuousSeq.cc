//19.7.LargestContinuousSeq.cc
/*
You are given an array of integers (both positive and negative). Find the continuous sequence with the largest sum. Return the sum.

Input: {2, -8, 3, -2, 4, -10}
Output: 5 (i.e., {3, -2, 4} )
*/
#include"header.h"
int LargestContinuousSeq(vector<int>nums){
	pair<int,int>res=make_pair(0,0);
	int sum = 0, maxsum =0;
	int first=0, last = 0;
	for(int i=0;i<nums.size();i++){
		sum += nums[i]
		if(maxsum<sum){
			maxsum = sum;
		}else if(sum<0){
			sum = 0;
		}
	}
	return maxsum;

}

int main(){

	vector<int>nums={2, -8, 3, -2, 4, -10};
	//pair<int,int>res = LargestContinuousSeq(nums);
	//cout << res.first << ',' << res.second <<endl;
	
	cout << "\nThe largest sum is: "<< LargestContinuousSeq(nums) << endl;
	return 0; 

}