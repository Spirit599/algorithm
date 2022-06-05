//929. 独特的电子邮件地址
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

    	unordered_set<string> memo;
    	for(const auto& email : emails)
    	{
    		string user;
    		for(char c : email)
    		{
    			if(c == '+' || c == '@')
    				break;
    			else if(c != '.')
    				user.push_back(c);
    		}
    		memo.emplace(user + email.substr(email.find('@')));
    	}

    	return memo.size();
    }
};