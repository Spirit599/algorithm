// 315. 计算右侧小于当前元素的个数
// 线段树

void build_tree(int* tree, int tree_index, int left, int right)
{
    if(left == right)
    {
        tree[tree_index] = 0;
        return ;
    }

    int mid = (right - left) / 2 + left;
    int tree_left = 2 * tree_index + 1;
    int tree_right = 2 * tree_index + 2;

    build_tree(tree, tree_left, left, mid);
    build_tree(tree, tree_right, mid + 1, right);

    tree[tree_index] = tree[tree_left] + tree[tree_right];
}

void update_tree(int* tree, int tree_index, int left, int right, int index)
{
    if(left == index && right == index)
    {
        ++tree[tree_index];
    }
    else if(left > index || right < index)
    {
        return;
    }
    else
    {
        int mid = (right - left) / 2 + left;
        int tree_left = 2 * tree_index + 1;
        int tree_right = 2 * tree_index + 2;

        update_tree(tree, tree_left, left, mid, index);
        update_tree(tree, tree_right, mid + 1, right, index);

        tree[tree_index] = tree[tree_left] + tree[tree_right];
    }
}

int query_tree(int* tree, int tree_index, int left, int right, int query_left, int query_right)
{
    if(left == query_left && right == query_right)
        return tree[tree_index];
    else if(left > query_right || right < query_left)
        return 0;
    else
    {
        int mid = (right - left) / 2 + left;
        int tree_left = 2 * tree_index + 1;
        int tree_right = 2 * tree_index + 2;

        int left_sum = query_tree(tree, tree_left, left, mid, query_left, min(mid, query_right));
        int right_sum = query_tree(tree, tree_right, mid + 1, right, max(mid + 1, query_left), query_right);

        return left_sum + right_sum;
    }
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        vector<int> ranked(nums);
        sort(ranked.begin(), ranked.end());
        map<int, int> memo;
        int n = nums.size();
        int rankk = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i > 0 && ranked[i] == ranked[i - 1])
                ;
            else
                memo[ranked[i]] = rankk;
            ++rankk;
        }

        for(int i = 0; i < n; ++i)
        {
            nums[i] = memo[nums[i]];
        }

        int tree[4 * n];
        build_tree(tree, 0, 0, n - 1);

        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i)
        {
            ans[i] = query_tree(tree, 0, 0, n - 1, 0, nums[i] - 1);
            update_tree(tree, 0, 0, n - 1, nums[i]);
        }

        return ans;
    }
};