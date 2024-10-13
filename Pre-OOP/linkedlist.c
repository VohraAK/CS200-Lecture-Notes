#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;


/**
 * @brief Creates a new node with given data.
 *
 * @param[in] data The data to be stored in the new node
 *
 * @details
 * The function allocates memory for a new node and initializes its data and next pointer fields.
 * It takes an integer data as argument and returns a pointer to the newly created node if the allocation is successful.
 * Otherwise, it returns NULL.
 */
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
        return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

/**
 * @brief Inserts a new node with given data after the target node in the linked list.
 *
 * @param[in] head The head of the linked list.
 * @param[in] target The data of the node after which the new node should be inserted.
 * @param[in] newData The data of the new node.
 *
 * @details
 * The function creates a new node with the given data and inserts it after the target node in the linked list.
 * The function takes a pointer to the head of the list, the target node, and the data of the new node as arguments.
 * The function returns nothing.
 */
void insertNode(Node *head, int target, int newData)
{
    // create new node
    Node *temp = createNode(newData);

    Node *ptr = head;

    // find target node
    while ((ptr->data != target) && (ptr != NULL))
        ptr = ptr->next;

    // make connection with the new node (pointed by ptr as its next in the list)
    temp->next = ptr->next;

    // connect previous node to new node (and break connection with previous node)
    ptr->next = temp;
}


/**
 * @brief Inserts a new node with the given data at the head of the linked list.
 *
 * @param[inout] head The head of the linked list.
 * @param[in] newData The data to be stored in the new node.
 *
 * @details
 * This function creates a new node with the given data and inserts it at the head of the linked list.
 * The function takes a pointer to the head of the list and the data of the new node as arguments.
 * The function returns nothing.
 */
void insertNodeAtHead(Node** head, int newData)
{
    // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = newData;

    // point new node to the node pointed by head
    newNode->next = *head;

    // point head to newNode
    *head = newNode;
}


int main()
{
    // Node* head = NULL;

    // Node* ptr = (Node*) malloc(sizeof(Node));

    // if (!ptr)
    // {
    //     printf("NULL PTR");
    //     return 1;
    // };

    // ptr -> data = -53;
    // ptr -> next = NULL;

    // head = ptr;

    // ptr = (Node*) malloc(sizeof(Node));

    // if (!ptr)
    // {
    //     printf("NULL PTR");
    //     return 1;
    // };

    // ptr -> data = 32;
    // ptr -> next = NULL;

    // // point head to ptr
    // head -> next = ptr;

    // printf("%d points to %d", head -> data, ptr -> data);

    // free(head);
    // free(ptr);


    // USING insertNode()

    // Node* head = createNode(1);

    // if (!head)
    // {
    //     printf("Allocation failed!");
    //     return 1;
    // }

    // Node* second = createNode(2);

    // if (!second)
    // {
    //     printf("Allocation failed!");
    //     return 1;
    // }

    // head -> next = second;

    // Node *third = createNode(3);

    // if (!third)
    // {
    //     printf("Allocation failed!");
    //     return 1;
    // }

    // second -> next = third;

    // third -> next = NULL;

    // // iterate over all nodes
    // Node* current = head;

    // printf("Before insertion...\n");

    // while (current != NULL)
    // {
    //     printf("%d -> ", current -> data);
    //     current = current -> next;
    // }

    // printf("NULL\n");

    // insertNodeAtHead(head, 69);
    // insertNodeAtHead(head, 70);
    // insertNodeAtHead(head, 71);

    // current = head;

    // printf("\nAfter insertion...\n");

    // while (current != NULL)
    // {
    //     printf("%d -> ", current -> data);
    //     current = current -> next;
    // }

    // printf("NULL\n");

    // free(head); free(second); free(third);


    // USING insertAtHead()
    Node* head = NULL;

    insertAtHead(&head, 100);
    insertAtHead(&head, 200);
    insertAtHead(&head, 300);
    insertAtHead(&head, 400);

    Node* current = head;

    printf("\0");

    while (current != NULL)
    {
        printf("%d -> ", current -> data);
        current = current -> next;
    }

    printf("NULL\n");

    return 0;
}