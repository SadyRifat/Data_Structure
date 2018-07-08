#include<iostream>
#include <stdlib.h>
using namespace std;


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int x){
    if(root == NULL){
        root = (struct node *)malloc(sizeof(struct node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if(root->data > x){
            root->left = insert(root->left, x);
        }
        else{
            root->right = insert(root->right, x);
        }
    }
    return root;
}

void preorder(struct node *root){
    if(root != NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}


bool search(struct node *root, int x){
    if(root != NULL){
        if(root->data == x){
            return 1;
        }
        else if(root->data > x){
            search(root->left, x);
        }
        else{
            search(root->right, x);
        }
    }
    else
        return 0;
}

struct node *findMax(struct node *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node *findMin(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node *Delete(struct node *root, int data)
{
    if(root == NULL)
        return 0;
    else if(data < root->data){
        root->left = Delete(root->left,data);
    }
    else if(data > root->data){
        root->right = Delete(root->right,data);
    }
    else
    {
        if(root->left == NULL && root->right == NULL){
            root = root->right;
            free(root);
        }
        else{
            if(root->left == NULL){
                struct node *temp = root;
                root = root->right;
                free(temp);
            }
            else if(root->right == NULL){
                struct node *temp = root;
                root = root->left;
                free(temp);
            }
            else{
                struct node *temp = findMax(root->left);
                root->data = temp->data;
                root->left = Delete(root->left,temp->data);
            }
        }
    }
    return root;
}


bool checkLeft(int *arr, int index, int root){
    bool temp = 1;
    if(arr[index] != -1){       ///Base Case /// Check Parent node has child or not
        if(root > arr[index]){
            temp = checkLeft(arr, (2*index)+1, root);   ///Recursion call for Parent node's left child
            temp = checkLeft(arr, (2*index)+2, root);   ///Recursion call for Parent node's right child
        }
        else{
            return 0;
        }
    }
    return temp;
}

bool checkRight(int *arr, int index, int root){
    bool temp = 1;
    if(arr[index] != -1){       ///Base Case /// Check Parent node has child or not
        if(root <= arr[index]){
            temp = checkRight(arr, (2*index)+1, root);   ///Recursion call for Parent node's left child
            temp = checkRight(arr, (2*index)+2, root);   ///Recursion call for Parent node's right child
        }
        else{
            return 0;
        }
    }
    return temp;
}


int main()
{
    int choice, number;
    struct node *root = NULL;

    while(1){
        ///system("cls");
        cout << endl;
        cout << "1. Insert in Binary Tree" << endl;
        cout << "2. Search Number from Tree " << endl;
        cout << "3. Traverse Operation " << endl;
        cout << "4. Delete " << endl;
        cout << "5. Smallest and Largest Element " << endl;
        cout << "6. Check BST " << endl;
        cout << "7. Exit " << endl << endl;

        cout << "Enter your choice : ";
        cin >> choice;


        if(choice == 1){
            cout << "Enter a Number for Insert: ";
            cin >> number;
            root = insert(root, number);
        }

        else if(choice == 2)
        {
            cout << "Enter the Number for Search: ";
            cin >> number;
            bool flag = search(root,number);
            if(flag == 1)
                cout << "Found " << endl;
            else
                cout << "Not found " << endl;
        }

        else if(choice == 3){
            cout << "Preorder traversal of the tree is: ";
            preorder(root);
            cout << endl;
            cout << "Inorder traversal of the tree is: ";
            inorder(root);
            cout << endl;
            cout << "Postorder traversal of the tree is: ";
            postorder(root);
            cout << endl;
        }

        else if(choice == 4){
            cout << "Enter Number to Delete: ";
            cin >> number;
            root = Delete(root,number);
        }

        else if(choice == 5){
            struct node *temp = findMax(root);
            cout << "Largest Element is:" << temp->data << endl;
            temp = findMin(root);
            cout << "Smallest Element is:" << temp->data << endl;
        }

        else if(choice == 6){
            int arr[100];
            for(int i=0; i<100; i++)                ///Initialize the array
                arr[i] = -1;
            cout << "Input Number of node for BST:: ";
            cin >> number;
            cout << "Enter the Node Elements::: ";
            for(int i=0; i<number; i++){            ///Take Binary Tree in an array
                cin >> arr[i];
            }

            bool temp = 1;                              ///Initialize a flag
            for(int i=0; i<number; i++){                ///For each node check it's left child
                ///Check the left child first
                temp = checkLeft(arr, (2*i)+1, arr[i]); ///If any node break BST condition then, temp=0
                if(temp == 0){
                    cout << "Not BST.. " << endl;
                    break;
                }
                ///If left child is OK the go for the right child
                temp = checkRight(arr, (i*2)+2, arr[i]);
                if(temp == 0){
                    cout << "Not BST.. " << endl;
                    break;
                }
            }
            if(temp == 1)   ///If all nodes are OK then the given Binary tree is BST
                cout << "BST.. " << endl;
        }

        else if(choice == 7){
            exit(1);
        }

        else{
            cout << "Wrong input. Try again." << endl << endl;
        }

    }
    return 0;
}
