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
int freq[no];
for(i=0;i<no;i++)
{
frame[i]=-1;
freq[i]=0;
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
freq[j]++;
break;
}
}
if(pgfound==0)
{
int min=freq[0];
int minindex=0;
for(j=0;j<no;j++)
{
if(freq[j]<min)
{
min=freq[j];
minindex=j;
}
}
frame[minindex]=page;
freq[minindex]=1;
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
pagefaults++;
}
}
printf("\nTotal Page Faults: %d\n", pagefaults);
printf("\nTotal Page Hits: %d\n", (len-pagefaults));
}
