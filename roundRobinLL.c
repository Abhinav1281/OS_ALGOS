#include <stdio.h>
#include <stdlib.h>
struct node
{ 
    int PId,at,bt,ct,wt,tat,st,remt;
    struct node *next;
    struct node *prev;
    
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
    
    node1->ct=-1;
    node1->wt=-1;
    node1->tat=-1;
    node1->st=-1;
    node1->remt=node1->bt;


    node1->next=NULL;
    if(start==NULL){
        start=node1;
        current=node1;
        node1->prev==NULL;
    }
    else
    {
        node1->prev=current;
        current->next=node1;
        current=node1;
    }
        
}

void display()
{
    printf("\nPId\tAT\tBT\tCT\tRT\tST\tWT\tTAT");

    struct node *index=start;
        
    while(index!=NULL)
    {
         printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",index->PId,index->at,index->bt,index->ct,index
         ->remt,index->st,index->wt,index->tat);
         index=index->next;
    }
}

int main()
{
    int n,comp=0,currt=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int q;
    printf("Enter quantum:");
    scanf("%d",&q);
    
    for(int i=0;i<n;i++)
    {
        create();
    }

    display();
    while(comp<n)
    {
        //printf("\nIN LOOP\n");
        struct node *index=start;
        
        while(index!=NULL)
        {
            if(index->remt==0){
                index=index->next;
                continue;
            }

            if(index->bt==index->remt)
                index->st=currt;

            if(index->remt<q){
                currt=currt+index->remt;
                index->remt=0;
            }
            else
            {
                currt+=q;
                index->remt-=q;
            }
            if(index->remt==0)
            {
                comp++;
                index->ct=currt;
                index->tat=index->ct-index->at;
                index->wt=index->tat-index->bt;
            }
            index=index->next;
        }
        //printf("\nINNER LOOP DONE\n");
    }
   // printf("\nLOOP DONE\n");
    display();
}