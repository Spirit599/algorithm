class Solution {
public:
	struct info
	{
		int index;
		int dis1;
		int dis2;
	};

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        info check[n];
        
        memset(check, 0, sizeof(check));
        // check[node1] = {node1, 1, 0};
        // check[node2] = {node2, 0, 1};
        queue<info> que1;
        que1.push({node1, 1, 0});
        while(!que1.empty())
        {
        	info cur = que1.front();
        	check[cur.index].index = cur.index;
        	check[cur.index].dis1 = cur.dis1;
        	que1.pop();
        	if(edges[cur.index] != -1 && !check[edges[cur.index]].dis1)
        	{
        		info next = {edges[cur.index], cur.dis1 + 1, -1};
        		que1.push(next);
        	}

        }
        

        queue<info> que2;
        que2.push({node2, 0, 1});
        while(!que2.empty())
        {
        	info cur = que2.front();
        	check[cur.index].index = cur.index;
        	check[cur.index].dis2 = cur.dis2;
        	que2.pop();
        	if(edges[cur.index] != -1 && !check[edges[cur.index]].dis2)
        	{
        		info next = {edges[cur.index], -1, cur.dis2 + 1};
        		que2.push(next);
        	}
        }
        for(int i = 0; i < n; ++i)
        	printf("%d %d %d\n", check[i].index, check[i].dis1, check[i].dis2);

        int ans = n;
        int minn = 0x3f3f3f3f;
        for(int i = 0; i < n; ++i)
        {
        	if(check[i].dis1 && check[i].dis2)
        	{
        		if(max(check[i].dis1, check[i].dis2) < minn)
        		{
        			minn = max(check[i].dis1, check[i].dis2);
        			ans = i;
        		}
        	}
        }

        if(minn != 0x3f3f3f3f)
        	return ans;
        return -1;
    }
};