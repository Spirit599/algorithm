class Solution {
public:
    pair<int, int> subSum(vector<int>& arr)
    {
        int maxx = 0;
        int minn = 0;
        int cur1 = 0;
        int cur2 = 0;
        for(int num : arr)
        {
            cur1 += num;
            if(cur1 > 0)
                maxx = max(maxx, cur1);
            else
                cur1 = 0;

            cur2 += num;
            if(cur2 < 0)
                minn = min(minn, cur2);
            else
                cur2 = 0;
        }
        return {maxx, -minn};
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int sumOfS2 = 0;
        int sumOfS1 = 0;
        for(int i = 0; i < n; ++i)
        {
            sumOfS2 += nums2[i];
            sumOfS1 += nums1[i];
        }
        vector<int>* big = &nums2;
        vector<int>* small = &nums1;
        int bigSum = sumOfS2;
        int smallSum = sumOfS1;
        if(sumOfS1 > sumOfS2)
        {
            bigSum = sumOfS1;
            smallSum = sumOfS2;
            big = &nums1;
            small = &nums2;
        }

        for(int i = 0; i < n; ++i)
        {
            (*small)[i] -= (*big)[i];
        }

        auto subSumOfDif = subSum(*small);
        return max(bigSum + subSumOfDif.first, smallSum + subSumOfDif.second);
    }
};