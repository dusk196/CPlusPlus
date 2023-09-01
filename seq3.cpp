#include <iostream>
#include <string>
#include<conio.h>
#include <stdlib.h>

using namespace std;


class Sequence
{
	string s;
	
	public:
		
		Sequence(string z)	// CONSTRUCTOR DECLARED
		{
			s = z;
			cout << "\nStrings created using constructor!";
		}
		
		~Sequence()	// DESTRUCTORS DECLARED
		{
			s.clear();
			cout << "\nCreated strings deleted using destructor!";
			getch();
		}
		
		void insert()
		{
			string p;
			int m, n;
			cout << "\nEnter the string to be inserted : ";
			cin >> p; // getline(cin,p);
			cout << "\nInput the position : ";
			cin >> m;
			n = s.size();
			if(m <= n)
			{
				s.insert(m,p);
			}
			else
			{
				cout << "\nGiven position is out of bound!";
			}
		}
		
		void del()
		{
			int x, y, o;
			o = s.size();
			cout << "\nInput the starting position to delete : ";
			cin >> x;
			cout << "\nInput the ending position to delete : ";
			cin >> y;
			if (x>=0 && y<=o)
			{
				s.erase(x,y);
			}
			else
			{
				cout << "\nGiven position is out of bound!";
			}
		}
		
		string find()
		{
			string b, ret;
			cout << "\nEnter the substring to find in the main string : ";
			cin >> b; // getline(cin,b);
			size_t found = s.find(b);
  			if (found!=string::npos)
  			{
   				cout << "\nPosition : " << found;
   				return "true";
   			}
   			else
   			{
   				return "false";
			}
		}
		
		void display()
		{
			cout << "\nPresent string : " << s;
		}
		
};


int main()
{
	string a, r;
	int choice;
	cout << "Enter a string : ";
	cin >> a; // getline(cin,a);
	Sequence str(a);
    do
    {
		cout << "\n\n1: Insert a string\n2: Delete a string\n3. Find a substring inside a string\n4. Display the string\n5. Exit\n\n\nEnter your choice : ";
    	cin >> choice;
        switch(choice)
        {
            case 1:
                str.insert();
                cout << "\nGiven string inserted successfylly";
                str.display();
                break;
            case 2:
                str.del();
                cout << "\nString deleted successfylly";
                str.display();
                break;
            case 3:
				r=str.find();
				if(r=="true")
					cout << "\nThe substring is found in the main string";
				else
					cout << "\nThe substring isn't found in the main string";
            	break;
            case 4:
            	str.display();
            	break;
        	case 5:
        		cout << "\nThank you. Now this program will exit.";
        		break;
            default:
                cout << "\nWrong Input";
        }
    } while(choice!=5);
	return 0;
}
