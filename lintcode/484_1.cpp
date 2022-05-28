class Solution {
public:
    /**
     * @param A: An integer array
     * @param index1: the first index
     * @param index2: the second index
     * @return: nothing
     */
    void swapIntegers(vector<int> &A, int index1, int index2) {
        
        swap(A[index1], A[index2]);
    }
};