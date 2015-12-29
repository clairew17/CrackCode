//Median.cc

//find median in unsorted array

#include"header.h"
int partition(vector<int>&nums, int first, int last);
int FindMed(vector<int>&nums, int first, int last, int k);

int main(){
	srand(time(NULL));
	vector<int> nums = GenerateRandomVector(6);
	PrintVector(nums);
	int res =  FindMed(nums, 0, nums.size() - 1, nums.size()/2);;
	if(nums.size()%2==0){
		res +=  FindMed(nums, 0, nums.size() - 1, nums.size()/2-1);
		res = res/2;
	}

	cout << "The median of array is "<< res << endl<< endl;
	sort(nums.begin(), nums.end());
	PrintVector(nums);
}

int FindMed(vector<int>&nums, int first, int last, int k)
{
	if(first > last)return -1;
	int pivot = partition(nums, first, last);
	if(pivot == k)return nums[k];
	if(pivot>k)return FindMed(nums, first, pivot-1, k);
	return FindMed(nums, pivot+1, last, k);
}
int partition(vector<int>&nums, int first, int last)
{
	int mid = first + (last - first)/2;
	int pivot = nums[mid];
	swap(nums[first], nums[mid]);
	int i= first+1, j = last;
	while(i<=j){
		while(i<=j && nums[i] <= pivot)i++;
		while(i<=j && nums[j] > pivot)j--;
		if(i<j)swap(nums[i],nums[j]);
	}
	swap(nums[first],nums[i-1]);
	return i-1;
}