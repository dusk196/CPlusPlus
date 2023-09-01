#include <iostream>
using namespace std;

class item
{
	int number;
	float cost;
	public:
		void getdata(void);
		void putdata(void);
};

void item :: getdata(void)
{
	cin >> number;
	cin >> cost;
}

void item :: putdata(void)
{
	cout << "number : " << number << "\n";
	cout << "cost : " << cost << "\n";
}

int main()
{
	item x;
	cout << "\nObject X " << "\n";
	x.getdata();
	x.putdata();
	item y;
	cout << "\nObject Y " << "\n";
	y.getdata();
	y.putdata();
	return 0;
}
