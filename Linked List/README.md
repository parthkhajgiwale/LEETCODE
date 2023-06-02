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
