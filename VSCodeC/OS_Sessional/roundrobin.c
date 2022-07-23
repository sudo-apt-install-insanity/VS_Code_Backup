#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

struct process_struct
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, rt, start_time;
    int bt_rem;
} ps[100];

int findmax(int a, int b)
{
    return a > b ? a : b;
}

int comparatorAT(const void *a, const void *b)
{
    int x = ((struct process_struct *)a)->at;
    int y = ((struct process_struct *)b)->at;
    if (x < y)
        return -1;
    else if (x >= y)
        return 1;
}

int comparatorPID(const void *a, const void *b)
{
    int x = ((struct process_struct *)a)->pid;
    int y = ((struct process_struct *)b)->pid;
    if (x < y)
        return -1;
    else if (x >= y)
        return 1;
}

int main()
{

    int n, idx;
    int cpu_utilization;

    bool visited[100] = {false}, is_first_process = true;
    int curr_time = 0;
    int completed = 0, tq, total_idle_time = 0, length_cycle;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    int queue[100], front = -1, rear = -1;
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process %d Arrival Time: ", i);
        scanf("%d", &ps[i].at);
        ps[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process %d Burst Time: ", i);
        scanf("%d", &ps[i].bt);
        ps[i].bt_rem = ps[i].bt;
    }

    printf("\nEnter time quanta: ");
    scanf("%d", &tq);

    qsort((void *)ps, n, sizeof(struct process_struct), comparatorAT);

    front = rear = 0;
    queue[rear] = 0;
    visited[0] = true;

    while (completed != n)
    {
        idx = queue[front];

        front++;

        if (ps[idx].bt_rem == ps[idx].bt)
        {
            ps[idx].start_time = findmax(curr_time, ps[idx].at);
            total_idle_time += (is_first_process == true) ? 0 : ps[idx].start_time - curr_time;
            curr_time = ps[idx].start_time;
            is_first_process = false;
        }

        if (ps[idx].bt_rem - tq > 0)
        {
            ps[idx].bt_rem -= tq;
            curr_time += tq;
        }
        else
        {
            curr_time += ps[idx].bt_rem;
            ps[idx].bt_rem = 0;
            completed++;

            ps[idx].ct = curr_time;
            ps[idx].tat = ps[idx].ct - ps[idx].at;
            ps[idx].wt = ps[idx].tat - ps[idx].bt;
            ps[idx].rt = ps[idx].start_time - ps[idx].at;

            sum_tat += ps[idx].tat;
            sum_wt += ps[idx].wt;
            sum_rt += ps[idx].rt;
        }

        for (int i = 1; i < n; i++)
        {
            if (ps[i].bt_rem > 0 && ps[i].at <= curr_time && visited[i] == false)
            {

                queue[++rear] = i;
                visited[i] = true;
            }
        }

        if (ps[idx].bt_rem > 0)

            queue[++rear] = idx;

        if (front > rear)
        {
            for (int i = 1; i < n; i++)
            {
                if (ps[i].bt_rem > 0)
                {
                    queue[rear++] = i;
                    visited[i] = true;
                    break;
                }
            }
        }
    }
    qsort((void *)ps, n, sizeof(struct process_struct), comparatorPID);

    printf("\nProcess No.\tAT\tCPU Burst Time\tStart Time\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n", i, ps[i].at, ps[i].bt, ps[i].start_time, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    printf("\n");

    printf("\nAverage TAT= %.2f", (float)sum_tat / n);
    printf("\nAverage WT= %.2f", (float)sum_wt / n);
    printf("\nAverage RT= %.2f", (float)sum_rt / n);
    return 0;
}
