typedef pair<int, int> pii;
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {

        queue<pii> que;
        que.push(make_pair(0, 0));
        unordered_set<long long> vis;

        while(!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;

            que.pop();
            if(x + y == targetCapacity)
                return true;
            long long mapping =  x * 1000005ll + y;
            if(vis.count(mapping))
                continue;

            printf("%d %d\n", x,y);
            vis.insert(mapping);

            que.push(make_pair(jug1Capacity, y));
            que.push(make_pair(x, jug2Capacity));
            que.push(make_pair(0, y));
            que.push(make_pair(x, 0));
            int add = min(x, jug2Capacity - y);
            que.push(make_pair(x - add, y + add));
            add = min(y, jug1Capacity - x);
            que.push(make_pair(x + add, y - add));
        }

        return false;
    }
};