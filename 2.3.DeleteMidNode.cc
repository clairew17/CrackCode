Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
void DeleteMidNode(ListNode *node){
    if(node == NULL)return;
    ListNode *cur=node->next;
    if(cur){
        node->val = cur->val;
        node->next = cur->next;
    }else{
        node = NULL;
    }
}