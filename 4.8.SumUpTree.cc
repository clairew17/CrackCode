//4.8.SumUpTree.cc   
/*
     You are given a binary tree in which each node contains a value. Design an algorithm to print all paths which sum up to that value. Note that it can be any path in the tree - it does not have to start at the root.
*/
#include"Tree.h"

void SumUpTree(vector<vector<int>> &res, TreeNode* root, vector<int> &sol,int sum){
	if(root==NULL)return;

	//update the root->val
	sol.push_back(root->val);
	int temp = sum - root->val;

	//check if it's a valid sum
	if(temp == 0){
		res.push_back(sol);
	}
	//explore branh left and right
	SumUpTree(res, root->left, sol, temp);
	SumUpTree(res, root->right, sol, temp);

	sol.pop_back();

}

int main(int argc, char * argv[])
{	
	cout << "Tree 1:\n";
	TreeNode* root = CreateTree(7);
	int sum = atoi(argv[1]);

	vector<vector<int>> res;
	vector<int>sol;

	SumUpTree(res, root, sol, sum);

	cout <<"There are "<<res.size() <<" paths which sum to " << sum << ":\n";
	for(auto r:res){
		PrintVector(r);
	}

	return 0;

}