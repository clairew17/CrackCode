//8.4.PermutationString.cc

#include"header.h"

void permute(vector<string> &res, string str, int begin){
	if(begin == str.size()){
		res.push_back(str);
		return;
	}
	for(int i=begin;i<str.size();i++){
		swap(str[i],str[begin]);
		permute(res, str, begin+1);
		swap(str[i],str[begin]);
		//handle duplicate
		while(i<str.size()-1 && str[i]==str[i+1])i++;
	}
}

int main(int argc, char * argv[]){
	string str = argv[1];
	sort(str.begin(),str.end());

	vector<string>res;
	permute(res,str,0);
	for(auto r:res){
		cout << r << endl;
	}
}