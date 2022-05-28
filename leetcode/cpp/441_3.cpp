typedef long long ll;

class Solution {
public:
    int arrangeCoins(int n) {

        return (sqrt( (ll)8 * n + 1) - 1) / 2;
    }
};