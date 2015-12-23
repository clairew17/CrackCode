//9.1.MergeSorted.cc

#include"header.h"

int main(){
	srand(time(NULL));
	int m = 5, n = 3;
	vector<int>a(m,0), b(n,0);

	for(int i=0;i<m;i++){
		a[i] = rand()%100;
	}
	sort(a.begin(),a.end());

	for(int i=0;i<n;i++){
		b[i] = rand()%100;
		a.push_back(0);
	}
	sort(b.begin(),b.end());

	cout << "Before Merge...\n";
	PrintVector(a);PrintVector(b);
	//cout << a.size() << endl;
	int tail_a = m-1, tail_b = n-1;
	int tail = m+n-1; 
	while(tail_a > -1 && tail_b > -1){
		if(a[tail_a]>b[tail_b]){
			a[tail--] = a[tail_a--];
		}else{
			a[tail--] = b[tail_b--];
		}
	}
	while(tail_b>=0){
		a[tail--] = b[tail_b--];
	}
	cout << "After Merge...\n";
	PrintVector(a);


}