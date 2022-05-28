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

//层序遍历
//队列

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        

        vector<vector<int>> ans;
        if(!root)
            return ans;     

        queue<Node*> que;
        que.push(root);
        
        while(!que.empty())
        {
            int level_num = que.size();
            vector<int> tmp;
            for (int i = 0; i < level_num; ++i)
            {
                Node* cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                for(auto son : cur->children)
                    que.push(son);
            }
            
            ans.push_back(tmp);
        }

        return ans;
    }
};