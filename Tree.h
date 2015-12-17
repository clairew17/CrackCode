#include"header.h"

void PrintGivenLevel(TreeNode* root,int level);
void PrintByLevel(TreeNode* root);
int height(TreeNode*root);
void PreOrderTranversal(TreeNode* root);
void InOrderTranversal(TreeNode* root);
void PostOrderTranversal(TreeNode* root);


int height(TreeNode*root){
	if(root==NULL)return 0;
	return max(height(root->left),height(root->right))+1;
}
//print by level
void PrintByLevel(TreeNode* root){
	int h = height(root);
	int i=h;
	while(i){
		PrintGivenLevel(root,h-i);
		i--;
	}
}
void PrintGivenLevel(TreeNode* root,int level){
	if(root == NULL)return;
	if(level == 0)printf("%d ", root->val);
	else if (level > 0)
	{
		PrintGivenLevel(root->left, level-1);
		PrintGivenLevel(root->right, level-1);
	}
}
//traverse a tree in order and print
/*void PreOrderTranversal(TreeNode* root){
	cout << "TREE:\n";
	if(root==NULL)return;

	stack<TreeNode*>TreeStack;
	TreeStack.push(root);
	TreeNode*temp, *left, *right;

	cout <<"[ "<< root->val <<" ]";
	while(!TreeStack.empty()){
		temp = TreeStack.top();
		TreeStack.pop();
		left = temp->left;
		right = temp->right;
		if(right!=NULL)TreeStack.push(right);
		if(left!=NULL)TreeStack.push(left);
		cout << "[ "<<(left==NULL?"":to_string(left->val))<<", "<<(right==NULL?"":to_string(right->val))<<" ]";
	}
	cout << endl;

}*/
void PreOrderTranversal(TreeNode* root){
	//cout << "TREE:\n";
	if(root==NULL)return;
	cout << root->val << ',';
	PreOrderTranversal(root->left);
	PreOrderTranversal(root->right);
	

}
void InOrderTranversal(TreeNode* root){
	//cout << "TREE:\n";
	if(root==NULL)return;
	InOrderTranversal(root->left);
	cout << root->val << ',';
	InOrderTranversal(root->right);

}
void PostOrderTranversal(TreeNode* root){
	//cout << "TREE:\n";
	if(root==NULL)return;
	PostOrderTranversal(root->left);
	PostOrderTranversal(root->right);
	cout << root->val << ',';

}