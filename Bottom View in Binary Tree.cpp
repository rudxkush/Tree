vector<int> bottomView(TreeNode* root) {
	  vector<int> ans;
    if (!root) 
        return ans;
	  unordered_map<int, int> mp; // line, value
    queue<pair<TreeNode*, int>> q; // node, line (column)
    q.push({root, 0});
    int minLine = 0, maxLine = 0;
    while(!q.empty()) {
	      auto [node, line] = q.front(); q.pop();
        mp[line] = node->val;
        
        minLine = min(minLine, line);
        maxLine = max(maxLine, line);
	      if(node->left) 
		        q.push({node->left, line - 1});

		    if(node->right) 
		        q.push({node->right, line + 1});

    }
    for(int i = minLine; i <= maxLine; ++i) {
        ans.push(it.second);
    }
	return ans;
}

