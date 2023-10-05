#include <stdio.h>
#include <stdlib.h>
void main(){
int i,n;
float sum1=0,sum2=0,avgW,avgT;
printf("Enter the number of processes : ");
scanf("%d",&n);
int t[n],w[n],c[n],b[n];
for(i=0;i<n;i++){
printf("Enter the burst time of the process P%d :",i);
scanf("%d",&b[i]);
}
for(i=0;i<n;i++){
if(i==0){
c[i]=b[i];
}
else{
c[i]=b[i]+c[i-1];
}
}
for(i=0;i<n;i++){
t[i]=c[i];
w[i]=t[i]-b[i];
sum1=sum1+t[i];
sum2=sum2+w[i];
}
avgT=sum1/n;
avgW=sum2/n;
printf("\nGantt Chart\n");
printf("------------------------------\n|");
for(i=0;i<n;i++){
printf("  P%d  |",i);
}
printf("\n------------------------------\n");
printf("0");
for(i=0;i<n;i++){
printf("      %d",c[i]);
}
printf("\n\nPROCESS\tBT\tWT\tTAT");
for(i=0;i<n;i++){
printf("\n%d\t%d\t%d\t%d\n",i,b[i],w[i],t[i]);
}
printf("\nThe total TAT is: %f",sum1);
printf("\nThe total WT is: %f",sum2);
printf("\nThe Average TAT is: %f",avgT);
printf("\nThe Average WT is: %f\n",avgW);
}
