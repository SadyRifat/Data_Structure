#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*node;

struct Head{
    int count;
    struct Node *top;
}*head;

void create(){
    head = (struct Head *)malloc(sizeof(struct Head));
    head->count = 0;
    head->top = NULL;
}


void destroy(){
    node = head->top;
    while(node != NULL){
        head->top = node->next;
        free(node);
        node = head->top;
    }
    free(node);
    head->top = NULL;
    head->count = 0;
}


void push(int data)
{
    if(head->top==NULL){
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = data;
        node->next = NULL;
        head->top = node;
    }
    else{
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = data;
        node->next = head->top;
        head->top = node;
    }
    head->count++;
}


int pop(){
    node = head->top;
    int num;
    if(node == NULL){
        return -1;
    }
    else{
        head->top = node->next;
        num = node->data;
        free(node);
        head->count--;
    }
    return num;
}


void display(){
    node = head->top;
    if(head->top == NULL)
        printf("Stack is Empty\n");
    else{
        while(node != NULL){
            printf("%d\n", node->data);
            node = node->next;
        }
    }
}


void parenthesis(char *str){
    int i, check;

    destroy();

     for(i=0; i<strlen(str); i++){
        if(str[i] == '('){
            push(5);
        }
        else if(str[i] == ')'){
            check = pop();
            if(check == -1){
                printf("Closing parentheses not end\n");
                return;
            }
        }
    }
    check = pop();
    if(check != -1){
        printf("Opening parentheses not matched\n");
    }
    else{
        printf("Parentheses matched\n");
    }
    destroy();
}

void reverse_data(){
    int number, temp, reminder;

    destroy();

    scanf("%d", &number);
    temp = number;

    while(temp != 0){
        reminder = temp % 2;
        push(reminder);
        temp = temp/2;
    }
    while(1){
        temp = pop();
        if(temp == -1) break;
        else printf("%d", temp);
    }
    destroy();
}



int main()
{
    int choice,number;
    create();

    while(1){
        printf("\n\n");
        printf("1. Push Stack\n");
        printf("2. Pop Stack\n");
        printf("3. Display Stack\n");
        printf("4. Parsing Unmatched Parenthesis\n");
        printf("5. Reverse Data\n");
        printf("6. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf ("Enter a number to Push : ");
            scanf ("%d", &number);
            push(number);
        }
        else if(choice == 2){
            pop();
            display();
        }
        else if(choice == 3){
            display();
        }
        else if(choice == 4){
            char str[100];
            printf("Enter the Equation: ");
            scanf("%s", &str);
            parenthesis(str);
        }
        else if(choice == 5){
            reverse_data();
        }
        else if(choice == 6)
            break;

        else
            printf("Invalid choice\n");
    }
    return 0;
}
