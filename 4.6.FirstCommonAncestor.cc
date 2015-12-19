//4.6.FirstCommonAncestor.cc


/*Design an algorithm and write code to  find the  first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.*/

#include"Tree.h"
bool Cover(TreeNode *root, TreeNode *p);


TreeNode* FirstCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){

	// if p && q are under same child node, recursively find the first common parent
	if(Cover(root->left, p) && Cover(root->left, q)){
		return FirstCommonAncestor(root->left, p, q);
	}
	if(Cover(root->right, p) && Cover(root->right, q)){
		return FirstCommonAncestor(root->right, p, q);
	}

	// if p and q are under different node, root is the firsty ancesstor
	return root;
}

//if node p is the child of root
bool Cover(TreeNode *root, TreeNode *p){
	if(root==NULL)return false;
	if(root == p)return true;
	return (Cover(root->left, p) || Cover(root->right, p));
}

int main()
{	
	TreeNode* root = CreateTree(7);
	TreeNode* p=root->right;
	TreeNode* q = root->right->right;
	cout << "the  first common ancestor of " << p->val << " and "<< q->val << " is: \n"; 
	TreeNode* fca = FirstCommonAncestor(root, p , q);
	cout << fca->val <<endl; 
	return 0;

}