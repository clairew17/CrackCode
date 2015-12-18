///8.1.Fibonacci.cc
//Write a method to generate the nth Fibonacci number.

#include"header.h"


int Fibonacci(int n){
	if(n==0)return 1;
	if(n==1)return 1;
	else return Fibonacci(n-2)+Fibonacci(n-1);
}
int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	cout << "Nth Fibonacci:\t"<< Fibonacci(n) << endl;
}