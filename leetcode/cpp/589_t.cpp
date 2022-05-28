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
        if(p){
            ans.push_back(p->val);

            for(Node* child : p->children)
                dfs(child);
        }

    }
    vector<int> preorder(Node* root) {
        
        dfs(root);

        return ans;
    }
};