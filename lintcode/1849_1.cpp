class Solution {
public:
    /**
     * @param customers: the number of customers
     * @param grumpy: the owner's temper every day
     * @param x: X days
     * @return: calc the max satisfied customers
     */
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int x) {
        
        int n = customers.size();

        int sum = 0;
        int extra = 0;

        int i = 0;
        while(i < x)
        {
            if(grumpy[i] == 1)
                extra += customers[i];
            else
                sum += customers[i];

            ++i;
        }
        int max_extra = extra;

        while(i < n)
        {
            if(grumpy[i] == 1)
                extra += customers[i];
            else
                sum += customers[i];

            if(grumpy[i - x] == 1)
                extra -= customers[i - x];

            max_extra = max(max_extra, extra);
            ++i;
        }

        return sum + max_extra;
    }
};