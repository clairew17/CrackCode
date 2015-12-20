//5.6.SwapOddEvenBit.cc

/*

Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).


*/

#include"header.h"

int main(){

	int x = 0b10010101;
	int odd = x & 0xaa;
	int even = x & 0x55;
	cout <<  bitset< 8 > (x) << endl;
	cout <<  bitset< 8 > ((odd>>1) | (even<<1)) << endl;
	return 0;
}