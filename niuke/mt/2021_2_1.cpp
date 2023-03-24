#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int k)
    {
        n = k;
        fa.resize(k, -1);
        height.resize(k, 0);
    }
    int n;
    vector<int> fa;
    vector<int> height;
    unordered_map<int, vector<int>> memo;

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
        // cout<<fx<<" "<<fy<<endl;
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
            fa[fy] = fx;
            ++height[fx];
        }
    }

    void print()
    {
        for(int i = 1; i < n; ++i)
        {
            int fx = findFa(i);
            memo[fx].push_back(i);
        }
        int k = memo.size();
        cout<<k<<endl;
        vector<int> tmp[k];
        int i = 0;
        for(auto& kv : memo)
        {
            tmp[i++] = kv.second;
        }
        sort(tmp, tmp + k, [](vector<int>& v1, vector<int>& v2) {return v1[0] < v2[0];});
        for(int i = 0; i < k; ++i)
        {
            for(int num : tmp[i])
            {
                cout<<num<<" ";
            }
            cout<<endl;
        }

    }



    
};

int main() {
    
    int n,m;
    cin >> n >> m;
    UnionFind uf(n + 1);

    int x,y;
    while(m--)
    {
        cin >> x >> y;
        uf.unionNode(x, y);
    }
    uf.print();
    return 0;
}
