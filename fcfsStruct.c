#include <stdio.h>
#include <stdlib.h>
struct node
{
    int PId,at,bt,ct,wt,tat;
    struct node *next;
    
};
struct node *start;
int ctl=0,awt=0,atat=0,n;
struct node *current;

void create()
{
    struct node *node1=(struct node *)malloc(sizeof(struct node));
    printf("\nENTER Process Id:");
    scanf("%d",&(node1->PId));
    printf("ENTER Arrival Time:");
    scanf("%d",&(node1->at));
    printf("ENTER Burst Time:");
    scanf("%d",&(node1->bt));
    node1->next=NULL;
    if(start==NULL){
        start=node1;
        current=node1;
    }
    else
    {
        current->next=node1;
        current=node1;
    }
        
}
void calc()
{
    struct node *node1=start;
    while(node1!=NULL)
    {
        if(ctl<node1->at)
            {
                node1->ct=(node1->at)+(node1->bt);
            }
            else
            {
                node1->ct=ctl+node1->bt;
            }
            ctl=node1->ct;
            node1->tat=(node1->ct)-(node1->at);
            node1->wt=(node1->tat)-(node1->bt);
            node1=node1->next;
            
    }
}

void display()
{
    struct node *node1=start;
    while(node1!=NULL)
    {
         awt+=node1->wt;
        atat+=node1->tat;
       
     printf("\n%d\t%d\t%d\t%d\t%d\t%d",node1->PId,node1->at,node1->bt,node1->ct,node1->wt,node1->tat);
        node1=node1->next;
        
    }
    printf("\nAverage Wait Time:%d\nAverage TurnAroundTime:%d",awt/n,atat/n);

}

int main()
{
    printf("Enter number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter for process:%d",i);
        create();
    }
     printf("\nPId\tAT\tBT\tCT\tWT\tTAT");
     calc();
   display();
}