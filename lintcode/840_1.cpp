// 840 · 可变范围求和

void build_tree(vector<int>& nums, int* tree, int tree_index, int left, int right)
{
    if(left == right)
    {
        tree[tree_index] = nums[left];
        return ;
    }

    int left_index = 2 * tree_index + 1;
    int right_index = 2 * tree_index + 2;
    int mid = left + (right - left) / 2;

    build_tree(nums, tree, left_index, left, mid);
    build_tree(nums, tree, right_index, mid + 1, right);

    tree[tree_index] = tree[left_index] + tree[right_index];
}

void update_tree(int* tree, int tree_index, int left, int right, int update, int val)
{
    if(left == update && right == update)
    {
        tree[tree_index] = val;
    }
    else if(left > update || right < update)
    {
        return;
    }
    else
    {
        int left_index = 2 * tree_index + 1;
        int right_index = 2 * tree_index + 2;
        int mid = left + (right - left) / 2;

        update_tree(tree, left_index, left, mid, update, val);
        update_tree(tree, right_index, mid + 1, right, update, val);

        tree[tree_index] = tree[left_index] + tree[right_index];
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
        int left_index = 2 * tree_index + 1;
        int right_index = 2 * tree_index + 2;
        int mid = left + (right - left) / 2;

        int sum_left = query_tree(tree, left_index, left, mid, query_left, min(mid, query_right));
        int sum_right = query_tree(tree, right_index, mid + 1, right, max(mid + 1, query_left), query_right);

        return sum_left + sum_right;
    }
}

class NumArray {
public:
    int* tree = nullptr;
    int n = 0;
    NumArray(vector<int> nums) {
        
        n = nums.size();
        tree = (int*)malloc(sizeof(int) * 4 * n);
        build_tree(nums, tree, 0, 0, n - 1);
    }
    
    void update(int i, int val) {
        
        update_tree(tree, 0, 0, n - 1, i, val);
    }
    
    int sumRange(int i, int j) {
        
        return query_tree(tree, 0, 0, n - 1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */