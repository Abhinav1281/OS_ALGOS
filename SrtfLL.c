#include <stdio.h>
#include <stdlib.h>
struct node
{ 
    int PId,at,bt,ct,wt,tat,remt;
    struct node *next;
    struct node *prev;
    
};
struct node *start,*calstart;
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

    node1->remt=node1->bt;


    node1->next=NULL;
    if(start==NULL){
        start=node1;
        calstart=start;
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

void sortRem() 
 {  
        struct node *current = calstart, *index = NULL;  
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
                    if(current->remt > index->remt) 
                    {  
                        temp = current->remt;  
                        current->remt = index->remt;  
                        index->remt = temp;

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

void display()
{
    printf("\n\nPId\tAT\tBT\tCT\tRT\tWT\tTAT");

    struct node *index=start;
        
    while(index!=NULL)
    {
         printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",index->PId,index->at,index->bt,index->ct,index
         ->remt,index->wt,index->tat);
         index=index->next;
    }
}
void sortPID() 
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
                    if(current->PId > index->PId) 
                    {  
                        temp = current->remt;  
                        current->remt = index->remt;  
                        index->remt = temp;

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
    struct node *index=calstart;
    while(comp<n)
    {
        if(index->at>currt)
        {
            index=index->next;
            continue;
        }
        
        if(index->remt==0)
        {
            index->ct=currt;
            index->tat=index->ct-index->at;
            index->wt=index->tat-index->bt;
            comp++;
            calstart=calstart->next;
        }
        else
        {
            index->remt=index->remt-1;
            currt+=1;
            sortRem();
        }
        index=calstart;
    }
    //sortPID();
    display();
}