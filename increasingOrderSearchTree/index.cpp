class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nodes;
        this->inorder_traversal(root, nodes);
        TreeNode* new_head = new TreeNode();
        TreeNode* curr_node = new_head;
        
        for (const auto &n : nodes) {
            curr_node->right = new TreeNode(n);
            curr_node = curr_node->right;
        }
        
        return new_head->right;
    }
    
    void inorder_traversal(TreeNode* curr_node, vector<int> &nodes) {
        if (curr_node == nullptr) {
            return;
        }
        
        this->inorder_traversal(curr_node->left, nodes);
        nodes.push_back(curr_node->val);
        this->inorder_traversal(curr_node->right, nodes);
    }
};