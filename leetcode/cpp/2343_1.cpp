class Solution {
public:
	struct num_index
	{
		string num;
		int index;
	};
	struct cmp_num_index
	{
		bool operator() (const num_index& p1, const num_index& p2)
		{
			if(p1.num != p2.num)
				return p1.num < p2.num;
			else
				return p1.index < p2.index;
		}
	};
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        unordered_map<int, vector<num_index>> memo;

        for(auto& query : queries)
        {
        	int key = query[1];
        	int kth = query[0];
        	
        	auto it = memo.find(key);
        	if(it == memo.end())
        	{
        		vector<num_index> cur;
        		for(int index = 0; index < nums.size(); ++index)
        		{
        			string num = nums[index].substr(nums[index].size() - key);
        			cur.push_back({num, index});
        		}

        		sort(cur.begin(), cur.end(), cmp_num_index());
        		memo[key] = cur;
        	}

        	ans.push_back(memo[key][kth - 1].index);
        }

        return ans;
    }
};