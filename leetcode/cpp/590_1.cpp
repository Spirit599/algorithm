/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> ans;
public:

    void dfs(Node* p)
    {
        for(auto child : p->children)
        {
            dfs(child);
        }
        ans.push_back(p->val);
    }

    vector<int> postorder(Node* root) {
        if(!root)
            return ans;
        dfs(root);
        return ans;
    }
};