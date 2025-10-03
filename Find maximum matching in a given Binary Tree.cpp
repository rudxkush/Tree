int rec(vector<vector<int>>& tree, int node, int parent, bool parentPick) {
    int count = 0;

    if(parentPick) {
        for(auto nei : tree[node]) {
            if(nei == parent) continue;
            count += rec(tree, nei, node, false);
        }
    } else {
        int notPick = 0;
        for(auto nei : tree[node]) {
            if(nei == parent) continue;
            notPick += rec(tree, nei, node, false);
        }

        int best = notPick;
        for(auto nei : tree[node]) {
            if(nei == parent) continue;
            int pick = 1 + rec(tree, nei, node, true) + (notPick - rec(tree, nei, node, false));
            best = max(best, pick);
        }
        count = best;
    }

    return count;
}
int maxNonAdjEdges(int n, vector<vector<int>>& edges) {
    vector<vector<int>> tree(n);
    for(auto edge : edges) {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }
    return rec(tree, 0, -1, false);
}
