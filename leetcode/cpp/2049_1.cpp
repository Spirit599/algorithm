//太丑陋

class Solution {
private:
    int ans = 0;
    long long maxx = 0;
    vector<int> edges[100005];
public:
    void init_edges(vector<int>& parents)
    {
        for (int i = 1; i < parents.size(); ++i)
        {
            edges[parents[i]].push_back(i);
        }
    }
    pair<long long, long long> dfs(int cur, int n)
    {
        long long left = 0;
        long long right = 0;
        long long r_left = 0;
        long long r_right = 0;
        if(edges[cur].size() >= 1)
        {
            int son1 = edges[cur][0];
            auto pii1 = dfs(son1, n);
            left = pii1.first + pii1.second + 1;
            r_left = left;
        }

        if(edges[cur].size() == 2)
        {
            int son2 = edges[cur][1];
            auto pii2 = dfs(son2, n);

            right = pii2.first + pii2.second + 1;
            r_right = right;
        }

        //cout<<cur<<" "<<r_left<<" "<<r_right<<endl;

        long long up = n - 1 - left - right;

        if(left == 0)
            left = 1;
        if(right == 0)
            right = 1;
        if(up == 0)
            up = 1;
        long long score = left * right * up;
        if(score > maxx)
        {
            maxx = score;
            ans = 1;
        }
        else if(score == maxx)
        {
            ++ans;
        }
        //cout<<score<<endl;

        return make_pair(r_left, r_right);


    }
    int countHighestScoreNodes(vector<int>& parents) {
        
        init_edges(parents);
        dfs(0, parents.size());


        return ans;
    }
};