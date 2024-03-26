#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK      1
#define NOTOK   0


struct mystr {
    struct mystr *next,  *prev;
    int age;
    char name[52];
    char *message;
};
struct mystr *head=0;

int add(int age, char *name, char *msg)
{
    struct mystr *new, *last;

    if((new = malloc(sizeof(struct mystr)))==NULL)
        return NOTOK;
  
    new->next = new->prev = 0;
    new->age = age;
    strcpy(new->name, name);

    new->message = malloc(8);
    strcpy(new->message, msg);

    if(head == NULL)    //1. 처음 노드를 생성할 경우
    {
        head = new;
        return (OK);
    }
    for(last=head; last->next; last = last->next)
            ;
        last->next = new;
        new->prev = last;
        return (OK);
}

int delete (char *name){
    struct mystr *ptr, *tmp;
    for(ptr=head; ptr; ptr=ptr->next){
        if(!strcmp(name, ptr->name)){
            if(ptr->prev==0){
                head = ptr->next;
                if(head)
                    head->prev=0;
            }
            else{
                ptr->prev->next = ptr->next;
            if(ptr->next)
                ptr->next->prev=ptr->prev;
            }
        
            free(ptr->message);
            free(ptr);
            return(OK);
        }
    }
    return (NOTOK);
}


void print()
{
    struct mystr *ptr=head;
    printf("---printf\n");
    while(ptr){
        printf("\t\name=[%s], age=[%d], message=[%s]\n", ptr->name, ptr->age, ptr->message);
        ptr=ptr->next;
    }
}


int main()
{
    int age;
    char name[8], message[8], command[8];

    printf("input command. (add, delete, print, end)");
    scanf("%s", command);

    while (strcmp(command,"end"))
    {
        if(!strcmp(command, "add"))
        {
            printf("\tinput name, message, age ");
            scanf("%s %s %d", name, message, &age);
            if(add(age, name, message)==OK)
                printf("\t\tadded successfully.\n");
            else   
         :       printf("\t\tadd fail\n");

        }
        else if(!strcmp(command, "delete"))
        {
            printf("\tinput name ");
            scanf("%s", name);
            if(delete (name)==OK)
                printf("\t\tdelted successfully.\n");
            else
                printf("\t\tdelted fail.\n");
        }
        else if(!strcmp(command, "print"))
        {
            print();
        }
        else if(!strcmp(command, "end"))
        {
            printf("\tend\t");
            exit (1);
        }
        else
        {
            printf("unknown command.\n");
        }
        printf("input command.(add, delete, print, end)");
        scanf("%s", command);
    }
}
