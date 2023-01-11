class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int n = people.size();
        int ans = 0;
        int right = n - 1;
        for(int left = 0; left < n; ++left)
        {
            while(left < right && people[left] + people[right] > limit)
            {
                --right;
            }

            if(left < right)
            {
                --right;
                ++ans;
            }
            else
                break;
        }

        return n - ans;
    }
};