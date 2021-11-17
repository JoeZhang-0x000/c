#include<iostream>
using namespace std;
/*
lagrange ²åÖµ·¨
*/
int main() {
	double x[] = {1.0,2.0,3.0,4.0  };
	double f[] = { 0.0,0.693,1.099,1.386 };
	double xa = 1.5;

	int n = sizeof(x) / sizeof(x[0]);
	cout << "n:" << n << endl;
	double ret = 0;
	
	for (int k = 0; k < n; k++)
	{
		double l = 1.0;
		for (int i = 0;i < n;i++)
		{
			if (i != k)
			{
				l = l *( (xa - x[i]) )/ (x[k] - x[i]);
				

			}
		}
		cout << "l:" << l << endl;
		ret += l * f[k];
	}


	cout << ret << endl;

	return 1;
}
