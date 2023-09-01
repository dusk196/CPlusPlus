#include<iostream>
using namespace std;
template<class T>


class A
{
	private:
		T x, y, z;
	public:
		void input (T a, T b, T c)
		{
			x=a;
			y=b;
			z=c;
		}
		void cal()
		{
			T sum;
			sum = 5*x+6*y-z;
			cout << "\n" << sum << "\n\n";
		}
};


int main()
{
	A <int> obj1;
	A <float> obj2;
	obj1.input(10,20,30);
	obj2.input(5.3,6.5,7.1);
	obj1.cal();
	obj2.cal();
	return 0;
}

