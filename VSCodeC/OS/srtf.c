#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
typedef struct process
{
    int pno;
    int at, bt;
    int et, tat, wt;
    int rt;
    bool complete;
} process;
void srtfscheduler(process p[], int n)
{
    int completed = 0, currtime = 0, min = INT_MAX;
    int min_pos = 0;
    while (completed != n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currtime && p[i].rt < min && p[i].rt > 0)
            {
                min = p[i].rt;
                min_pos = i;
                p[i].complete = true;
            }
        }
        if (p[min_pos].complete == false)
        {
            currtime++;
            continue;
        }
        p[min_pos].rt--;
        min = p[min_pos].rt;
        if (p[min_pos].rt == 0)
        {
            min = INT_MAX;
            completed++;
            p[min_pos].complete = false;
            p[min_pos].et = currtime + 1;
            p[min_pos].wt = p[min_pos].et - p[min_pos].bt - p[min_pos].at;
        }
        currtime++;
    }
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].bt + p[i].wt;
    }
}
double avgwaitingtime(process p[], int n)
{
    double avg = 0.0;
    for (int i = 0; i < n; i++)
    {
        avg = avg + p[i].wt;
    }
    avg = avg / n;
    return avg;
}
double avgturnaroundtime(process p[], int n)
{
    double avg = 0.0;
    for (int i = 0; i < n; i++)
    {
        avg = avg + p[i].tat;
    }
    avg = avg / n;
    return avg;
}
void display(process p[], int n)
{
    srtfscheduler(p, n);
    printf("-----------------------------------------------------------\n");
    printf("Process |\t AT |\t BT |\t CT |\t TAT |\t WT\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t|\t %d \t %d \t %d \t %d \t %d\n", p[i].pno, p[i].at, p[i].bt, p[i].et, p[i].tat, p[i].wt);
        printf("-----------------------------------------------------------\n");
    }
    printf("-----------------------------------------------------------\n");
}
int main(void)
{
    printf("Enter the number of processes : ");
    int n;
    scanf("%d", &n);
    process proc[n];
    printf("Enter the details for each process : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details for process %d ----\n", (i));
        proc[i].pno = i;
        printf("Arrival Time : ");
        scanf("%d", &proc[i].at);
        printf("Burst Time : ");
        scanf("%d", &proc[i].bt);
        proc[i].rt = proc[i].bt;
    }
    display(proc, n);
    printf("Average turn around time is : %lf\n", avgturnaroundtime(proc, n));
    printf("Average waiting time is : %lf\n", avgwaitingtime(proc, n));
}
