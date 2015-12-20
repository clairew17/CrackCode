//5.5.BitConvert.cc


#include"Tree.h"

int main(){
	int A = 0b10001000, B = 0b1;
	int C = A^B;
	int count = 0;
	while(C){
		//count the last bit
		count += C&1;
		//shift to right
		C >>= 1;
	}
	cout << "To convert ";
	cout << A << " to " << B << endl;
	cout << "Needs " << count << " bits\n";
	return 0;
}