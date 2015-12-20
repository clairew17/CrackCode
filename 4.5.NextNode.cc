

//Write an algorithm to  find the ‘next’ node (i.e., in-order successor) of a given node in a binary search tree where each node has a link to its parent.

#include"Tree.h"
TreeNode* leftmost(TreeNode* root);
TreeNode* Successor(TreeNode* node);

//return the next successor of a given node
TreeNode* Successor(TreeNode* node)
{
//if given parent
	if(!node)return NULL;
	TreeNode* successor;
	if(node->right)
	{
		successor = leftmost(node->right);
	}else{
		TreeNode* parent = node.parent;
		successor = Successor(parent);
	}
	return successor;

}


//return the leftmost node of a given tree
TreeNode* leftmost(TreeNode* root)
{
	TreeNode* node = root;
	if(node==NULL)return NULL;
	while(node)node=node->left;
	return node;
}



int main()
{
	


	TreeNode* next = Successor(root);

	return 0;
}