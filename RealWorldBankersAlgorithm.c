#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
int r;
int row, col, count = 0;
int numberOfProcess;
printf("\n Enter Number Of Process: ");
scanf("%d", &numberOfProcess);
int numberOfResources;
printf("\n Enter Number Of Resource: ");
scanf("%d", &numberOfResources);
int *availableResource = (int *) malloc(sizeof(int) * numberOfResources);
int **maximumResource = (int **) malloc(sizeof(int) * numberOfProcess);
for(r = 0; r < numberOfProcess; r++){
maximumResource[r] = (int *) malloc(sizeof(int) * numberOfResources);
}
int **allocationResource = (int **) malloc(sizeof(int) * numberOfProcess);
for(r = 0; r < numberOfProcess; r++){
    allocationResource[r] = (int *) malloc(sizeof(int) * numberOfResources);
}
int **needResource = (int **) malloc(sizeof(int) * numberOfProcess);
for(r = 0; r < numberOfProcess; r++){
    needResource[r] = (int *) malloc(sizeof(int) * numberOfResources);
}
int processSequence[numberOfProcess];
for(row = 0; row < numberOfResources; row++){
    printf("\n Number Of Available Resource %d: ", (row + 1));
    scanf("%d", &availableResource[row]);
}
for(row = 0; row < numberOfProcess; row++){
for(col = 0; col < numberOfResources; col++){
printf("\n Allocation P %d for R %d: ", (row + 1), (col + 1));
scanf("%d", &allocationResource[row][col]);
}
}
for(row = 0; row < numberOfProcess; row++){
for(col = 0; col < numberOfResources; col++){
printf("\n MAX P %d for R %d: ", (row + 1), (col + 1));
scanf("%d", &maximumResource[row][col]);
needResource[row][col] = maximumResource[row][col] - allocationResource[row][col];
}
}
printf("\n Available Resources: ");
for(row = 0; row < numberOfResources; row++){
    printf("%4d", availableResource[row]);
}
printf("\n Allocation \t MAX \t\t\t Need\n");
for(row = 0; row < numberOfProcess; row++)
{
printf("P%d",(row + 1));
for(col = 0; col < numberOfResources; col++)
printf("%4d", allocationResource[row][col]);
printf("\t\t");
for(col = 0; col < numberOfResources; col++){
    printf("%4d", maximumResource[row][col]);
}
printf("\t\t");
for(col = 0; col < numberOfResources; col++){
    printf("%4d", needResource[row][col]);
}
printf("\n");
}
int *work = (int *) malloc(sizeof(int) * numberOfResources);
for(row = 0; row < numberOfResources; row++){
    work[row] = availableResource[row];
}
int *finish = (int *) malloc(sizeof(int) * numberOfProcess);
for(row = 0; row < numberOfProcess; row++){
    finish[row] = 0;
}
int checking = 1;
while(checking)
{
checking = 0;
for(row = 0; row < numberOfProcess; row++)
{
if(!finish[row])
{
int col;
for(col = 0; col < numberOfResources; col++)
if(needResource[row][col] > work[col])
break;
if(col == numberOfResources)
{
for(col = 0; col < numberOfResources; col++)
work[col] = work[col] + allocationResource[row][col];
finish[row] = 1;
checking = 1;
processSequence[count++] = row;
}
}
}
}
int counter;
for(counter = 0; counter < numberOfProcess; counter++)
if(!finish[counter])
break;
printf("\n SAFE And Sequence is \n");
if(counter == numberOfProcess)
for(r = 0; r < count; r++)
printf(" Process: %d\n", processSequence[r]);
else
printf("\n DEAD LOCK");
}
//Output:
//MAX P 1 for R 1: 7 
//Enter Number of Process: 5
//Enter Number Of Resource: 3 
//Number Of Available Resource 1: 3 
//MAX P 1 for R 2:2 
//Available Resources: Allocation P1 0 1 0 P2 P3 2 P4 1 1 P5 0 0 2 ONWN 3 3 MAX 7 3 9 2 4 WN ONU WNNNW Need 7 4 1 2 2 6 1 4 3

