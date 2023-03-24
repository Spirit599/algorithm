#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int a[6];
    for(int i = 1; i <= 5; ++i)
        cin >> a[i];
    int sum = 0;
    int score = 0;
    for(int i = 1; i <= 5; ++i)
    {
        score += a[i] * i;
        sum += a[i];
    }
    if(sum == 0)
    {
        cout<<"0.0"<<endl;
        return 0;
    }
    score *= 10;
    double ave = floor((double)score / sum);
    ave /= 10;
    printf("%.1lf\n",ave);
}
