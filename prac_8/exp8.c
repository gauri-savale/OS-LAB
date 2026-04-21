#include<stdio.h>

int main(){
    int n,i,j;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n];
    int completed[n];

    for(i=0;i<n;i++){
        printf("\nProcess %d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        completed[i] = 0;   // not completed
    }

    int time = 0;
    int done = 0;

    while(done < n){

        int highest = -1;

        // Find highest priority process available at current time
        for(i=0;i<n;i++){
            if(at[i] <= time && completed[i] == 0){
                if(highest == -1 || pr[i] < pr[highest]){
                    highest = i;
                }
            }
        }

        if(highest != -1){
            time += bt[highest];
            ct[highest] = time;
            completed[highest] = 1;
            done++;
        }
        else{
            time++;   // If no process arrived yet
        }
    }

    float avg_wt = 0, avg_tat = 0;

    for(i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);

    return 0;
}
