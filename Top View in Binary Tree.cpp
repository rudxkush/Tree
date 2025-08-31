vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if (!root)
        return ans;
    map<int, int> mp;              // line, value
    queue<pair<TreeNode*, int>> q; // node, line (column)
    q.push({root, 0});
    int minLine = 0, maxLine = 0;
    while (!q.empty()) {
        auto [node, line] = q.front();
        q.pop();

        if (mp.find(line) == mp.end())
            mp[line] = node->val;

        if (node->left)
            q.push({node->left, line - 1});

        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : mp) {
        ans.push(it.second);
    }
    return ans;
}
