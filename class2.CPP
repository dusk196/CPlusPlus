#include <iostream>
using namespace std;

class item
{
	int number;
	float cost;
	public:
		void getdata(int a, float b)
		{
			number = a;
			cost = b;
		}
		void putdata(void)
		{
			cout << "number : " << number << "\n";
			cout << "cost : " << cost << "\n";
		}
};

int main()
{
	item x;
	cout << "\nObject X " << "\n";
	x.getdata(100, 299.95);
	x.putdata();
	item y;
	cout << "\nObject Y " << "\n";
	y.getdata(200, 175.5);
	y.putdata();
	return 0;
}
