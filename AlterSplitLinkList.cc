//AlterSplitLinkList.cc
/*

Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists ‘a’ and ‘b’. The sublists should be made from alternating elements in the original list. So if the original list is 0->1->0->1->0->1 then one sublist should be 0->0->0 and the other should be 1->1->1.

*/
#include"../CC/header.h"

vector<ListNode*>AlterSplitLinkList(ListNode* head){
	vector<ListNode*>res;
	ListNode * head1 = new ListNode(0), *head2 = new ListNode(0);
	ListNode * p1= head1, *p2= head2, *cur = head;
	while(cur && cur->next){
		p1->next = new ListNode(cur->val);
		p2->next = new ListNode(cur->next->val);
		p1 = p1->next;
		p2 = p2->next;
		cur = cur->next->next;
	}
	if(cur){p1->next = new ListNode(cur->val);p1=p1->next;}
	p1->next=NULL;
	p2->next=NULL;
	res.push_back(head1->next);
	res.push_back(head2->next);

	for(auto r:res){
		PrintLinkList(r);
	}
	return res;
}


vector<ListNode*>AlterSplitLinkListInplace(ListNode* head){
	vector<ListNode*>res;
	ListNode * head1 = head;
	if(!head || head->next == NULL){
		res.push_back(head1);
		return res;
	}
	ListNode * head2 = head->next;
	ListNode * p1= head, *p2= head2, *cur = head;
	
	if(cur->next){
		cur = cur->next->next;
		//cout << cur->val << endl;
		while(cur && cur->next){
			p1->next = cur;
			p2->next = cur->next;
			p1 = p1->next;
			p2 = p2->next;
			cur = cur->next->next;
			
		}
		if(cur){p1->next = cur;p1=p1->next;}
	}
	p1->next=NULL;
	p2->next=NULL;
	res.push_back(head1);
	res.push_back(head2);
	for(auto r:res){
		PrintLinkList(r);
	}
	return res;
}
int main(int argc, char *argv[]){
	srand(time(NULL));
	string str = argv[1];
	int n = stoi(str);
	ListNode* head =  GenerateRandomLinkList(n);
	PrintLinkList(head);
	cout << "After split:\n";
	vector<ListNode*>res = AlterSplitLinkList(head);
	cout << "After split:\n";
	vector<ListNode*>res1 = AlterSplitLinkListInplace(head);
	return 0;
}