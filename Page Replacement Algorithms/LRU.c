#include <stdio.h>

int main()
{
    int q[20], p[50], c = 0, c1, d, f, i, j, k = 0, n, r, t, b[20], c2[20];
    printf("\nEnter no. of frames: ");
    scanf("%d", &f);
    printf("Enter size of string: ");
    scanf("%d", &n);
    printf("Enter string values:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    q[k] = p[k];
    printf("\n\t%d\n", q[k]);
    c++;
    k++;

    for(i = 1; i < n; i++)
    {
        c1 = 0;

        for(j = 0; j < f; j++)
        {
            if(p[i] != q[j])
            {
                c1++;
            }
        }

        if(c1 == f)
        {
            c++;
            if(k < f)
            {
                q[k] = p[i];
                k++;

                for(j = 0; j < k; j++)
                {
                    printf("\t%d", q[j]);
                }

                printf("\n");
            }

            else
            {
                for(r = 0; r < f; r++)
                {
                    c2[r] = 0;

                    for(j = i - 1; j >= 0; j--)
                    {
                        if(q[r] != p[j])
                        {
                            c2[r]++;
                        }

                        else
                        {
                            break;
                        }
                    }
                }
                
                for(r = 0; r < f; r++)
                {
                    b[r] = c2[r];
                }

                for(r = 0; r < f; r++)
                {
                    for(j = r; j < f; j++)
                    {
                        if(b[r] < b[j])
                        {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }

                for(r = 0; r < f; r++)
                {
                    if(c2[r] == b[0])
                    {
                        q[r] = p[i];
                    }
                    printf("\t%d", q[r]);
                }
                printf("\n");
            }
        }
    }
    printf("\nThe no. of Page Faults is %d\n\n", c);
    return 0;
}

/* Alternate Program:
#include <stdio.h>
#include <limits.h>

void lru(int string[], int n, int size)
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

        for (int j = 0; j < n; j++)
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
            page_hits++;
        }
        
        else
        {
            int pos = INT_MAX;

            for (int j = 0; j < n; j++)
            {
                int k;
                for (k = i - 1; k >= 0; k--)
                {
                    if (frames[j] == string[k])
                    {
                        break;
                    }
                }

                if (k < pos)
                {
                    pos = k;
                    index = j;
                }
            }

            frames[index] = symbol;
            page_miss++;
            printf("\nSymbol: %d  Frame: ", symbol);

            for (int j = 0; j < n; j++)
            {
                printf("%d ", frames[j]);
            }
        }
    }
    printf("\n\nPage Hits: %d", page_hits);
    printf("\nPage Misses: %d\n\n", page_miss);
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

    lru(string, no_frames, size);
    return 0;
}
*/
