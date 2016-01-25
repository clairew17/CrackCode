//BSTPreOrder2PostOrder.cc

#include"Tree.h"
/*
BST PreOrder to PostOrder，给你一个BST的PreOrder，让你输出PostOrder。如果做过leetcode的 PreOrder + InOrder 构建Tree 和 PostOrder + InOrder 构建Tree的那两题，这题就不难做。
*/


vector<int> helper(vector<int>pre, int ps, int pe)
{
	vector<int>res;
	if(ps>pe)return res;
	res.push_back(pre[ps]);

	int pos=pe+1;
	for(int i=ps+1; i<=pe; i++)
	{
		if(pre[i]>pre[ps]){
			pos = i;
			break;
		}
	}
	
	vector<int>left = helper(pre, ps+1, pos-1);
	vector<int>right = helper(pre, pos, pe);

	res.insert(res.begin(), right.begin(), right.end());
	res.insert(res.begin(), left.begin(), left.end());

	return res	;
}

vector<int> BSTPreOrder2PostOrder(vector<int>pre)
{
	return helper(pre, 0, pre.size()-1);
}



int main(int argc, char *argv[])
{
	int n = stoi(argv[1]);
	TreeNode *root = CreateTree(n);
	

	vector<int>PreOrder = {7,3,0,2,9,8};
	vector<int>PostOrder = BSTPreOrder2PostOrder(PreOrder);
	PrintVector(PostOrder);

	return 0;
}