class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        unordered_map<string, int> memo;

        string cur;
        for(char c : paragraph)
        {

            if(c >= 'A' && c <= 'Z')
            {
                c += 'a' - 'A';
                cur.push_back(c);
            }
            else if(c == ' ' ||
                    c == '!' ||
                    c == '?' ||
                    c == ',' ||
                    c == ';' ||
                    c == '\'' ||
                    c == '.')
            {
                if(cur != "")
                    ++memo[cur];
                cur = "";
            }
            else
            {
                cur.push_back(c);
            }
        }
        if(cur != "")
            ++memo[cur];

        for(string& str : banned)
            memo.erase(str);

        string ans;
        int maxx = 0;
        for(auto& kav : memo)
        {
            //cout<<kav.first<<" "<<kav.second<<endl;
            if(kav.second > maxx)
            {
                maxx = kav.second;
                ans = kav.first;
            }
        }

        return ans;

    }
};