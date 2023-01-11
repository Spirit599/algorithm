class Solution {
public:
    bool isTransformable(string s, string t) {

        deque<int> idx[10];
        int n = s.size();
        for(int i = 0; i < n; ++i)
            idx[s[i] - '0'].push_back(i);

        int recIdx[10];
        memset(recIdx, -1, sizeof(recIdx));

        for(int i = 0; i < n; ++i)
        {
            int num = t[i] - '0';
            if(idx[num].empty())
                return false;
            recIdx[num] = idx[num].front();
            idx[num].pop_front();
            for(int j = num + 1; j < 10; ++j)
            {
                if(recIdx[j] != -1 && recIdx[j] > recIdx[num])
                    return false;
            }
        }

        return true;
    }
};