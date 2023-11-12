void heapify(int arr[], int size, int current);
void heapSort(int arr[], int size);
void quickSort(int array[], int low, int high);
void bubbleSort(int arr[], int n);
void printArray(int array[], int size);
void swap(int* a, int* b);
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
  

    printf("Mảng được sắp xếp là: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
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
