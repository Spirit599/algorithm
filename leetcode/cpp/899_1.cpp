// 最小表示法

class Solution {
public:
    string orderlyQueue(string s, int k) {

    	if(k != 1)
    	{
    		sort(s.begin(), s.end());
    		return s;
    	}
    	else
    	{
    		int i = 0;
    		int j = 1;
    		int k = 0;
    		int n = s.size();
    		while(i < n && j < n && k < n)
    		{
    			printf("%d %d %d\n", i, j, k);
    			char a = s[(i + k) % n];
    			char b = s[(j + k) % n];
    			if(a != b)
    			{
    				if(a > b)
    					i += k + 1;
    				else
    					j += k + 1;
    				if(i == j)
    					++i;
    				k = 0;
    			}
    			else
    			{
    				++k;
    			}
    			printf("%d %d %d\n----------------\n", i, j, k);
    		}
    		i = min(i, j);
    		return s.substr(i) + s.substr(0, i);
    	}
    }
};