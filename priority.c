#include <stdio.h>


int main()
{
    int n;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int pid[n],at[n],ct[n],bt[n],wt[n],tat[n],pro[n],awt=0,atat=0;
    for(int i=0;i<n;i++)
    {
        printf("Enter details for process:%d",i);
        printf("\nEnter Process ID:");
        scanf("%d",&pid[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&at[i]);
        printf("Enter Burst Time:");
        scanf("%d",&bt[i]);
        printf("Enter Priority:");
        scanf("%d",&pro[i]);
        
    }

    int ctl=0;
    for (int i = 0; i < n; i++)
    {
         for(int j=1; j < (n-i); j++)
         {  
            if(pro[j-1] < pro[j])
            {   
                int temp = pro[j-1];  
                 pro[j-1] = pro[j]; 
                 pro[j] = temp;
                 temp = pid[j-1];  
                 pid[j-1] = pid[j]; 
                 pid[j] = temp;
                 temp = at[j-1];  
                 at[j-1] = at[j]; 
                 at[j] = temp;
                 temp = bt[j-1];  
                 bt[j-1] = bt[j]; 
                 bt[j] = temp;
                   
            }  
                          
        }  
    }
    
    for(int i=0;i<n;i++)
    {
        if(ctl<at[i])
        {
            ct[i]=at[i]+bt[i];
        }
        else
        {
            ct[i]=ctl+bt[i];
        }
        ctl=ct[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("\nPId\tAT\tBT\tCT\tWT\tTAT");
    for(int i=0;i<n;i++)
    {
        awt+=wt[i];
        atat+=tat[i];
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],pro[i],wt[i],tat[i]);
    }

    printf("\nAverage Wait Time:%d\nAverage TurnAroundTime:%d",awt/n,atat/n);

}