#include <stdio.h>


int main()
{
    int n;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int q;
    printf("Enter quantum:");
    scanf("%d",&q);
    
    int tt=0,pid[n],at[n],ct[n],bt[n],rem[n],wt[n],tat[n],awt=0,atat=0,done=1;
    for(int i=0;i<n;i++)
    {
        printf("Enter details for process:%d",i);
        printf("\nEnter Process ID:");
        scanf("%d",&pid[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&at[i]);
        printf("Enter Burst Time:");
        scanf("%d",&bt[i]);
    }
    

    for(int i=0;i<n;i++)
    {
        rem[i]=bt[i];
    }
    while(1)
    {
        done=1;
        for (int i = 0 ; i < n; i++) 
        { 
            if (rem[i] > 0) 
            { 
                done = 0;  
  
                if (rem[i] > q) 
                { 
                    tt += q; 
  
                    rem[i] -= q; 
                } 
  
                else
                { 
                    tt = tt + rem[i]; 
  
                    wt[i] = tt - bt[i]; 
  
                    rem[i] = 0; 
                    done=1;
                } 
            } 
        }
        if (done == 1) 
          break; 
    }

    
    printf("\nPId\tAT\tBT\tCT\tWT\tTAT");
    for(int i=0;i<n;i++)
    {
        awt+=wt[i];
        atat+=tat[i];
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }

    printf("\nAverage Wait Time:%d\nAverage TurnAroundTime:%d",awt/n,atat/n);

}