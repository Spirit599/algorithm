class Solution {
public:

    bool check(int num)
    {
        int num_copy = num;

        while(num_copy != 0)
        {
            int k = num_copy % 10;
            if(k == 0)
            {
                return false;
            }

            if(num % k != 0)
            {
                return false;
            }

            num_copy = num_copy / 10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> ans;

        for(int num = left; num <= right; ++num)
        {
            if(check(num))
            {
                ans.push_back(num);
            }
        }

        return ans;
    }
};