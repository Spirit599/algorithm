class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int ans;
        for (string str : words)
        {
        	if(str.size() < pref.size())
        		continue;
        	int i = 0;
        	for (i; i < pref.size(); ++i)
        	{
        		if(str[i] != pref[i])
        			break;
        	}
        	if(i == pref.size())
        		++ans;
        }

        return ans;
    }
};