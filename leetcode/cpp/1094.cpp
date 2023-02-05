class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

    	vector<pair<int, int>> vpii;
    	for(auto& trip : trips)
    	{
    		vpii.emplace_back(trip[1], trip[0]);
    		vpii.emplace_back(trip[2], -trip[0]);
    	}
    	sort(vpii.begin(), vpii.end());
    	int cur = 0;
    	for(auto& [x, y] : vpii)
    	{
    		cur += y;
    		if(cur > capacity)
    			return false;
    	}
    	return true;
    }
};