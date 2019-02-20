/*
  FCFS Disk Scheduling Implementation
*/

#include <stdio.h>
#include <stdlib.h>


int main(){
  int queue[100], q_size, head, seek =0, diff;
  float avg;
  int i,j;
  printf("%s\n", "***FCFS Disk Scheduling Algorithm***");

  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);

  printf("%s\n", "Enter queue elements");
  for(i=1; i<=q_size; i++){
    scanf("%d",&queue[i]);
  }

  printf("%s\n","Enter initial head position");
  scanf("%d", &head);

  queue[0]=head;

  for(j=0; j<=q_size-1; j++){
    diff = abs(queue[j]-queue[j+1]);
    seek += diff;
    //printf("Move from %d to %d with Seek %d\n",queue[j],queue[j+1],diff);
  }
  for(i=0; i<=q_size-1; i++)
    printf("%d --> ",queue[i]);
  printf("%d\t",queue[i]);
  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\n", avg);

  return 0;
}