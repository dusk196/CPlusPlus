#include<iostream>
#include<math.h>

using namespace std;


template<class T>
class matrix
{
    int n;
	public:
		void mat()
		{
		    T  matrix[10][10], ratio, det, i, j, k, n;
    		cout << "Enter order of matrix: ";
    		cin >> n;
    		cout << "Enter the matrix: \n";
    		for(i = 0; i < n; i++)
			{
    		    for(j = 0; j < n; j++)
				{
    		        cin >> matrix[i][j];
    		    }
    		}
		    /* Conversion of matrix to upper triangular */
		    for(i = 0; i < n; i++)
			{
		        for(j = 0; j < n; j++)
				{
		            if(j>i)
					{
		                ratio = matrix[j][i]/matrix[i][i];
			                for(k = 0; k < n; k++)
							{
			                    matrix[j][k] -= ratio * matrix[i][k];
	                		}
            		}
        		}
    		}
		    det = 1; //storage for determinant
    		for(i = 0; i < n; i++)
        		det *= matrix[i][i];
    		cout << "The determinant of matrix is: " << det;
		}
};


int main()
{
	matrix <int> m;
	m.mat();
    return 0;
}
