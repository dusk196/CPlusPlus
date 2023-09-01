#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>

using namespace std;

class String
{
	char *ptr;
	int len;

	public:

		String()
		{
			len=0;
			ptr=0;
		}
		/*
		friend istream & operator >>(istream & ccin,String & obj)
		{
			char val[20];
			obj.len=strlen(val);
			obj.ptr=new char[obj.len+1];
			strcpy(obj.ptr,val);
			return ccin;
		}
		*/
		friend ostream & operator <<(ostream & ccout,String & obj)
		{
			ccout<<"\nOutput using extracion operator: "<<obj.ptr;
			return ccout;
		}
		String(char *s)
		{
			len=strlen(s);
			ptr=new char[len+1];
			strcpy(ptr,s);
		}
		String(String & s)
		{
			len=s.len;
			ptr=new char[len+1];
			strcpy(ptr,s.ptr);
		}
		friend String operator+(String s1,String s2)
		{
			String s3;
			s3.len=s1.len+s2.len;
			s3.ptr=new char[s3.len+1];
			strcpy(s3.ptr,s1.ptr);
			strcat(s3.ptr,s2.ptr);
			return s3;
		}
		friend void operator==(String s1,String s2)
		{
			int rel=0;
			if(strcmp(s1.ptr,s2.ptr)==0)
			{
				cout<<"\nBoth strings are same.";
			}
			else
			{
				cout<<"\nBoth strings are not same.";
			}
		}
		/*
		String operator=(String obj)
		{
			String s3;
			s3.len=obj.len;
			strcpy(s3.ptr,obj.ptr);
			return s3;
		}
		*/
		void display()
		{
			if(len==0)
			{
				cout<<"\n String is Empty.";
			}
			else
			{
				cout<<"\nThe string is: "<<ptr;
			}
		}
};

int main()
{
	char a[20], b[20];
	cout << "\nInput the 1st string: ";
	cin >> a;
	cout << "\nInput the 2nd string: ";
	cin >> b;
	String str1(a);
	String str2(b);
	str1.display();
	str2.display();
	String str3;
	cout << "\nAfter Concatination: ";
	str3=str1+str2;
	str3.display();
	cout << "\nAfter Comparing: ";
	str1==str2;
	cout << str1;
	cout << str2;
	cout << str3;
	getch();
	return 0;
}
