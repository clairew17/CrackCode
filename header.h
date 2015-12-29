#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<vector>
#include<utility>
#include<cstdlib>
#include<ctime>
#include<queue> 
#include<algorithm>
#include<math.h> 
#include<set> 
using namespace std;

string Result[2]={"False\n", "True\n"};

struct TreeNode
{
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void FindDeleteString(string &str1, string str2);
vector<int> windowsum(vector<int>nums, int ws);
void PrintVector(vector<int>nums);
ListNode* GenerateRandomLinkList(int len);
void PrintLinkList(ListNode*head);

//convert string in the format of [1,2,3]

vector<int> string2vector(string s){
    vector<int>res;
    FindDeleteString(s,"[");
    FindDeleteString(s,"]");
    //cout << "string="<<s << endl;

    string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find_first_of(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            res.push_back(stoi(token));
            //std::cout << token << std::endl;
            s.erase(0, pos + delimiter.length());
    }
    res.push_back(stoi(s));
	//PrintVector(res);
    return res;
}


//delete substring 
void FindDeleteString(string &str1, string str2){

    size_t found = str1.find(str2);
    if(found!=string::npos){
        str1.erase(found, str2.size());
    }

    return;
}

//print vector element by element
void PrintVector(vector<int>nums){
    for(int i=0;i<nums.size();i++){
        cout << nums[i];
        if(i<nums.size()-1)cout << ',';
        //else cout <<endl;
    }

    cout <<endl;
}
//true if two vectors are equal
bool CmpVector(vector<int>v1, vector<int>v2){
    int n1 = v1.size(), n2=v2.size();
    if(n1!=n2)return false;
    if(n1==0 && n2==0)return true;
    for(int i=0;i<n1;i++){
        if(v1[i]!=v2[i])return false;
    }
    return true;

}

ListNode* GenerateRandomLinkList(int len){
    //srand(time(NULL));
    int MAXNUM = 100;
    ListNode *head=new ListNode(0), *cur = head;
    for(int i=0;i<len;i++){
        cur->next = new ListNode(rand()%MAXNUM);
        cur = cur->next;
    }
    return head->next;
}

void PrintLinkList(ListNode*head){
    ListNode*cur = head;
    while(cur){
        cout << cur->val <<"->";
        cur = cur->next;
    }
    cout << endl;
}
vector<int>GenerateRandomVector(int len){
    //srand(time(NULL));
    int MAXNUM = 100;
    vector<int>res;
    for(int i=0;i<len;i++){
        res.push_back(rand()%MAXNUM);
    }
    //sort(res.begin(),res.end());
    return res;
}

ListNode* Vector2LinkList(vector<int> v1){
    ListNode *head=new ListNode(v1[0]), *cur = head;
    for(int i=1;i<v1.size();i++){
        cur->next = new ListNode(v1[i]);
        cur = cur->next;
    }
    return head;
}


