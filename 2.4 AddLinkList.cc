You have two numbers represented by a linked list, where each node contains a sin- gle digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (3 -> 1 -> 5), (5 -> 9 -> 2) Output: 8 -> 0 -> 8


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* SumListNode(ListNode *node1, ListNode *node2){
    ListNode *head=new ListNode(0),*pre = head;
    int carry=0, sum=0;
    while(node1 || node2|| carry){
        sum = node1?node1->val:0 + node2?node2->val:0 + carry;
        pre->next = new ListNode(sum%10);
        carry = sum/10;
        node1 = node1?node1->next:NULL;
        node2 = node2?node2->next:NULL;
    }
    pre->next = NULL;
    return head->next;
    
}