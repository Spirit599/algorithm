class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {

        map<int, int> hash;
        for(int num : arr)
            ++hash[num];

        while(!hash.empty())
        {
            // for(auto kav : hash)
            //     printf("%d %d\n",kav.first,kav.second);

            auto p_min = hash.begin();
            int doubled = 0;
            if(p_min->first >= 0)
                doubled = (p_min->first) * 2;
            else if(!(p_min->first & 1))
                doubled = (p_min->first) / 2;
            else
                return false;


            auto p_double = hash.find(doubled);
            if(p_double == hash.end())
                return false;

            --(p_min->second);
            --(p_double->second);

            if(p_min != p_double)
            {
                if(p_min->second == 0)
                    hash.erase(p_min);
                if(p_double->second == 0)
                    hash.erase(p_double);
            }
            else
            {
                if(p_min->second == 0)
                    hash.erase(p_min);
                else if(p_min->second == -1)
                    return false;
            }

        }

        return true;
    }
};