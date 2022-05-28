bool cmp(const string& str1, const string& str2)
{

    string str1_str2 = str1 + str2;
    string str2_str1 = str2 + str1;

    return str1_str2 > str2_str1;
}


class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> nums_str;
        bool zero = true;
        for(int i : nums)
        {
            nums_str.push_back(to_string(i));
            if(i != 0)
                zero = false;
        }

        if(zero)
            return "0";

        sort(nums_str.begin(), nums_str.end(), cmp);

        string ret;

        for(string str : nums_str)
            ret += str;

        return ret;
    }
};