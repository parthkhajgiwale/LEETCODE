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
