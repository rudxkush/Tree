vector<int> rightSideView(TreeNode* root) {
   vector<int> ans;
   if (!root) return ans;
   unordered_map<int, int> mp; // row -> val
   queue<pair<TreeNode*, int>> q; // node, row
   int maxRow = 0;
   q.push({root, 0});
   while (!q.empty()) {
       auto [node, row] = q.front(); q.pop();
       maxRow = max(maxRow, row);
       if (mp.find(row) == mp.end())
           mp[row] = node->val;
       if (node->right)
           q.push({node->right, row + 1});
       if (node->left)
           q.push({node->left, row + 1});
   }

   for (int i = 0; i <= maxRow; i++) {
       ans.push_back(mp[i]);
   }
   return ans;
}
