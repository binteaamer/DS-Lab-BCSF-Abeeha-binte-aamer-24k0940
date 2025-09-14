/*5. Implement the Interpolation Search algorithm. The program should take a sorted array
with uniformly distributed values and a target value from the user. The algorithm should
estimate the position of the target and check if the estimated position holds the correct
value. If the element is found, print its index; otherwise, indicate that it's not present.*/

//code
#include<iostream>
using namespace std;

int main(){
int n;
  cout<<"Enter number of elements: "<<endl;
  cin>>n;
  int arr[100];
    cout<<"enter "<<n<<" sorted integers (uniformly distributed): "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int target;
    cout<<"Enter value to search: "<<endl;
    cin>>target;

    int low=0, high=n-1;
    int foundIndex = -1;
    while(low<=high && target>=arr[low] && target<=arr[high]){
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if(arr[pos]==target){
            foundIndex = pos;
      break; }
      else if(arr[pos] < target)
            low = pos + 1;
        else high = pos - 1; }
  
    if(foundIndex != -1)
        cout<<"element found at index: "<<foundIndex<<endl;
    else
        cout<<"element not found in the array."<<endl;
    return 0;
}
