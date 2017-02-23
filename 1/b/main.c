#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "GraphAL.h"

#define MAX 10

int main(int argc, const char * argv[])
{
    int n;
    printf("Max Knoten:");
    scanf("%d", &n);

    Init(n);
    Insert(n, 1, 2);
    Insert(n, 1, 3);
    Insert(n, 1, 4);
    Insert(n, 1, 5);
    Insert(n, 1, 6);
    
    PrintResult(n);
    Delete(n, 1, 2);
    Delete(n, 1, 3);
    Delete(n, 1, 4);
    Delete(n, 1, 5);
    Delete(n, 1, 6);
    PrintResult(n);
    
    return 0;
}
