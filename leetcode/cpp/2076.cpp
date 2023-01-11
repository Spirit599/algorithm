class unionFind {
private:
    vector<int> fa;
    vector<int> height;
public:
    unionFind(int n)
    {
        fa.resize(n, -1);
        height.resize(n, 0);
    }

    int findFa(int x)
    {
        while(fa[x] != -1)
            x = fa[x];
        return x;
    }

    void unionNode(int x, int y)
    {
        int fx = findFa(x);
        int fy = findFa(y);
        if(fx == fy)
            return;

        if(height[fx] < height[fy])
        {
            fa[fx] = fy;
        }
        else if(height[fx] > height[fy])
        {
            fa[fy] = fx;
        }
        else
        {
            fa[fx] = fy;
            ++height[fy];
        }
    }

    bool isConnection(int x, int y)
    {
        return findFa(x) == findFa(y);
    }
};


class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        unionFind uf(n);

        vector<bool> ans;
        for(auto& req : requests)
        {
            int f1 = uf.findFa(req[0]);
            int f2 = uf.findFa(req[1]);
            bool ok = true;
            for(auto& re : restrictions)
            {
                int f3 = uf.findFa(re[0]);
                int f4 = uf.findFa(re[1]);
                if((f1 == f3 && f2 == f4) || (f2 == f3 && f1 == f4))
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                uf.unionNode(f1, f2);
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;


    }
};