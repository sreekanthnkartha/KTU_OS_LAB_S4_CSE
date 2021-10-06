#include <stdio.h>
#include <stdlib.h>
int n, a[40], f, c;
void fifo()
{
    int frame[f];
    for (int i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    int count = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        int fcheck = 0;
        for (int k = 0; k < f; k++)
            if (a[i] == frame[k])
                fcheck = 1;
        if (fcheck)
        {
            int ui = 9;
        }
        else
        {
            frame[j] = a[i];

            j = (j + 1) % f;
            count++;
        }
    }

    printf("%i", count);
}
void optimal()
{
    int frame[f];
    for (int i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    int count = 0, e;
    for (int i = 0; i < n; i++)
    {
        int fd = 0;

        for (int j = 0; j < f; j++)
        {

            if (a[i] == frame[j])
            {
                fd = 1;
                break;
            }
        }
        if (fd == 0)
        {
            frame[count++] = a[i];
            if (count == f)
            {
                e = i;
                break;
            }
        }
    }
    for (int i = e + 1; i < n; i++)
    {
        int fd = 0;
        for (int j = 0; j < f; j++)
        {

            if (a[i] == frame[j])
            {
                fd = 1;
                break;
            }
        }
        if (fd == 0)
        {

            if (i == n - 1)
            {
                count++;
            }
            else
            {

                int s = 0, si = 0, t = 0;
                for (int k = 0; k < f; k++)
                {

                    t = 0;
                    int j;
                    for (j = i + 1; j < n; j++)
                    {

                        t++;
                        if (a[j] == frame[k])
                        {
                            break;
                        }
                    }
                    if (j == n && frame[k] != a[n - 1])
                    {
                        t++;
                    }
                    if (s < t)
                    {

                        s = t;
                        si = k;
                    }
                }
                frame[si] = a[i];
                count++;
            }
        }
    }
    printf("pg: %i", count);
}
void lru()
{
    int time;
    printf("enter the instance\n");
    scanf("%i", &time);
    printf("Frame1\tFrame2\tFrame3\n");
    int frame[f];
    for (int i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    int count = 0, e;
    for (int i = 0; i < n; i++)
    {
        int fd = 0;

        for (int j = 0; j < f; j++)
        {

            if (a[i] == frame[j])
            {
                fd = 1;
                break;
            }
        }
        if (fd == 0)
        {
            frame[count++] = a[i];
            if (count == f)
            {
                e = i;
                break;
            }
        }
        if (time == i + 1)
        {
            for (int g = 0; g < f; g++)
                printf("%i\t", frame[g]);
            printf("\n");
        }
    }
    if (time == e + 1)
    {
        for (int g = 0; g < f; g++)
            printf("%i\t", frame[g]);
        printf("\n");
    }
    for (int i = e + 1; i < n; i++)
    {
        int fd = 0;
        for (int j = 0; j < f; j++)
        {

            if (a[i] == frame[j])
            {
                fd = 1;
                break;
            }
        }
        if (fd == 0)
        {

            if (i == n - 1)
            {
                count++;
            }
            else
            {
                // printf("%i %i",f,s);
                // int k ;
                int s = 0, si = 0, t = 0;
                for (int k = 0; k < f; k++)
                {

                    t = 0;
                    int j;
                    for (j = i - 1; j >= 0; j--)
                    {

                        t++;
                        if (a[j] == frame[k])
                        {
                            break;
                        }
                    }
                    if (s < t)
                    {

                        s = t;
                        si = k;
                    }
                }
                // printf("wsda");
                frame[si] = a[i];
                count++;
            }
        }
        if (time == i + 1)
        {
            for (int g = 0; g < f; g++)
                printf("%i\t", frame[g]);
            printf("\n");
        }
    }
    printf("pg: %i", count);
}
int main(int argc, char const *argv[])
{
    printf("Enter the length of reference string\n");
    scanf("%i", &n);
    printf("Enter the Reference string\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
    }
    printf("Enter the number of frames\n");
    scanf("%i", &f);
    // fifo();
    // optimal();
    lru();
    return 0;
}
/*
13
7 0 1 2 0 3 0 4 2 3 0 3 2
3
*/
