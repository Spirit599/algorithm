// 2337. 移动片段得到字符串
// 双指针

class Solution {
public:
    bool canChange(string start, string target) {
        
        int n = start.size();
        int i = 0;
        int j = 0;

        
        while(i < n)
        {
        	if(start[i] == 'L')
        	{
        		while(j < n && target[j] != 'L')
        		{
        			if(target[j] == 'R')
        				return false;
        			++j;
        		}
        		if(j == n || i < j)
        			return false;
        		++j;
        	}
        	else if(start[i] == 'R')
        	{
        		while(j < n && target[j] != 'R')
        		{
        			if(target[j] == 'L')
        				return false;
        			++j;
        		}
        		if(j == n || i > j)
        			return false;
        		++j;
        	}
        	++i;
        }

        while(j < n)
        {
        	if(target[j] != '_')
        		return false;
        	++j;
        }

        return true;
    }
}