void mapOutParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
    if (root == NULL) return;

    if (root->left != NULL) {
        mp[root->left] = root;
        mapOutParents(root->left, mp);
    }
    if (root->right != NULL) {
        mp[root->right] = root;
        mapOutParents(root->right, mp);
    }
}

void printKdistantNode(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    parentMap[root] = NULL;
    mapOutParents(root, parentMap);

    // BFS from target
    unordered_map<TreeNode*, bool> visited;
    queue<pair<TreeNode*, int>> q;
    q.push({target, 0});
    visited[target] = true;

    while (!q.empty()) {
        auto [node, dist] = q.front(); q.pop();

        if(dist == k) 
		cout << node->val << endl;
		
	   if(dist < k) {
	   	if(parentMap[node] != NULL && !visited[parentMap[node]]) {
			q.push({parentMap[node], dist + 1});
			visited[parentMap[node]] = true;
}
if(node->left != NULL && !visited[node->left]) {
	q.push({node->left, dist + 1});
			visited[node->left] = true;
}
if(node->right != NULL && !visited[node->right]) {
	q.push({node->right, dist + 1});
			visited[node->right] = true;
}
   }
    }
}
