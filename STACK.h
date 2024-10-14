#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }

    // destructor
    ~node()
    {

        int temp = this->data;

        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "memory freed for data  : " << temp << endl;
    }
};

// STACK IMPLEMENTATION
class stack
{
public:
    node *top;

    stack() { top = NULL; }

    void push(int element)
    {
        node *temp = new node(element);
        if (!temp)
            cout << "overflow !!" << endl;
        else
        {
            temp->next = top;
            top = temp;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "underflow !!!" << endl;
            return;
        }

        else
        {
            node *temp = top;
            top = top->next;
            cout << "popped item is : " << temp->data << endl;
            free(temp);
        }
    }


    int popOut()
    {
        if (top == NULL)
        {
            return -1;
        }

        else
        {
            node *temp = top;
            top = top->next;
            int data = temp->data;
            free(temp);
            return data;
        }
    }


    void peek()
    {
        if (top == NULL)
        {
            cout << "EMPTY STACK..." << endl;
        }
        else
        {
            cout << "top -> " << top->data << endl;
        }
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty (underflow)!" << endl;
            return;
        }

        node *temp = top;
        vector<string> elements;

        // Collect elements in the order they will be displayed
        while (temp != NULL)
        {
            elements.push_back(to_string(temp->data));
            temp = temp->next;
        }

        std::reverse(elements.begin(), elements.end());
        int width = 0;
        for (const auto &element : elements)
        {
            width = max(width, static_cast<int>(element.length()));
        }
        width += 4; // Padding for borders

        cout << "+";
        for (int i = 0; i < width; ++i)
            cout << "-";
        cout << "+" << endl;

        // Print elements in reverse order (last inserted first)
        for (int i = elements.size() - 1; i >= 0; --i)
        {
            cout << "|  " << setw(width - 4) << elements[i] << "  |" << endl;
            // Print underscore line below each element
            cout << "|" << string(width, '_') << "|" << endl;
        }

        cout << "+";
        for (int i = 0; i < width; ++i)
            cout << "-";
        cout << "+" << endl;

        cout << endl;
    }
};

