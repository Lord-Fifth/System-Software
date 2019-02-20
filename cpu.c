#include <stdio.h>
int n;
int b[100]; int p[100]; int pr[100];
int WT[100]; int TT[100];
int total_wt = 0, total_tt = 0;
float aw,at;

void fcfs()
	{int i,j;
	 WT[0] = 0;
	 total_wt = 0,total_tt = 0;
	 for(i=1;i<n;i++)
	 	{WT[i]=0;
		 for(j=0;j<i;j++)
		 	WT[i] = WT[i] + b[j];
		 total_wt = total_wt + WT[i];
		}
	 for(i=0;i<n;i++)
	 	{TT[i] = b[i] + WT[i];
		 total_tt = total_tt + TT[i];
		}
	 printf("\nPROCESS\t\t\tWAITING TIME\t\tTURNAROUND TIME\n");
	 for(i=0;i<n;i++)
	 	{printf("p[%d]\t\t\t%d\t\t\t%d\n",i,WT[i],TT[i]);
		}
	 aw = (float)total_wt/n;
	 at = (float)total_tt/n;
	 printf("Average Waiting Time : %f\n",aw);
	 printf("Average Turnaround Time : %f\n",at);
	}

void sjf()
	{int i,j,pos,temp;
	 for(i=0;i<n;i++)
	 	{pos = i;
		 for(j=i+1;j<n;j++)
			{if(b[j]<b[pos])
				pos = j;
			}
		 temp = b[i];
		 b[i]=b[pos];
		 b[pos]=temp;
		}
	 WT[0] = 0;
	 total_wt = 0,total_tt = 0;
	 for(i=1;i<n;i++)
	 	{WT[i]=0;
		 for(j=0;j<i;j++)
		 	WT[i] = WT[i] + b[j];
		 total_wt = total_wt + WT[i];
		}
	 for(i=0;i<n;i++)
	 	{TT[i] = b[i] + WT[i];
		 total_tt = total_tt + TT[i];
		}
	 printf("\nPROCESS\t\t\tWAITING TIME\t\tTURNAROUND TIME\n");
	 for(i=0;i<n;i++)
	 	{printf("p[%d]\t\t\t%d\t\t\t%d\n",i,WT[i],TT[i]);
		}
	 aw = (float)total_wt/n;
	 at = (float)total_tt/n;
	 printf("Average Waiting Time : %f\n",aw);
	 printf("Average Turnaround Time : %f\n",at);
	}
void rr()
	{int i,q,t,count; int rem_b[100];
	 printf("Enter the time quantum\n");
         scanf("%d",&q);
	 for(i=0;i<n;i++)
		rem_b[i]=b[i];
	 t=0;
	 count=n;
	 while(count>0)
		{for(i=0;i<n;i++)
		 	{if(rem_b[i]>0)
				{if(rem_b[i]>q)
					{t+=q;
					 rem_b[i]-=q;
					}
				else
					{t+=rem_b[i];
					 WT[i]=t-b[i];
					 rem_b[i]=0;
					 count=count-1;
					}
				}
			}
		}
	 total_wt = 0,total_tt = 0;
	 for(i=0;i<n;i++)
	 	{TT[i] = b[i] + WT[i];
		 total_tt = total_tt + TT[i];
		}
	 for(i=0;i<n;i++)
		total_wt = total_wt + WT[i];
	 printf("\nPROCESS\t\t\tWAITING TIME\t\tTURNAROUND TIME\n");
	 for(i=0;i<n;i++)
	 	{printf("p[%d]\t\t\t%d\t\t\t%d\n",i,WT[i],TT[i]);
		}
	 aw = (float)total_wt/n;
	 at = (float)total_tt/n;
	 printf("Average Waiting Time : %f\n",aw);
	 printf("Average Turnaround Time : %f\n",at);
	}
void prior()
	{int i,j,pos,temp;
	 
	 for(i=0;i<n;i++)
		{printf("Enter the priorities for the process %d\n",i);
		 scanf("%d",&pr[i]);
		}
	 for(i=0;i<n;i++)
		{pos = i;
		 for(j=i+1;j<n;j++)
		 	{if(pr[j]<pr[pos])
				pos=j;
			}
		 temp = b[i];
		 b[i]=b[pos];
		 b[pos]=temp;

		 temp = pr[i];
		 pr[i]=pr[pos];
		 pr[pos]=temp;
		}
	 WT[0] = 0;
	 total_wt = 0,total_tt = 0;
	 for(i=1;i<n;i++)
	 	{WT[i]=0;
		 for(j=0;j<i;j++)
		 	WT[i] = WT[i] + b[j];
		 total_wt = total_wt + WT[i];
		}
	 for(i=0;i<n;i++)
	 	{TT[i] = b[i] + WT[i];
		 total_tt = total_tt + TT[i];
		}
	 printf("\nPROCESS\t\t\tPRIORITY\t\tWAITING TIME\t\tTURNAROUND TIME\n");
	 for(i=0;i<n;i++)
	 	{printf("p[%d]\t\t\t%d\t\t\t%d\t\t\t%d\n",i,pr[i],WT[i],TT[i]);
		}
	 aw = (float)total_wt/n;
	 at = (float)total_tt/n;
	 printf("Average Waiting Time : %f\n",aw);
	 printf("Average Turnaround Time : %f\n",at);
	}

void main()
	{
	 int c,i,f=1;
	 while(f==1)
	 	{printf("Enter the total no. of processes\n");
		 scanf("%d",&n);
		 printf("Enter the burst time for the processes\n");
		 for(i=0;i<n;i++)
		 	{printf("p[%d]:",i);
			 scanf("%d",&b[i]);
			}
		 printf("Select the CPU scheduling algorithm to be implemented\n");
	 	 printf("1. FCFS\n2. SJF\n3. RR(preemptive)\n4. Priority\n5. END\n");
	 	 scanf("%d",&c);
	 	 if(c==1)
			fcfs();
         	 else if(c==2)
         		sjf();
	 	else if(c==3)
			rr();
         	else if(c==4)
        		prior();
	 	else if(c==5)
			f=0;
		else
			printf("Invalid choice");
		}
	}


