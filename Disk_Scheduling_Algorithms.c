
#include<stdio.h>
#include<stdlib.h>

int main() 
{
    int track[] = {88,83,7,13,90,79,11,63};
    printf("Enter the initial position of the R/W Head: ");
    int rw;
    scanf("%d", & rw);
    int ttm = 0, i, j;
    printf("-----------------------------------------------\n");
    printf("The choices for Disk Scheduling are :\n");
    printf("-----------------------------------------------\n");
    printf("1. FCFS (First-Come-First-Serve)\n");
    printf("2. SSTF (Shortest-Seek-Time-First)\n");
    printf("3. SCAN Disk Scheduling\n");
    printf("4. C-SCAN (Circular SCAN) Disk Scheduling\n");
    printf("5. LOOK Disk Scheduling\n");
    printf("6. C-LOOK (Circular LOOK) Disk Scheduling\n");
    printf("-----------------------------------------------\n");
    printf("Enter your choice : ");
    int ch;
    scanf("%d", & ch);
    printf("-----------------------------------------------\n");
    int min, min_index, n = (sizeof(track) / sizeof(int));
    int temp, index;
    switch (ch) 
    {
        case 1:
        printf("The sequence of tracks moved by the read/write head is: \n % d ",rw);
        for (i = 0; i < n; i++) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
            track[i] = -1;
        }
        printf("\n"); printf("The total track movement = %d cylinders\n", ttm); 
        printf("-----------------------------------------------\n");
        break;
        case 2:
        printf("The sequence of tracks moved by the read/write head is: \n % d ",rw);
        for (j = 0; j < n; j++) 
        {
            min = 9999;
            for (i = 0; i < n; i++) 
            {
                if (track[i] != -1) 
                {
                    if (abs(track[i] - rw) < min) 
                    {
                        min = abs(track[i] - rw);
                        min_index = i;
                    }
                }
            }
            ttm += abs(track[min_index] - rw);
            rw = track[min_index];
            printf(" ->> %d", rw);
            track[min_index] = -1;
        }
        printf("\n"); printf("The total track movement = %d cylinders\n", ttm); 
        printf("-----------------------------------------------\n");
        break;
        case 3:
        printf("The sequence of tracks moved by the read/write head is: \n % d ",rw);
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n - 1; j++) 
            {
                if (track[j] > track[j + 1]) 
                {
                    temp = track[j];
                    track[j] = track[j + 1];
                    track[j + 1] = temp;
                }
            }
        }
        for (i = 0; i < n; i++) 
        {
            if (track[i] > rw) 
            {
                index = i;
                break;
            }
        }
        for (i = index - 1; i >= 0; i--) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
        }
        ttm += abs(rw - 0); rw = 0; printf(" ->> %d", rw);
        for (i = index; i < n; i++) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
        }
        printf("\n"); printf("The total track movement = %d cylinders\n", ttm); 
        printf("-----------------------------------------------\n");
        break;
        case 4:
        printf("The sequence of tracks moved by the read/write head is: \n % d ",rw);
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n - 1; j++) 
            {
                if (track[j] > track[j + 1]) 
                {
                    temp = track[j];
                    track[j] = track[j + 1];
                    track[j + 1] = temp;
                }
            }
        }
        for (i = 0; i < n; i++) 
        {
            if (track[i] > rw) 
            {
                index = i;
                break;
            }
        }
        for (i = index - 1; i >= 0; i--) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
        }
        ttm += abs(rw - 0); 
        rw = 0; 
        printf(" ->> %d", rw); 
        ttm += abs(rw - 99); 
        rw = 99; 
        printf(" ->> %d", rw);
        for (i = n - 1; i >= index; i--) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
        }
        printf("\n"); 
        printf("The total track movement = %d cylinders\n", ttm); 
        printf("-----------------------------------------------\n");
        break;
        case 5:
        printf("The sequence of tracks moved by the read/write head is: \n % d ",rw);
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n - 1; j++) 
            {
                if (track[j] > track[j + 1]) 
                {
                    temp = track[j];
                    track[j] = track[j + 1];
                    track[j + 1] = temp;
                }
            }
        }
        for (i = 0; i < n; i++) 
        {
            if (track[i] > rw) 
            {
                index = i;
                break;
            }
        }
        for (i = index - 1; i >= 0; i--) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
        }
        for (i = index; i < n; i++) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
        }
        printf("\n"); 
        printf("The total track movement = %d cylinders\n", ttm); 
        printf("-----------------------------------------------\n");
        break;
        case 6:
        printf("The sequence of tracks moved by the read/write head is: \n % d ",rw);
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n - 1; j++) 
            {
                if (track[j] > track[j + 1]) 
                {
                    temp = track[j];
                    track[j] = track[j + 1];
                    track[j + 1] = temp;
                }
            }
        }
        for (i = 0; i < n; i++) 
        {
            if (track[i] > rw) 
            {
                index = i;
                break;
            }
        }
        for (i = index - 1; i >= 0; i--) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
        }
        for (i = n - 1; i >= index; i--) 
        {
            ttm += abs(track[i] - rw);
            rw = track[i];
            printf(" ->> %d", rw);
        }
        printf("\n"); 
        printf("The total track movement = %d cylinders\n", ttm); 
        printf("-----------------------------------------------\n");
        break;
        default:
        printf("Sorry, your entered choice doesn't exist... Aborting\n"); 
        exit(0);
        break;
    }
    return 0;
}
