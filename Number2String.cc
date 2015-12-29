//19.6.Number2String.cc
#include"header.h"
/*

Given an integer between 0 and 999,999, print an English phrase that describes the integer (eg, “One Thousand, Two Hundred and Thirty Four”).

*/

string Number2String(int num){
	string res;
	if(num<0 || num>999999)return res;
	int count =0,temp;
	while(num){
		temp = num%10;
		count++;
		if(count==2)
	}

}
int main(){
	int num = 123456;
	cout << Number2String(num)<<endl;
	return 0;
}