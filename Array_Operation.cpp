#include<iostream>
using namespace std;

int arr[100];
int size;

void show_array(){
    cout << "Array::: "
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert_item(int p, int num){
    for(int i=size; i>=p; i--){
        arr[i+1] = arr[i];
    }
    arr[p] = num;
    size++;
    show_array();
}

///void insert_item(int p, int num){     ///Another Way
//    size++;
//    int temp;
//    for(int i=p;i<size;i++){
//        temp = arr[i];
//        arr[i]=num;
//        num=temp;
//    }
//    show_array();
//}

void delete_item(int pos){

    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    show_array();
}

int main()
{
    int input, pos, value,del;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter the Values: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    while(1){
        cout << endl;
        cout << "Press 1 for Insert" << endl;
        cout << "Press 2 for Update" << endl;
        cout << "Press 3 for Delete" << endl;
        cout << "Press 4 for Exit" << endl;
        cin >> input;

        if(input == 1){
            cout << "Position: ";
            cin >> pos;
            if(pos > size){
                cout << "Invalid index..." << endl;
                continue;
            }
            cout << "New Value: ";
            cin >> value;
            insert_item(pos, value);
        }
        else if(input == 2){
            cout << "Position: ";
            cin >> pos;
            if(pos >= size){
                cout << "Invalid index..." << endl;
                continue;
            }
            cout << "New Number: ";
            cin >> value;
            arr[pos] = value;
            show_array();
        }
        else if(input == 3){
            cout << "Deleted position: ";
            cin >> del;
            if(pos >= size){
                cout << "Invalid index..." << endl;
                continue;
            }
            delete_item(del);
        }
        else if(input == 4){
            break;
        }
        else{
            cout << "Wrong choice. Try again." << endl;
        }
    }
    return 0;
}
