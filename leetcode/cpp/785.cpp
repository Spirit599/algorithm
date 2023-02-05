class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

    	int n = graph.size();
    	int visColor[n];
    	memset(visColor, 0, sizeof(visColor));

    	function<bool(int, int)> isBip = [&](int cur, int color) {

    		visColor[cur] = color;
    		for(int next : graph[cur])
    		{
    			if(visColor[next] == color || (visColor[next] == 0 && !isBip(next, -color)))
    				return false;
    		}
    		return true;
    	};

    	for(int i = 0; i < n; ++i)
    	{
    		if(visColor[i] != 0)
    			continue;
    		if(!isBip(i, 1))
    			return false;
    	}
    	return true;
    }
};