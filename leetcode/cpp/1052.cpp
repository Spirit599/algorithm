class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int sum = 0;
        int n = customers.size();
        for(int i = 0; i < n; ++i)
        {
            if(grumpy[i] == 0)
                sum += customers[i];
        }

        int add = 0;
        for(int i = 0; i < min(n, minutes); ++i)
        {
            if(grumpy[i] == 1)
                add += customers[i];
        }
        int maxAdd = add;
        for(int i = minutes; i < n; ++i)
        {
            if(grumpy[i] == 1)
                add += customers[i];
            if(grumpy[i - minutes] == 1)
                add -= customers[i - minutes];
            maxAdd = max(maxAdd, add);
        }
        return sum + maxAdd;
    }
};