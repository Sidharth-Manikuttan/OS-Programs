#include <stdio.h>
#include <stdlib.h>
void main()
{
int len,no,i,j,pagefaults=0;
printf("Enter the ref str len :  ");
scanf("%d",&len);
printf("Enter the ref str :\n");
int str[len];
for(i=0;i<len;i++)
{
scanf("%d",&str[i]);
}
printf("Enter the number of frames : ");
scanf("%d",&no);
int frame[no];
int past[no];
for(i=0;i<no;i++)
{
frame[i]=-1;
past[i]=0;
}
for(i=0;i<len;i++)
{
int pgfound=0;
int page=str[i];
for(j=0;j<no;j++)
{
if(frame[j]==page)
{
printf("hit\n");
pgfound=1;
past[j]=i+1;
break;
}
}
if(pgfound==0)
{
int min=past[0];
int minindex=0;
for(j=0;j<no;j++)
{
if(past[j]<min)
{
min=past[j];
minindex=j;
}
}
frame[minindex]=page;
for (j = 0; j < no; j++)
            {
                if (frame[j] != -1)
                {
                    printf("%d |", frame[j]);
                }
                else
                {
                    printf("  |");
                }
            }
            printf("\n");
past[minindex]=i+1;
pagefaults++;
}
}
printf("\nTotal Page Faults: %d\n", pagefaults);
printf("\nTotal Page Hits: %d\n", (len-pagefaults));
}
