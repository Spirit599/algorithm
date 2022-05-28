const double eps = 0.00000001;

class Solution {
public:
    int halveArray(vector<int>& nums) {

        //vector<double> my_nums;
        double sum = 0;
        priority_queue<double, vector<double>, less<double>> pq;
        for(int num : nums)
        {
            sum += num;
            //my_nums.push_back(num);
            pq.push(num);
        }

        double target = sum / 2;
        double cur = 0;
        int ans = 0;

        while(1)
        {
            double maxx = pq.top();
            pq.pop();

            maxx = maxx / 2;
            cur += maxx;
            pq.push(maxx);

            ++ans;

            //printf("%lf %lf\n", cur, target);

            if(cur > target || abs(cur - target) < eps)
            {
                break;
            }
        }

        return ans;
    }
};