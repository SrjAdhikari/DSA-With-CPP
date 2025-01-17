#include <iostream>
using namespace std;

// Definition of the Node class for the Doubly Linked List
class Node
{
public:
    int data;   // Variable to store the data of the node
    Node *prev; // Pointer to the previous node in the list
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize the node with data and set the prev and next pointers to NULL
    Node(int data)
    {
        this->data = data; // Set the data for the node
        this->prev = NULL; // Initialize the prev pointer to NULL
        this->next = NULL; // Initialize the next pointer to NULL
    }
};

// Function to insert multiple nodes at the tail of the Doubly Linked List
void insertAtTail(Node *&head, Node *&tail, int arr[], int size)
{
    // Iterate through the array elements
    for (int i = 0; i < size; i++)
    {
        // If the linked list is empty (head is NULL), create the first node
        if (head == NULL)
        {
            head = new Node(arr[i]); // Create a new node with the current array element and set it as the head
            tail = head;             // Since this is the only node, head and tail both point to this node
        }
        // If the linked list is not empty, create a new node and insert it at the end of the list
        else
        {
            Node *temp = new Node(arr[i]); // Create a new node with the current array element
            tail->next = temp;             // Link the current tail node's next pointer to the new node
            temp->prev = tail;             // Link the new node's prev pointer to the current tail node
            tail = temp;                   // Update the tail to point to the new node
        }
    }
}

// Function to print all elements of the Doubly Linked List starting from the head node
void printDLL(Node *head)
{
    Node *temp = head; // Temporary pointer to traverse the linked list

    // Traverse the list until the end is reached (i.e., temp becomes NULL)
    while (temp)
    {
        cout << temp->data << " -> "; // Print the data of the current node
        temp = temp->next;            // Move to the next node in the list
    }
    cout << endl; // Print a newline character at the end of the list
}

int main()
{
    Node *head = NULL;                      // Initialize the head of the Doubly Linked List as NULL
    Node *tail = NULL;                      // Initialize the tail of the Doubly Linked List as NULL
    int array[] = {1, 2, 3, 4, 5};          // Array containing the elements to be inserted into the list
    int size = sizeof(array) / sizeof(int); // Calculate the size of the array

    // Call the function to insert elements at the tail of the list
    insertAtTail(head, tail, array, size);

    cout << "Printing Doubly Linked List: " << endl;
    printDLL(head); // Call the function to print the Doubly Linked List

    return 0;
}