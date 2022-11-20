class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {

        vector<int> arr1(arr);
        sort(arr.begin(), arr.end());

        int n = arr.size();
        vector<int> ans;
        for(int i = n - 1; i >= 0; --i)
        {
            int j = 0;
            for(; j < n; ++j)
            {
                if(arr[i] == arr1[j])
                    break;
            }

            if(i == j)
                continue;

            ans.push_back(j + 1);
            reverse(arr1.begin(), arr1.begin() + j + 1);
            ans.push_back(i + 1);
            reverse(arr1.begin(), arr1.begin() + i + 1);
        }

        for(int num : arr1)
            printf("%d ", num);

        return ans;
    }
};