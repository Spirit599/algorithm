class Solution {
public:
	struct maxx
	{
		int __1st;
		int __2nd;
	};
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int, maxx> memo;
        for(int num : nums)
        {
        	int key = 0;
        	int num_copy = num;
        	while(num)
        	{
        		key += num % 10;
        		num = num / 10;
        	}

        	auto it = memo.find(key);
        	if(it == memo.end())
        	{
        		memo[key].__1st = num_copy;
        		memo[key].__2nd = 0;
        	}
        	else
        	{
        		if(num_copy > it->second.__1st)
        		{
        			it->second.__2nd = it->second.__1st;
        			it->second.__1st = num_copy;
        		}
        		else if(num_copy > it->second.__2nd)
        		{
        			it->second.__2nd = num_copy;
        		}
        	}
        }

        int ans = -1;
        for(auto& kav : memo)
        {
        	if(kav.second.__2nd == 0)
        		continue;
        	ans = max(ans, kav.second.__1st + kav.second.__2nd);
        }

        return ans;
    }
};