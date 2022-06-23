// 1219 · 加热器

class Solution {
public:
    /**
     * @param houses: positions of houses
     * @param heaters: positions of heaters
     * @return: the minimum radius standard of heaters
     */
    int findRadius(vector<int> &houses, vector<int> &heaters) {

        sort(heaters.begin(), heaters.end());
        int maxx = 0;

        for(int house : houses)
        {
            //cout<<"house : "<<house<<endl;
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            //cout<<*it<<endl;
            int ret = 0x7fffffff;
            if(it != heaters.end())
                ret = min(ret, *it - house);
            if(it != heaters.begin())
                ret = min(ret, house - *(--it));


            maxx = max(maxx, ret);
        }

        return maxx;
    }
};