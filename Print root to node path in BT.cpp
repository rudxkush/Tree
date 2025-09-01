vector<vector<int>> res;

void recBacktrack(TreeNode* root, vector<int>& possiblePath) {
    if(root == NULL) return;

    // include current node
    possiblePath.push_back(root->data);

    // if leaf, save the path
    if(root->left == NULL && root->right == NULL) {
        res.push_back(possiblePath);
    } else {
        if(root->left) recBacktrack(root->left, possiblePath);
        if(root->right) recBacktrack(root->right, possiblePath);
    }

    // backtrack
    possiblePath.pop_back();
}

vector<vector<int>> allRootToLeaf(TreeNode* root) {
    vector<int> possiblePath;
    recBacktrack(root, possiblePath);
    return res;
}
