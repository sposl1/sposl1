#include<stdio.h>
#define max 30

int main()
{
    int i,j,n,BT[max],AT[max],WT[max],TAT[max],CT[max];
    float AWT=0,ATAT=0;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the Arrival time of process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&AT[i]);
    }
    printf("Enter the Burst time of process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&BT[i]);
    }    

    CT[0]=0;
    printf("process\t Arrival time\t Burst time\t Waiting time\t Turn around time\n");
    for(i=0;i<n;i++)
    {
        WT[i]=0;
        TAT[i]=0;
        CT[i+1]=CT[i]+BT[i];
        WT[i]=CT[i]-AT[i];
        TAT[i]=WT[i]+BT[i];
        AWT=AWT+WT[i];
        ATAT=ATAT+TAT[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);
    }
    AWT=AWT/n;
    ATAT=ATAT/n;
    printf("Average waiting time is %f\n",AWT);
    printf("Average turn around time is %f\n",ATAT);
    return 0;
}