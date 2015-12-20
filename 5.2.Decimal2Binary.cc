//5.2.Decimal2Binary.cc
/*

     Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary rep- resentation. If the number can not be represented accurately in binary, print “ERROR”


*/
#include"Tree.h"

string Decimal2Binary(string str)
{
	size_t found = str.find_first_of('.');
	int int_part;
	double dec_part;
	string int_str, dec_str;
	if(found != string::npos){
		int_part = stoi(str.substr(0,found));
		dec_part = stod(str.substr(found));
		//cout << int_part <<'\t' << dec_part << endl;

		while(int_part){
			int r = int_part%2;
			int_part >>= 1;
			int_str = to_string(r)+int_str;
		}
		if(int_str.size()==0)int_str += "0";
		
		//convert decimal part to binary
		while(dec_part != 0){
			//cout << dec_part <<endl;
			if(dec_str.size()>32){return "ERROR";}
			if(dec_part==1){
				dec_str.append(to_string(dec_part));
				break;
			}
			double r = dec_part*2;
			if(r>=1){
				dec_str.append(to_string(1));
				dec_part = r-1;
			}else{
				dec_str.append(to_string(0));
				dec_part = r;
			}

		}
		//cout << dec_str <<endl;
		return (int_str+"."+dec_str);

	}

	return "ERROR";

}


int main(){

	string str = "0.0078125";

	cout << "Input:\t"<<str <<endl;
	cout << "BinaryForm:\t" << Decimal2Binary(str) <<endl;
	return 0;

}