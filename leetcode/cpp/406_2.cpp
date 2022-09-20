// 406. 根据身高重建队列
// 线段树
bool cmp(const vector<int>& v1, const vector<int>& v2)
{
	if(v1[0] != v2[0])
		return v1[0] < v2[0];
	else
		return v1[1] > v2[1];
}

class Solution {
public:
	int* segMentTree;
	void build_tree(int treeIndex, int left, int right) {

		if(left == right)
		{
			segMentTree[treeIndex] = 1;
			return ;
		}
		else {

			int mid = (left + right) >> 1;
			int leftIndex = 2 * treeIndex + 1;
			int rightIndex = 2 * treeIndex + 2;

			build_tree(leftIndex, left, mid);
			build_tree(rightIndex, mid + 1, right);

			segMentTree[treeIndex] = segMentTree[leftIndex] + segMentTree[rightIndex];
		}


	}
	int query(int treeIndex, int left, int right, int sum) {
		//printf("%d %d %d %d %d\n", left, right, treeIndex, sum, segMentTree[treeIndex]);
        if(sum == segMentTree[treeIndex] && left == right)
            return right;
		int leftIndex = 2 * treeIndex + 1;
		int rightIndex = 2 * treeIndex + 2;
        int mid = (left + right) >> 1;
        int leftSum = segMentTree[leftIndex];
        if(sum <= leftSum)
            return query(leftIndex, left, mid, sum);
        else
            return query(rightIndex, mid + 1, right, sum - leftSum);

	}
    void modify(int treeIndex, int left, int right, int updateIndex, int val)
    {
        //printf("%d %d %d %d\n", left, right, treeIndex, updateIndex);
        if(left == updateIndex && right == updateIndex)
        {
            segMentTree[treeIndex] = val;
            return ;
        }
        else if(left > updateIndex || right < updateIndex)
            return ;

        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;

        modify(leftIndex, left, mid, updateIndex, val);
        modify(rightIndex, mid + 1, right, updateIndex, val);

        segMentTree[treeIndex] = segMentTree[leftIndex] + segMentTree[rightIndex];
        
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

    	int n = people.size();
    	segMentTree = (int*)malloc(sizeof(int) * 4 * n);
    	memset(segMentTree, 0, sizeof(int) * 4 * n);
    	build_tree(0, 0, n - 1);
    	
    	sort(people.begin(), people.end(), cmp);

    	vector<vector<int>> ans(n);
    	for(auto& vec : people)
    	{
    		int k = vec[1] + 1;
    		int index = query(0, 0, n - 1 ,k);
            modify(0, 0, n - 1, index, 0);
    		//printf("%d %d %d\n",vec[0], vec[1], index);
            ans[index] = vec;
    	}

    	return ans;
    	
    }
};