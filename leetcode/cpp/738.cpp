class Solution {
public:
    int monotoneIncreasingDigits(int n) {

    	string num(to_string(n));

    	int m = num.size();
    	int cIdx = -1;
    	int pre = 10;
    	for(int i = m - 1; i >= 0; --i)
    	{
    		int cur = num[i] - '0';
    		if(cur > pre)
    		{
    			cIdx = i;
    			pre = cur - 1;
    		}
    		else
    		{
    			pre = cur;
    		}
    	}

    	printf("%d\n", cIdx);
    	if(cIdx != -1)
    	{
    		--num[cIdx];
    		for(int i = cIdx + 1; i < m; ++i)
    			num[i] = '9';
    	}

    	return stoi(num);
    }
};