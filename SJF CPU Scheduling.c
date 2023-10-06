#include <stdio.h>
#include <stdlib.h>
struct process {
	int bt,ct,tat,wt,p;
};
void main()
{
	int n,i,j,current_ct=0,a[20];
	float total_tat=0,total_wt=0;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	struct process p[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of process P%d : ",i);
		scanf("%d",&p[i].bt);
		p[i].p=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].bt>p[j+1].bt)
			{
				struct process temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	j=0;
	printf("Gantt Chart\n-----------------------------------------------------\n|");
	for(i=0;i<n;i++)
	{
		current_ct+=p[i].bt;
		printf("P%d\t|",p[i].p);
		a[j++]=current_ct;
		p[i].ct=current_ct;
		p[i].tat=p[i].ct;
		p[i].wt=p[i].tat-p[i].bt;
		total_tat+=p[i].tat;
		total_wt+=p[i].wt;
	}
	printf("\n--------------------------------------------------------\n0\t");
	for(i=0;i<j;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nProcess \tTurnaround time \tWaiting time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d \t\t%d\t\t \t%d\n",p[i].p,p[i].tat,p[i].wt);
	}
	printf("Total turnaround time : %f\n",total_tat);
	printf("Total Waiting time : %f\n",total_wt);
	printf("Average turnaround time : %f\n",total_tat/n);
	printf("Average waiting time : %f\n",total_wt/n);
}
