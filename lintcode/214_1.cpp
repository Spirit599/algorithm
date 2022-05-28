#include <numeric>

class Solution {
public:
    /**
     * @param a: an array of float numbers
     * @return: a float number
     */
    float maxOfArray(vector<float> &a) {
        
        return *max_elememt(a.begin(), a.end());
    }
};