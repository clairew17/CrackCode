//4.7.IsSubTree.cc
/*
You have two very large binary trees: T1, with millions of nodes, and T2, with hun- dreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
*/
#include"Tree.h"

bool MatchTree(TreeNode* r1, TreeNode* r2);
bool IsSubTree(TreeNode* r1, TreeNode* r2);


bool IsSubTree(TreeNode* r1, TreeNode* r2){
	if(r1 == NULL && r2 != NULL)return false;
	if(r2 == NULL)return true;
	if(r1->val == r2->val){
		if(MatchTree(r1,r2))return true;
	}
	return (IsSubTree(r1->left,r2) || IsSubTree(r1->right,r2));
}

bool MatchTree(TreeNode* r1, TreeNode* r2)
{
	if(r1==NULL && r2==NULL)return true;
	if(r1==NULL || r2==NULL)return false;
	if(r1->val != r2->val) return false;
	return (MatchTree(r1->left,r2->left) && MatchTree(r1->right,r2->right));
}

int main()
{	
	cout << "Tree 1:\n";
	TreeNode* root1 = CreateTree(16);
	cout << "Tree 2:\n";
	TreeNode* root2 = CreateTree(7);
	
	cout <<"Tree2 is "<< (IsSubTree(root1, root2)?"":"Not")<<" the subtree of Tree1\n";

	return 0;

}