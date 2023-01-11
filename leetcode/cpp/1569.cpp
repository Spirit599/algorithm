// struct TreeNode {
//     int val;
//     int size;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), size(1), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), size(1), left(nullptr), right(nullptr) {}
// };
class Solution {
public:
    int mod = 1e9 + 7;
    void BSTinsert(TreeNode* root, int val) {

        TreeNode* p = root;
        while(p)
        {
            if(val > p->val)
            {
                if(p->right == nullptr)
                {
                    p->right = new TreeNode(val);
                    return ;
                }
                p = p->right;
            }
            else
            {
                if(p->left == nullptr)
                {
                    p->left = new TreeNode(val);
                    return ;
                }
                p = p->left;
            }
        }
    }



    int numOfWays(vector<int>& nums) {

        int n = nums.size();
        if(n == 1)
            return 0;

        int c[n + 1][n + 1];
        memset(c, 0, sizeof(c));
        c[0][0] = 1;
        for(int i = 1; i <= n; ++i)
        {
            c[i][0] = 1;
            for(int j = 1; j <= min(i, n); ++j)
            {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }

        TreeNode* root = new TreeNode(nums[0]);
        for(int i = 1; i < n; ++i)
            BSTinsert(root, nums[i]);

        function<pair<long long, int>(TreeNode*)> dfs = [&] (TreeNode* p) -> pair<long long, int> {

        if(!p)
            return make_pair(1, 0);

        auto [llans, llsize] = dfs(p->left);
        auto [rrans, rrsize] = dfs(p->right);
        int allSize = llsize + rrsize;
        return make_pair(llans * rrans % mod * c[allSize][llsize] % mod, allSize + 1);
    };



        return (dfs(root).first - 1 + mod) % mod;
    }
};