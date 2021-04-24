#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

struct DLNode {
    int  data;
    struct DLNode * next;
    struct DLNode * prev; 
};

struct SLNode {
    int  data;
    struct SLNode *next;    
};
void printDLList(struct DLNode* list) 
{
    while (list != NULL)
    {
        printf("%i -> ", list->data);
        list = list->next;
    }
    printf("\n");
}
void printSLList(struct SLNode* list) 
{
    printf("SLLIST: \n");
    while (list != NULL)
    {
        printf("%i -> ", list->data);
        list = list->next;
    }
    printf("\n");
}
int size(struct DLNode* d_head)
{
    int  m = 0;
    while (d_head->next!=NULL)
    {
        d_head = d_head->next;
        m++;
    } 
    return m+1;
}
struct SLNode * createSLNode(int data){
    struct SLNode * pnode = malloc(sizeof(struct SLNode));
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}
struct DLNode* createDLNode(int data)  
{
    struct DLNode * pnode = malloc(sizeof(struct DLNode)); 
    pnode->prev = NULL;
    pnode->data = data;  
    pnode->next = NULL;
    return pnode;
}
int find(struct DLNode* d_head)
    {
        int f[100];
        int m = size( d_head);
        printf("size = %i \n",m);
        int u = 0;
        int v = 0;
        int p = 0;
        int n = 0;
        int l = 1;
        while (d_head != NULL)
        {
            f[v] =  d_head->data;
            d_head = d_head->next;
            v++;
        }
        for (size_t i = 0; i < m; i++)
        {
            printf("%i ",f[i]);
            if (f[i] % 2 == 0)
            {
                p++;
            }       
        }
        if (p == 0)
        {
            l = 0;
            return l ;
        }  
        else
        {    
            u = f[0];
            if (u %2 == 1)
            {
                u = f[1];
            }
            
            puts("");
            for (size_t i = 0; i < m; i++)
            {
                    for (size_t k = 0; k < m; k++)
                    {
                    if (f[i]<f[k] && f[i]%2 == 0 && f[k]%2 == 0)
                    {
                        u = f[k];
                    }  
                }
            }
            printf("u  = %i ",u);       
            while (f[n]!= u)
            {
                l++;
                n++;
            }
            printf("index  = %i ",l);
            return l;
        }
    }
struct DLNode* addDLNode(struct DLNode* d_head, struct DLNode* node) 
    {
        if (d_head == NULL)
        {
            d_head = node;
            
        }
        else
        {
            int index = find(d_head);
            puts("");
            if (index == 0)
            {
                node->next = d_head;
                node->prev = NULL;
                d_head->prev = node;               
                return node;
            }
            if (index == 1)
            {
                node->next = d_head->next;
                node->prev = d_head;
                d_head->next = node;  
            }
            else
            {  
                struct DLNode * temp = d_head;
                for(int i = 0; i < index-1; i++){
                    temp = temp->next;
                }
                node->next = temp->next;
                node->prev = temp;
                temp->next = node;    
            }
        }
        return d_head;       
    } 
int avgg(struct DLNode* head)
{
    float x = 0;
    float count = 0;  
    float avg = 0;
    while (head!=NULL)
    {
        x = x + head->data ;
        head = head->next;
        count++;
    }
    
    avg = x / count;
    printf("avg = %f\n", avg );
    return avg; 
}
struct DLNode* removeDLNode(struct DLNode* head)
{
    float avg = avgg(head);
    struct DLNode * temp = head;

    while (temp!=NULL){
        if(temp->data > avg ){

            struct DLNode * tempForDel = temp;

            if(temp->next!=NULL){
                temp->next->prev = temp->prev;
            }

            if(temp->prev!=NULL){
                temp->prev->next = temp->next;
            }
            else{
                head = temp->next;
                head->prev = NULL;
            }

            temp = temp->next;
            free(tempForDel);
        }
        else{
            temp = temp->next;
        }
    }
    return head;  
}
struct SLNode * slnode_back(struct SLNode * head)
{
    if (head == NULL) return NULL;
    struct SLNode * node = head;
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node;
}

struct SLNode * slnode_push_back(struct SLNode * head, int new_value) 
{
    struct SLNode * new_node = createSLNode(new_value); 
    if (head == NULL) {
        return new_node;
    } else {
        struct SLNode * back = slnode_back(head);
        back->next = new_node;
        return head;
    }
}
struct SLNode* createSecondList(struct DLNode* d_head)
{
    int avg = avgg(d_head);
    struct DLNode* dlHead1 = d_head;
    struct SLNode * s_head = NULL;
  
    while (d_head->next != NULL)
    {
        if (d_head->data > avg)
        {
            s_head = slnode_push_back(s_head , d_head->data);
            
        }
        d_head = d_head->next;
    }
    
    return s_head;
}
struct SLNode* addSLNode(struct SLNode* head, struct SLNode* node) 
{
    if (head == NULL)
    {
        return node;
    }
    else 
    {
        node->next = head->next;
        head->next = node;
        return head;
    }    
}
int main()
{
    

char comm[10];
    struct DLNode * d_head = NULL;
    struct SLNode * s_head = NULL;
    int data = 0;
    while (1)
    {
        printf("-----------------------------------\n 1: DLnode \n 21: Remove nodes and create SLlis \n 22: add slnode after s_head\n 3: exit\n");
        printf("command:");
        scanf("%s",comm);
        if (strncmp("3", comm, 1)==0)
        {
            return 0;
        }
        else if (strncmp("1", comm, 1)==0)
        {
            printf("Input data: ");
            scanf("%i", &data);
            struct DLNode * new_node = createDLNode(data);    
            d_head = addDLNode(d_head, new_node);  
            printDLList(d_head);
            puts(""); 
        } 
        else if (strncmp("21", comm, 2)==0)
        {  
            
            printDLList(d_head);
            s_head = createSecondList(d_head);
            removeDLNode(d_head);
            printSLList(s_head);
        }
        else if (strncmp("22", comm, 2)==0)
        {  
            printf("Input data: ");
            scanf("%i", &data);
            struct SLNode * new_node = createSLNode(data);
            s_head = addSLNode(s_head,new_node);
            printSLList(s_head);
        }
    }
}