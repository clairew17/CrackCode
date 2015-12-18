Implement an algorithm to find the nth to last element of a singly linked list.


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* N2Last(ListNode*head,int N){
    if(head==NULL)return NULL;
    ListNode* fast = head, *slow = head;
    int i =1;
    while(fast->next){
        fast = fast->next;
        if(i>N)slow=slow->next;
        i++;
    }
    return slow;
}