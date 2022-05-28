//数学 最小差距
//暴力


class Solution {
public:
    vector<int> constructRectangle(int area) {

        int i = sqrt(double(area));
        while(area % i != 0)
        {
            --i;
        }
        return {area / i, i};
    }
};