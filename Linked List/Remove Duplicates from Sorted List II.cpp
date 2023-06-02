class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Empty list or single node, no duplicates
        }
        
        ListNode dummy(0); // Create a dummy node to handle the case of duplicates at the beginning
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* current = head;
        
        while (current != nullptr) {
            while (current->next != nullptr && current->val == current->next->val) {
                current = current->next; // Skip duplicates
            }
            
            if (prev->next == current) {
                // No duplicates, move prev and current pointers forward
                prev = prev->next;
            } else {
                // Duplicates found, skip all duplicate nodes
                prev->next = current->next;
            }
            
            current = current->next;
        }
        
        return dummy.next;
    }
};
