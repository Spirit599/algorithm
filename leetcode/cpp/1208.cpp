class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

    	int n = s.size();
    	vector<int> remain;
    	for(int i = 0; i < n; ++i)
    	{
    		remain.emplace_back(abs(s[i] - t[i]));
    	}


    	int ans = 0;
    	int curCost = 0;
    	int left = -1;
    	for(int right = 0; right < n; ++right)
    	{
    		curCost += remain[right];
    		while(left != right && curCost > maxCost)
    			curCost -= remain[++left];
    		ans = max(ans, right - left);
    	}
    	

    	return ans;

    }
};