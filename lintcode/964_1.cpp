//964 · 食物集合
//二分


class Solution {
public:
    /**
     * @param lunch: an array that contains each lunch food's calories and value
     * @param dinner: an array that contains each dinner food's calories and value
     * @param t: the minest limit value
     * @return: return the min calories
     */
    int getMinCalories(vector<vector<int>> &lunch, vector<vector<int>> &dinner, int t) {
        
        //sort(lunch.begin(), lunch.end(), [] (const vector<int>& v1, const vector<int>& v2) {return v1[0] < v2[0];});
        sort(dinner.begin(), dinner.end(), [] (const vector<int>& v1, const vector<int>& v2) {return v1[1] < v2[1];});
        int n = dinner.size();
        int min_heat[n];
        memset(min_heat, 0, sizeof(min_heat));

        min_heat[n - 1] = dinner[n - 1][0];
        for(int i = n - 2; i >= 0; --i)
            min_heat[i] = min(min_heat[i + 1], dinner[i][0]);

        int ans = 0x3f3f3f3f;
        for(vector<int>& lun : lunch)
        {
            int need_find = t - lun[1];
            if(need_find <= 0)
                ans = min(ans, lun[0]);
            else
            {
                int index = binary_search(need_find, dinner);
                if(index != -1)
                    ans = min(ans, lun[0] + min_heat[index]);
            }
        }

        if(ans != 0x3f3f3f3f)
            return ans;
        else
            return -1;
    }

    int binary_search(int need_find, vector<vector<int>> &dinner)
    {
        int low = 0;
        int high = dinner.size();

        while(low != high)
        {
            int mid = low + (high - low) / 2;
            if(dinner[mid][1] >= need_find)
                high = mid;
            else
                low = mid + 1;
        }
        if(low != dinner.size())
            return low;
        else
            return -1;
    }
};