#include<stdio.h>

int main(){
    int n,i,time=0,done=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n];
    int remaining[n];

    for(i=0;i<n;i++){
        printf("\nProcess %d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        remaining[i] = bt[i];   // remaining burst time
    }

    while(done < n){

        int highest = -1;

        // Find highest priority process available at current time
        for(i=0;i<n;i++){
            if(at[i] <= time && remaining[i] > 0){
                if(highest == -1 || pr[i] < pr[highest]){
                    highest = i;
                }
            }
        }

        if(highest != -1){
            remaining[highest]--;   // execute for 1 time unit
            time++;

            if(remaining[highest] == 0){
                ct[highest] = time;
                done++;
            }
        }
        else{
            time++;  // CPU idle
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
