//找空子 不要一个个的找 找连续的一段


class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {

        // set<int> se(nums.begin(), nums.end());

        // nums.assign(se.begin(), se.end());

        sort(nums.begin(), nums.end());

        long long ans = 0;

        long long bef = 0;
        for(int num : nums)
        {
            if(num == bef + 1 || num == bef)
                ;
            else
            {
                long long n = (num - bef - 1);
                if(k >= n)
                {
                    //cout<<n<<" "<<k<<endl;
                    k = k - n;
                    ans += n * (bef + num) / 2;
                }
                else
                {
                    //cout<<n<<" "<<k<<endl;
                    ans += k * (bef + 1 + bef + k) / 2;
                    k = 0;
                }
            }
            if(k == 0)
                break;
            bef = num;
        }

        ans += (long long)k * (nums[nums.size() - 1] + 1 + nums[nums.size() - 1] + k) / 2;

        return ans;

    }
};