class Solution {
public:
    int findMinMoves(vector<int>& machines) {

        long long sum = 0;
        long long max_machines = 0;
        for(auto& i : machines)
        {
            sum += i;
            if(i > max_machines)
                max_machines = i;
        }

        if(sum / machines.size() * machines.size() != sum)
        {
            return -1;
        }

        long long avl = sum / machines.size();

        long long need = 0;
        long long ret = 0;

        for(auto& i : machines)
        {
            int cur = avl - i;
            
            need += cur;

            //cout<<need<<" "<<cur<<endl;
            ret = max(ret, max(need, -need));
        }

        return max(ret, max_machines - avl);
    }
};