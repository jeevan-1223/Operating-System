#include <stdio.h>
int main() 
{
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], rem[n];
    for (int i = 0; i < n; i++) 
	{
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];  
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    int time = 0, done;
    while (1)
	 {
        done = 1;
        for (int i = 0; i < n; i++) 
		{
            if (rem[i] > 0) 
			{
                done = 0; 
                if (rem[i] > quantum)
				 {
                    time += quantum;
                    rem[i] -= quantum;
                } 
                else 
				{
                    time += rem[i];
                    wt[i] = time - bt[i];  
                    rem[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
    for (int i = 0; i < n; i++) 
	{
        tat[i] = bt[i] + wt[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) 
	{
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    return 0;
}

