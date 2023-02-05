const int kbit = 5;
const int kBitMask = (1 << 5) - 1;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {

    	vector<int> cnt(batchSize);
    	for(int num : groups)
    		++cnt[num % batchSize];

    	long long mask = 0;
    	for(int i = batchSize - 1; i >= 1; --i)
    	{
    		mask = (mask << kbit) | cnt[i];
    	}

    	unordered_map<long long, int> memo;

    	function<int(long long)> dfs = [&](long long mask) -> int {

    		if(mask == 0)
    			return 0;
    		if(memo.count(mask))
    			return memo[mask];
    		
    		int tot = 0;
    		for(int i = 1; i < batchSize; ++i)
    		{
    			int amount = (mask >> (i - 1) * kbit) & kBitMask;
    			tot += amount * i;
    		}

    		int ret = 0;
    		for(int i = 1; i < batchSize; ++i)
    		{
    			int amount = (mask >> (i - 1) * kbit) & kBitMask;
    			if(amount > 0)
    			{
    				int result = dfs(mask - (1LL << ((i - 1) * kbit)));
    				if((tot - i) % batchSize == 0)
    					++result;
    				ret = max(ret, result);
    			}
    			
    		}

    		return memo[mask] = ret;
    	};

    	return dfs(mask) + cnt[0];
    }
};