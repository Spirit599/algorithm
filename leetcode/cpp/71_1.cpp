// #include <iostream>
// #include <cstring>
// #include <vector>

// using namespace std;

class Solution {
private:    
    string ret;
    vector<string> single_folder;
public:
    void Pretreatment(string &path) {

        int path_len = path.size();
        int i = 0;
        string temp;

        while(i < path_len - 1)
        {
            if(path[i] != '/' || path[i + 1] != '/')
                temp.push_back(path[i]);
            i++;
        }
        if(path[i] != '/')
            temp.push_back(path[i]);

        path = temp;
    }

    void split_path(string path) {
        char * cstr = new char [path.size() + 1];
        strcpy(cstr, path.c_str());
        char * p = strtok (cstr,"/");

        while (p)
        {
            single_folder.push_back(p);
            p = strtok(NULL,"/");
        }

        delete[] cstr;
       
    }

    void joint() {

        int single_folder_size = single_folder.size();


        int i = 0;
        int double_point_nums = 0;
        while(i < single_folder_size)
        {
            if(single_folder[i] == "..")
            {
                double_point_nums++;
            }
            else if (single_folder[i] == ".")
            {
                ;
            }
            else
            {
                if(double_point_nums > 0)
                {
                    double_point_nums--;
                }
                else
                {
                    ret = ret + single_folder[i] + "/";
                }
            }
            i++;
        }

    }


    string simplifyPath(string path) {

        reverse(path.begin(), path.end());

        Pretreatment(path);
        //cout<<path<<endl;
        split_path(path);

        joint();

        reverse(ret.begin(), ret.end());

        if(ret == "")
            ret = "/";
        

        return ret;
    }

};

// int main(int argc, char const *argv[])
// {
//     Solution s1;
//     s1.simplifyPath("/a/./b/../c");
//     return 0;
// }