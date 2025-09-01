void sparsePrint(TreeNode* root) {
	queue<TreeNode*> q;
 	bool flag = false;
	q.push(root);
	vector<vector<int>> sparseMatrix;
	while(!q.empty()) {
		int n = q.size();
		vector<int> level; 
		while(n) {
			TreeNode* node = q.front(); 
			q.pop();
			level.push_back(node->val);
			if(node->left != NULL) q.push(node->left);
			if(node->right != NULL) q.push(node->right);
			n–-;
    }
    if(flag == 1) reverse(level.begin(), level.end()); 
            sparseMatrix.push_back(level);
          flag = !flag;
    }

  for(auto &row : sparseMatrix) {
    for(int val : row) cout << val << " ";
        cout << "\n";
    }
}

