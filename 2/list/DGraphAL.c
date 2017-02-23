#include <stdio.h>
#include <stdlib.h>
#include "DGraphAL.h"

typedef enum bool
{
    true,
    false
}bool;

#define MAX 10

typedef struct Node* NodeList;
typedef NodeList AryList[MAX];
typedef struct Node
{
    int v;
    NodeList next;
} Node;

static AryList l;
int reference[MAX];
int visited[MAX];

int anzahl;


void Init(int n)
{
    
    int i;
    n--;
    for (i = 0; i < n; i++)
    {
        l[i] = NULL;
    }
    anzahl = n;
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

void Insert(int src, int dest)
{
    if(anzahl+1 >= dest && anzahl+1 >= src)
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
    else
    {
        printf("\n%d - src: %d - dest: %d\n", (anzahl+1), src, dest);
    }
}

void Delete(int src, int dest)
{
    NodeList prev, cur;
    if(l[src] == NULL)
    {
        printf("Leere Liste\n");
    }
    else
    {
        prev = NULL;
        cur = l[src];
        while(cur->v != dest && cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        if(dest == cur->v)
        {
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
}

void Destroy()
{
    int i;
    NodeList last, cur;
    
    for(i = 0; i < anzahl; i++)
    {
        cur = l[i];
        while (cur != NULL)
        {
            last = cur->next;
            free(cur);
            cur = last;
        }
    }
}

void Sort(int i)
{
    NodeList cur;
    printf("%d\n", i);
    cur = l[i];
    visited[i] = 1;
    while (cur != NULL)
    {
        reference[cur->v]--;
        if(reference[cur->v] == 0)
        {
            Sort(cur->v);
        }
        cur = cur->next;
    }
}

void TopSort()
{
    int i;
    NodeList cur;
    
    for (i = 1; i <= anzahl; i++)
    {
        reference[i] = 0;
        visited[i] = 0;
    }
    for(i = 1; i <= anzahl; i++)
    {
        cur = l[i];
        if(cur != NULL)
        {
            while(cur != NULL)
            {
                reference[cur->v]++;
                cur = cur->next;
            }
        }
    }
    
    for(i = 1; i <= anzahl; i++)
    {
        if(reference[i] == 0)
        {
            if(!visited[i])
            {
                Sort(i);
            }
        }
    }
}

void PrintResult()
{
    int i;
    NodeList cur;
    for(i = 0; i < anzahl; i++)
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
