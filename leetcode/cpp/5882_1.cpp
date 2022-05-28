

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        

        int grid_size = grid[0].size();

        if(grid_size == 1)
            return 0;

        vector<long long> prefix(grid_size);
        vector<long long> suffix(grid_size);

        long long sum = 0;
        for (int i = 0; i < grid_size; ++i)
        {
            sum += grid[1][i];
            prefix[i] = sum;
            cout<<prefix[i]<<" ";
        }

        sum = 0;
        for(int i = grid_size - 1; i >= 0; --i)
        {
            sum += grid[0][i];
            suffix[i] = sum;
        }


        int i = 0;
        int j = grid_size - 1;
        while(i != j)
        {
            if(prefix[i] < suffix[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        if(i == 0)
            return suffix[1];
        else if(i == grid_size - 1)
            return prefix[grid_size - 2];
        else
        {
            return max(prefix[i - 1], suffix[i + 1]);
        }

    }
};