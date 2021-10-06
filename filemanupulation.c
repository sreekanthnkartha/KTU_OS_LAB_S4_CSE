#include <stdio.h>
struct file
{
    int si;
    int len;
    int b[100];
    int wrted;
    struct node *k;
} f[100];
int mem[100], n;
struct node
{
    int n;
    struct node *next;
};
int seq()
{
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        printf("file%i\n", i + 1);
        scanf("%i", &f[i].si);
        scanf("%i", &f[i].len);
        int check = 0;
        for (int j = f[i].si; j < f[i].si+f[i].len; j++)
        {
            if (mem[j] == 1)
            {
                f[i].wrted = 0;
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            f[i].wrted = 1;
            for (int j = f[i].si; j < f[i].si+f[i].len; j++)
            {
                mem[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(f[i].wrted==0)
        printf("file%i NOT ALOCATED\n",i+1);
        else
        printf("file%i ALOCATED\n",i+1);
    }

}
int ind()
{
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        printf("file%i\n", i + 1);
        scanf("%i", &f[i].si);
        scanf("%i", &f[i].len);
        int check = 0;
        if(mem[f[i].si]==1)
        {
            f[i].wrted=0;
            f[i].b[0]=-1;
        }
        else
        {
            mem[f[i].si]=1;

            for(int j=0;j<f[i].len;j++)
            {
                scanf("%i",&f[i].b[j]);
                if(mem[f[i].b[j]]==1)
                {
                    f[i].wrted=0;
                    f[i].b[0]=-1;
                    check=1;
                    break;
                }
                else
                {
                    mem[f[i].b[j]]=1;
                }
            }
            if(check==0)
            {
                f[i].wrted=1;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if(f[i].wrted==0)
        printf("file%i NOT ALOCATED\n",i+1);
        else
        printf("file%iALOOCATED\n",i+1);
    }

}
int main(int argc, char const *argv[])
{
    // seq();
    // ind();
    return 0;
}
