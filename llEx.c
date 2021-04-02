#include <stdio.h>
#include <stdlib.h>
struct node
{ 
    int data;
    struct node *next;
    struct node *prev;
    
};
struct node *start;
int ctl=0,awt=0,atat=0,n;
struct node *current;

void create()
{
    struct node *node1=(struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA:");
    scanf("%d",&(node1->data));
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
                    if(current->data > index->data) 
                    {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
 }
 void display()
{
    //printf("ENTERED DISPLAY");
    struct node *node1=start;
    //printf("%p",node1->next);
    printf("\nNORMAL:::");
    while(node1!=NULL){
         //printf("ENTERED LOOP");
        printf("%d\t",node1->data);
        node1=node1->next;
        
    }
    printf("\nREVERSED:::");
    node1=current;
    while(node1!=NULL){
         //printf("ENTERED LOOP");
        printf("%d\t",node1->data);
        node1=node1->prev;
        
    }
}

 int main()
 {
     int num=5;
     for (int i = 0; i < num; i++)
     {
         create();
     }
     display();
     sortPRIOS();
    display(); 
 }
