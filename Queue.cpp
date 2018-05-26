#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*node;

struct Head
{
    int count;
    struct Node *front;
    struct Node *rear;
}*head;

void create(){
    head = (struct Head *)malloc(sizeof(struct Head));
    head->count = 0;
    head->front = NULL;
    head->rear = NULL;
}

void Enque(int value){
    node =(struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;

    if(head->count == 0){
        head->front = node;
        head->rear = node;
        (head->count)++;
    }
    else{
        head->rear->next = node;
        head->rear = node;
        (head->count)++;
    }
}

int Deque(){
    int num;
    struct Node *temp;

    if(head->count == 0)
        return -1;
    else if(head->count == 1)
    {
        temp = head->front;
        head->rear = NULL;
        head->front = NULL;
        (head->count)--;
        num = temp->data;
        free(temp);
    }
    else
    {
        temp = head->front;
        head->front = head->front->next;
        (head->count)--;
        num = temp->data;
        free(temp);
    }
    return num;
}

void Show()
{
    struct Node *temp;
    temp = head->front;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Destroy(){
    struct Node *temp = head->front;
    while(temp){
        head->front = head->front->next;
        free(temp);
        temp = head->front;
    }
    head->front = NULL;
    head->rear = NULL;
    head->count = 0;
}

void copy_queue(){
    Destroy();
    int size, value;
    cout << "Size of Q1: ";
    cin >> size;
    cout << "Input Data: ";
    while(size--){
        cin >> value;
        Enque(value);
    }

    for(int i=0; i<head->count; i++){
        int temp = Deque();
        Enque(temp);
    }
    cout << "Output Data: ";
    Show();
    Destroy();
}

void compression_string(string str){
    Destroy();
    for(int i=0; i<str.length(); i++){
        int temp = (int)str[i];
        Enque(temp);
    }
    for(int i=0; i<str.length(); i++){
        char ch = (char)Deque();
        if(ch != ' '){
            cout << ch;
        }
    }
    cout << endl;
    Destroy();
}

///===============Stack to Queue Start
struct sNode{
    int data;
    struct sNode *next;
}*snode;

struct sHead{
    int count;
    struct sNode *top;
}*shead;

void screate(){
    shead = (struct sHead *)malloc(sizeof(struct sHead));
    shead->count = 0;
    shead->top = NULL;
}

void push(int data)
{
    if(shead->top==NULL){
        snode = (struct sNode *)malloc(sizeof(struct sNode));
        snode->data = data;
        snode->next = NULL;
        shead->top = snode;
    }
    else{
        snode = (struct sNode *)malloc(sizeof(struct sNode));
        snode->data = data;
        snode->next = shead->top;
        shead->top = snode;
    }
    shead->count++;
}

int pop(){
    snode = shead->top;
    int num;
    if(snode == NULL){
        return -1;
    }
    else{
        shead->top = snode->next;
        num = snode->data;
        free(snode);
        shead->count--;
    }
    return num;
}

///===============Stack to Queue End

void delete_negative(){
    Destroy();
    int size, value;
    cout << "Size of Q: ";
    cin >> size;
    cout << "Input Data: ";
    while(size--){
        cin >> value;
        Enque(value);
    }
    int loop = head->count;
    for(int i=0; i<loop; i++){
        int ret = Deque();
        if(ret > 0){
            Enque(ret);
        }
    }
    Show();
    Destroy();
}


int main()
{
    int choice,number, size;
    string str;
    create();

    while(1){
        printf("\n\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Copy Queue\n");
        printf("5. Compress to String\n");
        printf("6. Stack to Queue Creation\n");
        printf("7. Delete all Negative Integer\n");
        printf("8. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        if(choice == 1){
            cout << "Enter Number for Enqueue: ";
            cin >> number;
            Enque(number);
            Show();
        }
        else if(choice == 2){
            Deque();
            Show();
        }
        else if(choice == 3){
            Show();
        }
        else if(choice == 4){
            copy_queue();
        }
        else if(choice == 5){
            string str;
            cin.ignore();
            getline(cin, str);
            compression_string(str);
        }
        else if(choice == 6){
            Destroy();
            cout << "Enter the size of the stack: ";
            cin >> size;
            screate();
            for(int i=0; i<size; i++){
                cin >> number;
                push(number);
            }
            int c = shead->count;
            while(c--){
                Enque(pop());
            }
            Show();
            Destroy();
        }
        else if(choice == 7){
            delete_negative();
        }
        else{
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
