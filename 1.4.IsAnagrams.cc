//1.4.IsAnagrams.cc

//Write a method to decide if two strings are anagrams or not.

#include"header.h"
bool IsAnagrams(string str1, string str2){
	int n1 = str1.size(), n2 = str2.size();
	if(n1!=n2)return false;
	
	map<char,int>m;
	for(auto ss:str1){
		if(m.find(ss)==m.end()){
			m[ss]=1;
		}else{
			m[ss]++;
		}
	}
	for(auto ss:str2){
		if(m.find(ss)==m.end()){
			return false;
		}else{
			m[ss]--;
			if(m[ss]<0)return false;
		}
	}
	for(auto iter=m.begin();iter != m.end(); iter++){
		if(iter->second !=0)return false;
	}
	return true;
}

bool IsAnagramsSort(string str1, string str2)
{
	int n1 = str1.size(), n2 = str2.size();
	if(n1!=n2)return false;
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	//cout << str1 <<"\t"<< str2 << endl;
	if(str1 != str2)return false;
	else return true;

}


int main(int argc, char* argv[])
{
	if(argc != 3) return 0;
	//cout << argc << endl;
	string str1 = argv[1];
	string str2 = argv[2];
	cout <<str1 << " and "<<str2 <<" is"<< (IsAnagramsSort(str1,str2)?"":" not") << " anagrams!\n";
}