#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,initial;
	printf("Enter the Number of Request\n");
	 scanf("%d",&n);
        printf("Enter the Request Sequence\n");
	for(i=0;i<n;i++)
	        scanf("%d",&RQ[i]);
	 printf("Enter Initial Head Position\n");
	        scanf("%d",&initial);
	    
			for(i=0;i<n;i++)
	  		  {
	  		  	TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
	 		   	initial=RQ[i];
	    		  }
	 printf("Total Head Momemnt is %d",TotalHeadMoment);
}