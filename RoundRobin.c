#include <stdio.h>


int main()
{
    int n,comp=0,currt=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int q;
    printf("Enter quantum:");
    scanf("%d",&q);
    
    int tt=0,pid[n],at[n],ct[n],bt[n],rem[n],st[n],wt[n],tat[n],awt=0,atat=0;
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
        wt[i]=-1;
        tat[i]=-1;
        ct[i]=-1;
        st[i]=-1;
        rem[i]=bt[i];
    }
    printf("\nPId\tAT\tBT\tCT\tRT\tST\tWT\tTAT");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],rem[i],st[i],wt[i],tat[i]);
    }

    
    while(comp<n)
    {
         
        for(int i=0;i<n;i++)
        {
            if(rem[i]==0)
            {
                continue;
            }
            if(rem[i]==bt[i])
            {
                st[i]=currt;
            }
            if(rem[i]<q)
            {
                currt=currt+rem[i];
                rem[i]=rem[i]-rem[i];
            }
            else
            {
                currt=currt+q;
                rem[i]=rem[i]-q;
            }
            if(rem[i]==0)
            {
                comp++;
                ct[i]=currt;
                tat[i]=ct[i]-at[i];
                wt[i]=tat[i]-bt[i];
            }
        }
    }
    
    
    printf("\nPId\tAT\tBT\tCT\tRT\tST\tWT\tTAT");
    for(int i=0;i<n;i++)
    {
        awt+=wt[i];
        atat+=tat[i];
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],ct[i],rem[i],st[i],wt[i],tat[i]);
    }

    printf("\nAverage Wait Time:%d\nAverage TurnAroundTime:%d",awt/n,atat/n);

}