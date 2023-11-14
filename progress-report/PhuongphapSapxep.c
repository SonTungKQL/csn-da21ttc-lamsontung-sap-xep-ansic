#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void heapify(int arr[], int size, int current);
void heapSort(int arr[], int size);
void quickSort(int array[], int low, int high);
void bubbleSort(int arr[], int n);
void printArray(int array[], int size);
void swap(int* a, int* b);

struct node  
{
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void heapify(int arr[], int size, int current)
{
    int largest = current;
    int left= 2*current+1;  
    int right= 2*current+2;
   
    if(left<size && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest=right;
    }
    if(current!=largest ){
        swap(&arr[current], &arr[largest]);
        heapify(arr, size, largest);
    }

}
void heapSort(int arr[], int size)
{
    for(int i= (size/2)-1;i>=0;i--)
    {
        heapify(arr, size, i);
    }
    for(int i=size-1;i>=0;i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0 );
    }

}
void quickSort(int array[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n; i++)
   {
       for (j = n-1; j > i; j--)
       {
           if(arr[j] < arr[j-1])
               swap(&arr[j], &arr[j-1]);
       }
   }
}
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void swap(int* a, int* b){
    int t= *a;
    *a=*b;
    *b=t;
}
int partition(int array[], int low, int high) 
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) 
    {
        if (array[j] <= pivot) 
        {  
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}
void printList()
{
   struct node *ptr = head;
   printf("\n[ ");
   while(ptr != NULL)
	{        
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}
void insertFirst(int key, int data)
{
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;

   link->data = data;
	
   link->next = head;
	
   head = link;
}
struct node* deleteFirst()
{

   struct node *tempLink = head;
	
   head = head->next;
	
   return tempLink;
}
bool isEmpty()
{
   return head == NULL;
}

int length()
{
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next)
	{
      length++;
   }
	
   return length;
}
struct node* find(int key){

   struct node* current = head;

   if(head == NULL)
   {
        return NULL;
   }
   while(current->key != key)
   {
      if(current->next == NULL)
      {
         return NULL;
      }else {
         current = current->next;
      }
   }      
   return current;
}
struct node* deleteKey(int key){

   //bat dau tu first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //neu list la trong
   if(head == NULL){
      return NULL;
   }

   //duyet qua list
   while(current->key != key){
	
      //neu day la last node
      if(current->next == NULL){
         return NULL;
      }else {
         //luu tham chieu toi link hien tai
         previous = current;
         //di chuyen toi next link
         current = current->next;             
      }
		
   }

   //cap nhat link
   if(current == head) {
      //thay doi first de tro toi next link
      head = head->next;
   }else {
      //bo qua link hien tai
      previous->next = current->next;
   }    
	
   return current;
}

// ham sap xep
void sort(){

   int i, j, k, tempKey, tempData ;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head ;
      next = head->next ;
		
      for ( j = 1 ; j < k ; j++ ) {   
		
         if ( current->data > next->data ) {
            tempData = current->data ;
            current->data = next->data;
            next->data = tempData ;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
			
         current = current->next;
         next = next->next;                        
      }
   }   
}

// ham dao nguoc list
void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;  
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}
int main()
{
    int arr[]= {12,6,10,5,1,9};
    int size= sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, size);
    printf("Mang chua sap xep: \n");
    
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printf("Mảng được sắp xếp theo thứ tự tăng dần: \n");
    printArray(arr, size);
    bubbleSort(arr, size - 1);

    printf("Mảng được sắp xếp là: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
