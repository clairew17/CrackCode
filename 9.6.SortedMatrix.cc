//9.6.SortedMatrix.cc
/*

Given a matrix in which each row and each column is sorted, write a method to  nd an element in it.


*/

#include"header.h"

pair<int, int> SearchMatrix(vector<vector<int>>mat, int target){
	pair<int, int>res;
	int m = mat.size();if(m<1)return res;
	int n= mat[0].size();
	int i = 0, j = n-1;
	while(i<m && j>=0){
		if(mat[i][j] == target){
			res = make_pair(i,j);
			return res;
		}
		if(mat[i][j] < target)i++;
		if(mat[i][j] > target)j--;
	}
	return res;

}
int main(){
	//int m = 5, n =5;

	vector<vector<int>>mat={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
	pair<int, int>res =  SearchMatrix(mat, 1);
	for(auto v:mat)PrintVector(v);
	cout << res.first << '\t' <<res.second <<endl;
	return 0;
}