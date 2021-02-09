void _pre(TreeNode* node, vector<int> &acc, const int &l) {
    if (!node) return;
    
    if (acc.size() == l) {
        acc.push_back(node->val);
    }
    
    _pre(node->right, acc, l + 1);
    _pre(node->left, acc, l + 1);
}

vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    
    vector<int> acc{};
    
    _pre(root, acc, 0);
    
    return acc;
}