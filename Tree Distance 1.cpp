#include <bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
int depth[200001], answer[200001];

void computeDepth(int node, int parent) {
    int maxDepth = 0;
    for (int child : tree[node]) {
        if (child != parent) {
            computeDepth(child, node);
            maxDepth = max(maxDepth, 1 + depth[child]);
        }
    }
    depth[node] = maxDepth;
}

void computeAnswer(int node, int parent, int parentContribution) {
    vector<int> prefixMax, suffixMax;

    for (int child : tree[node])
        if (child != parent)
            prefixMax.push_back(depth[child]), suffixMax.push_back(depth[child]);

    for (int i = 1; i < (int)prefixMax.size(); i++)
        prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);

    for (int i = (int)suffixMax.size() - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i], suffixMax[i + 1]);

    int idx = 0;
    for (int child : tree[node]) {
        if (child != parent) {
            int left = (idx == 0) ? INT_MIN : prefixMax[idx - 1];
            int right = (idx == (int)suffixMax.size() - 1 ? INT_MIN : suffixMax[idx + 1]);
            int contribution = 1 + max(parentContribution, max(left, right));
            computeAnswer(child, node, contribution);
            idx++;
        }
    }

    answer[node] = 1 + max(parentContribution, prefixMax.empty() ? -1 : prefixMax.back());
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    computeDepth(1, 0);
    computeAnswer(1, 0, -1);

    for (int i = 1; i <= n; i++)
        cout << answer[i] << ' ';
    cout << '\n';
    return 0;
}
