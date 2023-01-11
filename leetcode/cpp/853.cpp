typedef pair<int, int> pii;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pii> cars(n);
        for(int i = 0; i < n; ++i)
            cars[i] = make_pair(position[i], speed[i]);

        sort(cars.begin(), cars.end(), greater<pii>());

        int ans = 1;
        int preLimit = 0;
        for(int i = 1; i < n; ++i)
        {
            int dis1 = target - cars[preLimit].first;
            int dis2 = target - cars[i].first;
            int s1 = cars[preLimit].second;
            int s2 = cars[i].second;

            if(1ll * s2 * dis1 < 1ll * s1 * dis2) //没超过
            {
                ++ans;
                preLimit = i;
            }
        }

        return ans;

    }
};