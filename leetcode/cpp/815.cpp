class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        vector<int> routeToCars[1000005];
        int n = routes.size();
        for(int i = 0; i < n; ++i)
        {
            for(int route : routes[i])
            {
                routeToCars[route].emplace_back(i);
            }
        }

        bool visRoute[1000005];
        memset(visRoute, 0, sizeof(visRoute));
        bool visCar[n];
        memset(visCar, 0, sizeof(visCar));

        queue<int> que;
        que.emplace(source);
        visRoute[source] = true;

        // for(int car : routeToCars[source])
        // {
        //     if(!visCar[car])
        //     {
        //         visCar[car] = true;
        //         for(int route : routes[car])
        //         {
        //             if(!visRoute[route])
        //             {
        //                 visRoute[route] = true;
        //                 que.emplace(route);
        //             }
        //         }
        //     }
        // }

        int time = 1;
        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                int curRoute = que.front();
                if(curRoute == target)
                    return time;
                que.pop();
                for(int car : routeToCars[curRoute])
                {
                    if(!visCar[car])
                    {
                        visCar[car] = true;
                        for(int route : routes[car])
                        {
                            if(!visRoute[route])
                            {
                                visRoute[route] = true;
                                que.emplace(route);
                            }
                        }
                    }
                }

            }
            ++time;
        }

        return -1;
    }
};