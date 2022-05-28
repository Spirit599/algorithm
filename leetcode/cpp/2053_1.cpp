class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        string ans;
        int cur = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            bool flag = true;
            for(int j = 0; j < arr.size(); ++j)
            {
                if(arr[i] == arr[j] && i != j)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ++cur;
            if(cur == k)
                return arr[i];
        }

        return ans;
    }
};