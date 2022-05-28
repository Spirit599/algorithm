class Solution {
public:
    int count_2(int num)
    {
        int ans = 0;
        while(num % 2 == 0)
        {
            ++ans;
            num = num / 2;
        }

        return ans;
    }
    int count_5(int num)
    {
        int ans = 0;
        while(num % 5 == 0)
        {
            ++ans;
            num = num / 5;
        }

        return ans;
    }
    int maxTrailingZeros(vector<vector<int>>& grid) {
        
        int y = grid.size();
        int x = grid[0].size();

        vector<vector<pair<int, int>>> left_to_right(y, vector<pair<int, int>>(x));
        vector<vector<pair<int, int>>> up_to_down(y, vector<pair<int, int>>(x));


        for(int i = 0; i < y; ++i)
        {

            left_to_right[i][0].first = count_2(grid[i][0]);
            left_to_right[i][0].second = count_5(grid[i][0]);

            for(int j = 1; j < x; ++j)
            {
                left_to_right[i][j].first = left_to_right[i][j - 1].first;
                left_to_right[i][j].second = left_to_right[i][j - 1].second;

                left_to_right[i][j].first += count_2(grid[i][j]);
                left_to_right[i][j].second += count_5(grid[i][j]);

            }
        }


        for(int j = 0; j < x; ++j)
        {

            up_to_down[0][j].first = count_2(grid[0][j]);
            up_to_down[0][j].second = count_5(grid[0][j]);

            for(int i = 1; i < y; ++i)
            {
                up_to_down[i][j].first = up_to_down[i - 1][j].first;
                up_to_down[i][j].second = up_to_down[i - 1][j].second;

                up_to_down[i][j].first += count_2(grid[i][j]);
                up_to_down[i][j].second += count_5(grid[i][j]);
                
            }
        }

        int ans = 0;

        for(int i = 0; i < y; ++i)
        {
            for(int j = 0; j < x; ++j)
            {
                //left up
                int num_2 = left_to_right[i][j].first + up_to_down[i][j].first;
                int num_5 = left_to_right[i][j].second + up_to_down[i][j].second;
                num_2 -= count_2(grid[i][j]);
                num_5 -= count_5(grid[i][j]);
                ans = max(ans, min(num_2, num_5));

                //left down
                num_2 = left_to_right[i][j].first + (up_to_down[y - 1][j].first - up_to_down[i][j].first);
                num_5 = left_to_right[i][j].second + (up_to_down[y - 1][j].second - up_to_down[i][j].second);
                ans = max(ans, min(num_2, num_5));

                //right up
                num_2 = (left_to_right[i][x - 1].first - left_to_right[i][j].first) + up_to_down[i][j].first;
                num_5 = (left_to_right[i][x - 1].second - left_to_right[i][j].second) + up_to_down[i][j].second;
                ans = max(ans, min(num_2, num_5));

                //right down
                num_2 = (left_to_right[i][x - 1].first - left_to_right[i][j].first) + (up_to_down[y - 1][j].first - up_to_down[i][j].first);
                num_5 = (left_to_right[i][x - 1].second - left_to_right[i][j].second) + (up_to_down[y - 1][j].second - up_to_down[i][j].second);
                num_2 += count_2(grid[i][j]);
                num_5 += count_5(grid[i][j]);

                ans = max(ans, min(num_2, num_5));
            }
        }

        return ans;
    }
};