//8.2.grid.cc

//Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can only move in two directions: right and down. How many possible paths are there for the robot?FOLLOW UPImagine certain squares are “o  limits”, such that the robot can not step on them. Design an algorithm to get all possible paths for the robot.
#include"header.h"

int combine(int n, int k){
	if(k==0)return 1;
	else return (combine(n-1,k-1)*n/k);
}
void PrintMatrix(vector<vector<int>> matrix){
	int m = matrix.size(), n= matrix[0].size();
	if(m<1 || n<1)return;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}

}

int BlockedRoute(vector<vector<int>> matrix){

	int m = matrix.size(), n= matrix[0].size();
	if(m<1 || n<1)return 0;
	//cout << m << '\t' <<n <<endl;
	PrintMatrix(matrix);

	vector<vector<int>>res(m,vector<int>(n,1));

	for(int i=0;i<m;i++){
		if(matrix[i][0]==1){
			res[i][0]=0;
		}else if(i && res[i-1][0]==0){
			res[i][0] =0;
		}
	}
	for(int i=0;i<n;i++){
		if(matrix[0][i]==1){
			res[0][i]=0;
		}else if(i && res[0][i-1]==0){
			res[0][i] =0;
		}
	}
	cout << endl;PrintMatrix(res);

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(matrix[i][j]==1)
				res[i][j]=0;
			else 
				res[i][j] = res[i-1][j] + res[i][j-1];

		}
	}
	cout << endl;PrintMatrix(res);

	return res[m-1][n-1];


}



int main(int argc, char *argv[]){
	int N = stoi(argv[1]);
	vector<vector<int>> matrix(N, vector<int>(N,0));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			matrix[i][j] = int(rand()%10>7);
		}
	}
	
	//cout << combine(N-1, 2*N-2) << endl;
	cout << BlockedRoute(matrix) << endl;

}