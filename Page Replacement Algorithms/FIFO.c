#include <stdio.h>

void fifo(int string[20], int n, int size)
{
    int frames[n];

    for (int i = 0; i < n; i++)
    {
        frames[i] = -1;
    }

    int index = -1;
    int page_miss = 0;
    int page_hits = 0;

    for (int i = 0; i < size; i++)
    {
        int symbol = string[i];
        int flag = 0;

        for(int j = 0; j < n; j++)
        {
            if (symbol == frames[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            printf("\nSymbol: %d  Frame: ", symbol);

            for (int j = 0; j < n; j++)
            {
                printf("%d ", frames[j]);
            }
            page_hits += 1;
        }

        else
        {
            index = (index + 1) % n;
            frames[index] = symbol;
            page_miss += 1;
            printf("\nSymbol: %d  Frame: ", symbol);

            for (int j = 0; j < n; j++)
            {
                printf("%d ", frames[j]);
            }
        }
    }
    printf("\n\nPage hits: %d", page_hits);
    printf("\nPage misses: %d\n\n", page_miss);
}

int main(void)
{
    int no_frames, size;
    printf("\nEnter no. of frames: ");
    scanf("%d", &no_frames);
    printf("Enter size of string: ");
    scanf("%d", &size);
    int string[size];
    printf("Enter string values:\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &string[i]);
    }

    fifo(string, no_frames, size);
    return 0;
}
