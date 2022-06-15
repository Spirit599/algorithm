//184 · 最大数

class Solution {
public:
    /**
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums) {
        
        vector<string> str_nums;
        for(int num : nums)
            str_nums.push_back(std::move(to_string(num)));
        
        sort(str_nums.begin(), str_nums.end(), [](const string& a, const string& b) {return a + b > b + a;});

        string ans;
        for(string& str: str_nums)
            ans += str;

        if(ans == "" || ans[0] == '0')
            return "0";
        else
            return ans;
    }
};