class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int start = max(k - n2, 0);
        int end = min(n1, k);
        vector<int> ans(k);

        for(int i = start; i <= end; ++i)
        {
            vector<int> arr1(maxArr(nums1, i));
            vector<int> arr2(maxArr(nums2, k - i));
            vector<int> curRet(merge(arr1, arr2));
            if(curRet > ans)
                ans.swap(curRet);
        }
        return ans;
    }

    vector<int> maxArr(vector<int>& nums, int k) {

        vector<int> stk;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && stk.back() < nums[i] && k - stk.size() < n - i)
            {
                stk.pop_back();
            }
            if(stk.size() != k)
                stk.push_back(nums[i]);
        }
        return stk;
    }

    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {

        int n1 = arr1.size();
        int n2 = arr2.size();
        int p1 = 0;
        int p2 = 0;
        vector<int> ret(n1 + n2);

        int i = 0;
        while(p1 < n1 && p2 < n2)
        {
            if(arr1[p1] > arr2[p2])
                ret[i++] = arr1[p1++];
            else if(arr1[p1] < arr2[p2])
                ret[i++] = arr2[p2++];
            else
            {
                int a1 = p1;
                int a2 = p2;
                while(a1 < n1 && a2 < n2 && arr1[a1] == arr2[a2])
                {
                    ++a1;
                    ++a2;
                }
                if(a1 == n1)
                {
                    ret[i++] = arr2[p2++];
                }
                else if(a2 == n2)
                {
                    ret[i++] = arr1[p1++];
                }
                else if(arr2[a2] > arr1[a1])
                {
                    ret[i++] = arr2[p2++];
                }
                else
                {
                    ret[i++] = arr1[p1++];
                }
            }
        }

        while(p1 < n1)
            ret[i++] = arr1[p1++];
        while(p2 < n2)
            ret[i++] = arr2[p2++];
        return ret;
    }
};