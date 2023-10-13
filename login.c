#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    char username[20];
    char password[20];
} typedef user;

struct LinkedList
{
    user data;
    struct LinkedList *next;
} typedef LinkedList;

typedef struct LinkedList *node;

node head = NULL;

node createNode()
{
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    return temp;
}
node addNode(node head, user user)
{
    node temp, p;
    temp = createNode();
    temp->data = user;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

void addUser()
{
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    user user;
    strcpy(user.username, username);
    strcpy(user.password, password);
    head = addNode(head, user);
    printf("Register successfully!\n");
}

void login()
{
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    node p = head;
    while (p != NULL)
    {
        if (strcmp(p->data.username, username) == 0 && strcmp(p->data.password, password) == 0)
        {
            printf("Login successfully!\n");
            return;
        }
        p = p->next;
    }
    printf("Login failed!\n");
}

void main()
{
    while (1)
    {
        int choice;
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            addUser();
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }
}