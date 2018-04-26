#include<stdio.h>

main()

{

int at[10],bt[10],rt[10],pr[10],endTime,i,smallest,processGantt[100],k,temp;

int remain=0,n,time,avg_wt=0,avg_tat=0;

printf("Enter no of Processes : ");

scanf("%d",&n);

for(i=0;i<n;i++)

{

printf("\nEnter arrival time for Process P[%d]: ",i+1);

scanf("%d",&at[i]);

printf("Enter burst time for Process P[%d ]:",i+1);

scanf("%d",&bt[i]);

rt[i]=bt[i];

}


printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");

rt[9]=9999;

for(time=0;remain!=n;time++)

{

smallest=9;

for(i=0;i<n;i++)

{

	if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)

	{

		processGantt[time]=i;

		smallest=i;

	}

}

rt[smallest]--;

if(rt[smallest]==0)

{

remain++;

endTime=time+1;

printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-at[smallest],endTime-bt[smallest]-at[smallest]);

avg_wt+=endTime-bt[smallest]-at[smallest];

avg_tat+=endTime-at[smallest];

}

}

printf("\n\nAverage waiting time = %.2f\n",avg_wt*1.0/n);

printf("Average Turnaround time = %.2f\n\n",avg_tat*1.0/5);

for(i=0;i<=time;i++)

{

printf(" %d->P[%d] ",i,processGantt[i]+1);

}

}
