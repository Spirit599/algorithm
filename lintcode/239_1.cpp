class Solution {
public:
    /**
     * @param a: parameter of the equation
     * @param b: parameter of the equation
     * @param c: parameter of the equation
     * @return: a double array, contains at most two root
     */
    vector<double> rootOfEquation(double a, double b, double c) {
        
        double eps = 1e-6;
        double detal = b * b - 4 * a * c;

        vector<double> ans;
        if(fabs(detal - 0) < eps)
        {
            ans.emplace_back((-1 * b) / (2 * a));
        }
        else if(detal > 0)
        {
            ans.emplace_back(((-1 * b) + sqrt(detal))/ (2 * a));
            ans.emplace_back(((-1 * b) - sqrt(detal))/ (2 * a));
            if(ans[0] > ans[1])
                swap(ans[1], ans[0]);
        }
        else if(detal < 0)
        {
            ;
        }

        return ans;
    }
};