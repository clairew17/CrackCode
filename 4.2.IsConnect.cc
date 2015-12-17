//4.2 IsConnect.cc
//Given a directed graph, design an algorithm to  nd out whether there is a route be- tween two nodes.
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;

#define PROB 60

// construct a directed graph has @size nodes.
vector<pair<int, int> > DirectedGraph(int size) {
    vector<pair<int, int> > result;
    srand(time(NULL));
    int direction = 0;
    pair<int, int> temp;
    for (int i = 0; i < size-1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (rand() % 100 < PROB) {
                direction = rand() % 2;
                if (direction)
                    temp = make_pair(i, j);
                else
                    temp = make_pair(j, i);
                result.push_back(temp);
            }
        }
    }
    return result;
}

//#include"head.h"
using namespace std;
bool Connect(int start, int end, map<int,bool>Visited, vector<pair<int, int> > &edges);

bool IsConnect(int start, int end, vector< pair<int, int> > &edges){
    map<int,bool>Visited;
    cout << start;
    return Connect(start,end,Visited,edges);
}

bool Connect(int start, int end, map<int,bool>Visited, vector<pair<int, int> > &edges){
    if(start==end)return true;
    vector<int>next;
    for(auto p:edges){
        if(p.first==start){

            if(Visited.find(p.second)==Visited.end() || Visited[p.second]==false){
                Visited[p.second]=true;
                cout << "->" << p.second;

                if(Connect(p.second,end,Visited,edges)==true){
                    return true;
                }
                //next.push_back(p.second);
                Visited[p.second]=false;
            }
        }
    }
    

    return false;
    
}
int main(){
    int size = 10;
    vector<pair<int, int> > gragh = DirectedGraph(size);
    for (int i = 0; i < size; ++i) {
        //gragh.push_back(make_pair(i,i+1));
        cout << gragh[i].first << " " << gragh[i].second << ";";
    }
    cout << endl;
    int start = rand()%size;
    int end = rand()%size;
    cout << start <<"->"<< end <<" is:\n";
    if(IsConnect(start,end,gragh))
        cout << "\nConnected!\n";
    else
        cout<<"\nUnconnected!" <<endl;
    return 0;

}
