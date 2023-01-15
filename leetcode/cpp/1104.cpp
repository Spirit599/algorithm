class Solution {
public:
    vector<int> pathInZigZagTree(int label) {

    	vector<int> ans;
    	int maxn = 1;
    	while(maxn <= label)
    		maxn *= 2;
    	printf("maxn = %d\n", maxn);
    	
    	while(1)
    	{
    		ans.emplace_back(label);
    		label = label / 2;
    		if(label == 0)
    			break;
    		int base1 = maxn / 4;
    		int base2 = maxn / 2 - 1;
    		label = base2 + base1 - label;
    		maxn /= 2;
    	}

    	reverse(ans.begin(), ans.end());
    	return ans;
    }
};