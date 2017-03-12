#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Input {
    int time;          // Current time
    char command[5];   // Playing or paused
};

int cmpfunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int sum(int *array, int *len)
{
    int sum = 0;
    for (int i = 0; i < *len; i++) {
        sum += array[i];
    }

    return sum;
}

int main()
{
    int switches;
    scanf("%d", &switches);

    struct Input holder[switches];

    char deviceHolder[7];
    for(int i = 0; i < switches; i++) {
        scanf("%d %s %s", &holder[i].time, deviceHolder, holder[i].command);

        if (deviceHolder[0] == 'm') // A mobile takes extra time
            holder[i].time += 100;
    }

    qsort(holder, switches, sizeof(struct Input), cmpfunc);

    int totTime = 0; // Final time
    int itemsInArray = 0;
    int nextHolder[switches];
    memset(nextHolder, 0, switches * sizeof(int));

    for (int i = 0; i < switches; i++) {
        if (strcmp(holder[i].command, "play") == 0) {
            nextHolder[itemsInArray] = holder[i].time;
            itemsInArray++;
        } else {
            if (sum(nextHolder, &itemsInArray) != 0) {
                totTime += holder[i].time - nextHolder[0];
                memset(nextHolder, 0, switches * sizeof(int));
                itemsInArray = 0;
            }
        }
    }

    printf("%d\n", totTime);

    return 0;
}
