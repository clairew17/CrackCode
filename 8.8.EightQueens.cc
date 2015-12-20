//8.8.EightQueens.cc

/*

Write an algorithm to print all ways of arranging eight queens on a chess board so that none of them share the same row, column or diagonal.


*/


#include"header.h"

void Place(int row);
bool check(int row);

vector<int>col4row(8,0);
int count = 0;

int main(){
	//vector<vector<int>> mat(8, vector<int>(8,0));
	Place(0);
	//cout << count << endl;
	return 0;
}

bool check(int row){
	for(int i=0;i<row;i++){
		int diff = abs(col4row[i] - col4row[row]);
		if(diff == 0 || diff == row-i)return false;
	}
	return true;
}

void Place(int row){
	if(row == 8){
		for(int i=0;i<8;i++){
			for(int j=0; j<8;j++){
				if(j==col4row[i])cout << '1' << '\t';
				else cout << '0' << '\t';
			}
			cout << endl;
		}
		cout << endl << endl;
		//PrintVector(col4row);
		return;
	}
	for(int i= 0; i< 8;i++){
		col4row[row] = i;
		if(check(row)){
			Place(row+1);
		}
	}

}