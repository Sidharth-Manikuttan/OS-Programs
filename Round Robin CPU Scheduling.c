#include <stdio.h>
#include <stdlib.h>
struct process {
	int p,bt,ct,tat,wt,rt;
};
void main()
{
	int n,i,time_slice,current_ct=0,flag=0,j,a[50],k=0;
	float total_tat=0,total_wt=0;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	struct process p[n];
	int vis[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of the process P%d :",i);
		scanf("%d",&p[i].bt);
		p[i].p=i;
		p[i].rt=p[i].bt;
	}
	printf("Enter the time slice : ");
	scanf("%d",&time_slice);
	printf("\nGantt Chart\n-------------------------------------------------------------\n|");
	for(i=0;i<n;i++)
	{
		flag=0;
		if(p[i].rt<=time_slice&&p[i].rt>0)
		{
			printf("P%d\t|",i);
			current_ct+=p[i].rt;
			p[i].ct=current_ct;
			p[i].rt=0;
			a[k++]=current_ct;
		}
		else if(p[i].rt>0)
		{
			printf("P%d\t|",i);
			current_ct+=time_slice;
			p[i].rt=p[i].rt-time_slice;
			a[k++]=current_ct;
		}
		for(j=0;j<n;j++)
		{
			if(p[j].rt!=0)
				flag=1;
		}
		if((i==n-1)&&(flag==1))
			i=-1;
	}
	printf("\n");
	printf("-------------------------------------------------------------\n0\t");
	for(i=0;i<k;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ct;
		p[i].wt=p[i].tat-p[i].bt;
		total_tat+=p[i].tat;
		total_wt+=p[i].wt;
	}
	printf("\nProcess  Turnaround time  Waiting time\n");
	for(i=0;i<n;i++){
		printf("P%d\t\t%d\t\t%d\n",i,p[i].tat,p[i].wt);
	}
	printf("\nTotal Turnaround time : %f ",total_tat);
	printf("\nTotal Waiting time : %f ",total_wt);
	printf("\nAverage turnaround time : %f\n",total_tat/n);
	printf("Average waiting time : %f\n",total_wt/n);
}
