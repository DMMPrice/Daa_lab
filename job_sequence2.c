#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct job
{
    int name;
    int profit;
    int deadline;
    int slot;
} JOB;

int merge(JOB *jobs, int beg_index, int mid_index, int end_index)
{
    int left_array_size = mid_index - beg_index + 1;
    int right_array_size = end_index - mid_index;
    JOB left_array[left_array_size], right_array[right_array_size];
    for (int i = 0; i < left_array_size; i++)
    {
        left_array[i] = jobs[beg_index + i];
    }
    for (int i = 0; i < right_array_size; i++)
    {
        right_array[i] = jobs[mid_index + 1 + i];
    }
    int a = 0, b = 0, c = beg_index;
    while (a < left_array_size && b < right_array_size)
    {
        if (left_array[a].profit >= right_array[b].profit)
        {
            jobs[c] = left_array[a];
            a++;
        }
        else
        {
            jobs[c] = right_array[b];
            b++;
        }
        c++;
    }
    while (a < left_array_size)
    {
        jobs[c] = left_array[a];
        a++;
        c++;
    }
    while (b < right_array_size)
    {
        jobs[c] = right_array[b];
        b++;
        c++;
    }
    return 0;
}

void merge_sort(JOB *jobs, int beg_index, int end_index)
{
    if (beg_index < end_index)
    {
        int mid_index = (beg_index + (end_index - 1)) / 2;
        merge_sort(jobs, beg_index, mid_index);
        merge_sort(jobs, mid_index + 1, end_index);
        merge(jobs, beg_index, mid_index, end_index);
    }
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void jobSequence(JOB *jobs, int n)
{

    int jobSeq[n];
    int max_profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--)
        {
            if (jobs[j].slot == 0)
            {
                jobSeq[j] = i;
                jobs[j].slot = 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (jobs[i].slot)
        {
            printf("\n time %d - %d: job %d ,profit =%d", i, i + 1, jobs[jobSeq[i]].name, jobs[jobSeq[i]].profit);
            max_profit += jobs[jobSeq[i]].profit;
        }
    }
    printf("\nMAX PROFIT = %d ", max_profit);
}

int main()
{
    system("clear");
    clock_t start_time, end_time;
    double cpu_time_used;

    int number_of_jobs;
    printf("\nEnter the number of jobs : ");
    scanf("%d", &number_of_jobs);

    JOB *jobs = (JOB *)malloc(number_of_jobs * sizeof(JOB));

    for (int i = 0; i < number_of_jobs; i++)
    {
        printf("Enter the dadline of job %d : ", i + 1);
        scanf("%d", &jobs[i].deadline);
        printf("Enter the profit of job %d : ", i + 1);
        scanf("%d", &jobs[i].profit);
        jobs[i].name = i + 1;
        jobs[i].slot = 0;
    }

    start_time = clock();

    merge_sort(jobs, 0, number_of_jobs - 1);

    printf("\nThe sequence of jobs :-\n");
    jobSequence(jobs, number_of_jobs);

    end_time = clock();

    cpu_time_used = (double)(end_time - start_time);
    printf("\n\n Time taken by the program = %f  \n", cpu_time_used);
    free(jobs);

    return 0;
}
