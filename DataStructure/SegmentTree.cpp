void build_tree(vector<int>& nums, int* tree, int tree_index, int num_left, int num_right)
{
    if(num_left == num_right)
    {
        tree[tree_index] = nums[num_left];
    }
    else
    {
        int tree_left = tree_index * 2 + 1;
        int tree_right = tree_index * 2 + 2;
        int num_mid = (num_right - num_left) / 2 + num_left;

        build_tree(nums, tree, tree_left, num_left, num_mid);
        build_tree(nums, tree, tree_right, num_mid + 1, num_right);

        tree[tree_index] = tree[tree_left] + tree[tree_right];
    }

}

int query_tree(int* tree, int tree_index, int num_left, int num_right,
                                                            int query_left, int query_right)
{
    if(query_left > num_right || query_right < num_left)
    {
        return 0;
    }
    else if(query_left == num_left && query_right == num_right)
    {
        return tree[tree_index];
    }
    else
    {
        int tree_left = tree_index * 2 + 1;
        int tree_right = tree_index * 2 + 2;
        int num_mid = (num_right - num_left) / 2 + num_left;
    
        int sum_left = query_tree(tree, tree_left, num_left, num_mid, query_left, min(query_right, num_mid));
        int sum_right = query_tree(tree, tree_right, num_mid + 1, num_right, max(query_left, num_mid + 1), query_right);
        
        return sum_left + sum_right;
    }
}

void update_tree(int* tree, int tree_index, int num_left, int num_right,
                                                            int update_index, int val)
{
    
    if(num_left == update_index && update_index == num_right)
    {
        tree[tree_index] = val;
    }
    else if(update_index > num_right || update_index < num_left)
    {
        return ;
    }
    else
    {

        int tree_left = tree_index * 2 + 1;
        int tree_right = tree_index * 2 + 2;
        int num_mid = (num_right - num_left) / 2 + num_left;
        update_tree(tree, tree_left, num_left, num_mid, update_index, val);
        update_tree(tree, tree_right, num_mid + 1, num_right, update_index, val);

        tree[tree_index] = tree[tree_left] + tree[tree_right];
    }
}