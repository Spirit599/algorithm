class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

    	vector<int> xcood;
    	for(auto& v : buildings)
    	{
    		xcood.emplace_back(v[0]);
    		xcood.emplace_back(v[1]);
    	}

    	sort(xcood.begin(), xcood.end());
    	int n = buildings.size();
    	int idx = 0;
    	priority_queue<pair<int, int>> pq;
    	vector<vector<int>> ans;
    	for(int x : xcood)
    	{
    		while(idx < n && buildings[idx][0] <= x)
    		{
    			pq.emplace(buildings[idx][2], buildings[idx][1]);
    			++idx;
    		}
    		while(!pq.empty() && pq.top().second <= x)
    			pq.pop();

    		int y = pq.empty() ? 0 : pq.top().first;

    		if(ans.empty() || ans.back()[1] != y)
    			ans.push_back({x, y});
    	}

    	return ans;
    }
};