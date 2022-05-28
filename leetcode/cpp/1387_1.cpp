bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
{
    if(p1.second != p2.second)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

class Solution {
public:
    int get_weight(int num)
    {
        int ret = 0;
        while(num != 1)
        {
            if(num % 2 == 0)
                num = num / 2;
            else
                num = 3 * num + 1;
            ++ret;
        }
        return ret;
    }
    int getKth(int lo, int hi, int k) {

        vector<pair<int, int>> vp;

        for (int i = lo; i <= hi; ++i)
        {
            vp.push_back({i, get_weight(i)});
        }

        sort(vp.begin(), vp.end(), cmp);

        return vp[k - 1].first;

    }
};