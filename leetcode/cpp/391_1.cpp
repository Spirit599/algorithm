//矩形填充


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        map<pair<int, int>, int> mpi;
        pair<int, int> left_down = {rectangles[0][0], rectangles[0][1]};
        pair<int, int> left_up = {rectangles[0][0], rectangles[0][3]};
        pair<int, int> right_down = {rectangles[0][2], rectangles[0][1]};
        pair<int, int> right_up = {rectangles[0][2], rectangles[0][3]};

        int sum  = 0;
        for(auto& vec : rectangles)
        {
            pair<int, int> ld = {vec[0], vec[1]};
            pair<int, int> lu = {vec[0], vec[3]};
            pair<int, int> rd = {vec[2], vec[1]};
            pair<int, int> ru = {vec[2], vec[3]};
            sum += (vec[2] - vec[0]) * (vec[3] - vec[1]);
            ++mpi[ld];
            ++mpi[lu];
            ++mpi[rd];
            ++mpi[ru];
            if(ld.first <= left_down.first && ld.second <= left_down.second)
            {
                left_down.first = ld.first;
                left_down.second = ld.second;
            }
            if(lu.first <= left_up.first && lu.second >= left_up.second)
            {
                left_up.first = lu.first;
                left_up.second = lu.second;
            }
            if(rd.first >= right_down.first && rd.second <= right_down.second)
            {
                right_down.first = rd.first;
                right_down.second = rd.second;
            }
            if(ru.first >= right_up.first && ru.second >= right_up.second)
            {
                right_up.first = ru.first;
                right_up.second = ru.second;
            }
        }
        //cout<<sum<<endl;
        //cout<<left_down.first<<" "<<left_down.second<<" "<<right_up.first<<" "<<right_up.second<<" "<<endl;
        if((right_up.first - left_down.first) * (right_up.second - left_down.second) != sum)
            return false;

        --mpi[left_down];
        --mpi[left_up];
        --mpi[right_down];
        --mpi[right_up];
        for(auto kav : mpi)
        {
            //cout<<kav.first.first<<kav.first.second<<kav.second<<endl;
            if(kav.second & 1)
                return false;
        }
        return true;
    }
};