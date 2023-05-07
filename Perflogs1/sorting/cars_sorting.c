#include <stdio.h>

struct car {
    int num;
    int time;
};

void sort(struct car arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].time > arr[j+1].time) {
                struct car temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of cars waiting for repair: ");
    scanf("%d", &n);
    struct car cars[n];
    for (i = 0; i < n; i++) {
        printf("Enter the estimated repair time for car %d: ", i+1);
        scanf("%d", &cars[i].time);
        cars[i].num = i+1; 
    }
    sort(cars, n);
    int total_time = 0;
    printf("Car  Lost Time\n");
    for (i = 0; i < n; i++) {
            int lost_time = cars[0].time;

        for (int j = 1; j < i+1; j++) {
            lost_time += cars[j].time;
        }
        printf("%d      %d\n", cars[i].num, lost_time);
        total_time += lost_time;
    }
    printf("The total lost time is: %d\n", total_time);
    return 0;
}

