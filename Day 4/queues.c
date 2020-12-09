#include<stdio.h>

#define MAX 5
int queue_array[MAX];
int rear = - 1;
int front = - 1;

void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else if(front==rear)
    {
    printf("Element deleted from queue is : %d\n", queue_array[front]);
    front=rear=-1;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

void qdisplay()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}

void qisempty()
{
    if(front>rear || (front==-1&&rear==-1))
    printf("\nQueue is empty");
    else
    printf("\nQueue is not empty");
}

void qisfull()
{
    if(rear==MAX-1)
    printf("\nQueue is full");
    else
    printf("\nQueue is not full");
}

// Check if the circular queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == MAX - 1)) return 1;
  return 0;
}

// Check if the circular queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue() {
    int element;
    printf("\nEnter the element to be inserted:");
    scanf("%d",&element);
  if (isFull())
    printf("\n Queue is full!! \n");
  else
    {
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue_array[rear] = element;
    printf("\n Inserted -> %d", element);
    }
}

// Removing an element
void deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = queue_array[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % MAX;
    }
    printf("\n Deleted element -> %d \n", element);
  }
}

// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % MAX) {
      printf("%d ", queue_array[i]);
    }
    printf("%d ", queue_array[i]);
  }
}

void main()
{
    int choice,x,qchoice;
    printf("\n\nEnter the type of queue to be used:\n1. Normal Queue\n2. Circular queue\nYour choice:");
    scanf("%d",&qchoice);
    if(qchoice==1)
    {
        while (1)
        {
            printf("\n1. Insert \n");
            printf("2. Delete\n");
            printf("3. Display\n");
            printf("4. Isempty()\n");
            printf("5. Isfull()\n");
            printf("6.Quit \n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                insert();
                break;
                case 2:
                delete();
                break;
                case 3:
                qdisplay();
                break;
                case 4:
                qisempty();
                break;
                case 5:
                qisfull();
                break;
                case 6:
                exit(0);
                break;
                default:
                printf("Wrong choice \n");
            } 
        }
    }
    else if(qchoice==2)
    {
    while (1)
        {
            printf("\n1. Insert \n");
            printf("2. Delete\n");
            printf("3. Display\n");
            printf("4. Isempty()\n");
            printf("5. Isfull()\n");
            printf("6. Quit \n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                enQueue();
                break;
                case 2:
                deQueue();
                break;
                case 3:
                display();
                break;
                case 4:
                x=isEmpty();
                if(x==1) printf("\nQueue is empty\n");
                else printf("\nQueue is not empty\n");
                break;
                case 5:
                x=isFull();
                if(x==1) printf("\nQueue is full\n");
                else printf("\nQueue is not full\n");
                break;
                case 6:
                exit(0);
                break;
                default:
                printf("Wrong choice \n");
            } 
        }
    }
}