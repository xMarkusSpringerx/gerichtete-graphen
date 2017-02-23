#include <stdio.h>
#include <stdlib.h>

#include "GraphAL.h"
#define MAX 10

typedef enum bool
{
    true,
    false
}bool;

typedef struct Node* NodeList;
typedef NodeList AryList[MAX];
typedef struct Node
{
    int v;
    NodeList next;
} Node;


static AryList l;

void Init(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        l[i] = NULL;
    }
}

static NodeList newNode(int val)
{
    NodeList n;
    n = malloc(sizeof(Node));
    if (n == NULL)
    {
        printf("ERROR");
        exit(354);
    } /* END if */
    n->next = NULL;
    n->v = val;
    
    return n;
}

void Insert(int n, int src, int dest)
{
    if(n >= dest && n >= src)
    {
        Append(src, dest);
        Append(dest, src);
    }
}

void Append(int src, int dest)
{
    NodeList n, last;
    n = newNode(dest);
    if(l[src] == NULL)
    {
        l[src] = n;
    }
    else
    {
        last = l[src];
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = n;
    }
}

void Delete(int n, int src, int dest)
{
    DeleteNode(n, src, dest);
    DeleteNode(n, dest, src);
}

void DeleteNode(int n, int src, int dest)
{
    NodeList prev, cur;
    if(l[src] == NULL)
    {
        printf("Keine Einträge vorhanden");
    }
    else
    {
        prev = NULL;
        cur = l[src];
        while(cur->v != dest)
        {
            prev = cur;
            cur = cur->next;
        }
        if(prev == NULL)
        {
            l[src] = cur->next;
        }
        else
        {
            prev->next = cur->next;
        }
        printf("\n%d\n", cur->v);
        free(cur);
    }
}

void Destroy(int n)
{
    int i;
    NodeList last;
    for(i = 0; i < n; i++)
    {
        while (l[i]->next != NULL)
        {
            last = l[i]->next;
            free(l[i]);
            l[i] = last;
        }
    }
}

void PrintResult(int n)
{
    int i;
    NodeList cur;
    for(i = 0; i <=n; i++)
    {
        cur = l[i];
        if(cur != NULL)
        {
            printf("\n%d -> ", i);
            while(cur != NULL)
            {
                printf("%d ", cur->v);
                cur = cur->next;
            }
            printf("\n");
        }
    }
    
}