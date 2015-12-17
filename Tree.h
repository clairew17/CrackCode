#include"header.h"

void PrintGivenLevel(TreeNode* root,int level);
void PrintByLevel(TreeNode* root);
int height(TreeNode*root);
void PreOrderTranversalRecurse(TreeNode* root);
void InOrderTranversalRecurse(TreeNode* root);
void PostOrderTranversalRecurse(TreeNode* root);
void PostOrderTranversal(TreeNode* root);
void PreOrderTranversal(TreeNode* root);
void InOrderTranversal(TreeNode* root);
vector<int> in_order(TreeNode *root);
void destroy_tree(TreeNode *leaf);
void Insert2BST(int key, TreeNode *&leaf);
void Insert2BST(int val,TreeNode* &root);
TreeNode* GenerateBSTree(vector<int> nums);
void PrintTree(TreeNode* node);
TreeNode* MiniBinaryTree(vector<int> &nums);
TreeNode* GenerateTree(vector<int> &nums,int start, int end);




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
void PreOrderTranversalRecurse(TreeNode* root){
	//cout << "TREE:\n";
	if(root==NULL)return;
	cout << root->val << ',';
	PreOrderTranversalRecurse(root->left);
	PreOrderTranversalRecurse(root->right);
	

}
void InOrderTranversalRecurse(TreeNode* root){
	//cout << "TREE:\n";
	if(root==NULL)return;
	InOrderTranversalRecurse(root->left);
	cout << root->val << ',';
	InOrderTranversalRecurse(root->right);

}
void PostOrderTranversalRecurse(TreeNode* root){
	//cout << "TREE:\n";
	if(root==NULL)return;
	PostOrderTranversalRecurse(root->left);
	PostOrderTranversalRecurse(root->right);
	cout << root->val << ',';
}

void PreOrderTranversal(TreeNode* root){
	//cout << "TREE:\n";
	if(root==NULL)return;
	stack<TreeNode*>TreeStack;
	TreeStack.push(root);
	//cout << root->val << endl;
	TreeNode *node;
	while(!TreeStack.empty()){
		node  = TreeStack.top();
		TreeStack.pop();
		cout << node->val << ',';
		if(node->right)TreeStack.push(node->right);
		if(node->left)TreeStack.push(node->left);
	}
	//cout << root->val << ',';
}

void PostOrderTranversal(TreeNode* root){
	if(root==NULL)return;
	stack<TreeNode*>TreeStack;

	TreeNode *node=root;
	

	while(node){
		TreeStack.push(node);
		node = node->right;
	}

	node = TreeStack.top();
	while(!TreeStack.empty() && node)
	{
		//print & pop
		node = TreeStack.top();
		node = node->left;
		while(node){
			TreeStack.push(node);
			node = node->left;
		}

		node = TreeStack.top();
		TreeStack.pop();
		cout << node->val << ",";
	}


}
void InOrderTranversal(TreeNode* root){
	if(root==NULL)return;
	stack<TreeNode*>TreeStack;
<<<<<<< HEAD
	TreeNode *node=root;

	//push all left child
	while(node){
		TreeStack.push(node);
		node = node->left;
	}

	while(!TreeStack.empty())
	{
		//print & pop
		node = TreeStack.top();
		TreeStack.pop();
		cout << node->val << ",";

		//acces right child
		node = node->right;

		while(node){
			TreeStack.push(node);
			node = node->left;
=======
	//if(root->right)TreeStack.push(root->right);
	if(root)TreeStack.push(root);
	TreeNode *node=root;
    while(node){
        if(node->left)TreeStack.push(node->left);
        node = node->left;
    }
	while(!TreeStack.empty()){
		node = TreeStack.top();
		cout << node->val << ",";
        
        if(node->right){
			TreeStack.push(node->right);
            node = node->right;
            while(node){
                node = node->left;
                if(node)TreeStack.push(node);
            }
>>>>>>> 35f2d3369fe369edf9d8366a8d53484153ce7c04
		}
	}

}

vector<int> in_order(TreeNode *root) {
    stack<TreeNode*> st;
    vector<int> ar;
    if (root == NULL) return ar;
    st.push(root);
    while (!st.empty()) {
        TreeNode *root = st.top();
        if (root->left) {
            st.push(root->left);
        } else {
            ar.push_back(root->val);
            st.pop();
            if (root->right) {
                st.push(root->right);
            }
        }
    }
    return ar;
}

void PrintTree(TreeNode* node)
{

	cout << "height= "<<height(node);
	cout << "\nBy Level:\n";
	PrintByLevel(node);
	cout << "\nIn Order:\n";
	InOrderTranversalRecurse(node);
	//cout << endl;
	//InOrderTranversal(node);
	//PrintVector(in_order(node));
	cout << "\nPre Order:\n";
	PreOrderTranversalRecurse(node);
	cout << "\nPost Order:\n";
	PostOrderTranversalRecurse(node);
	//PostOrderTranversal(node);
	cout << endl;
	//PostOrderTranversal(node);
	cout << endl;
}
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
