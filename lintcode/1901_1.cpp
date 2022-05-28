class Solution {
public:
    /**
     * @param A: The array A.
     * @return: The array of the squares.
     */
    vector<int> SquareArray(vector<int> &A) {
        
        for(auto& num : A)
            num = num * num;

        sort(A.begin(), A.end());

        return A;
    }
};