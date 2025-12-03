#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESSES 10
typedef struct 
{
    int id;
    int priority;
    int burst_time;
    int waiting_time;
} 
Process;
void calculateWaitingTime(Process processes[], int n) 
{
    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++) 
	{
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}
void scheduleProcesses(Process processes[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (processes[j].priority < processes[j + 1].priority) 
			{
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
void printSchedule(Process processes[], int n) 
{
    printf("Process ID\tPriority\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority, processes[i].burst_time, processes[i].waiting_time);
    }
}
int main() 
{
    Process processes[MAX_PROCESSES];
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
	{
        printf("Enter Process ID, Priority, and Burst Time for Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].id, &processes[i].priority, &processes[i].burst_time);
    }
    scheduleProcesses(processes, n);
    calculateWaitingTime(processes, n);
    printSchedule(processes, n);
    return 0;
}

