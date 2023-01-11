class Solution {
public:
    int maxVectorRectangle(vector<int>& arr) {

        int n = arr.size();
        int left[n];
        memset(left, -1, sizeof(left));
        int right[n];
        for(int i = 0; i < n; ++i)
            right[i] = n;

        vector<int> upStk;
        for(int i = 0; i < n; ++i)
        {
            while(!upStk.empty() && arr[upStk.back()] > arr[i])
            {
                right[upStk.back()] = i;
                upStk.pop_back();
            }
            if(!upStk.empty())
                left[i] = upStk.back();
            upStk.emplace_back(i);
        }

        int ret = 0;
        for(int i = 0; i < n; ++i)
            ret = max(ret, (right[i] - left[i] - 1) * arr[i]);
        return ret;
    }

    int maximalRectangle(vector<string>& matrix) {

        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<int> arr(n);
        int ans = 0;

        for(auto& vec : matrix) 
        {
            for(int i = 0; i < n; ++i)
            {
                if(vec[i] == '1')
                    ++arr[i];
                else
                    arr[i] = 0;
            }

            ans = max(ans, maxVectorRectangle(arr));
        }

        return ans;
    }
};