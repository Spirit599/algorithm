// 剑指 Offer II 119. 最长连续序列

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    	unordered_set<int> memo;
    	for(int num : nums)
    		memo.insert(num);

    	int ans = 0;
    	for(auto& key : memo)
    	{
    		if(memo.count(key - 1))
    			continue;
    		int cnt = 1;
    		int x = key + 1;
    		while(1)
    		{
    			if(memo.count(x))
    			{
    				++x;
    				++cnt;
    			}
    			else
    			{
    				break;
    			}
    		}
    		ans = max(ans, cnt);
    	}

    	return ans;
    }
};