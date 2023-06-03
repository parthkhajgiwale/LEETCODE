class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }
        
        return dfs(headID, informTime, adjList);
    }
    
    int dfs(int currentEmployee, vector<int>& informTime, vector<vector<int>>& adjList) {
        int maxTime = 0;
        for (int subordinate : adjList[currentEmployee]) {
            maxTime = max(maxTime, dfs(subordinate, informTime, adjList));
        }
        return informTime[currentEmployee] + maxTime;
    }
};
