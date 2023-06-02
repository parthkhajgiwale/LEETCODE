class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            // If the list is empty or has only one node, there can't be a cycle
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                // If the fast pointer reaches the end of the list, there is no cycle
                return false;
            }
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If the loop exits, it means there is a cycle
        return true;
    }
};
