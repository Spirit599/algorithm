class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

    	vector<int> stk;
    	vector<int> ans;
    	for(int num : asteroids)
    	{
    		if(num < 0)
    		{
    			bool isLive = true;
    			while(!stk.empty() && stk.back() <= -num)
    			{
    				int pval = stk.back();
    				stk.pop_back();
    				if(pval == -num)
    				{
    					isLive = false;
    					break;
    				}
    			}
    			if(stk.empty() && isLive)
    				ans.emplace_back(num);
    		}
    		else
    		{
    			stk.emplace_back(num);
    		}
    	}

    	ans.insert(ans.end(), stk.begin(), stk.end());
    	return ans;
    }
};