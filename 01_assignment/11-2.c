#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define NOTOK 0

struct node {
    struct node *next, *prev;
    char name[52];
    char number[30];
} *head = NULL, *tail = NULL;

int insert(char *name, char *number) {
    struct node *new_node;
    if ((new_node = malloc(sizeof(struct node))) == NULL)
        return (NOTOK);
    new_node->next = new_node->prev = NULL;
    strcpy(new_node->name, name);
    strcpy(new_node->number, number);

    if (!head) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    return (OK);
}

int find(char *name) {
    struct node *ptr;
    int found = 0;
    for (ptr = head; ptr; ptr = ptr->next) {
        if (!strcmp(name, ptr->name)) {
            printf("%s : %s\n", ptr->name, ptr->number);
            found = 1;
        }
    }
    if (!found)
        printf("not find\n");
    return found;
}

void print(void) {
    struct node *ptr;
    for (ptr = head; ptr; ptr = ptr->next) {
        printf("name = [%s]\n", ptr->name);
        printf("number = [%s]\n\n", ptr->number);
    }
}

int delete(char *name) {
    struct node *ptr;
    for (ptr = head; ptr; ptr = ptr->next) {
        if (!strcmp(name, ptr->name)) {
            if (ptr->prev)
                ptr->prev->next = ptr->next;
            else
                head = ptr->next;

            if (ptr->next)
                ptr->next->prev = ptr->prev;
            else
                tail = ptr->prev;

            free(ptr);
            printf("========delete node=======\n");
            return OK;
        }
    }
    return NOTOK;
}

void save(char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Could not open file for writing\n");
        return;
    }
    struct node *ptr = head;
    while (ptr) {
        fprintf(file, "%s %s\n", ptr->name, ptr->number);
        ptr = ptr->next;
    }
    fclose(file);
    printf("Data saved to %s\n", fileName);
}

void initialize(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Could not open file for reading\n");
        return;
    }
    // Free the existing list
    struct node *ptr = head;
    while (ptr) {
        struct node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    head = tail = NULL;

    // Read the file and reconstruct the list
    char name[52], number[30];
    while (fscanf(file, "%s %s", name, number) != EOF) {
        insert(name, number);
    }
    fclose(file);
    printf("Data initialized from %s\n", fileName);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        initialize(argv[1]);
    }

    char name[52], number[52], command[10];

    printf("input command: insert, print, find, delete, save, initialize, quit : ");
    while (scanf("%s", command) != EOF) {
        if (!strcmp(command, "insert")) {
            printf("name ? ");
            scanf("%s", name);
            printf("number ? ");
            scanf("%s", number);
            insert(name, number);
        } else if (!strcmp(command, "find")) {
            printf("name ? ");
            scanf("%s", name);
            find(name);
        } else if (!strcmp(command, "print")) {
            print();
        } else if (!strcmp(command, "delete")) {
            printf("name ? ");
            scanf("%s", name);
            delete(name);
        } else if (!strcmp(command, "save")) {
            printf("file name ? ");
            scanf("%s", number); // Reusing the `number` variable to store the filename
            save(number);
        } else if (!strcmp(command, "initialize")) {
            printf("file name ? ");
            scanf("%s", number); // Reusing the `number` variable to store the filename
            initialize(number);
        } else if (!strcmp(command, "quit")) {
            exit(0);
        } else {
            printf("unknown command.\n");
        }
        printf("input command: insert, print, find, delete, save, initialize, quit : ");
    }

    return 0;
}
