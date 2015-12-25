//9.5.StringInterperse.cc
#include"header.h"
int search(vector<string>dict, string str, int lo, int hi){
	while(lo <= hi){
		
		while(lo <= hi && dict[hi]==""){
			hi--;
		}
		//cout << dict[hi] << endl;
		//cout << lo << '\t' << hi <<endl;
		if(lo > hi)return -1;
		int mid = (lo+hi)/2;
		//cout << dict[lo]<<"\t"<< dict[mid]<<"\t"<< dict[hi] << endl;

		while(dict[mid] == ""){//avoid dict[mid]==""
			mid++;
		}
		if(str==dict[mid]){
			return mid;
		}else if(str > dict[mid]){
			lo = mid+1;
		}else hi = mid-1;

	}

	return -1;
}

int main(){
	vector<string>dict={"at", "", "","", "ball","", "","",  "car", "","", "dad", "",""}; 
	string str = "balla";
	int ind = search(dict,str,0,dict.size()-1);
	if(ind!=-1)cout<< dict[ind] << endl;
	else cout << "Not found!\n";

}