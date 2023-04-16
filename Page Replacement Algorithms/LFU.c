#include <stdio.h>

void print(int frameno, int frame[])
{
    int j;

    for (j = 0; j < frameno; j++)
    {
        printf("%d\t", frame[j]);
    }

    printf("\n");
}

int main()
{
    int i, j, k, n, page[50], frameno, frame[10], move = 0, flag, count = 0, count1[10] = {0}, repindex, leastcount;
    float rate;
    printf("\nEnter no. of frames: ");
    scanf("%d", &frameno);
    printf("Enter size of string: ");
    scanf("%d", &n);
    printf("Enter string values:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &page[i]);
    }

    for (i = 0; i < frameno; i++)
    {
        frame[i] = -1;
    }

    printf("\nPage Reference String\t\tFrames\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t\t", page[i]);
        flag = 0;

        for (j = 0; j < frameno; j++)
        {
            if (page[i] == frame[j])
            {
                flag = 1;
                count1[j]++;
                printf("No Replacement\n");
                break;
            }
        }

        if (flag == 0 && count < frameno)
        {
            frame[move] = page[i];
            count1[move] = 1;
            move = (move + 1) % frameno;
            count++;
            print(frameno, frame);
        }

        else if (flag == 0)
        {
            repindex = 0;
            leastcount = count1[0];

            for (j = 1; j < frameno; j++)
            {
                if (count1[j] < leastcount)
                {
                    repindex = j;
                    leastcount = count1[j];
                }
            }

            frame[repindex] = page[i];
            count1[repindex] = 1;
            count++;
            print(frameno, frame);
        }
    }

    rate = (float)count / (float)n;

    printf("\nNumber of Page Faults is %d\n", count);
    printf("Fault Rate is %f\n\n", rate);

    return 0;
}

/* Alternate Program:
// 31-48; 51; 79-100
#include <stdio.h>
#define MAX_FRAMES 100
#define MAX_REFERENCES 1000

int main()
{
    int frames[MAX_FRAMES];
    int references[MAX_REFERENCES];
    int count[MAX_FRAMES];
    int i, j, k, n, p, faults, min_count, least_used_frame;
    printf("\nEnter no. of frames: ");
    scanf("%d", &n);
    printf("Enter size of string: ");
    scanf("%d", &p);
    printf("Enter string values:\n");

    for (i = 0; i < p; i++)
    {
        scanf("%d", &references[i]);
    }

    faults = 0;

    for (i = 0; i < n; i++)
    {
        frames[i] = -1;
        count[i] = 0;
    }

    //
    printf("\nReference |");

    for (i = 0; i < n; i++)
    {
        printf(" Frame %d  |", i+1);
    }

    printf(" Fault?\n");
    printf("----------|");

    for (i = 0; i < n; i++)
    {
        printf("----------|");
    }

    printf("--------\n");
    //
    for (i = 0; i < p; i++)
    {
        printf("%9d |", references[i]);//

        for (j = 0; j < n; j++)
        {
            if (frames[j] == references[i])
            {
                count[j]++;
                break;
            }
        }

        if (j == n)
        {
            min_count = count[0];
            least_used_frame = 0;

            for (k = 1; k < n; k++)
            {
                if (count[k] < min_count)
                {
                    min_count = count[k];
                    least_used_frame = k;
                }
            }

            frames[least_used_frame] = references[i];
            count[least_used_frame] = 1;
            faults++;
            //
            printf("%9d |", frames[0]);

            for (j = 1; j < n; j++)
            {
                printf(" %8d |", frames[j]);
            }

            printf("   Yes\n");
        }

        else
        {
            printf("%9d |", frames[0]);

            for (j = 1; j < n; j++)
            {
                printf(" %8d |", frames[j]);
            }

            printf("    No\n");
            //
        }
    }

    printf("\nThe no. of Page Faults is %d\n\n", faults);
    return 0;
}
*/
