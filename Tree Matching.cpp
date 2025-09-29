#include <bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
int dp[200001][2];  

void solve(int src, int par) {
    vector<int> prefix, suffix;
    dp[src][0] = dp[src][1] = 0;

    bool leaf = true;
    for (int child : tree[src]) {
        if (child != par) {
            leaf = false;
            solve(child, src);
        }
    }

    if (leaf) return;

    for (int child : tree[src]) {
        if (child == par) continue;
        prefix.push_back(max(dp[child][0], dp[child][1]));
        suffix.push_back(max(dp[child][0], dp[child][1]));
    }

    for (int i = 1; i < (int)prefix.size(); i++) prefix[i] += prefix[i - 1];
    for (int i = (int)suffix.size() - 2; i >= 0; i--) suffix[i] += suffix[i + 1];

    dp[src][0] = suffix[0];

    int idx = 0;
    for (int child : tree[src]) {
        if (child == par) continue;

        int left = (idx == 0) ? 0 : prefix[idx-1];
        int right = (idx == (int)suffix.size() - 1) ? 0 : suffix[idx + 1];

        dp[src][1] = max(dp[src][1], 1 + left + right + dp[child][0]);
        idx++;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    solve(1,0);
    cout << max(dp[1][0], dp[1][1]);
}

// Another approach (Simple & Equally complex as the above solution)
#include <bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
set<int> st;

void dfs(int node, int parent) {
    for (int child : tree[node]) {
        if (child == parent) continue;
        dfs(child, node);
    }

    // if both node and parent are not already covered
    if (parent != 0 && st.find(node) == st.end() && st.find(parent) == st.end()) {
        st.insert(node);
        st.insert(parent);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);
    cout << st.size() / 2;
}
