//二分

class Solution {
public:
    bool check(long long day, vector<int>& time, int totalTrips)
    {

        long long sum_trips = 0;
        for(int t : time)
        {
            sum_trips += day / t;
            if(sum_trips >= totalTrips)
                return true;
        }
        //cout<<sum_trips<<endl;

        return false;



    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long low = 1;
        int maxx = 1;
        for(int t : time)
            maxx = max(maxx, t);
        long long high = (long long)totalTrips * (long long)maxx; 

        while(high != low)
        {
            long long day = low + (high - low) / 2;
            
            if(check(day, time, totalTrips))
                high = day;
            else
                low = day + 1;
            //printf("%d %d %d\n",low,day,high);
        }
        
        return low;
    }
};