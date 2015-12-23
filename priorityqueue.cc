#include"header.h"

/*bool compare(int a, int b)
{
   return (a>b);
}*/


bool compare(pair<int,int> a, pair<int,int> b)
{
   return (a.first<b.first);
}
 
std::priority_queue<int, vector<pair<int,int>>, decltype(&compare)> pq1(&compare);
 
std::priority_queue<int, vector<pair<int, int>>, std::less<int> > pq2;


int main(){
	srand(time(NULL));
	int size = 5;
	//priority_queue<pair<int,int>>pq;
	int start, end;
	pair<int, int> temp;
	for(int i=0;i<size;i++){
		start = rand()%20;
		end = rand()%20;
		cout << start << ',' <<end << endl;
		temp = make_pair(start, end);
		pq1.push(temp);
		//pq2.push(temp);
	}
	while(!pq1.empty()){
		cout <<"("<< pq1.top().first << "," <<pq1.top().second<< "), ";
		pq1.pop();
	}
	cout << endl;
	/*
	while(!pq2.empty()){
		cout << pq2.top() << ", ";
		pq2.pop();
	}
	cout << endl;*/
	return 0;
}