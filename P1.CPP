#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<String.h>
#define MAX 50

using namespace std;

class String
{
	char str[MAX];
	public:
	friend void operator>>(istream &i,String &s1)
	{
		i >> s1.str;
	}
	friend void operator<<(ostream &o,String &s1)
	{
		o << s1.str;
	}
	void operator=(String s1);
	void operator==(String s1);
	void operator+(String s1);	
	String()
	{
		strcpy(str," ");
	}
	String(char s[])
	{
		strcpy(str,s);
	}
};


void String::operator=(String s1)
{
	strcpy(str,s1.str);
	cout << "The copied String is : " << str;
}


void String::operator==(String s1)
{
	if(strcmp(str,s1.str)==0)
		cout << "Strings are equal.";
	else
		cout << "Strings are not equal.";
}


void String::operator+(String s1)
{
	if(strlen(str)+strlen(s1.str)<MAX)
	{
		strcat(str,s1.str);
		cout << "Concatenated String is : " << str;
	}
	else
	{
		cout << "The array size is exceeded.";
	}
}


int main()
{
	String s1,s2;
	int choice;
	char ans;
	do
	{
		cout << "1. Copy String\n2. Comparison\n3. Concatenation\n4. Extraction\n5. Insertion";
		cout << "\nEnter your choice : ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			cout << "Enter the String: ";
			cin >> s1;
			s2=s1;
			break;
		case 2:
			cout << "Enter the 1st String: ";
			cin >> s1;
			cout << "Enter the 2nd String: ";
			cin >> s2;
			s1==s2;
			break;
		case 3:
			cout << "Enter the 1st String: ";
			cin >> s1;
			cout << "Enter the 2nd String: ";
			cin >> s2;
			s1+s2;
			break;
		case 4:
			cout << "Enter the String: ";
			cin >> s1;
			cout << "Output shown using insertion operator : ";
			cout << s1;
			break;
		case 5:
			cout << "Enter the String: ";
			cin >> s1;
			cout << "Input taken using insertion operator.";
			break;
		default:
			cout << "Please enter correct choice.";
			break;
		}
		cout << "\nDo you want to continue? (y/n): ";
		cin >> ans;
	}while(ans=='y' || ans=='Y');
	getch();
	return 0;
}
