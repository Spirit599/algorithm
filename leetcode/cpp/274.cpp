class Solution {
public:
    int hIndex(vector<int>& citations) {

    	sort(citations.begin(), citations.end(), greater<int>());

    	int ans = 0;
    	int n = citations.size();
    	for(int i = 0; i < n; ++i)
    	{
    		int cnt = i + 1;
    		if(cnt <= citations[i])
    		{
    			ans = cnt;
    		}
    		else
    			return ans;
    	}
    	return ans;
    }
};