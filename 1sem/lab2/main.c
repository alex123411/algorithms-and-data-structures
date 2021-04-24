#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int matrix(){
    int m = 0;
    int n = 0;
    printf("ВВедіть висоту: ");
    scanf("%i",&m);
    printf("ВВедіть ширину: ");
    scanf("%i",&n);
    int M[m][n];
    int m1 = m - 1;
    int n1 = n - 1;
    int j = 0;

    while (j < m * n) //обхід
    {
        for (int i = n1; i >= n - n1 - 1; i--)
        {
            
            M[m1][i] = j;
            j++;
        }
        
        for (int i = m1 - 1; i > m - m1 - 1; i--)
        {
            M[i][n-n1-1] = j;
            j++;
        }
        
        for (int i = n - n1 - 1; i <= n1; i++)
        {
            
            M[m-m1-1][i] = j;
            j++;
        }
        
        for (int i = m - m1; i < m1; i++)
        {
            
            M[i][n1] = j;
            j++;
        }
       
        m1 --;
        n1 --;
    }
    for (size_t i = 0; i < m; i++)
    {
        for (size_t k = 0; k < n; k++)
        {
            printf(" %i",  M[i][k]);
        }
        printf("\n"  );
    }
    printf(" qwe"  );
}


int main()
{
    int l1 = 0;
    printf("1)Вивести матрицю від 0 до M*N\n2)Вивети матрицю рандомних чисел\n");
    scanf("%i",&l1);
    if (l1 == 1){
        matrix();
    }
    else
    {
    int m = 0;
    int n = 0;
    int Max = 0;
    printf("ВВедіть висоту: ");
    scanf("%i",&m);
    printf("ВВедіть ширину: ");
    scanf("%i",&n);
    int M[m][n];
    srand(time(0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            M[i][j] = rand() % 101 + (-50);
            printf(" %i",  M[i][j]);
                     
        }
        printf("\n");
    }
    int m1 = m - 1;
    int n1 = n - 1;
    int j = 0;
    int min = 0;
    Max = M[m-1][n-1];
    while (j < m * n) //обхід
    {
        for (int i = n1; i >= n - n1 - 1; i--)
        {
            printf("%i ", M[m1][i]);
            j++;
            if (m1 > i || m1+i>m)
            {              
                if (Max <= M[m1][i-1])
                {
                    Max = M[m1][i-1];
                }
            }          
            else if (m1<i)
            {
                min = M[m1][i];
                if (min >= M[m1][i-1])
                {
                    min = M[m1][i-1];
                }                
            } 
        }        
        for (int i = m1 - 1; i > m - m1 - 1; i--)
        {
            printf("%i ", M[i][n-n1-1]);
            j++;
            if (i>n-n1-1)
            {
                if (Max <= M[i][n-n1-1])
                {
                    Max = M[i][n-n1-1];
                }
            }
            else if (m1<n-n1-1 && i+n-n1-1<m)
            {
                if (min >= M[i][n-n1-1])
                {
                    min = M[i][n-n1-1];
                }
            } 
        }       
        for (int i = n - n1 - 1; i <= n1; i++)
        {
            printf("%i ", M[m-m1-1][i]);
            j++;
             if (m-m1-1<i && i+m-m1-1<m)
            {
                if (min >= M[m-m1-1][i])
                {
                    min = M[m-m1-1][i];
                }
            } 
        }       
        for (int i = m - m1; i < m1; i++)
        {
            printf("%i ", M[i][n1]);
            j++;
             if (n1+i > m)
            {
                if (Max <= M[i][n1])
                {
                    Max = M[i][n1];
                }
            }
            else if (i<n1 && i+n1<m)
            {
                if (min >= M[i][n1])
                {
                    min = M[i][n1];
                }
            } 
        }      
        m1 --;
        n1 --;
    }
    printf("\n\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n ; j++)
            {
                if  (Max == M[i][j])
                {
                printf("Максимальний під головною і побічною:[%i][%i] %i\n",i ,j, Max);
                break;
                }          
            }  
        }
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            if  (min == M[i][j])
            {
               printf("Мінімальний між головною і побічною:[%i][%i] %i\n",i ,j, min);
               break;
            }          
        }  
    } 
    }
} 