class Solution {
public:
    /**
     * @param pos: the vision ward can control interval
     * @param L: you need to control interval length
     * @return: return the minium number of vision ward to control the interval
     */
    struct cmp_pos
    {
        bool operator() (const vector<int>& v1, const vector<int>& v2)
        {
            if(v1[0] != v2[0])
                return v1[0] < v2[0];
            else
                return v1[1] > v2[1];
        }
    };

    int getMiniumVisionWard(vector<vector<int>> &pos, int L) {
        // write your code here

        sort(pos.begin(), pos.end(), cmp_pos());

        int ans = 0;

        int cur_start = 0;
        int cur_end = 0;
        int i = 0;
        int n = pos.size();

        while(i < n)
        {
            int j = i;
            while(j < n)
            {
                if(pos[j][0] <= cur_start)
                {
                    cur_end = max(cur_end, pos[j][1]);
                    ++j;
                }
                else
                {
                    break;
                }
            }

            if(i == j)
                return -1;

            ++ans;
            cur_start = cur_end;
            i = j;
            if(cur_end >= L)
                break;
        }

        if(cur_end >= L)
            return ans;
        
        return -1;
    }
};