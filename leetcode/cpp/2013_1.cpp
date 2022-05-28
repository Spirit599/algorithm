typedef vector<int> my_point;

namespace std {
    template <> //function-template-specialization
        class hash<my_point>{
        public :
            size_t operator()(const my_point &point ) const
            {
                return hash<int>()(point[0]) ^ hash<int>()(point[1]);
            }
    };
};


class DetectSquares {
private:
    unordered_map<vector<int>, int> points;


public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {

        auto  it = points.find(point);
        if(it != points.end())
        {
            ++it->second;
        }
        else
        {
            points.insert({point, 1});
        }

    }
    
    int count(vector<int> point) {

        int ret = 0;



        for (auto& p1 : points)
        {
            if((p1.first)[0] == point[0] && (p1.first)[1] != point[1])
            {


                auto p2 = points.find({point[0] + (p1.first)[1] - point[1], point[1]});

                if(p2 != points.end())
                {

                    auto p3 = points.find({(p2->first)[0], (p1.first)[1]});
                    if(p3 != points.end())
                    {

                        ret += (p1.second)*(p2->second)*(p3->second);
                    }
                }

                p2 = points.find({point[0] + point[1] - (p1.first)[1], point[1]});

                if(p2 != points.end())
                {

                    auto p3 = points.find({(p2->first)[0], (p1.first)[1]});
                    if(p3 != points.end())
                    {

                        ret += (p1.second)*(p2->second)*(p3->second);
                    }
                }
            }
        }

        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */