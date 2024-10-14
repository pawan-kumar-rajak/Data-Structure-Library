#include<iostream>
using namespace std;

class CNode{
    public :
        int data;
        CNode* next ;
        
        //constructor
        CNode(){}
        
        CNode (int data){
            this -> data= data;
            this -> next = NULL;
        }
        
        ~CNode(){
            int temp = this -> data;
            if (next != NULL){
                delete next;
                next = NULL;
            }
            cout<<"the CNode deleted with data : "<<temp<<endl;
        }

        //!Functions

        void insertAtPosition (CNode* & tail , int position, int data);
        void insertCNode(CNode* &tail, int element, int d);
        void deleteCNode(CNode* &tail, int value) ;
        void print(CNode* tail);
};


//___________________________
void CNode:: insertAtPosition (CNode* & tail , int position, int data){
    if (tail == NULL){
        CNode* temp = new CNode(data);
        tail= temp;
        temp -> next = temp;
        return;
    }
    
    if (position==1) {
        CNode* curr = tail->next; 
        CNode* temp = new CNode(data);
        temp -> next = curr;
        tail ->next= temp;
        return;
    }
    
    int count=1;
    CNode* curr = tail;
    while(count <position-1){
        curr = curr->next;
        count ++;
    }
    CNode* temp = new CNode(data);
    temp -> next = curr -> next;
    curr -> next = temp;
    tail =temp;
}


//___________________________

void CNode:: insertCNode(CNode* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        CNode* newCNode = new CNode(d);
        tail = newCNode;
        newCNode -> next = newCNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        CNode* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala CNode
        CNode* temp = new CNode(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}   

//___________________________

void CNode:: deleteCNode(CNode* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        CNode* prev = tail;
        CNode* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 CNode Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 CNode linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

//___________________________
 void CNode:: print(CNode* tail) {


    if (tail == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }

        CNode* temp = tail->next;  // Start from the head (next of tail)
        cout << "Circular Linked List: ";

        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != tail->next) {
                cout << " -> ";  // Arrow between CNodes
            }
        } while (temp != tail->next);

        cout << endl;
        cout << "Tail: " << tail->data << endl << endl; // Display tail data
    

} 
 
 
//___________________________