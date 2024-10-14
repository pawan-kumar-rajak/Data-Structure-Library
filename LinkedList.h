#include<iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;
        
        public :
        
        node (){
            this->data = 0;
            this -> next = NULL;
            }
            
        
        node(int data){
            this -> data = data;
            this -> next = NULL;
        }


        // ! Functions
        void insertAtHead(node * &head , int data);

        void insertAtTail(node * &tail , int data);

        void insertAtPosition (node* &tail ,   node* &head , int position , int data);

        void insertAtValue(node*  &head ,node* &tail ,int value , int data);

        void print(node* &head);

        int getLength(node * &head);

        void reverseByLoop(node* &head);

        void reverseByRec1(node* &head , node* curr , node* prev);

        node* reverseByRec2 ( node* &head);

};



//___________________________


//INSERTION at HEAD
void node:: insertAtHead(node * &head , int data){
    
    if(head == NULL){     //NO ELEMENT EXIST
        node* temp = new node(data );
            head = temp;
            return;
        }
        
        else{
    // create new node
    node* temp = new node(data);
    
    //new node ke adress pr purane  node ka adress (head) daldo
    temp-> next = head;
    
    //head ko new node ke adress ke barabar krdo
    head = temp;
        }
}


//___________________________

//INSERTION AT TAIL
void node:: insertAtTail(node * &tail , int data){
    
    if ( tail == NULL){    //empty list
        node * temp = new node(data);
        tail = temp;
    }
    else{
    // create new node
    node* temp = new node(data);
    
    //purane node ke adress(tail) par new node ka adress daldo
    tail -> next = temp;
    
    //tail ko new node ke adress ke barabar krdo
    tail = temp;
    }
}


//___________________________

void node:: insertAtPosition (node* &tail ,   node* &head , int position , int data){
    
    //inserting at head
    if ( position == 0 || position==1){
        insertAtHead (head , data);
        return;
    }
    
    node * temp = head;
    int count = 1;  // track traversing
    
    //traversing to (position -1) position because node will insert at position 
    while ( count <= position-1){
        
        //temp ko agle nodes ke adress pr le jao --> traversing 
        temp = temp -> next;
        count++;
    }
    
    //inserting at last
    if(temp ->next == NULL){
        insertAtTail(tail , data);
        return;
    }
    
    node* nodeToInsert = new node (data);
    
    nodeToInsert -> next = temp -> next;
    
    //new node ke adres ko purane node(temp) ke next pr store krdo
    temp ->next = nodeToInsert;
}
        
//___________________________
//___________________________

void node:: insertAtValue(node*  &head ,node* &tail ,int value , int data){
    node* curr = head;
    
    
    if(head == NULL){
        insertAtHead (head , data);
        return ;
    }
    
    else{
        while(curr -> data != value ){
            curr = curr->next;
        }
            if(curr -> next == NULL){
                insertAtTail(tail , data);
                return;
            }
    }
        node* temp = new node(data);
        temp -> next = curr -> next;
        curr->next = temp;
    }


//______________________________________

//print linked list
void node:: print(node* &head){
    node * temp = head;
    
     while (temp != NULL){
         cout<<temp -> data <<" ";
          if (temp->next != NULL) {
            cout << "-> ";  // Arrow between DNodes
        }
         temp = temp ->next;
     }
     cout<<endl;
}

//___________________________

int node:: getLength(node * &head){
    int len = 0;
    node* temp = head ;
    
    while ( temp != NULL){
        len ++;
        temp = temp -> next;
    }
    return len;
}

//___________________________

//REVERSE     ITERATIVELY    using LOOPS

void node:: reverseByLoop(node* &head){
    //if empty list OR Single node present
    if( head == NULL   ||   head ->next == NULL){
        return ;
    }
    else{
        node* prev = NULL;
        node * curr = head;
        
        while (curr != NULL){
            node* forward = curr ->next;
            
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
       
    }
}


//___________________________
//REVERSE     BY     RECURSION     I
void node:: reverseByRec1(node* &head , node* curr , node* prev){
    
    //base case
    if(curr ==NULL){
        head = prev;
        return;
    }
    
    else{
        //node* froward = curr ->next ;
        reverseByRec1 (head , curr->next , curr);
        curr ->next = prev;
    }
}


//___________________________
//REVERSE     BY    RECURSION    II

node* node:: reverseByRec2 ( node* &head){
    //empty list of single node list
    if (head == NULL   ||    head -> next ==NULL){
        return head;
    }
    
   node* chotaHead = reverseByRec2 (head ->next);
    head ->next ->next = head;
    head -> next = NULL;
    
    return  chotaHead;
    }                                                                                                          
//___________________________