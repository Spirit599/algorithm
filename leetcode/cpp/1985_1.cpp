bool cmp(const string& num1, const string& num2)
{
    if(num1.size() != num2.size())
        return num1.size() > num2.size();
    else
        return num1 > num2;
}

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        //string ret;

        sort(nums.begin(), nums.end(), cmp);

        for(auto& num : nums)
            cout<<num<<endl;



        return nums[k - 1];
    }
};