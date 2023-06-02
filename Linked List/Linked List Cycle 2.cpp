/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Check if the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;
        
        // Move slow pointer by 1 step and fast pointer by 2 steps
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If the pointers meet, there is a cycle
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        
        // If there is no cycle, return NULL
        if (!hasCycle) {
            return NULL;
        }
        
        // Reset the slow pointer to the head
        slow = head;
        
        // Move both pointers at the same speed until they meet again
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Return the node where the cycle begins
        return slow;
    }
};
