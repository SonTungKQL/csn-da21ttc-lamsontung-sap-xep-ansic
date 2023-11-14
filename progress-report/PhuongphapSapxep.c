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
void insertFirst(int key, int data);
void printList();
void sort();
void reverse(struct node** head_ref);

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

   struct node* current = head;
   struct node* previous = NULL;

   if(head == NULL){
      return NULL;
   }
   while(current->key != key)
   {
      if(current->next == NULL)
      {
         return NULL;
      }else {
         previous = current;

         current = current->next;             
      }
		
   }
   if(current == head)
   {
      head = head->next;
   }else{

      previous->next = current->next;
   }    
	
   return current;
}
void sort()
{
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
void reverse(struct node** head_ref) 
{
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

    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56);

    heapSort(arr, size);
    printf("Mang chua sap xep: \n");
    
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printf("Mảng được sắp xếp theo thứ tự tăng dần: \n");
    printArray(arr, size);
    bubbleSort(arr, size - 1);

    printf("Danh sach ban dau: "); 
    printList();

    printf("Mảng được sắp xếp là: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("Danh sach ban dau: "); 
    printList();

    while(!isEmpty()){            
      struct node *temp = deleteFirst();
      printf("\nGia tri bi xoa:");  
      printf("(%d,%d) ",temp->key,temp->data);        
    }  
	
    printf("\nDanh sach sau khi da xoa gia tri: ");          
    printList();
    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56); 
    printf("\nPhuc hoi danh sach: ");  
    printList();
    printf("\n");  

    struct node *foundLink = find(4);
        
    if(foundLink != NULL)
    {
        printf("Tim thay phan tu: ");  
        printf("(%d,%d) ",foundLink->key,foundLink->data);  
        printf("\n");  
    }else {
        printf("Khong tim thay phan tu.");  
    }

    deleteKey(4);
    printf("Danh sach, sau khi xoa mot phan tu: ");  
    printList();
    printf("\n");
    foundLink = find(4);
        
    if(foundLink != NULL)
    {
        printf("Tim thay phan tu: ");  
        printf("(%d,%d) ",foundLink->key,foundLink->data);  
        printf("\n");  
    }else {
        printf("Khong tim thay phan tu.");  
    }
        
    printf("\n");  
    sort();
        
    printf("Danh sach sau khi duoc sap xep: ");  
    printList();
        
    reverse(&head);
    printf("\nDanh sach sau khi bi dao nguoc: ");  
    printList();
}
