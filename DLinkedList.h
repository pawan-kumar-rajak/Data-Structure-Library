#include<iostream>
using namespace std;

class DNode{
    public :
        int data;
        DNode* prev;
        DNode* next;
        
        DNode(int data){
            this -> data = data;
            prev = NULL;
            next = NULL;
        }
        
        //destructor
        ~DNode () {
            
            int temp = this -> data;
            if ( next != NULL){
                delete next;
                next = NULL;
                }
           cout <<"memory freed for data  : "<<temp<<endl;
        }



        //!Functions
        void insertAtHead (DNode* &head , int data);
        void insertAtTail (DNode* &tail , int data);
        void insertAtPosition (DNode* &head , DNode* &tail , int position  , int data);
        void deletion (DNode* &head , DNode* &tail, int position);
        void insertAtValue (DNode* &head , DNode* &tail , int value , int data);
        void print(DNode* head ,DNode* &tail);

};
        
//___________________________

void DNode:: insertAtHead (DNode* &head , int data){
    
    //if no DNode or DNode is empty
    if(head == NULL){
        DNode* temp = new DNode(data);
        head = temp;
    }
    
    else{
    //1st - creation of new DNode 
    DNode* temp = new DNode(data);                
    //temp ke next ko purane wale DNode(head ) se point kra do
    temp ->next = head;
    
    //purane wale(head ) ke prev ko naye wale (temp) se point kra do
    head -> prev= temp;
    
    //head ki position change kro
    head = temp;
    }
}


//___________________________
void DNode:: insertAtTail ( DNode* & tail ,int data)
{
    //if empty
    if(tail == NULL){
        DNode* temp = new DNode(data);
        tail = temp;
    }
    
    else{
    DNode* temp = new DNode(data);
    
    tail -> next= temp;
    temp -> prev= tail;
    tail = temp;
}
}


//___________________________
void DNode:: insertAtPosition (DNode* &head , DNode* &tail , int position  , int data){
    
    if (position==1){
        insertAtHead (head , data );
        return;
    }
    
    DNode* temp = head;
   int count = 1;
    while(count < position-1){
        temp = temp ->next;
        count++;
    }
    
    if (temp -> next ==NULL){
        insertAtTail (tail , data);
        return;
    }
    
    else{
        DNode * DNodeToInsert = new DNode(data);
        
        DNodeToInsert -> next =
                         temp -> next;
                         
        temp ->next -> prev =
                    DNodeToInsert;
        
        temp -> next = DNodeToInsert;
        
        DNodeToInsert -> prev = temp;
    }
}

//___________________________
void DNode:: deletion (DNode* &head , DNode* &tail, int position){
   DNode* temp = head;
   if (position ==1){
              temp -> next -> prev =NULL;
              head = temp ->next;
              temp -> next = NULL;
              delete temp;
   }
   
   else{
          DNode* prev = NULL;
          DNode* curr = head;
          
          int count = 1;
          //traversing 
          while (count < position){
              prev = curr;
              curr = curr-> next ;
              count ++;
              
              if (curr ->next == NULL){
                  tail = prev;
              }
          }
          
          curr -> prev = NULL;
          prev -> next = curr -> next;
          curr -> next = NULL;
          delete curr;
   }
   }


//___________________________

void DNode:: insertAtValue (DNode* &head , DNode* &tail , int value , int data){
    
    
    
    if (head == NULL){
        insertAtHead(head , data);
        return;
    }
    
    else {
        DNode * curr = head;
        
        while (curr -> data != value){
            curr = curr->next;
            }
            if(curr -> next == NULL){
                insertAtTail (tail , data);
                return;
        }
        
            
            DNode * DNodeToInsert = new DNode(data);
        
        DNodeToInsert -> next =
                         curr -> next;
                         
        curr ->next -> prev =
                    DNodeToInsert;
        
        curr -> next = DNodeToInsert;
        
        DNodeToInsert -> prev = curr;
    }
    }
                  
//___________________________
void DNode:: print(DNode* head ,DNode* &tail){
    
    DNode* temp = head;
    while(temp != NULL){
         cout << temp->data;
        if (temp->next != NULL) {
            cout << "  <-->  ";  // Arrow between DNodes
        }
        temp = temp->next;
    }
    cout<<endl;
    cout<<"head : "<<head ->data<<endl;
    cout<<"tail : "<<tail -> data<<endl<<endl;
}
//___________________________
