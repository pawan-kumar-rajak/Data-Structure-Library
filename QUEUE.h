#include<iostream>
#include<queue>
using namespace std;

class Queue{
    int* arr;
    int front;
    int rear ;
    int size ;

    public :

        Queue()  //Constructor
        {
            front = 0;
            rear = 0;

            size = 10; //assume
            arr = new int[size];
            cout<<"Queue is created !!"<<endl;
        }

        /*--------------------Functions----------------------------------*/

        bool isEmpty(){
            if(rear == front)
                return true;
            
            else
                return false;
        }


        void enqueue(int data){
            if(rear == size)    // full condition
                cout<<"queue is full !!"<<endl;

            else{
                cout<<data<<" entered successfully.. "<<endl;
                arr[rear] = data;
                rear ++ ;
            }
        }


        int dequeue(){
            if (rear == front){
                return -1;
            }

            else{
                int ans = arr[front];
                arr[front] = -1;
                front++;

                if(front == rear){
                    front = 0;
                    rear = 0;
                }

                return ans;
            }
        }

        int Front(){
            if (rear == front){
                return -1;
            } 
            else{
                return arr[front];
            } 
        }

        void display(){
            int f = front ; 
            int r =  rear;
            if(f == r){
                cout<<"empty queue"<<endl<<endl;

                for(int i = 0 ; i<size ; i++){
                    cout<<" * | ";
                }
                cout<<endl;
            }


            else{

                while(f != r){
                    cout<<arr[f]<<" | ";
                    f ++;
                }
                for(int i = 0 ; i<size -r ; i++){
                    cout<<" * | ";
                }
                cout<<endl;
            }
        }  
};
