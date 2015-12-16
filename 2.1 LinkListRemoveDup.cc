Write code to remove duplicates from an unsorted linked list. FOLLOW UP

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* RemoveDup(ListNode*head){
    if(head==NULL)return head;
    return RemoveDupMap(ListNode*head);
    return RemoveDupNoMap(ListNode*head);
}

ListNode* RemoveDupMap(ListNode*head){
    map<int,int>NodeMap;
    ListNode* cur =head,pre=head;
    while(head){
        NodeMap[cur]++;
    }
    
    NodeMap[head]--;
    cur = head->next;
    while(cur){
        if(NodeMap[cur->val]==1){
            pre->next = cur;
            pre = cur;
        }
        NodeMap[cur->val]--;
        cur = cur->next;
    }
    pre->next =NULL;
    return head;
    
}


ListNode* RemoveDupNoMap(ListNode*head){
    ListNode* cur =head,pre=head;
    cur = head->next;
    while(cur){
        if(Exist(head,cur))continue;//bypass
        else{
            pre->next = cur;
            pre = cur;
        }
        cur=cur->next;
    }
    pre->next = NULL;
}
//return true if exist duplicate node of cur from head to cur
bool Exist(ListNode*head, ListNode*cur){
    if(!head || !cur)return true;
    ListNode*pre =head;
    while(pre && pre!=cur){
        if(pre->val == cur->val)return true;
        else pre = pre->next;
    }
    return false;
}