//4.4 BSTLevel.cc

//Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth (eg, if you have a tree with depth D, you’ll have D linked lists).

#include"Tree.h"
vector<ListNode*> BSTLevel(TreeNode* root);


vector<ListNode*> BSTLevel(TreeNode* root)
{
	vector<ListNode*> List;

}

int main()
{
	vector<int>nums;
	int size =5;
	int i=size;
	while(i--){
		nums.push_back(i);
	}
	sort(nums.begin(),nums.end());
	PrintVector(nums);
	TreeNode* root= GenerateBSTree(nums);
	PrintTree(root);


	vector<ListNode*> List = BSTLevel(root);

	return 0;
}