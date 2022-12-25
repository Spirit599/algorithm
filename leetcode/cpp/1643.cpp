class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {

        string first(destination[1], 'H');
        first.append(destination[0], 'V');
        cout<<first<<endl;
        
        while(--k)
        {
            next_permutation(first.begin(), first.end());
        }

        return first;
    }
};