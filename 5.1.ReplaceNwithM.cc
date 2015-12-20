//5.1.ReplaceNwithM.cc
/*

You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100

*/


#include"Tree.h"

int main(){

	int N = 0b10001010;
	int M = 0b101;
	// bits count from LSB
	int i = 2, j = 5;

	//set all 32 bits to 1
	int max = ~0;
	//fron j to LSB is 0, MSB to j is 1 
	int left = max - ((1<<j)-1);
	//fron i to LSB is 1
	int right = (1<<i)-1;
	int mask = left | right;
	cout <<"left "<< bitset< 8 >(left) << endl;
	cout <<"righ "<< bitset< 8 >(right) << endl;
	cout <<"mask "<< bitset< 8 >(mask) << endl;
	int n = N & mask;
	int m = M<<i;


	cout <<"N = "<< bitset< 8 >(N) << endl;
	cout <<"M = "<< bitset< 8 >(M) << endl;
	cout <<"r = "<< bitset< 8 >(n | m) << endl;
	return 0;
}