#include"header.h"
 
/*

lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,

Take the set of integers
1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,……

First, delete every second number, we get following reduced set.
1,3,5,7,9,11,13,15,17,19,…………

Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….

Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

Therefore, set of lucky numbers is 1, 3, 7, 13,………



*/


/* Returns 1 if n is a lucky no. ohterwise returns 0*/
bool isLucky(int n, int step)
{
	if(n<step)return true;
	if(n%step==0)return false;
	int new_n = n - (n/step);
	return isLucky(new_n, step+1);
}

/*Driver function to test above function*/
int main(int argc, char*argv[])
{
  int n = stoi(argv[1]);
  cout << n <<" is Lucky Number: "<< Result[isLucky(n, 2)] <<endl;
  return 0;
}