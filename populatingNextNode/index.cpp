Node* connect(Node* root) {
    if (!root) {
        return nullptr;
    }
    
    queue<Node*> q;
    q.push(root);
    
    int s = -1;
    Node* t = nullptr;
    Node* tx = nullptr;
    
    while (!q.empty()) {
        s = q.size();
        
        while (s) {
            t = q.front();
            q.pop();
            
            if (t->right) {
                q.push(t->right);
            }
            
            if (t->left) {
                q.push(t->left);
            }
            
            t->next = tx;
            tx = t;
            --s;
        }
        
        tx = nullptr;
    }
    
    return root;
}