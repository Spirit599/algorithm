class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        unordered_map<string, int> memo;
        int n = messages.size();
        string ans;
        int maxx = 0;
        for(int i = 0; i < n; ++i)
        {
            int k = 0;
            istringstream stream(messages[i]);
            string cur;
            while(stream >> cur)
                ++k;
            memo[senders[i]] += k;
            if(memo[senders[i]] > maxx)
            {
                maxx = memo[senders[i]];
                ans = senders[i];
            }
            else if(memo[senders[i]] == maxx)
            {
                ans = max(ans, senders[i]);
            }
        }
        return ans;
    }
};