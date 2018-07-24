///************************************///
///.....This code is completed by
///.....Kafik Khan
///......ID: 2017-2-60-078
///********************************///

#include<iostream>
using namespace std;
int arr[100], SIZE=0, arr1[100], SIZE1 = 0, arr2[100000];
void push(int pos)
{
    int index;
    if(!((pos-1)/2 < 0))
    {
        index = (pos-1)/2;
    }
    else
    {
        return;
    }
    if(arr[pos] > arr[index])
    {
        int temp = arr[index];
        arr[index] = arr[pos];
        arr[pos] = temp;
        push(index);
    }
}

void heap_down(int pos)
{
    int index1 = 2*pos + 1;
    int index2 = 2*pos + 2;
    cout<<index1<<" "<<index2<<endl;
    if(index1 >= SIZE && index2 >= SIZE)
    {
        return;
    }
    if(arr[index1] > arr[pos] && arr[index2] > arr[pos])
    {
        if(arr[index1] > arr[index2])
        {
            //cout<<"Index 1 is larger: "<<arr[index1]<<" "<<arr[index2]<<endl;
            int temp = arr[index1];
            arr[index1] = arr[pos];
            arr[pos] = temp;
            //cout<<"the root: "<<arr[0]<<endl;
            //arr[pos] = arr[index1];
            heap_down(index1);
        }
        else if(arr[index1] < arr[index2])
        {
            //cout<<"Index2 is larger: "<<arr[index1]<<" "<<arr[index2]<<endl;
            //cout<<"The root: "<<arr[0]<<endl;
            int temp = arr[index2];
            arr[index2] = arr[pos];
            arr[pos] = temp;

            //arr[pos] = arr[index2];
            heap_down(index2);
        }
    }
    else if(arr[index1] > arr[pos])
    {
        int temp = arr[index1];
        arr[index1] = arr[pos];
        arr[pos] = temp;
        //cout<<"Just index1 is larger: "<<arr[index1]<<endl;
        //cout<<"The root: "<<arr[0]<<endl;
            //arr[pos] = arr[index1];
        heap_down(index1);
    }
    else if(arr[pos] < arr[index2])
        {
            int temp = arr[index2];
            arr[index2] = arr[pos];
            arr[pos] = temp;
            //cout<<"Just index2 is larger: "<<arr[index2]<<endl;
            //cout<<"The root: "<<arr[0]<<endl;
            //arr[pos] = arr[index2];
            heap_down(index2);
        }

}
void MIN_PUSH(int pos)
{
    int index;
    if(!((pos-1)/2 < 0))
    {
        index = (pos-1)/2;
    }
    else
    {
        return;
    }
    if(arr1[pos] < arr1[index])
    {
        int temp = arr1[index];
        arr1[index] = arr1[pos];
        arr1[pos] = temp;
        MIN_PUSH(index);
    }
}
int main()
{
    while(1)
    {
        cout<<"1. Add\n2. View\n3. Delete\n4. Largest And smallest element\n5. Priority Queue(Do not use it if you have used any options in the top 4)\n5. View Priority Queue\nChoice: ";
        int choice;
        cin>>choice;
        if(choice == 1)
        {
            cout<<"Number: ";
            int num;
            cin>>num;
            ///push(num);
            arr[SIZE] = num;
            push(SIZE);
            SIZE++;
        }
        else if(choice == 2)
        {
            for(int i=0; i<SIZE; i++)
            {
                cout<<arr[i]<<endl;
            }
        }
        else if(choice == 3)
        {
            cout<<arr[0]<<" is about to be deleted\n";
            arr[0] = arr[SIZE-1];
            //cout<<arr[SIZE]<<endl;
            arr[SIZE-1] = 0;
            SIZE--;
            heap_down(0);
            cout<<arr[0]<<endl;
        }
        else if(choice == 4)
        {
            cout<<"The largest value is: "<<arr[0]<<endl;
            for(int i=0; i<SIZE; i++)
            {
                arr1[SIZE1] = arr[i];
                MIN_PUSH(SIZE1);
                SIZE1++;
            }
            cout<<"The minimum value is: "<<arr1[0]<<endl;
        }
        else if(choice == 5)
        {
            cout<<"Priority Queue\nNumber: ";
            int num, priority;
            cin>>num;
            cout<<"Priority: ";
            cin>>priority;
            arr[SIZE] = 100*priority + num;
            arr2[100*priority + num] = num;
            push(SIZE);
            SIZE++;
        }
        else if(choice == 6)
        {
            for(int i=0; i<SIZE; i++)
            {
                int k = arr2[arr[i]];
                cout<<k<<" ";
            }
        }
    }
}
