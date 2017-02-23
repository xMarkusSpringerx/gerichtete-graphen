#include <stdio.h>
#include <stdlib.h>

#include "DGraphAL.h"

#define MAX 10

int main(int argc, const char * argv[])
{
    int n;
    printf("Max Knoten: ");
    scanf("%d", &n);
    
    Init(n);
    
    //Delete(n, 2, 4);
    
    PrintResult();
    // Destroy(n);
    
    TopSort();

    return 0;
}
