#include <stdio.h>

#define MAX 100

void roundRobinScheduling(int arrivalTime[], int burstTime[], int n, int timeQuantum) 
{
    int remainingTime[MAX];
    int completionTime[MAX];
    int waitingTime[MAX];
    int turnaroundTime[MAX];
	int i;
    // Initialize the remaining time with burst time for all processes
    for ( i = 0; i < n; i++) 
    {
        remainingTime[i] = burstTime[i];
    }

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) 
    {
        for ( i = 0; i < n; i++) 
        {
            if (remainingTime[i] > 0) 
            {
                if (remainingTime[i] <= timeQuantum) 
				{
                    // Process completes execution
                    currentTime =currentTime + remainingTime[i];
                    completionTime[i] = currentTime;
                    remainingTime[i] = 0;
                    completedProcesses++;
                } 
				else
				{
                    // Process still needs to execute
                    currentTime =currentTime + timeQuantum;
                    remainingTime[i] =remainingTime[i] - timeQuantum;
                }
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    for ( i = 0; i < n; i++) 
    {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    // Display process details in tabular form
    float AWT=0;
    float ATAT=0;
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for ( i = 0; i < n; i++) 
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1,
               arrivalTime[i],
               burstTime[i],
               completionTime[i],
               waitingTime[i],
               turnaroundTime[i]);
               AWT=AWT+waitingTime[i];
               ATAT=ATAT+turnaroundTime[i];
    }
    printf("AWT is %f\n",AWT/n);
    printf("ATAT is %f\n",ATAT/n);
}

int main() {
    int i,n;
    int arrivalTime[MAX];
    int burstTime[MAX];
    int timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time of all the processes: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arrivalTime[i]);
    }

    printf("Enter burst time of all the processes: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &burstTime[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    roundRobinScheduling(arrivalTime, burstTime, n, timeQuantum);

    return 0;
}
