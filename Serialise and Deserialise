class laSerialDeSerial {
public:
    string serialise(TreeNode* root) {
        if (!root) return "#";

        queue<TreeNode*> q;
        q.push(root);
        string tree;

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node == NULL) {
                tree += "#,";
                continue;
            }
            tree += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return tree;
    }

    TreeNode* deSerialise(string& tree) {
        if (tree == "#") return NULL;

        stringstream ss(tree);
        string val;
        getline(ss, val, ',');  // root value

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            // Left child
            if (getline(ss, val, ',')) {
                if (val != "#") {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }

            // Right child
            if (getline(ss, val, ',')) {
                if (val != "#") {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
