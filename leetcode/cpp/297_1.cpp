//297. 二叉树的序列化与反序列化

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ret;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();

            if(cur)
            {
                ret += to_string(cur->val);
                que.push(cur->left);
                que.push(cur->right);
            }
            else
            {
                ret.push_back('#');
            }
            ret.push_back(' ');

        }

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        

        istringstream stream(data);
        string str_head;
        stream >> str_head;
        if(str_head != "#")
        {
            TreeNode* head = new TreeNode(atoi(str_head.c_str()));
            queue<TreeNode*> que;
            que.push(head);

            while(!que.empty())
            {
                TreeNode* cur = que.front();
                que.pop();

                if(cur)
                {
                    string str_left;
                    stream >> str_left;
                    if(str_left != "#")
                    {
                        cur->left = new TreeNode(atoi(str_left.c_str()));
                        que.push(cur->left);
                    }

                    string str_right;
                    stream >> str_right;
                    if(str_right != "#")
                    {
                        cur->right = new TreeNode(atoi(str_right.c_str()));
                        que.push(cur->right);
                    }

                }
            }

            return head;
        }
        else
        {
            return nullptr;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));