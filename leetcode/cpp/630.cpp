class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(), [](const vector<int>& v1, const vector<int>& v2)
            {return v1[1] < v2[1];});

        priority_queue<int> pq;
        int sum = 0;

        for(auto& course : courses)
        {
            pq.emplace(course[0]);
            sum += course[0];
            if(sum > course[1])
            {
                sum -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};