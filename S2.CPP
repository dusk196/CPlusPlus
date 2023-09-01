#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50

class string
{
	char str[MAX];
	public:
	friend void operator>>(istream &i,string &s1) // insertion operator
	{
		i >> s1.str;
	}
	friend void operator<<(ostream &o,string &s1) // extraction operator
	{
		o << s1.str;
	}
	void operator=(string s1);
	void operator==(string s1);
	void operator+(string s1);	
	string()
	{
		strcpy(str," ");
	}
	string(char s[])
	{
		strcpy(str,s);
	}
};


void string::operator=(string s1)
{
	strcpy(str,s1.str);
	cout << "The copied string is : " << str;
}


void string::operator==(string s1)
{
	if(strcmp(str,s1.str)==0)
		cout << "Strings are equal.";
	else
		cout << "Strings are not equal.";
}


void string::operator+(string s1)
{
	if(strlen(str)+strlen(s1.str)<MAX)
	{
		strcat(str,s1.str);
		cout << "Concatenated string is : " << str;
	}
	else
	{
		cout << "The array size is exceeded.";
	}
}


void main()
{
	string s1,s2;
	int choice;
	char ans;
	clrscr();
	do
	{
		cout << "1. Copy String\n2. Comparison\n3. Concatenation\n4. Extraction\n5. Insertion";
		cout << "\nEnter your choice : ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			cout << "Enter the string: ";
			cin >> s1;
			s2=s1;
			break;
		case 2:
			cout << "Enter the 1st string: ";
			cin >> s1;
			cout << "Enter the 2nd string: ";
			cin >> s2;
			s1==s2;
			break;
		case 3:
			cout << "Enter the 1st string: ";
			cin >> s1;
			cout << "Enter the 2nd string: ";
			cin >> s2;
			s1+s2;
			break;
		case 4:
			cout << "Enter the string: ";
			cin >> s1;
			cout << "Output shown using insertion operator : ";
			cout << s1;
			break;
		case 5:
			cout << "Enter the string: ";
			cin >> s1;
			cout << "Input taken using insertion operator.";
			break;
		default:
			cout << "Please enter correct choice.";
			break;
		}
		cout << "\nDo you want to continue? (y/n): ";
		flushall();
		cin >> ans;
	}while(ans=='y' || ans=='Y');
	getch();
}