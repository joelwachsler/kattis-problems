#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void print_array(int n, int array[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int p = 0; p < n; p++)
        {
            printf("%d\t", array[i][p]);
        }
        printf("\n");
    }

    printf("Done printing array!\n");
}

void print_sides(int n, int array[][2])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, %d\t", array[i][0], array[i][1]);
    }
    printf("\n");
}

bool check(int array_len, int array[][2])
{
    for (int i = 0; i < array_len; i++)
        if (array[i][1] == 0)
            return false;
    return true;
}

int loop(int k, int array_len, int array[][2], int *k_values)
{
    int count = 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < array_len; j++)
        {
            /*printf("First: %d, Second: %d\n", array[j][0], array[j][1]);*/
            if (array[j][1] == 0 && array[j][0] == k_values[i])
            {
                array[j][1] = 1;
                if (check(array_len, array))
                    return count;
                break;
            }
        }
        /*printf("NEW\n");*/
        count++;
    }

    return 0;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    // Make array which will hold the horisontal data
    int horisontal[n][n][2];
    memset(horisontal, 0, sizeof(int) * (n * n * 2));
    int temp_int;

    for (int p = 0; p < n; p++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp_int);
            horisontal[p][i][0] = temp_int;
        }
    }

    // Get k-values
    int k_values[k];
    int k_temp;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &k_temp);
        k_values[i] = k_temp;
    }

    // Make array which will hold the vertical data
    int vertical[n][n][2];
    memset(vertical, 0, sizeof(int) * (n * n * 2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vertical[i][j][0] = horisontal[j][i][0];
        }
    }

    // Make array for top-left to bottom-right
    int top_left[n][2];
    int top_right[n][2];
    // Set zero arrays
    memset(top_left, 0, sizeof(int) * n * 2);
    memset(top_right, 0, sizeof(int) * n * 2);
    for (int i = 0; i < n; i++)
    {
        top_left[i][0] = horisontal[i][i][0];
        top_right[i][0] = horisontal[i][(n - i) - 1][0];
    }

    int steps_left = loop(k, n, top_left, k_values);
    int steps_right = loop(k, n, top_right, k_values);

    int horisontal_steps[n];
    int vertical_steps[n];
    for (int i = 0; i < n; i++)
    {
        horisontal_steps[i] = loop(k, n, horisontal[i], k_values);
        vertical_steps[i] = loop(k, n, vertical[i], k_values);
    }

    int lowest = INT_MAX;
    if (steps_left != 0)
        lowest = steps_left;
    if (steps_right != 0 && steps_right < steps_left)
        lowest = steps_right;

    for (int i = 0; i < n; i++)
    {
        if (horisontal_steps[i] != 0 && horisontal_steps[i] < lowest)
            lowest = horisontal_steps[i];
        if (vertical_steps[i] != 0 && vertical_steps[i] < lowest)
            lowest = vertical_steps[i];
    }

    printf("%d", lowest);

    return 0;
}
