class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {

        int n = nums.size();
        int half1 = n >> 1;
        int half2 = n - half1;
        int s1 = 1 << half1;
        int s2 = 1 << half2;
        int arr1[s1];
        arr1[0] = 0;
        int arr2[s2];
        arr2[0] = 0;

        for(int s = 1; s < s1; ++s)
        {
            for(int i = 0; i < half1; ++i)
            {
                if((s & (1 << i)) == 0)
                    continue;
                arr1[s] = arr1[s ^ (1 << i)] + nums[i];
                break;
            }
        }

        for(int s = 1; s < s2; ++s)
        {
            for(int i = 0; i < half2; ++i)
            {
                if((s & (1 << i)) == 0)
                    continue;
                arr2[s] = arr2[s ^ (1 << i)] + nums[i + half1];
                break;
            }
        }

        sort(arr1, arr1 + s1);
        sort(arr2, arr2 + s2);

        int ans = INT_MAX;
        auto it1 = lower_bound(arr1, arr1 + s1, goal);
        if(it1 != arr1 + s1)
            ans = min(ans, abs(goal - *it1));
        if(it1 != arr1)
            ans = min(ans, abs(goal - *(--it1)));

        auto it2 = lower_bound(arr2, arr2 + s2, goal);
        if(it2 != arr2 + s2)
            ans = min(ans, abs(goal - *it2));
        if(it2 != arr2)
            ans = min(ans, abs(goal - *(--it2)));

        int p1 = 0;
        int p2 = s2 - 1;
        while(p1 < s1 && p2 >= 0)
        {
            int num = arr1[p1] + arr2[p2];
            ans = min(ans, abs(goal - num));
            if(num > goal)
                --p2;
            else
                ++p1;
        }

        return ans;
    }
};