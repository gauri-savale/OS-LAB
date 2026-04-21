#include <stdio.h>

#define MAX_PROCESSES 10

// Function to calculate waiting time (SRTF - Preemptive SJF)
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int remaining_bt[MAX_PROCESSES];

    for (int i = 0; i < n; i++)
        remaining_bt[i] = bt[i];

    int complete = 0, current_time = 0;

    while (complete != n) {
        int min_bt = 9999;
        int shortest = -1;

        // Find process with minimum remaining burst time
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0 && remaining_bt[i] < min_bt) {
                min_bt = remaining_bt[i];
                shortest = i;
            }
        }

        // If no process found
        if (shortest == -1) {
            current_time++;
            continue;
        }

        // Execute process for 1 unit
        remaining_bt[shortest]--;
        current_time++;

        // If process finishes
        if (remaining_bt[shortest] == 0) {
            complete++;
            int finish_time = current_time;
            wt[shortest] = finish_time - bt[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
    }
}

// Function to calculate Turn Around Time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average times
void calculateAverageTimes(int processes[], int n, int bt[]) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n",
               processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

// Main function
int main() {
    int processes[] = {1, 2, 3, 4};
    int burst_time[] = {6, 8, 7, 3};

    int n = sizeof(processes) / sizeof(processes[0]);

    calculateAverageTimes(processes, n, burst_time);

    return 0;
}
