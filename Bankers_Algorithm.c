// Bankers algorithm for printing the safe sequence

#include <stdio.h>

void main()
{
	int n, m, i, j, k;
	n = 5;
	m = 3;
	int alloc[n][m];
	printf("Enter the allocated resources (A,B,C) for the 5 processes(P0,P1,P2,P3,P4,P5):\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the allocated resources for P%d:\n",i);
		for(j=0;j<m;j++)
			scanf("%d",&alloc[i][j]);
	}
	int max[n][m];
	printf("Enter the maximum resources (A,B,C) for the 5 processes(P0,P1,P2,P3,P4):\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the maximum resources for P%d:\n",i);
		for(j=0;j<m;j++)
			scanf("%d",&max[i][j]);
	}
	int avail[m];
	printf("Enter the total resources (A,B,C):\n");
	for(i=0;i<m;i++)
	scanf("%d",&avail[i]);
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	} 
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	} 
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {
				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
	printf("P%d -> ", ans[i]);
	printf("P%d", ans[n - 1]);
	printf("\n\n");
}
