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

}
void InOrderTranversal(TreeNode* root){
	if(root==NULL)return;
	stack<TreeNode*>TreeStack;
	//if(root->right)TreeStack.push(root->right);
	if(root)TreeStack.push(root);
	TreeNode *node;
	while(!TreeStack.empty()){
		node = TreeStack.top();
		if(node->left){
			TreeStack.push(node->left);
		}else{
			//print cur
			cout << node->val << ",";
			TreeStack.pop();
			if(node->right){
				TreeStack.push(node->right);
			}
		}
	}
}

vector<int> in_order(TreeNode *root){
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
            
            if (!st.empty()) {
                root = st.top();
                ar.push_back(root->val);
                st.pop();
            }

        }
    }
    return ar;
}
