//4.2 IsConnect.cc

Given a directed graph, design an algorithm to  nd out whether there is a route be- tween two nodes.

bool IsConnect(int start, int end, vector<pair<int, int>>& edges){
    map<int,bool>Visited;
    return Connect(start,end,Visited,edges);
}

bool Connect(int start, int end, map<int,bool>Visited, vector<pair<int, int>>& edges){
    if(start==end)return true;
    vector<int>next;
    for(auto p:edges){
        if(p.first==start){
            if(Visited.find(p.second)!=Visited.end()){
                next.push_back(p.second);
                Visited[p.second]=true;
            }
        }
    }
    
    for(auto n:next){
        if(Connect(n,end,Visited,edges)==true){
            return true;
        }
    }
    return false;
    
}