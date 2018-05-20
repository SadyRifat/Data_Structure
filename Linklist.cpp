#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
}*head;

void add(int value){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = head;
    head = newnode;
}

int insert(int loc, int value){
    struct node *temp, *newnode;
    temp = head;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if(loc == 0){
        newnode->next = head;
        head = newnode;
    }
    else{
        for(int i=1; i<loc; i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void append(int value){
    struct node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = temp->next;
    temp->next = newnode;

}

void delete_beginning(){
    struct node *temp = head;
    head = temp->next;
    free(temp);
}

void delete_last(){
    struct node *temp, *prev;
    temp = head;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}


void position_delete(int loc){
    struct node *temp, *prev;
    temp = head;

    for(int i=0; i<loc; i++){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

void display(){
    struct node *temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}


void reverse_list(){
    struct node *left, *right, *temp;
    left = NULL;
    temp = head;
    while(temp != NULL){
        right = temp->next;
        temp->next = left;
        left = temp;
        temp = right;
    }
    head = left;
    display();
}



int main()
{
    int choice, value, position;

    while(1){
        cout << endl << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at any position" << endl;
        cout << "3. Insert at last" << endl;
        cout << "4. Delete from last position" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from any position" << endl;
        cout << "7. Reverse link list" << endl;
        cout << "8. Exit" << endl << endl;

        cout << "Enter your choice::: ";
        cin >> choice;


        if(choice == 1){
            cout << "Enter the value: ";
            cin >> value;
            add(value);
            display();
        }

        else if(choice == 2){
            cout << "Enter the position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insert(position, value);
            display();
        }
        else if(choice == 3){
            cout << "Enter the value: ";
            cin >> value;
            append(value);
            display();
        }

        else if(choice == 4){
            delete_last();
            display();
        }

        else if(choice == 5){
            delete_beginning();
            display();
        }

        else if(choice == 6){
            cout << "Enter the position: ";
            cin >> position;
            position_delete(position);
            display();
        }

        else if(choice == 7){
            reverse_list();
        }

        else if(choice == 8){
            exit(1);
        }

        else{
            cout << "Wrong choice. Try again..." << endl;
        }
    }
    return 0;
}
