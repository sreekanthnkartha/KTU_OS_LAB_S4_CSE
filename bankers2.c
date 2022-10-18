#include <stdio.h>
#include <stdlib.h>
int n,r;
int alloc[10][10],avail[5],max[10][10],need[10][10],req[10],seq[10],vis[10];
void init(){
for(int i=0;i<10;i++){
    vis[i]=0;
    seq[i]=0;
}
}
int safe(){
   int count=0,valid=1;
   int i,j;
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        vaild=1;
        for(int jj=0;jj<r;jj++){
            if(need[j][jj]>avail[j]){
                vaild=0;
                break;
            }
        }
        if(valid==0){
            continue;
        }
        else{
            if(vis[i]==0){
                seq[count]=j;
                count++;
                vis[i]=1;
            }
        }
    }
   }
   if(count==n){
    return 1;
   }
   else{
    return 0;
   }
}
void safeseq(int s){

if(s==0){
    printf("Safe Sequence : %i\n",s+1);
    for(int i=0;i<n;i++){
        printf("%i ",seq[i]);
    }
}
else{
    init();
    int ii,jj;
    ii=s==1 ?
}
}
main()
{
   printf("Enter the no. of processors\n");
   scanf("%i",&n);
   printf("Enter the no. of resources\n\n");
   scanf("%i",&r);
   print("Enter the Allocation matrix\n");
   for(int i=0;i<n;i++){
    printf("\n p%i",i);
    for(int j=0;j<r;j++){
        scanf("%i",&alloc[i][j]);
    }
   }
   print("Enter the Max matrix\n");
   for(int i=0;i<n;i++){
    printf("\n p%i",i);
    for(int j=0;j<r;j++){
        scanf("%i",&max[i][j]);
    }
   }
   printf("\nEnter available matrix\n");
   for(int i=0;i<n;i++){
    scanf("%i",&avail[i]);
   }
   printf("Need matrix\n");
   for(int i=0;i<n;i++){
    printf("\n p%i",i);
    for(int j=0;j<r;j++){
        need[i][j]=max[i][j]-alloc[i][j];
        printf(" %i",need[i][j]);
    }
   }
   int check;
   check=safe();
   if(check==1){
    printf("Safe sequence occured\n");
    for(int gg=0;gg<3;gg++){
        safeseq(gg);
    }
   }
   else{
     printf("Safe sequence cant find\n");
     exit(0);
   }
   printf("Enter process which need immediate request\n");
   int sel;
   scanf("%i",&sel);
   for(int i=0;i<r;i++){
    scanf("%i",&req[i]);
   }
   check=safereq();
   if(check==1){
    int y=safe();
    if(y==1){
        printf("Safe sequence occured\n");
        safeseq(0);
    }
    else{
        printf("Safe sequence cant find\n");
    }
   }
   scanf("%i",&);
   scanf("%i",&);
   printf("\n");
   printf("\n");
}
