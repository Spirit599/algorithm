// 2374. 边积分最高的节点

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        int n = edges.size();
        long long cnt[n];
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; ++i)
        	cnt[edges[i]] += i;

        int ans = -1;
        int maxx = 0;
        for(int i = 0; i < n; ++i)
        {
        	printf("%d\n", cnt[i]);
        	if(cnt[i] > maxx)
        	{
        		ans = i;
        		maxx = cnt[i];
        	}
        }

        return ans;
    }
};