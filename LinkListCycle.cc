//LinkListCycle.cc
#include"../CC/header.h"

bool hasCycle(ListNode *head) {
	ListNode *fast  = head, *slow = head;
	while(fast && fast->next && slow){
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)return true;
	}
	return false;
}