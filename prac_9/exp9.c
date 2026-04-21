#include<stdio.h>

int main(){
    int n,i;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int at[n], bt[n];
    int rt[n];
    int ct[n], tat[n], wt[n];
    int start[n];
    int response[n];
    int completed[n];
    for(i=0;i<n;i++){
        printf("\nProcess %d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        rt[i] = bt[i];
        completed[i] = 0;
        start[i] = -1;
    }
    int time = 0;
    int done = 0;
    while(done < n){
        int longest = -1;
        for(i=0;i<n;i++){
            if(at[i] <= time && completed[i] == 0){
                if(longest == -1 || rt[i] > rt[longest]){
                    longest = i;
           }
          }
        }

        if(longest != -1){
            if(start[longest] == -1){
                start[longest] = time;
            }
            rt[longest]--;
            time++;
            if(rt[longest] == 0){
                ct[longest] = time;
                completed[longest] = 1;
                done++;
      }
     }
     else{
            time++;
     }
    }
    float avg_wt = 0, avg_tat = 0, avg_rt = 0;
    for(i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        response[i] = start[i] - at[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
        avg_rt += response[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    avg_rt /= n;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1, at[i], bt[i], ct[i], tat[i], wt[i], response[i]);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Response Time = %.2f", avg_rt);
}
