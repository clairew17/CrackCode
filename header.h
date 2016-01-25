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
#include<unordered_set>
using namespace std;
#define null INT_MIN
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
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

//*************************** LinkList ***************************

ListNode* FindMidLinkList(ListNode *head);
ListNode* ReverseLinkList(ListNode *head);
void InterleaveMergeLinkList(ListNode *head1, ListNode *head2);
ListNode* GenerateRandomLinkList(int len);
void PrintLinkList(ListNode*head);

//*************************** LinkList ***************************


void FindDeleteString(string &str1, string str2);
vector<int> windowsum(vector<int>nums, int ws);
void PrintVector(vector<int>nums);
vector<int> Arr2Vec(int arr[], int n);
//convert string in the format of [1,2,3]
vector<int>GenerateRandomVector(int len);

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
    vector<int>vect = GenerateRandomVector(len);

    ListNode *head=new ListNode(0), *cur = head;
    for(int i=0;i<len;i++){
        cur->next = new ListNode(vect[i]);
        cur = cur->next;
    }
    PrintLinkList(head->next);cout << endl;
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
    //uncomment this line if you want unsorted linklist
    //sort(res.begin(),res.end());
    PrintVector(res);
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

vector<int> Arr2Vec(int arr[], int n){
    //int  n = sizeof(arr)/sizeof(int);
    vector<int> res; 
    for(int i=0;i<n;i++){
        res.push_back(arr[i]);
    }
    return res;
}



//return the node before mid point of linklist
ListNode* FindMidLinkList(ListNode*head){
    //if(head==NULL || head->next==NULL)return NULL;

    ListNode *slow = head, *fast = head, *pre = head;
    while(fast && fast->next){
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast==NULL){//even number of node 
        //do nothing
    }else{//odd number of node
        slow = slow->next;;
        //pre = pre->next;
    }
    //return the node before mid
    //odd: n/2 th node
    //even n/2 -1 th node
    return pre;

}

//reverse linklist
ListNode* ReverseLinkList(ListNode *head){
    if(head==NULL)return NULL;
    ListNode *cur = head, *next, *pre = NULL;
    while(cur){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
//merge two list in an inverleaving way
void InterleaveMergeLinkList(ListNode *head1, ListNode *head2){
    ListNode *p1 = head1, *p2 = head2, *next1, *next2;
    while(p1 && p2){
        //cout << p1->val << ',' << p2->val <<endl;
        next1 = p1->next;
        next2 = p2->next;

        p1->next = p2;
        p2->next = next1;
        
        p2 = next2;
        p1 = next1;
    }
    //return head1;
}

