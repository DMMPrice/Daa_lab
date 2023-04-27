// Write a program in C to do job sequence

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Job
{
    char id[3];
    int deadline;
    int profit;
}Job;
int minValue(int x, int y)
{
    if (x < y)
        return x;
    return y;
}
void jobSequencingWithDeadline(Job jobs[],int n);
int main()
{
    int n, i, j;
    n = 0;
    Job *jobs, temp;
    printf("Enter the number of Jobs: ");
    scanf("%d", &n);
    jobs = (Job *)malloc(n * sizeof(Job));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Job number: ");
        scanf("%s", (jobs + i)->id);
        printf("Enter the Job deadline: ");
        scanf("%d", &(jobs + i)->deadline);
        printf("Enter the Job profit: ");
        scanf("%d", &(jobs + i)->profit);
    }
    printf("Displaying Information:\n");
    for (int i = 0; i < n; ++i)
        printf("Job %s\t%d\t%d\n", (jobs + i)->id, (jobs + i)->deadline, (jobs + i)->profit);
    // sort the jobs profit wise in descending order
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (jobs[j + 1].profit > jobs[j].profit)
            {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
    printf("%s\t%s\t%s\n", "Job", "Deadline", "Profit");
    for (i = 0; i < n; i++)
        printf("%s\t%d\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    jobSequencingWithDeadline(jobs, n);
    return 0;
}
void jobSequencingWithDeadline(Job jobs[],int n){
    //variables
  int i, j, k, maxprofit;

  //free time slots
  int timeslot[MAX];

  //filled time slots
  int filledTimeSlot = 0;

  //find max deadline value
  int dmax = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }

  //free time slots initially set to -1 [-1 denotes EMPTY]
  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }

  printf("dmax: %d\n", dmax);

  for(i = 1; i <= n; i++) {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    //if all time slots are filled then stop
    if(filledTimeSlot == dmax) {
      break;
    }
  }

  //required jobs
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%s", jobs[timeslot[i]].id);

    if(i < dmax) {
      printf(" --> ");
    }
  }

  //required profit
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}