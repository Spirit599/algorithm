class Solution {
private:
    vector<int> distance;
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int ret = 0;
        int points_size = points.size();
        if(points_size < 3)
            return ret;

        int i = 0;
        while(i < points_size - 2)
        {
            int j = i + 1;
            int k = i + 2;
            if(compare_distance_equal(points[i], points[j], points[k]) == true)
            {
                ret += 2;
            }
            i++;

        }

        return ret;
    }

    int get_distance(const vector<int> &p1,
                     const vector<int> &p2)
    {
        
    }

    // bool compare_distance_equal(const vector<int> &p1, 
    //                             const vector<int> &p2,
    //                             const vector<int> &p3)
    // {
    //     int dis1 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    //     int dis2 = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);

    //     cout<<dis1<<dis2<<endl;

    //     return dis1 == dis2;
    // }
};