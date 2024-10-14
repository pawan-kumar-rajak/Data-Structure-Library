#include<bits/stdc++.h>

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


//todo:----------------------level order traversal----------------------
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


//todo :..................................(Diameter of tree)......................................
//* diameter : largest path between two end nodes (root/leaf)

pair<int,int> DiameterFast(node* root){

    //base case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    //* return diameter and height of left/right subtree
    pair<int,int> left  = DiameterFast(root ->left);
    pair<int,int> right  = DiameterFast(root ->right);

    //* three ways to achieve ans
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second;

    //* return maxvalues of diameter and height
    pair<int,int> ans ;
    ans.first = max(op1 , max(op2 , op3));      //diameter
    ans.second = max(left.second , right.second) + 1;   //height

    return ans;

}

//-----------------------------------------------------------------

int diameter(node* root){
    
    return DiameterFast(root).first;      //return first value of pair -> diameter
}


//todo : .....................................(balance tree?)..........................................

pair<bool , int> isbalanceFast(node* root){

    if (root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isbalanceFast(root ->left);       //* check if left part is balanced
    pair<bool,int> right = isbalanceFast(root ->right);      //* check if right part is balanced

    bool leftAns = left.first;
    bool rightAns = right.first;

    //* check balance condition
    bool diff = abs((left.second - right.second) <= 1);

    //? : additional if condition to check problematic node
    if(!diff){
        cout<<"unbalanced node : "<<root->data<<endl;
    }

    pair<bool ,int> ans;

    //* update height for each node
    ans.second =  max(left.second , right.second) + 1 ;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }

    else{
        ans.first = false;
    }

    return ans;
}

//--------------------------------------------------
bool isbalance(node* root){

    return isbalanceFast(root).first;
    
}

//todo:............................(identical tree)........................................

bool isIdentical(node* r1 ,node* r2){

    //base case
    if(r1 == NULL  &&  r2 == NULL){     //when both tree are null -> identical
        return true;
    }

    if( r1 != NULL  &&  r2 == NULL){    //both are unidentical
        return false;
    }

    if( r1 == NULL  &&  r2 != NULL){
        return false;
    }


    bool left = isIdentical(r1-> left , r2 ->left);
    bool right = isIdentical(r1->right , r2->right);

    bool value = (r1->data == r2->data);    //dono node ka data check kro

    if(left && right && value){
        return true;
    }

    else{
        return false;
    }
}

//todo: ................problem 3 (VERTICAL ORDER TRAVERSAL)............................

vector<int> verticalOrderTraversal(node* root){

    //*     create mapping between ( horizontal distance <-> levelwise nodes ) 
    //*     another mapping for levelwise nodes ( level <-> nodes )
    //*     all nodes in a level are stored in a list/ vector 
    map<int, map<int, vector<int> > > nodes;

    //queue for traversal
    // node* for BFS traversal
    // int-int pair for horizontal distance and levels
    queue <pair <node* , pair<int , int > > > q;

    vector <int> ans;

    if (root == NULL)
        return ans;
    
    //for 1st line level and HD is 0;
    q.push( make_pair(root ,  make_pair ( 0 , 0 )));

    while (!q.empty())
    {
        //take out front element of queue
        pair <node* , pair<int , int > > temp = q.front();
        q.pop();

        //take out node from pair
        node* frontNode = temp.first;
        int HD = temp.second.first;     //horizontal distance
        int lvl = temp.second.second;

        //make entry for each nodes in lvel /  create table
        nodes[HD][lvl].push_back(frontNode->data);

        if(frontNode->left){
            //when we go left horizontal distance decrease and level increase (has child)
            q.push(make_pair(frontNode->left , make_pair(HD -1 ,lvl+1)));
        }


        if(frontNode->right){
            //when we go right horizontal distance increase and level increase (has child)
            q.push(make_pair(frontNode->right , make_pair(HD+1 , lvl+1)));
        }


    }

    //! THIS [AUTO] KEYWORD AUTOMATICALLY SORT AND GIVE ELEMENTS IN SORTED ORDER

    for(auto i : nodes){
        //i represent row  --> <int , map<int , vector<int> >
        //we are intrested in vector<int> as ans
        for(auto j : i.second){
            //j is a row -->  <int , vector<int> >
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
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

