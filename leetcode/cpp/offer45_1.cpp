bool cmp(const string& str1, const string& str2)
{
    return (str1 + str2) < (str2 + str1);
}

class Solution {
public:
    string minNumber(vector<int>& nums) {

        vector<string> vstr;
        for(int num : nums)
            vstr.push_back(to_string(num));
    
        cout<<vstr[0]<<endl;
        sort(vstr.begin(), vstr.end(), cmp);

        string ans;
        for(string str : vstr)
            ans.append(str);

        return ans;
    }
};