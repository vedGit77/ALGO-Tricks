// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.


// LOGIC:

// Distance traveled by fast pointer = 2 * (Distance traveled by slow pointer)

// (m + n*x + k) = 2*(m + n*y + k)

// m -->  Dist of 1st node from cycle head
// n -->  Length of cycle
// k -->  dist of (node where slow and fast meet) FROM (the 1st cycle node)
// x -->  Number of complete cyclic rounds made by fast pointer before they meet first time
// y -->  Number of complete cyclic rounds made by slow pointer before they meet first time

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        slow = slow->next;
        fast = fast->next->next;

        while(slow != fast){
            if(fast==NULL || fast->next==NULL)
                return NULL;
            
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = head;             //imp-1

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;   //imp-2  //not fast->next->next
        }

        return slow;
    }
};
