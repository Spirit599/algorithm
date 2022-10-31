class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector<string> ans;
        int n = queries[0].size();
        for(string& query : queries)
        {
            bool ok = false;
            for(string& dict : dictionary)
            {
                int dif = 0;
                for(int i = 0; i < n; ++i)
                {
                    if(query[i] != dict[i])
                    {
                        ++dif;
                        if(dif > 2)
                            break;
                    }
                }
                if(dif <= 2)
                    ok = true;
            }
            if(ok)
                ans.push_back(query);
        }
        return ans;
    }
};