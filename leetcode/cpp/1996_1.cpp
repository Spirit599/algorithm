bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    if(v1[0] != v2[0])
        return v1[0] > v2[0];
    else
        return v1[1] < v2[1];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        long long ret = 0;

        int max_defense = 0;

        sort(properties.begin(), properties.end(), cmp);

        // for(auto& v :  properties)
        // {
        //     cout<<v[0]<<" "<<v[1]<<endl;
        // }

        for(auto& v : properties)
        {
            if(max_defense > v[1])
            {

                ret++;
            }
            else
            {
                max_defense = v[1];
            }
        }

        return ret;
    }
};