//MiniBinaryTree.cc

Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.


TreeNode* MiniBinaryTree(vector<int> nums){

	return GenerateTree(nums,0,nums.size());

}
TreeNode* GenerateTree(vector<int> nums,int start, int end){
	if(start<end)return NULL;
	mid = (start+end)/2;
	TreeNode* node = new TreeNode(nums[mid]);
	node->left = GenerateTree(nums,start,mid);
	node->right = GenerateTree(nums,mid+1,end);
	return node;

}