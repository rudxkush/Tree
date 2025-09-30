class Solution {
public:
    int res = 0; 

    int dfs(vector<vector<int>>& graph, int node, int parent) {
        int longest = 0, secondLongest = 0;

        for (auto nei : graph[node]) {
            if (nei == parent) continue;
            int len = dfs(graph, nei, node); 
          
            if (len > secondLongest) {
                secondLongest = len;
            }
            if (secondLongest > longest) {
                swap(longest, secondLongest);
            }
        }
        res = max(res, longest + secondLongest);

        return 1 + longest;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs(graph, 0, -1);
        return res;
    }
};
