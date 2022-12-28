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
    bool gcdSort(vector<int>& nums) {

        unionFind uf(100005);
        for(int num : nums)
        {
            int numc = num;
            for(long long i = 2; i * i <= num; ++i)
            {
                if(num % i == 0)
                {
                    uf.unionNode(numc, i);
                    while(num % i == 0)
                    {
                        num = num / i;
                    }
                }
            }

            if(num != 1)
                uf.unionNode(numc, num);
        }

        vector<int> sortNums(nums.begin(), nums.end());
        sort(sortNums.begin(), sortNums.end());

        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != sortNums[i] && !uf.isConnection(nums[i], sortNums[i]))
                return false;
        }
        return true;
    }
};