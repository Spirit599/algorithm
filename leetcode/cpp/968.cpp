/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct status
    {
        int a; //节点有摄像头 
        int b; //可以覆盖
        int c; //至少覆盖两个子树
    };
    int minCameraCover(TreeNode* root) {

        int inf = 0x3f3f3f3f;

        function<status(TreeNode*)> dfs = [&](TreeNode* cur) -> status {

            if(cur == nullptr)
                return {inf, 0, 0};

            status retLeft = dfs(cur->left);
            status retRight = dfs(cur->right);
            int a = 1 + retLeft.c + retRight.c;
            int b = min(a, min(retLeft.b + retRight.a, retLeft.a + retRight.b));
            int c = min(b, retLeft.b + retRight.b);

            return {a, b, c};
        };

        return dfs(root).b;
    }
};