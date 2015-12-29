//299.BullsandCows.cc
#include"header.h"
string getHint(string secret, string guess) {
	int bull = 0, cow = 0;
	string res;
	if(secret.size()!=guess.size())return res;
	int n = secret.size();
	vector<char>ss;
	for(int i=0;i<secret.size();i++){
		if(secret[i] == guess[i])bull++;
		else{
			ss.push_back(secret[i]);
		}
	}
	for(int i=0;i<secret.size();i++){
		if(secret[i] != guess[i]){
			auto it = find(ss.begin(),ss.end(),guess[i]);
			if( it!= ss.end()){
				cow++;
				ss.erase(it);
			}
		}
	}
	res = to_string(bull)+"A"+to_string(cow)+"B";
	return res;
}
int main(){
	//string str1 = "1807", str2 = "7810";
	string str1 = "1123" , str2 = "0111";
	cout << getHint(str1,str2)<<endl;;
	return 0;
}