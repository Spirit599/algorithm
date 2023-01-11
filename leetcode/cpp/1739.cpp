class Solution {
public:
    int minimumBoxes(int n) {
        

        int depth = 1;
        int sum = 0;
        while(depth * (depth + 1) / 2 + sum <= n)
        {
            sum += depth * (depth + 1) / 2;
            ++depth;
        }


        int remain = n - sum;
        int add = 0;
        while(remain > 0)
        {
            ++add;
            remain -= add;
        }

        return depth * (depth - 1) / 2 + add;
    }
};