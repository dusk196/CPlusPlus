#include<iostream>
#include<math.h>

#define size 10
using namespace std;
double d=0;

template<class any>


class matrix
{
    int row, col;
    any a[size][size];
    public:
        void getdata();
        matrix operator+(matrix m);
        matrix operator*(matrix c);
        void display();
};


template<class any>
void matrix<any> :: getdata()
{
    cout << "\nEnter row size : ";
    cin >> row;
    cout << "\nEnter column size : ";
    cin >> col;
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cout << "\nEnter elements : ";
            cin >> a[i][j];
        }
    }
}


template<class any>
matrix<any> matrix<any> :: operator+(matrix m)
{
    int i, j;
    matrix<any> temp1;
    temp1.row=row;
    temp1.col=col;
    if((row==m.row)&&(col==m.col))
    {
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                temp1.a[i][j]=a[i][j]+m.a[i][j];
            }
        }
        return temp1;
    }
    else
        cout << "\nAddition not possible\n";
    temp1.row=0;
    temp1.col=0;
    return temp1;
}


template<class any>
matrix<any> matrix<any> :: operator*(matrix c)
{
    int i, j, k;
    any sum=0;
    matrix<any> temp2;
    temp2.row=row;
    temp2.col=col;
    if(col==c.row)
    {
        for(i=0; i<row; i++)
        {
            for(j=0; j<c.col; j++)
            {
                for(k=0; k<c.row; k++)
                {
                    sum=sum+a[i][k]*c.a[k][j];
                }
                temp2.a[i][j]=sum;
                sum=0;
            }
        }
        return temp2;
    }
    else
        cout << "\nMultiplication not possible\n";
    temp2.row=0;
    temp2.col=0;
    return temp2;
}


template<class any>
void matrix<any> :: display()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << "\t" << a[i][j];
            cout << "\n";
        }
    }
}


int main()
{
    matrix<int> b, d, r;
    int y, n, k, mat[10][10], i, j;
    do
    {
        cout << "\n\n1: Matrix Addition\n2: Matrix Multiplication\n3: Matrix Determinant\n\n\nEnter your choice : ";
        cin >> y;
        switch(y)
        {
            case 1:
                b.getdata();
                d.getdata();
                r=b+d;
                r.display();
                break;
            case 2:
                b.getdata();
                d.getdata();
                r=b*d;
                r.display();
                break;
            case 3:
	        cout << "\nEnter the order of matrix : " ;
        	cin >> n;
        	for(i=0;i<n;i++)
        	{
        	    for(j=0;j<n;j++)
        	    {
        		cout << "Enter the elements of matrix [M]*[N] = [" << i << "]*[" << j << "] : ";
        	        cin >> mat[i][j];
        	    }
        	}
		k = det<int>(n, mat);
        	cout << "\nDeterminant : " << k;
                break;
            default:
                cout << "\nWrong Input";
        }
    }while(1);
    return 0;
}


template <class any>
any det(any n, any mat[10][10])
{
	any c, subi, i, j, subj, submat[10][10];  
        if (n == 2) 
        {
            return ( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
        }
        else
        {  
            for(c = 0; c < n; c++)
            {  
                subi = 0;  
                for(i = 1; i < n; i++)
                {  
                    subj = 0;
                    for(j = 0; j < n; j++)
                    {    
                        if (j == c)
                        {
                            continue;
                        }
                        submat[subi][subj] = mat[i][j];
                        subj++;
                    }
                    subi++;
                }
            d = d + (pow(-1 ,c) * mat[0][c] * det(n - 1 ,submat));
            }
        }
        return d;
}
