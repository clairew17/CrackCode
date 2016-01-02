//MidLinkList.cc
#include"../CC/header.h"

/*
return value of mid point in a linked list;
if the lenght is even, return the average of the mid two
*/
int getMidLinkList(ListNode *head){
	if(head==NULL){
		cout <<"\n No mid for an empty list!\n";
		return 0;
	}
	ListNode *fast = head, *slow = head, *pre = head;
	double mid_val = 0;
	while(fast && fast->next){
		fast = fast->next->next;
		//record the previous pointer
		pre = slow;
		slow = slow->next;
	}
	if(fast==NULL){//even number
		mid_val = (pre->val + slow->val)/2;
	}else{
		mid_val = slow->val;
	}
	return mid_val;
}

int main(int argc, char*argv[]){
	int len = stoi(argv[1]);
	ListNode *head = GenerateRandomLinkList(len);
	PrintLinkList(head);
	cout << "mid value = "<<getMidLinkList(head)<<endl;
}