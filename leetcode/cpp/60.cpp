class Solution {
public:
    string getPermutation(int n, int k) {

    	int f[10];
    	f[0] = 1;
    	for(int i = 1; i < 10; ++i)
    		f[i] = f[i - 1] * i;

    	bool vis[n + 1];
    	memset(vis, 0, sizeof(vis));
    	string ans;

    	for(int i = 0; i < n; ++i)
    	{
    		int behind = f[n - i - 1];
    		int kth = (k - 1) / behind + 1;
    		int idx = 1;
    		printf("kth = %d\n", kth);
			for(; idx <= n; ++idx)
			{
				if(!vis[idx])
				{
					--kth;
					if(kth == 0)
						break;
				}
			}

    		k %= behind;
    		if(k == 0)
    			k = behind;
    		vis[idx] = true;
    		ans.push_back(idx + '0');
    	}

    	return ans;
    }
};