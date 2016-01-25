//Knights Adventure.cc

/*

Knight's Adventure：一个Chess Board，你要把一个Knight从给定起点跳到给定终点，棋盘上有一些blocked square不能走，求最短步数。Warning：最后三个test case非常大，长宽都是10000+，大数据测试。

*/
#include"header.h"
struct point{
	int x;
	int y;
	point(int a, int b):x(a),y(b){};
};

/*
void ShortestPath(vector<vector<int>>&mat, vector<vector<int>>&dp)
{
	int m = mat.size(), n = mat[0].size();
	
	for(int i=1;i<m;i++){
		if(mat[i][0]==1)
			dp[i][0]=INT_MAX;
		else 
			dp[i][0]=dp[i-1][0]==INT_MAX?INT_MAX:dp[i-1][0]+1;
	}
	for(int j=1;j<n;j++){
		if(mat[0][j]==1)
			dp[0][j]=INT_MAX;
		else 
			dp[0][j]=dp[0][j-1]==INT_MAX?INT_MAX:dp[0][j-1]+1;
	}

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(mat[i][j]==1)
				dp[i][j]=INT_MAX;
			else{
				int dis = min(dp[i-1][j], dp[i][j-1]);
				dp[i][j] = dis==INT_MAX?INT_MAX:dis+1;
			}
		}
	}

	
}*/
/*
int ShortestPath(vector<vector<int>>&mat, int sx, int sy, int dx, int dy)
{
	int m = mat.size(), n = mat[0].size();
	if(sx<0 || sx>=m || sy<0 || sy >= n)return -1;
	if(mat[sx][sy]==1)return -1;

	//visit dest
	if(sx==dx && sy == dy)return 0;
	mat[sx][sy]=1;

	int dis = INT_MAX;
	for(auto d:dir){
		
		int x = sx + d[0], y = sy + d[1];
		if(x>=0 && x<m && y>=0 && y<n && mat[x][y]==0){
			int dd = ShortestPath(mat, x, y, dx, dy);
			if(dd != -1)
				dis = min(dis, dd);
		}
	}

	cout << sx << ',' << sy << "\tdis="<<dis <<endl;
	if(dis == INT_MAX)return INT_MAX;
	return dis+1;
	
}*/
//update neighbors of (sx, sy)

vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

int ShortestPath(vector<vector<int>>&mat, int sx, int sy, int dx, int dy){
	//if(mat[sx][sy]==1)dp[]
	int m = mat.size(), n = mat[0].size();
	if(sx<0 || sx>=m || sy<0 || sy >= n)return -1;
	if(sx==dx && sy == dy)return 0;
	queue<pair<int,int>>q;

	q.push(make_pair(sx,sy));
	mat[sx][sy] = 1;
	int len = 1;
	int count  = q.size();

	while(count-->0){

		auto cur = q.front(); q.pop();
		//cout << "seed:\t"<<cur.first << ',' << cur.second << ", len="<<len <<endl;
		for(auto d:dir){
			int x = cur.first + d[0], y = cur.second + d[1];
			if(x==dx && y==dy)return len;
			//visit four neighbors
			if(x>=0 && x<m && y>=0 && y<n && mat[x][y] != 1){
				cout << "neighbors:\t"<<x << ',' << y << ", len="<<len <<endl;
				q.push(make_pair(x,y));
				mat[x][y] = 1;
			}
		}
		if(count==0){
			count = q.size();
			len++;
			//cout << "level="<<len <<", count="<<count<<endl;
		}
	}

	return -1;

}


int main()
{
	int m = 4, n = 6;
	vector<vector<int>>mat(m, vector<int>(n,0));
	mat[0][2]=1;mat[1][2]=1;mat[2][2]=1;
	mat[0][3]=1;mat[0][4] =0;
	mat[2][4]=1;mat[3][4]=1;
	//mat[3][2]=1;mat[3][3]=1;mat[3][4]=1;
	//mat[4][3]=1;
	
	//min distance to dest
	vector<vector<int>>dp(m, vector<int>(n,INT_MAX));

	//ShortestPath(mat, 0, 0, 0, 6);
	/*for(auto p:dp){
		PrintVector(p);
	}*/


	cout << ShortestPath(mat, 1, 1, 3 ,5) << endl;

	
	return 0;

	//point src(0,0), dest(3,4);

}