class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {

        vector<int> ans;
        if(tomatoSlices > cheeseSlices * 4 || tomatoSlices < cheeseSlices * 2)
            return ans;

        if((tomatoSlices - 2 * cheeseSlices) % 2 != 0)
            return ans;

        return {(tomatoSlices - 2 * cheeseSlices) / 2, cheeseSlices - (tomatoSlices - 2 * cheeseSlices) / 2};
    }
};