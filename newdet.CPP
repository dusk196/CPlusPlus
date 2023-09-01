#include <iostream>
#include<math.h>
using namespace std;

template <class T>
T det(T n, T mat[10][10])
{
	T c, subi, i, j, subj, submat[10][10], d;  
        if (n == 2) 
        {
            return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
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


int main()
{
        int n, k, mat[10][10], i, j;
        cout << "\nEnter the order of matrix : " << "\n";
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
        cout << "\nDeterminant : " << k << "\n";
        return 0;
}
