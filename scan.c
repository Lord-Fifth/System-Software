/*
SCAN - Disk Scheduling Algorithm (Elevator)
scans down towards the nearest end and then when it hits the bottom,
it scans up servicing the requests that it didn't get going down.
If a request comes in after it has been scanned it will not be serviced
until the process comes back down or moves back up.
*/

#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199


int main(){
  int queue[20];
  int head, max, q_size, temp, sum;
  int dloc; //location of disk (head) arr
  int i,j;

  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);

  printf("%s\n", "Enter head position");
  scanf("%d", &head);

  printf("%s\n", "Enter queue elements");
  for(i=0; i<q_size; i++){
    scanf("%d", &queue[i]);
  }

  queue[q_size] = head; //add RW head into queue
  q_size++;

  //sort the array
  for(i=0; i<q_size;i++){
    for(j=i; j<q_size; j++){
      if(queue[i]>queue[j]){
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }

  max = queue[q_size-1];

  //locate head in the queue
  for(i=0; i<q_size; i++){
    if(head == queue[i]){
      dloc = i;
      break;
    }
  }

  if(abs(head-LOW) <= abs(head-HIGH)){

      for(j=dloc; j>=0; j--){
        printf("%d --> ",queue[j]);
      }
      for(j=dloc+1; j<q_size; j++){
        printf("%d --> ",queue[j]);
      }

      } else {

      for(j=dloc+1; j<q_size; j++){
          printf("%d --> ",queue[j]);
      }
      for(j=dloc; j>=0; j--){
          printf("%d --> ",queue[j]);
      }

  }




  sum  = head + max;
  printf("\nTotal Seek time %d", sum);
  printf("\nAverage Seek time %d\n", (sum/(q_size-1)));

  return 0;
}