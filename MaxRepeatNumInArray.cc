#include"header.h"
//Find the maximum repeating number in O(n) time and O(1) extra space
//return the index of maximal repeating num
int MaxRepeatNum(vector<int> nums){
	int n = nums.size();
	if(n==0)return -1;
	if(n==1)return nums[0];

	sort(nums.begin(), nums.end());
	PrintVector(nums);

	int len = 1;
	int start = 0;
	int res = nums[start];
	for(int i=1;i<n;i++){
		if(nums[i]!=nums[i-1]){
			if(len < i-start){
				len = i-start;
				res = nums[start];
			}
			start = i;
		}
	}
	return res;

}


int main(int argc, char *argv[]){
	int n = stoi(argv[1]);
	vector<int>nums = GenerateRandomVector(n);
	int res = MaxRepeatNum(nums);
	cout << res <<endl;
	return 0;
}