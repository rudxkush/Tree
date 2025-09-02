// leftChildIndex = 2*i + 1
// rightChildIndex =  2*i + 2
int maximumWidthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int size = q.size();
  unsigned long long leftIndex = q.front().second;      
  unsigned long long rightIndex = q.back().second;   
  
        maxWidth = max(maxWidth, (int)(rightIndex - leftIndex + 1));

        for (int i = 0; i < size; i++) {
            auto [node, index] = q.front(); 
            q.pop();
            // Normalize index to avoid overflow
            index -= leftIndex;
            if (node->left)  q.push({node->left, 2*index + 1});
            if (node->right) q.push({node->right, 2*index + 2});
        }
    }

    return maxWidth;
}
