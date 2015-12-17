//MiniBinaryTree.cc

//Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.

#include"Tree.h"

TreeNode* MiniBinaryTree(vector<int> &nums)
{
	return GenerateTree(nums,0,nums.size());
}

TreeNode* GenerateTree(vector<int> &nums,int start, int end)
{
	//cout << start <<","<< end << endl;
	if(start>=end)return NULL;
	int mid = (start+end)/2;
	TreeNode* node = new TreeNode(nums[mid]);

	node->left = GenerateTree(nums,start,mid);
	node->right = GenerateTree(nums,mid+1,end);

	return node;
}


/*int main(){
	vector<int>nums;
	int size =11;
	int i=size;
	while(i--){
		nums.push_back(i);
	}
	sort(nums.begin(),nums.end());
	PrintVector(nums);
	TreeNode* node=MiniBinaryTree(nums);
	PrintTree(node);
	//TreeNode* node= GenerateBSTree(nums);

	return 0;
}*/
