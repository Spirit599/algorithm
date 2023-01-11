class Solution {
public:
    int father[205];
    int height[205];
    int find(int index)
    {
        while(father[index] != -1)
        {
            index = father[index];
        }
        return index;
    }
    void unionTree(int index1, int index2)
    {
        int f1 = find(index1);
        int f2 = find(index2);
        if(f1 != f2)
        {
            if(height[f1] > height[f2])
                father[f2] = f1;
            else if(height[f1] < height[f2])
                father[f1] = f2;
            else
            {
                father[f1] = f2;
                ++height[f2];
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n =isConnected.size();
        
        memset(father, -1, sizeof(father));
        memset(height, 0, sizeof(height));

        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(isConnected[i][j])
                {
                    unionTree(i, j);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(father[i] == -1)
                ++ans;
        }

        return ans;
    }
};