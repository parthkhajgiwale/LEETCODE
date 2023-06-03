# 02-06-23 Daily Challenge: Max Detonation 

This is the solution for the "Max Detonation" daily challenge, dated June 2, 2023. The challenge involves finding the maximum detonation size based on a given set of bomb coordinates.

## Problem Description

You are given a set of bombs represented by their coordinates and radius. Each bomb is represented as a triplet (x, y, r), where (x, y) are the coordinates of the bomb and r is its radius. The radius represents the distance from the bomb within which it can cause a detonation.

Your task is to determine the maximum number of bombs that can be detonated simultaneously. Two bombs can be detonated simultaneously if the square of the Euclidean distance between them is less than or equal to the square of the radius of at least one of the bombs.

## Solution

The provided solution uses a Depth-First Search (DFS) approach to find the maximum detonation. Here is an overview of the solution algorithm:

1. Create an empty graph, represented as a vector of vectors, where each index represents a bomb and its corresponding vector contains the indices of the bombs that can be detonated by it.

2. Iterate over each pair of bombs (i, j) in the given set, excluding cases where i and j are the same bomb.

3. Calculate the squared Euclidean distance between bombs i and j using the `squaredDist` function.

4. If the squared distance is less than or equal to the square of the radius of bomb i, add bomb j to the adjacency list of bomb i in the graph.

5. Initialize a variable `ans` to 0, which will store the maximum number of detonated bombs.

6. Iterate over each bomb i in the graph.

7. Create an unordered set `seen` and add bomb i to it.

8. Perform a DFS starting from bomb i, adding all reachable bombs to the `seen` set.

9. Update `ans` to the maximum value between `ans` and the size of the `seen` set.

10. Return the value of `ans`, which represents the maximum number of detonated bombs.

The `dfs` function performs a recursive DFS traversal of the graph, starting from a given bomb. It adds each visited bomb to the `seen` set and continues the DFS for all unvisited neighboring bombs.

The `squaredDist` function calculates the squared Euclidean distance between two bombs using their coordinates.

## Usage

To use the `Solution` class, follow these steps:

1. Create an instance of the `Solution` class.

2. Call the `maximumDetonation` method, passing in the vector of bomb coordinates as a parameter.

3. The method will return the maximum number of bombs that can be detonated simultaneously.

Example usage:

```cpp
vector<vector<int>> bombs = {
  {0, 0, 2},
  {1, 1, 3},
  {2, 2, 1}
};

Solution solution;
int maxDetonation = solution.maximumDetonation(bombs);
cout << "Maximum Detonation: " << maxDetonation << endl;
```

Output:

```
Maximum Detonation: 2
```

This indicates that the maximum number of bombs that can be detonated simultaneously is 2.

Note: The solution assumes that the necessary headers and libraries (such as `unordered_set`, `vector`, and `iostream`) are included separately.

# 03-06-23 Daily Challenge: Time Needed to Inform All Employees

## Problem Description

A company has `n` employees with a unique ID for each employee from 0 to `n - 1`. The head of the company is the one with `headID`.

Each employee has one direct manager given in the `manager` array where `manager[i]` is the direct manager of the `i`-th employee, and `manager[headID] = -1`. It is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The `i`-th employee needs `informTime[i]` minutes to inform all of their direct subordinates (i.e., After `informTime[i]` minutes, all their direct subordinates can start spreading the news).

You need to implement the `numOfMinutes` function, which will receive the following parameters:

- `n`: An integer representing the number of employees in the company.
- `headID`: An integer representing the ID of the head of the company.
- `manager`: A vector of integers representing the direct manager of each employee.
- `informTime`: A vector of integers representing the time taken by each employee to inform their direct subordinates.

The function should return the number of minutes needed to inform all the employees about the urgent news.

## Example

Input:
```
n = 1, headID = 0, manager = [-1], informTime = [0]
```

Output:
```
0
```

Explanation:
The head of the company is the only employee in the company.

## Solution

The solution uses a depth-first search (DFS) approach to traverse the employee tree and calculate the total time needed to inform all employees.

The algorithm follows these steps:

1. Create an adjacency list to represent the subordination relationships between employees.
2. Create a helper function, `dfs`, to perform the depth-first search.
3. Initialize a variable `maxTime` to keep track of the maximum time taken to inform all employees.
4. For the current employee, iterate through their direct subordinates using the adjacency list. For each subordinate, recursively call the `dfs` function, passing the subordinate's ID and the accumulated time.
5. During the recursive calls, update the `maxTime` variable if the accumulated time is greater than the current maximum.
6. After the DFS traversal is complete, return the `maxTime`.

The time complexity of this solution is O(n), where n is the number of employees. The space complexity is also O(n), considering the adjacency list used to represent the subordination relationships.

