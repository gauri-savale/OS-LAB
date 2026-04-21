#include <stdio.h>

int main() {
    int n, m, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n * m];
    int max[n * m];
    int need[n * m];
    int avail[m];
    int finish[n], safeSeq[n];

    // Allocation
    printf("Enter Allocation:\n");
    for(i = 0; i < n * m; i++) {
        scanf("%d", &alloc[i]);
    }

    // Max
    printf("Enter Max:\n");
    for(i = 0; i < n * m; i++) {
        scanf("%d", &max[i]);
    }

    // Available
    printf("Enter Available:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Need = Max - Allocation
    for(i = 0; i < n * m; i++) {
        need[i] = max[i] - alloc[i];
    }

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 1;

                for(j = 0; j < m; j++) {
                    if(need[i * m + j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag) {
                    for(j = 0; j < m; j++) {
                        avail[j] += alloc[i * m + j];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("System is NOT safe\n");
            return 0;
        }
    }

    printf("System is SAFE\nSequence: ");
    for(i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }

    return 0;
}
