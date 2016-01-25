#include"../CC/header.h"

void bfs(vector<vector<int>>& mat, vector<vector<int>>&dist, int sx, int sy, int mask){
        //if(mat[sx][sy]==1)dp[]
    int m = mat.size(), n = mat[0].size();
    if(sx<0 || sx>=m || sy<0 || sy >= n)return;
    //if(sx==dx && sy == dy)return 0;
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
            //visit four neighbors
            if(x>=0 && x<m && y>=0 && y<n && mat[x][y] == mask){
                //cout << "neighbors:\t"<<x << ',' << y << ", len="<<len <<endl;
                q.push(make_pair(x,y));
                mat[x][y] = mask-1;

                if(dist[x][y]==INT_MAX)dist[x][y]=0;
                dist[x][y] += len;
            }
        }
        if(count==0){
            count = q.size();
            len++;
            //cout << "level="<<len <<", count="<<count<<endl;
        }
    }
    return;
}

int shortestDistance(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size(), mark=0, ans;

    vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
    vector<pair<int, int>>buildings;

    int dx[4] = {0, 1, 0, -1}; // up, right, down, left
    int dy[4] = {1, 0, -1, 0};

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[j][i]==1){
                buildings.push(make_pair(i,j));
            }
        }
    }

    int mask = 0;
    while(!buildings.empty()){
        auto p = buildings.front(); 
        buildings.pop();
        int y=p.first, x=p.second;
        bfs(grid, dist, x, y, mask);
        mask--;
    }
    int len = INT_MAX;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(dist[i][j] != INT_MAX){
                len = min(dist[i][j], len);
            }
        }
    }
    return len;
}

int main(){
    vector<vector<int>>grid={
        {1 , 0 , 2 , 0 , 1}
        {0 , 0 , 0 , 0 , 0}
        {0 , 0 , 1 , 0 , 0}};
    cout << shortestDistance(grid)<<endl;
    return 0;
}
