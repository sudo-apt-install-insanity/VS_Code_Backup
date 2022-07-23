// Banker's Algorithm
#include <stdio.h>
int main()
{
    int ainesh_n, ainesh_m, i, j, k;
    ainesh_n = 5;
    ainesh_m = 3;
    int ainesh_alloc[5][3]; // = {{ 0, 1, 0 },
                            //	  { 2, 0, 0 },
                            //	  { 3, 0, 2 },
                            //	  { 2, 1, 1 },
                            //	  { 0, 0, 2 } };

    int ainesh_max[5][3]; // = {{ 7, 5, 3 },
                          //	{ 3, 2, 2 },
                          //	{ 9, 0, 2 },
                          //	{ 2, 2, 2 },
                          //	{ 4, 3, 3 } };

    int ainesh_avail[3]; //= { 3, 3, 2 };

    printf("Enter allocation matrix: \n");
    for (i = 0; i < ainesh_n; i++)
    {
        for (j = 0; j < ainesh_m; j++)
        {
            scanf("%d", &ainesh_alloc[i][j]);
        }
    }
    printf("Enter maximum matrix: \n");
    for (i = 0; i < ainesh_n; i++)
    {
        for (j = 0; j < ainesh_m; j++)
        {
            scanf("%d", &ainesh_max[i][j]);
        }
    }
    printf("Enter available resources: \n");
    for (i = 0; i < ainesh_m; i++)
    {
        scanf("%d", &ainesh_avail[i]);
    }

    int ainesh_need[ainesh_n][ainesh_m];
    for (i = 0; i < ainesh_n; i++)
    {
        for (j = 0; j < ainesh_m; j++)
            ainesh_need[i][j] = ainesh_max[i][j] - ainesh_alloc[i][j];
    }

    int ainesh_f[ainesh_n], ainesh_ans[ainesh_n], ind = 0;
    for (k = 0; k < ainesh_n; k++)
    {
        ainesh_f[k] = 0;
    }

    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < ainesh_n; i++)
        {
            if (ainesh_f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < ainesh_m; j++)
                {
                    if (ainesh_need[i][j] > ainesh_avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ainesh_ans[ind++] = i;
                    for (y = 0; y < ainesh_m; y++)
                        ainesh_avail[y] += ainesh_alloc[i][y];
                    ainesh_f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < ainesh_n; i++)
    {
        if (ainesh_f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < ainesh_n - 1; i++)
            printf(" P%d ->", ainesh_ans[i]);
        printf(" P%d", ainesh_ans[ainesh_n - 1]);
    }

    return (0);
}
