class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

    	string ans;
    	unordered_map<string, string> memo;
    	for(auto& Vstr : knowledge)
    		memo[Vstr[0]] = Vstr[1];
    	
    	bool leftH = false;
    	string key;
    	
    	for(char c : s)
    	{
    		if(c == '(')
    		{
    			leftH = true;
    		}
    		else if(c == ')')
    		{
    			leftH = false;
    			auto it = memo.find(key);
    			if(it != memo.end())
    			{
    				ans.append(it->second);
    			}
    			else
    			{
    				ans.push_back('?');
    			}
    			key = "";
    		}
    		else
    		{
    			if(leftH)
    				key.push_back(c);
    			else
    				ans.push_back(c);
    		}
    	}

    	return ans;
    }
};