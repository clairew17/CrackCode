//quickSelect.cc
#include"header.h"
int partition(vector<int> &nums, int start, int end);
int quickselect(vector<int> &nums, int start, int end, int k);

/*int quickSelect(vector<int> nums, int start, int end, int k){
	if(start <= end){
		int pivot = partition(nums, start, end);
		if(pivot == k){
			return nums[k];
		}
		if(pivot > k){
			return quickselect(nums, start, pivot-1,k);
		}
		if(pivot < k){
			return quickselect(nums, pivot+1, end, k);
		}
	}
	return INT_MIN;
}

int partition(vector<int> nums, int start, int end){
	int pivot = start + rand()%(end-start+1);
	cout << "pivot="<<pivot << ", start="<<start << ", end="<<end<<endl;
	swap(nums[pivot], nums[end]);
	PrintVector(nums);
	for(int i=start;i<end;i++){
		if(nums[i]>nums[end]){
			swap(nums[i], nums[end]);
			start++;
			PrintVector(nums);
			cout << "start=" << start << endl;
		}
	}
	PrintVector(nums);
	cout << "start=" << start << endl;
	swap(nums[start], nums[end]);
	return start;

}*/

 
int quickselect(vector<int> &G, int first, int last, int k) {
  if(first > last)return INT_MIN;

  int pivot = partition(G, first, last);
  if(pivot == k)return G[k];
  if(pivot > k)return quickselect(G, first, pivot - 1, k);
  else return quickselect(G, pivot + 1, last, k);
  return 0;
}

int partition(vector<int> &G, int first, int last) {
  int mid = first + (last - first)/2;
  int pivot = G[mid];
  swap(G[first], G[mid]);
  int i = first +1, j = last;
  //move any element > pivot after j
  while(i <= j){
  	while(i<=j && G[i]<=pivot)i++;
  	while(i<=j && G[j]>pivot)j--;
  	if(i<j)swap(G[i], G[j]);
  }
  //i-1: the last element < pivot
  swap(G[i-1],G[first]);
  return i-1;
}

int main(){
	vector<int> nums = {3,2,2,1,2};//GenerateRandomVector(10);
	PrintVector(nums);
	int k = 3;
	srand(time(NULL));
	//cout << "Select "<< k << "th element:";
	int res =  quickselect(nums, 0, nums.size() - 1, k - 1);;
	cout << "Select "<< k << "th element:"<< res << endl;
	sort(nums.begin(), nums.end());
	PrintVector(nums);

}