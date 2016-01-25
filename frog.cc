//frog.cc

#include"header.h"


/*int solution(int A[], int N, int X, int D)
{
	if(N==0||X<=D)return 0;
	//time to reach location i
	int *res = new int(X+1);
	memset(res, INT_MAX, X+1);

	res[0] = 0;

	map<int,int>leaf;
	leaf[0] = 0;
	leaf[X] = 0;


	for(int i=0;i<N;i++){
		//if(A[i]+D>=X)return i;
		if(leaf.find(A[i]) == leaf.end()){
			leaf[A[i]]=i;
		}
	}

	for(int pos=1; pos<=X; pos++){
		if(leaf.find(pos)!=leaf.end()){
			if(pos<=D){
				res[pos]=leaf[pos];
			}else{
				for(int step =1; step<=D; step++){
					if(leaf[pos] > res[pos-step]){
					//leaf falls before pos-step
					//jump from pos-step
						cout << pos <<','<< pos-step <<endl;
						res[pos] = min(res[pos], res[pos-step]);
					}else{
						cout << "update with leaf: "<< pos <<','<< pos-step <<endl;
						cout << res[pos] << ',' << leaf[pos] <<endl;
						res[pos] = min(res[pos], leaf[pos]);
					}
				}
			}
		}
	}
	for(int i=0;i<X+1;i++)
		cout << res[i]<<',';
	cout<<endl;
	int val = res[X]==INT_MAX?-1:res[X];
	free(res);
	return val;
}*/

int solution(int A[], int N, int X, int D){
	
}


int main(){

	int A[] = {3, 1, 3, 5, 2, 1, 6};
	int sz = sizeof(A)/sizeof(int);
	int X = 7, D = 3;
	cout << solution(A, sz, X, D)<<endl;
	return 0;
}