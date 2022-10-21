#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int n, np;

struct hole
{
    int size;
    bool visited;
} h[40];
struct pro
{
    int size;
    int index;
} p[40];

//Initialise Function: 
void in()
{
    int i;
//  Clear the index of every process.
    for (i = 0; i < np; i++)
    {
        p[i].index = -1;
    }
//  Make every node unvisited.
    for (i = 1; i <= n; i++)
    {
        h[i].visited = false;
    }
}

// First Fit
// In this method, first job claims the first available memory with space more than or equal to it’s size.
void ff()
{
    int i, j;
    in();
    for (i = 0; i < np; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (h[j].visited == false && h[j].size >= p[i].size)
            {
                h[j].visited = true;
                p[i].index = j;
                break;
            }
        }
    }
    for (i = 0; i < np; i++)
    {
        if (p[i].index != -1)
        {
            printf("\n P%i - H%i", i, p[i].index);
        }
        else
        {
            printf("\n P%i - allocation not possible", i);
        }
    }
    printf("\n");
}

// Best Fit
// In this method, the operating system first searches the whole of the memory 
// according to the size of the given job and allocates it to the closest-fitting 
// free partition in the memory, making it able to use memory efficiently.
void bf()
{
    int i, j;
    in();
    int t, s, si;
    for (i = 0; i < np; i++)
    {
        s = INT_MAX;
        si = -1;
        for (j = 1; j <= n; j++)
        {
            if (h[j].visited == false && h[j].size >= p[i].size)
            {
                if (h[j].size < s)
                {
                    s = h[j].size;
                    si = j;
                }
            }
        }
        if (si != -1)
        {
            p[i].index = si;
            h[si].visited = true;
        }
    }
    for (i = 0; i < np; i++)
    {
        if (p[i].index != -1)
        {
            printf("\n P%i - H%i", i, p[i].index);
        }
        else
        {
            printf("\n P%i - allocation not possible", i);
        }
    }
    printf("\n");
}

// Worst Fit
// In this allocation technique, the process traverses the whole memory and always search for the largest hole/partition, 
// and then the process is placed in that hole/partition.
void wf()
{
    int i, j;
    in();
    int t, s, si;
    for (i = 0; i < np; i++)
    {
        s = 0;
        si = -1;
        for (j = 1; j <= n; j++)
        {
            if (h[j].visited == false && h[j].size >= p[i].size)
            {
                if (h[j].size > s)
                {
                    s = h[j].size;
                    si = j;
                }
            }
        }
        if (si != -1)
        {
            p[i].index = si;
            h[si].visited = true;
        }
    }
    for (i = 0; i < np; i++)
    {
        if (p[i].index != -1)
        {
            printf("\n P%i - H%i", i, p[i].index);
        }
        else
        {
            printf("\n P%i - allocation not possible", i);
        }
    }
    printf("\n");
}

// Driver Code
// Main

int main()
{
    int c;
    printf("Enter the number of holes\n");
    scanf("%i", &n);
    printf("Enter the sizes of holes\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &h[i].size);
    }
    printf("Number of processes\n");
    scanf("%i", &np);
    printf("Sizes of processes\n");
    for (int i = 0; i < np; i++)
    {
        scanf("%i", &p[i].size);
    }
    while (1)
    {
        printf("\n1.First Fit\n");
        printf("2.Best Fit\n");
        printf("3.Worst Fit\n");
        printf("4.Exit\n");
        printf("->");
        scanf("%i", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            ff();
            break;
        case 2:
            bf();
            break;
        case 3:
            wf();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter correct option\n");
        }
    }
}

// END
