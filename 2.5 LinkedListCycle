struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
EXAMPLE
input: A -> B -> C -> D -> E -> C [the same C as earlier]
output: C
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
    if(head==NULL)return NULL;
    ListNode*fast = head,*slow = head;
    bool Found = false;
    //detect circle
    while(fast&&fast->next&&slow){
        
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast==slow){
            Found = true;
            break;
        }
    }
    if(Found==false)return NULL;
    
    cout << fast->val <<endl;
    slow = head;
    while(fast && slow && fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
    
    }
};