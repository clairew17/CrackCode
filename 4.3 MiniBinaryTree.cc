//MiniBinaryTree.cc

//Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.

#include"Tree.h"
TreeNode* MiniBinaryTree(vector<int> &nums);
TreeNode* GenerateTree(vector<int> &nums,int start, int end);
void Insert2BST(int val,TreeNode* &root);
TreeNode* GenerateBSTree(vector<int> nums);


TreeNode* MiniBinaryTree(vector<int> &nums){
	return GenerateTree(nums,0,nums.size());
}

TreeNode* GenerateTree(vector<int> &nums,int start, int end){
	//cout << start <<","<< end << endl;
	if(start>=end)return NULL;
	int mid = (start+end)/2;
	TreeNode* node = new TreeNode(nums[mid]);

	node->left = GenerateTree(nums,start,mid);
	node->right = GenerateTree(nums,mid+1,end);

	return node;
}

TreeNode* GenerateBSTree(vector<int> nums){
	TreeNode*root(NULL);
	for(auto n:nums){
		Insert2BST(n,root);
	}
	return root;
}

void Insert2BST(int key, TreeNode *&leaf)
{
    if(leaf==NULL)cout << "NULL\n";
	if(leaf==NULL){
		leaf=new TreeNode(key);
      	leaf->left=NULL;    //Sets the left child of the child node to null
      	leaf->right=NULL;
  }else if(key< leaf->val)
  {
    if(leaf->left!=NULL)
     Insert2BST(key, leaf->left);
    else
    {
      leaf->left=new TreeNode(key);
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->val)
  {
    if(leaf->right!=NULL)
      Insert2BST(key, leaf->right);
    else
    {
      leaf->right=new TreeNode(key);
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}
void destroy_tree(TreeNode *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

int main(){
	vector<int>nums;
	int size = 5;
	int i=size;
	while(i--){
		nums.push_back(i);
	}
	sort(nums.begin(),nums.end());
	PrintVector(nums);
	TreeNode* node=MiniBinaryTree(nums);

	//TreeNode* node= GenerateBSTree(nums);

	cout << "height= "<<height(node)<<endl;
	cout << "\nBy Level:\n";
	PrintByLevel(node);
	cout << "\nIn Order:\n";
	InOrderTranversalRecurse(node);
	cout << endl;
	InOrderTranversal(node);
	//vector<int>temp = in_order(node);
	//PrintVector(temp);

	cout << "\nPre Order:\n";
	PreOrderTranversalRecurse(node);
	cout << endl;
	PreOrderTranversalRecurse(node);

	cout << "\nPost Order:\n";
	PostOrderTranversalRecurse(node);
	cout << endl;
	PostOrderTranversal(node);
	cout << endl;
	return 0;
}
