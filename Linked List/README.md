# 141. Linked List Cycle 

This project implements an algorithm to detect if a linked list contains a cycle. A cycle in a linked list occurs when there is a node that can be reached again by continuously following the next pointers.

## Algorithm

The algorithm used to detect a cycle in a linked list is Floyd's Tortoise and Hare algorithm. It involves two pointers: a slow pointer that moves one node at a time and a fast pointer that moves two nodes at a time. If there is a cycle in the linked list, the fast pointer will eventually catch up to the slow pointer.

The algorithm can be summarized as follows:
1. Initialize two pointers, `slow` and `fast`, to the head of the linked list.
2. Iterate through the linked list using the following steps:
   - Move the `slow` pointer one step forward.
   - Move the `fast` pointer two steps forward.
   - If the `fast` pointer reaches the end of the list (i.e., becomes `nullptr`), there is no cycle in the linked list.
   - If the `fast` pointer ever equals the `slow` pointer, a cycle is detected.
3. If the loop exits without finding a cycle, return `false`. Otherwise, return `true`.

## Example

Consider the following example:

```cpp
Input: head = [3, 2, 0, -4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

In this example, the linked list contains a cycle, and the tail of the list connects to the second node.

## Usage

To use the algorithm, follow these steps:

1. Create a new instance of the `Solution` class.
2. Call the `hasCycle` method, passing the head of the linked list as the parameter.
3. The method will return `true` if a cycle is detected in the linked list, and `false` otherwise.

```cpp
Solution solution;
bool hasCycle = solution.hasCycle(head);
```

## Time Complexity

The time complexity of the algorithm is O(n), where n is the number of nodes in the linked list. The algorithm uses two pointers to traverse the list, and in the worst case, the pointers will meet after traversing the entire list.

## Space Complexity

The space complexity of the algorithm is O(1). It only requires a constant amount of additional space to store the two pointers.

# 142. Linked List Cycle II

This is a problem in which we need to detect if there is a cycle in a linked list and find the node where the cycle begins.

## Problem Description

Given the head of a linked list, the task is to return the node where the cycle begins. If there is no cycle, the function should return `null`.

A cycle in a linked list occurs when there is a node in the list that can be reached again by continuously following the next pointer. The `pos` variable is used to denote the index of the node that the tail's next pointer is connected to (0-indexed). It is set to -1 if there is no cycle. Note that the `pos` value is not passed as a parameter.

## Example

Input: head = [3,2,0,-4], pos = 1

Output: tail connects to node index 1

Explanation: There is a cycle in the linked list, where the tail connects to the second node.

## Approach

To detect the cycle in the linked list and find the node where the cycle begins, we can use Floyd's Cycle-Finding Algorithm, also known as the "Tortoise and Hare Algorithm." The algorithm involves two pointers moving through the linked list at different speeds. If there is a cycle, the two pointers will eventually meet at the same node.

The algorithm can be implemented using the following steps:

1. Check if the list is empty or has only one node. If so, return `null`.
2. Initialize two pointers, `slow` and `fast`, both pointing to the head of the linked list.
3. Move the `slow` pointer by 1 step and the `fast` pointer by 2 steps in each iteration.
4. If the pointers meet (`slow == fast`), there is a cycle. Set a flag to indicate the presence of a cycle.
5. Reset the `slow` pointer to the head of the linked list.
6. Move both pointers at the same speed (1 step) until they meet again.
7. The meeting point will be the node where the cycle begins. Return this node.
8. If there is no cycle (the pointers never meet), return `null`.

## Implementation

The solution is implemented in C++ and provided in the `Solution` class. The `detectCycle` function takes the head of the linked list as input and returns the node where the cycle begins or `null`.

The solution follows the steps mentioned in the approach section. It uses two pointers, `slow` and `fast`, to detect the cycle and find the cycle start node.

To run the solution, instantiate the `Solution` class, create a linked list, and call the `detectCycle` function, passing the head of the linked list as an argument.

## Complexity Analysis

The time complexity of the solution is O(n), where n is the number of nodes in the linked list. The algorithm visits each node at most twice, once for cycle detection and once for finding the cycle start node.

The space complexity is O(1) as the solution uses a constant amount of extra space regardless of the input size.
Certainly! Here's an example of a README.md file for the "Remove Duplicates from Sorted List" problem:

# 83.Remove Duplicates from Sorted List

This is a solution to the "Remove Duplicates from Sorted List" problem. Given the head of a sorted linked list, the task is to delete all duplicates such that each element appears only once. The solution returns the updated linked list with duplicates removed and sorted.

### Example

Input:
```
[1, 1, 2]
```
Output:
```
[1, 2]
```

### Approach

To solve this problem, the following approach is used:

1. Check if the head is null or the next node is null. If true, return the head as it is.
2. Create a pointer named "current" and set it to the head of the list.
3. Iterate through the list while the current node and its next node are not null.
4. Check if the value of the current node is equal to the value of its next node.
   - If true, set the next node of the current node to the next node of its next node, effectively skipping the duplicate node.
   - If false, move the current node to its next node.
5. After the loop ends, return the head of the updated list.

The solution is implemented in C++.

### Implementation

The solution is implemented in C++ and the code can be found in the `solution.cpp` file.

To use the solution, instantiate a `Solution` object and call the `deleteDuplicates` method, passing the head of the sorted linked list as the parameter. The method will return the head of the updated list with duplicates removed.

```cpp
ListNode* deleteDuplicates(ListNode* head) {
    // Implementation
}
```

### Complexity Analysis

The solution has a time complexity of O(n), where n is the number of nodes in the linked list. This is because we iterate through the list once to remove the duplicates. The space complexity is O(1) as we use a constant amount of extra space.

Certainly! Here's a README.md file for the "Remove Duplicates from Sorted List II" problem:

# 82.Remove Duplicates from Sorted List II

This is a solution for the "Remove Duplicates from Sorted List II" problem. Given a sorted linked list, the task is to delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. The resulting linked list should also be sorted.

## Problem Statement

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

## Example

Input:
```
[1, 2, 3, 3, 4, 4, 5]
```

Output:
```
[1, 2, 5]
```

## Approach

To solve this problem, we can use two pointers, `prev` and `current`, to traverse the linked list. We iterate through the list and keep track of the nodes that have duplicate numbers. If a duplicate is found, we skip all the duplicate nodes. If no duplicates are found, we move the `prev` and `current` pointers forward.

To handle the case of duplicates at the beginning of the list, we create a dummy node that points to the head of the list. This simplifies the code by avoiding special cases.

The algorithm can be summarized as follows:

1. Initialize a dummy node that points to the head of the list.
2. Initialize `prev` and `current` pointers to the dummy node.
3. Iterate through the list while `current` is not null:
   - If `current` and `current->next` have different values, move `prev` and `current` pointers forward.
   - If `current` and `current->next` have the same value, skip all the duplicate nodes by updating the `prev->next` pointer.
4. Return the `dummy.next` pointer, which points to the head of the resulting list.

## Complexity Analysis

The time complexity of this solution is O(n), where n is the number of nodes in the linked list. We iterate through the list once. The space complexity is O(1) as we only use a constant amount of additional space.

## Summary

The "Remove Duplicates from Sorted List II" problem is solved by iterating through the linked list and skipping the nodes that have duplicate numbers. The solution maintains a `prev` and `current` pointer to handle the removal of duplicate nodes. The resulting linked list is returned and is sorted as well.

This problem can be solved using a simple and efficient algorithm, with a time complexity of O(n) and a space complexity of O(1).
Sure! Here's a sample `README.md` file explaining the problem and providing the solution code:

# 2. Add Two Numbers - Linked List

This problem involves adding two numbers represented by linked lists. The digits of each number are stored in reverse order, with each node of the linked list containing a single digit. The task is to add the two numbers and return the sum as a linked list.

## Example

Input:
```
l1 = [2,4,3]
l2 = [5,6,4]
```

Output:
```
[7,0,8]
```

Explanation: 342 + 465 = 807.

## Solution

The solution involves iterating over the linked lists simultaneously, adding the corresponding digits and keeping track of any carry. The `addTwoNumbers` function in the provided code implements this logic.

The steps of the solution are as follows:

1. Create a dummy node to track the result.
2. Initialize a current pointer to the dummy node.
3. Initialize a carry variable to 0.
4. Iterate over the linked lists while l1 or l2 or carry is non-zero.
   - Calculate the sum by adding the carry and the values of l1 and l2 nodes. If either list reaches its end, consider its value as 0.
   - Update the carry by dividing the sum by 10.
   - Create a new node with the value equal to the sum modulo 10 (the digit at the current position).
   - Move the current pointer to the next node.
   - Update l1 and l2 pointers to their next nodes if they are not at the end.
5. Return the next node of the dummy node, which represents the actual result.

To use the provided code, create a `ListNode` struct that represents a node in the linked list. The struct should have an `int` value and a `next` pointer to the next node. The code also requires the input linked lists `l1` and `l2` to be non-empty.

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Implementation of the addTwoNumbers function
    // ...
    // ...
}
```

You can then call the `addTwoNumbers` function with your desired inputs to get the result.

Feel free to use this solution code as a starting point for your implementation. Good luck!

