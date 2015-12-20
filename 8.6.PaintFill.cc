//8.6.PaintFill.cc

#include"header.h"


void Fill(vector< vector<int> > &Fig, int x, int y, int old_color, int new_color){
	if(x<0 || x >= Fig.size() || y < 0 || y >= Fig[0].size())return;
	if(Fig[x][y] == old_color){//in zone
		Fig[x][y] = new_color;
		Fill(Fig, x-1,y,old_color,new_color);
		Fill(Fig, x+1,y,old_color,new_color);
		Fill(Fig, x,y-1,old_color,new_color);
		Fill(Fig, x,y+1,old_color,new_color);
	}
}

int main(){
	srand(time(NULL));

	int m = 4, n = 5;
	vector<vector<int>>Fig(m,vector<int>(n,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			Fig[i][j] = rand()%2;
		}
		PrintVector(Fig[i]);
	}

	int x = 1, y = 1;
	int old_color = Fig[x][y];
	int new_color = 2;
	Fill(Fig, x,y,old_color,new_color);
	cout << "\nAfter PaintFill:\n";
	for(auto f:Fig){
		PrintVector(f);
	}
	return 0;
}