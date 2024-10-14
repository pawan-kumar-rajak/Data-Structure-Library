#include<iostream>
#include<queue>
#include <cmath>

using namespace std;

class node{

    public:

        int data;
        node* left;
        node* right;

        //* constructor
        node(int data){
            this-> data = data;
            this-> left = NULL;
            this-> right = NULL;
        }


        // default construtor
        node(){
            this-> data = 0;
            this-> left = NULL;
            this-> right = NULL;
        }


};

node* buildTree(node* root){

    cout<<"enter data : ";
    int data;  cin>>data;
    
    root = new node(data);

    if(data == -1)
        return NULL;

    cout<<"\nenter data for inserting in left of "<<data<<endl;
    root -> left = buildTree(root ->left);

    cout<<"\nenter data for inserting in right of "<<data<<endl;
    root -> right = buildTree(root ->right);

    return root;
}

//todo: -----------------------visualization of Tree Upto 4 level ---------------
// Helper function to calculate the height of the tree
int calculateHeight(node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Print spaces to format the output
void printSpaces(int count) {
    for (int i = 0; i < count; ++i)
        cout << "  ";
}

// Function to print branches "/ and \"
void printBranches(int nodeCount, int spaceBetween) {
    for (int i = 0; i < nodeCount; i++) {
        printSpaces(spaceBetween - 1);
        cout << "/";
        printSpaces(spaceBetween -3);
        cout << "\\";
        // printSpaces(spaceBetween-1);
    }
    cout << endl;
}

// Print the current level's nodes with proper spacing
void printLevelNodes(queue<node*> nodes, int nodeCount, int spaceBetween) {
    for (int i = 0; i < nodeCount; i++) {
        node* temp = nodes.front();
        nodes.pop();
        // cout<<"  ";
        printSpaces(spaceBetween );
        if (temp != nullptr) {
            cout << temp->data;
        } else {
            cout << "X";
        }
        // printSpaces(spaceBetween);
    }
    cout << endl;
}

// Perform level order traversal and print each level with proper formatting
void VisualizeTree(node* root) {
    if (root == nullptr) return;

    int height = calculateHeight(root);
    int maxNodes = pow(2, height) - 1;
    int level = 0;

    if(height > 4){
        cout<<"sorry but Visualisation is only suitable for max level = 4"<<endl;
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty() && level < height) {
        int nodeCount = pow(2, level);  // Number of nodes at the current level
        int spaceBetween = maxNodes / (nodeCount + 1);  // Spacing between nodes

        printLevelNodes(q, nodeCount, spaceBetween+1);

        // Print branches if there is another level
        if (level + 1 < height) {
            printBranches(nodeCount, spaceBetween+1);
        }

        // Enqueue children nodes for the next level
        for (int i = 0; i < nodeCount; i++) {
            node* temp = q.front();
            q.pop();
            if (temp != nullptr) {
                q.push(temp->left);
                q.push(temp->right);
            } else {
                q.push(nullptr);
                q.push(nullptr);
            }
        }
        level++;
    }
}

void levelOrderTraversal(node* root){
    //Dry run at page 123-124
    cout<<endl<<endl<<"printing level order traversal :"<<endl;

    queue<node*> q;
    q.push(root);
    q.push(NULL);       //*null will act as seperator

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){           //* Purana level khtam ho gya
            cout<<endl;     //*seperator

            if(!q.empty())  //* this means still child nodes are present  -> ek bar fir se seperator dalna pdega
                q.push(NULL);
        }

        else{
            cout<<temp->data<<" ";

            if(temp ->left){        //! if temp ->left is not empty/NULL
                q.push(temp ->left);
            }

            if(temp -> right){      //! if temp ->right is not empty/NULL
                q.push(temp -> right);
            }
        }
    }cout<<endl;
}

void inorder(node* root){

    if(root == NULL){
        return ;
    }

    inorder(root-> left);
    cout<<root ->data<<" ";
    inorder(root -> right);
}


void preorder(node* root){

    if(root == NULL){
        return ;
    }

    cout<<root ->data<<" ";
    preorder(root-> left);
    preorder(root -> right);
}


void postorder(node* root){

    if(root == NULL){
        return ;
    }

    postorder(root-> left);
    postorder(root -> right);
    cout<<root ->data<<" ";
}


void buildFromLevelOrder(node* &root){

    queue<node*> q;

    cout<<"root node data : ";
    int rootData;   cin>>rootData;
    root = new node(rootData);
    q.push(root);

    while(!q.empty()){

        node* temp= q.front();
        q.pop();

        cout<<"enter left node of "<<temp ->data<<endl;
        int leftData;   cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp -> left);
        }


        cout<<"enter right node of "<<temp ->data<<endl;
        int rightData;   cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

void waitForEnterAndClear()
{
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}