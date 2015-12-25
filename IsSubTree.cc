//IsSubTree.cc
#include"../CC/Tree.h"

bool IsSub(TreeNode* T1, TreeNode *T2){
	if(T2==NULL)return true;
	if(T1 == NULL)return false;
	return (IsSameTree(T1,T2) || IsSub(T1->left, T2) || IsSub(T1->right, T2));
}

bool IsSameTree(TreeNode* T1,TreeNode* T2){
	if(T1==T2==NULL)return true;
	if(T1==NULL || T2==NULL)return false;
	if(T1->val != T2->val)return false;
	return (IsSameTree(T1->left, T2->left) && IsSameTree(T1->right, T2->right));
}