#define MAX 10
#include <stdio.h>


typedef enum bool {
    true,
    false
}bool;
typedef bool Matr[MAX][MAX];

Matr matrix;

int anzahl;

void Init(int n)
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j= 0; j< n; j++)
        {
            matrix[i][j] = false;
        }
    }
}

void Insert(int n, int src, int dest)
{
    if(n >= src && n >= dest)
    {
        matrix[src-1][dest-1] = true;
        matrix[dest-1][src-1] = true;
    }
}

void Delete(int n, int src, int dest)
{
    if(n >= src && n >= dest)
    {
        matrix[src-1][dest-1] = false;
        matrix[dest-1][src-1] = false;
    }
}

void PrintResult(int n)
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j= 0; j< n; j++)
        {
            if(matrix[i][j] == true)
            {
                printf("T ");
            }
            else
            {
                printf("F ");
            }
            
        }
        printf("\n");
    }
    printf("\n");
}
