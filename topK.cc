//topK.cc
#include"header.h"

bool myfunction (int i,int j) { return (i>j); }

void topK(vector<int> vect, int k, vector<int>&res){
	
	priority_queue<int, vector<int>, greater<int>>MinQ;//min heap
	for(auto v:vect){
		if(MinQ.size()==k && MinQ.top() < v){
				MinQ.pop();
		}
		if(MinQ.size()<k)
			MinQ.push(v);
	}
	if(MinQ.size() != k){
		cout << "\n Not enought input\n";
		return;
	}
	for(int j = k-1;j>=0;j--){
		res[j] = MinQ.top();
		MinQ.pop();
	}
}


int main(int argc, char * argv[]){
	int n = stoi(argv[1]), k = stoi(argv[2]);
	if(n<k || n<0 || k<0){
		cout << "\n Not enought input\n";
		return 0;
	}
	vector<int>vect = GenerateRandomVector(n);
	vector<int>res(k,0);
	topK(vect, k, res);
	PrintVector(res);
	sort(vect.begin(), vect.end(),myfunction);
	PrintVector(vect);
	return 0;
}