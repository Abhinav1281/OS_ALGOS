#include <stdio.h>
#include <stdlib.h>
struct node
{ 
    int PId,at,bt,ct,wt,tat,prio;
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
    printf("ENTER Priority:");
    scanf("%d",&(node1->prio));
    
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
 void sortPRIOS() 
 {  
        struct node *current = start, *index = NULL;  
        int temp;    
        if(start==NULL) 
        {  
            return;  
        }  
        else {  
            while(current != NULL) 
            {  
                index = current->next;  
                while(index != NULL) 
                {  
                    if(current->bt > index->bt) 
                    {  
                        temp = current->prio;  
                        current->prio = index->prio;  
                        index->prio = temp;

                        temp = current->at;  
                        current->at = index->at;  
                        index->at = temp;
                        
                        temp = current->PId;  
                        current->PId = index->PId;  
                        index->PId = temp;

                        temp = current->bt;  
                        current->bt = index->bt;  
                        index->bt = temp;

                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
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
       
     printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",node1->PId,node1->at,node1->bt,node1->ct,node1->wt,node1->tat
     ,node1->prio);
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
     printf("\nPId\tAT\tBT\tCT\tWT\tTAT\tPRIO");
     display();
     sortPRIOS();
     calc();
     printf("\n\nPId\tAT\tBT\tCT\tWT\tTAT\tPRIO");
    display();
}
