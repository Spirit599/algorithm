class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int ans = 0;
        int up = 0;
        int down = 0;
        int n = arr.size();

        for(int i = 1; i < n; ++i)
        {
            if(arr[i] > arr[i - 1])
            {
                if(down != 0)
                    up = 0;
                ++up;
                down = 0;
            }
            else if(arr[i] < arr[i - 1])
            {
                ++down;
            }
            else
            {
                up = 0;
                down = 0;
            }
            if(up && down)
                ans = max(ans, up + down + 1);
        }


        return ans;
    }
};