/*Look at task 1 tree and write a function to check if a given array represents
a Binary Heap? Also that sort the array in ascending order.*/
//Binary Heap (Max Heap)
// ascending order (using Heap Sort)


//code 
//binary heap 

bool is_max_heap(int arr[],int n){
for(int i=1;i<=n/2;i++){
int l=2*i;
int r=2*i+1;
if(l<=n && arr[i] < arr[l]) return false;
  if(r<=n && arr[i] < arr[r]) return false;}
  
return true;}

//sort
void heapify_down(int arr[],int n,int i){
int largest=i;
int l=2*i;
int r=2*i+1;
  
if(l<=n && arr[l] > arr[largest]) largest=l;
 if(r<=n && arr[r] > arr[largest]) largest=r;
 if(largest!=i){
int t=arr[i]; arr[i]=arr[largest]; arr[largest]=t;
heapify_down(arr,n,largest);}}

void heap_sort(int arr[],int n){
for(int i=n/2;i>=1;i--)
heapify_down(arr,n,i);
  for(int i=n;i>=2;i--){
    int t=arr[1]; arr[1]=arr[i]; arr[i]=t;
heapify_down(arr,i-1,1);}}
