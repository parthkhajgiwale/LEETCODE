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

