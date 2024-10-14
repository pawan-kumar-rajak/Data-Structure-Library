
# Data Structures Library/Visualization

## Overview
A collection of header files implementing various data structures (e.g., linked lists, stacks, queues, trees, graphs) with corresponding visualizations to assist developers and students in understanding and using these structures effectively.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Linked List](#linked-list)
    - [Singly linked list](#singly-linked-list)
    - [Doubly linked list](#doubly-linked-list)
    - [Circular linked list](#circular-linked-list)

  - [Stack](#stack)
  - [Queue](#queue)
  - [Binary Tree](#binary-tree)
    - [Tree Creation and Traversal](#tree-creation-and-traversal)
    - [Tree with more functions](#tree-more-functions)
  - [Graph (coming soon...)](#graph)
  - [Hash Table (coming soon...)](#hash-table)
<!-- - [Examples](#examples) -->
- [Contributing](#contributing)
- [License](#license)

## Features
- Implementations of various data structures with easy-to-use functions.
- **Visual representations** for certain structures.
- ***Example usage*** for each structure.

## Installation
1. open terminal in your Project directory
2. Clone the repository:
   ```bash
   git clone https://github.com/pawan-kumar-rajak/Data-Structure-Library.git
   ```
3. Open Data-Structure-Library 
4. copy the header files you needed and paste it in your code directory
5. Include the header files in your Code:
   ```cpp
   #include "LinkedList.h"
   #include "STACK.h"
   #include "QUEUE.h"
   #include "BTree.h"
   #include "Graph.h"
   #include "HashTable.h"
   ```

## Usage

### Linked List

#### Singly Linked List

- **Functions:**
  - `void insertAtHead(node * &head , int data);`

  - `void insertAtTail(node * &tail , int data);`

  - `void insertAtPosition (node* &tail ,   node* &head , int position , int data);`

  - `void insertAtValue(node*  &head ,node* &tail ,int value , int data);`

  - `void print(node* &head);`

  - `int getLength(node * &head);`

  - `void reverseByLoop(node* &head);`

  - `void reverseByRec1(node* &head , node* curr , node* prev);`

  - `node* reverseByRec2 ( node* &head);`

- **Example:**
  ```cpp
  node* n1 = new node(3);

	node* head = n1;
	node* tail = n1;

	n1->print(head);
	n1->insertAtHead(head, 13);
	
	n1->insertAtTail(tail , 20);
	n1->print(head);

	n1->insertAtPosition(tail ,head ,2 , 99);
	n1->print(head);
	
  ```

- ***Visualization***
<br><br>
![LinkedList](/Visualization/LinkedList.png)
---
#### Doubly Linked List

- **Functions:**
  
  - `void insertAtHead (DNode* &head , int data);`

  - `void insertAtTail (DNode* &tail , int data);`

  - `void insertAtPosition (DNode* &head , DNode* &tailint position  , int data);`

  - `void deletion (DNode* &head , DNode* &tail, int position);`

  - `void insertAtValue (DNode* &head , DNode* &tail , int value , int data);`

  - `void print(DNode* head ,DNode* &tail);`
  
- **Example:**
  ```cpp
  DNode* n2 = new DNode(5);
	DNode* DHead = n2;
	DNode* DTail = n2;

	n2->insertAtHead(DHead,101);
	n2->print(DHead,DTail);

	n2->insertAtHead(DHead,102);
	n2->print(DHead,DTail);
  ```

---
#### Circular Linked List

- **Functions:**
  - `void insertAtPosition (CNode* & tail , int position, int data);`

  - `void insertCNode(CNode* &tail, int element, int d);`

  - `void deleteCNode(CNode* &tail, int value) ;`

  - `void print(CNode* tail);`

- **Example:**
  ```cpp
  CNode* n2 = new CNode(5);

  //all functions will be done at tail beacuse the list is circular (tail ~ head) 

	CNode* CTail = n2;

	n2->insertAtPosition(CTail,0,101);
	n2->print(CTail);

  //insert after the specified node(here:101)
	n2->insertCNode(DHead,101,65);
	n2->print(CTail);
  ```
---
---
### Stack
- **Functions:**
  - ` void push (int element )`

  - `void pop();`

  - `int popOut();`

  - `void peek();`

  - `void display();`

- **Example:**
  ```cpp
  stack s;
	s.push(8);
	s.push(10);
	s.push(5);
	s.display();

	s.pop();
	s.display();

	cout<<"popping a value : "<<s.popOut()<<endl;
	s.peek();
  s.display();
  ```

- ***Visualization***
<br><br>
![Stack](/Visualization/STACK.png)
---
---
### Queue
- **Functions:**
  - `bool isEmpty()`
  - `void enqueue(int data)`
  - `int dequeue()`
  - `int Front()`
  - `oid display()`

- **Example:**
  ```cpp

    //give size while initialization or Default size=10

    int size = 10;
    Queue q(size);   //or Queue q;
    q.display();
    q.enqueue(1);
    q.enqueue(8);
    q.display();
   
    cout<<"front  " <<q.Front()<<endl;;
  ```
- ***Visualization***
<br><br>
![Queue](/Visualization/Queue.png)
<hr/>
<hr/>
<br>

### Binary Tree

```cpp
 #include "BTree.h"
 ```

#### Tree Creation and Traversal
 **Functions:**
  - `node* buildTree(node* root)`
  

  *visualizeTree is suitable for tree upto level 4*
  - `void VisualizeTree(node* root)`

  - `void levelOrderTraversal(node* root)`

  - `void inorder(node* root)`

  - `void preorder(node* root)`

  - `void postorder(node* root)`

  - `void buildFromLevelOrder(node* &root)`

  - `int calculateHeight(node* root)`
  

- **Example:**
  ```cpp
    node* root;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    //JUST COPY AND in output window Right Click to test
    // 1 2 3 4 5 6 7 -1 -1 8 -1 -1 9 -1 10 -1 -1 -1 -1 -1 -1
    /*
                           1
                        /    \
                      2       3
                    /   \    /  \
                  4      5  6    7
                        /    \    \
                      8       9     10
    */
  ```
- ***Visualization***
<br><br>
![BTree](/Visualization/Btree.png)
---
#### Tree More Functions
```cpp
 #include "BTreeUtils.h"
 ```
- **Functions:**   *BTree (Above) +*
  - `int diameter(node* root)`

  - `bool isbalance(node* root)`

  - `bool isIdentical(node* r1 ,node* r2)`

  - `vector<int> verticalOrderTraversal(node* root)`

- **Example:**
  ```cpp
     node* root;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 7 9 2 6 -1 -1 -1 -1 5 -1 -1 -1 (copy and paste in output window for test tree creation)

   // 1. Height
    cout<<endl<<"height of tree is : "<<height(root)<<endl;

    // 2. Diameter
    cout<<endl<<"diameter is : "<<diameter(root)<<endl;

    // 3. check if tree is balance
    if(isbalance(root)){
        cout<<endl<<"tree is balanced $$"<<endl;
    } 

    else{
        cout<<endl<<"tree is not balanced !!"<<endl;
    }

  ```

---
---

### Graph
- **Functions:**
  - `void addEdge(int u, int v);`
  - `void bfs(int startVertex);`
- **Example:**
  ```cpp
  Graph graph;
  graph.addEdge(1, 2);
  graph.bfs(1);
  ```
---
---

### Hash Table
- **Functions:**
  - `void insert(int key, int value);`
  - `int search(int key);`
- **Example:**
  ```cpp
  HashTable ht;
  ht.insert(1, 100);
  int value = ht.search(1);
  ```


## Contributing
Contributions are welcome! Please open an issue or submit a pull request.

## License
ISC License

Copyright (c) 2024, Pawan

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
PERFORMANCE OF THIS SOFTWARE.

