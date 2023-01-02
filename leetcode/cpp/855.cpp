typedef pair<int, int> pii;
struct comp
{
    bool operator() (const pii& p1, const pii& p2)
    {
        int dif1 = p1.second - p1.first;
        int d1 = dif1 / 2;
        int dif2 = p2.second - p2.first;
        int d2 = dif2 / 2;
        if(d1 != d2)
            return d1 < d2;
        else
            return p1.first > p2.first;
    }
};

class ExamRoom {
public:
    set<int> seats;
    priority_queue<pii, vector<pii>, comp> pq;
    int n;
    ExamRoom(int nn) : n(nn) {

    }
    
    int seat() {

        

        int seatSize = seats.size();
        if(seatSize == 0)
        {
            seats.insert(0);
            return 0;
        }
        
        int right = n - 1 - *(seats.rbegin());
        int left = *(seats.begin());
        while(seats.size() >= 2)
        {
            auto [ll, rr] = pq.top();
            if(seats.count(ll) && seats.count(rr) && *next(seats.find(ll)) == rr)
            {
                int d = (rr - ll) / 2;
                if(d <= left || d < right)
                    break;

                pq.pop();
                int newSeat = ll + d;
                pq.emplace(ll, newSeat);
                pq.emplace(newSeat, rr);
                seats.emplace(newSeat);
                return newSeat;
            }
            else
            {
                pq.pop();
            }
        }

        if(right > left)
        {
            pq.emplace(*seats.rbegin(), n - 1);
            seats.emplace(n - 1);
            return n - 1;
        }
        else
        {
            pq.emplace(0, *seats.begin());
            seats.emplace(0);
            return 0;
        }
    }
    
    void leave(int p) {


        auto it = seats.find(p);
        auto nextIt = it;
        ++nextIt;
        if(it != seats.begin() && nextIt != seats.end())
        {
            pq.emplace(*prev(it), *next(it));
        }
        seats.erase(it);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */