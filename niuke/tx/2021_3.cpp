#include<bits/stdc++.h>
using namespace std;

//y^2 = 2Ax  y = Bx + C
//解析几何  联立方程组 判断是否有解 detal = b^2 - 4ac
//根据交点分布判断
const double eps = 0.00000001;
const double step_length = 0.00001;
typedef long long ll;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		double A;
		double B;
		double C;
		cin >> A >> B >> C;	

		double a = B * B;
		double b = 2 * (B * C - A);
		double c = C * C;
		double detal = b * b - 4 * a * c;
			

		if(detal > 0)
		{
			double x1 = ((-b) - sqrt(detal)) / (2 * a);
			double x2 = ((-b) + sqrt(detal)) / (2 * a);
			double y1 = B * x1 + C;
			double y2 = B * x2 + C;
			//cout<<x1<<" "<<y1<<endl;
			//cout<<x2<<" "<<y2<<endl;
			if((y1 > 0 && y2 > 0) || (y1 < 0 && y2 < 0))
			{
				double area = 0;
				for (double i = x1; i <= x2; i += step_length)
				{
					area += abs(sqrt(2 * A * i) - (B * i + C)) * step_length;
				}
				printf("%.9f",area);
			}
			else
			{
				double area = 0;
				for (double i = 0; i <= x1; i += step_length)
				{
					area += 2 * (sqrt(2 * A * i)) * step_length;
				}
				for (double i = x1; i <= x2; i += step_length)
				{
					area += abs(sqrt(2 * A * i) - (B * i + C)) * step_length;
				}
				printf("%.9f",area);
			}
		}
	}


	return 0;
}

