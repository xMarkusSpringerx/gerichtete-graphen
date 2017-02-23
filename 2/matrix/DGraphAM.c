#include "DGraphAM.h"
#define MAX 10
#include <stdio.h>
#include <string.h>

typedef enum bool {
    false,
    true
}bool;

typedef bool Matr[MAX][MAX];

Matr matrix;

int anzahl;

bool visited[MAX];

void Init(int n)
{
    anzahl = n;
    int i,j;
    
    for (i = 0; i < MAX; i++) {
        visited[i] = false;
    }
    
    for(i = 0; i < n; i++)
    {
        for(j= 0; j< n; j++)
        {
            matrix[i][j] = false;
        }
    }
}


bool IsEmptyCol(int cNr) {
    int i;
    for(i = 0; i < anzahl; i++) {
        if(matrix[i][cNr] && !visited[i]) {
            return true;
        }
    }
    return false;
}



void TopSort(void) {
    int i;
    for(i = 0; i < anzahl; i++) {
        
        
        if(!IsEmptyCol(i) && !visited[i]) {
            printf("%d ", i+1);
            visited[i] = true;
            TopSort();
        }

    }

}

void Insert(int n, int src, int dest)
{
    if(n >= src && n >= dest)
    {
        matrix[src-1][dest-1] = true;
    }
}

void Delete(int n, int src, int dest)
{
    if(n >= src && n >= dest)
    {
        matrix[src-1][dest-1] = false;
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
