//trailingZeroes.cc

#include"../CC/header.h"
int trailingZeroes(int n){

	int count = 0;
	if(n<0)return count;

	for(long long i=5; n/i >0 ; i *= 5){//consider the overflow
		count += n/i;
	}
	return count;

}