// multiset的  *(++multiset.end()) 不一定是最值

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        multiset <int, greater<int>> pro;
        priority_queue<int> pq;
        int n = profits.size();

        pair<int, int> capAndPro[n];
        for(int i = 0; i < n; ++i)
            capAndPro[i] = make_pair(capital[i], profits[i]);
        sort(capAndPro, capAndPro + n);

        int i = 0;
        while(k--)
        {
            while(i < n && capAndPro[i].first <= w)
            {
                //printf("%d\n", i);
                //pq.push(capAndPro[i].second);
                pro.insert(capAndPro[i].second);
                ++i;
            }
            if(!pro.empty())
            {
                w += *(pro.begin());
                //printf("%d\n", p);
                pro.erase(pro.begin());
            }
            else
            {
                break;
            }
        }

        return w;
    }
};