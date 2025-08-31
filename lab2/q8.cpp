/*
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day.
*/


//code
#include<iostream>
using namespace std;

int main(){
    int n, m ;
    cout<<"enter number of days"<<endl;
    cin>>n;
    cout<<"enter number of readings in a day"<<endl;
    cin>>m;

float **temperature=new float*[n];
for(int i=0; i<n;i++){
    temperature[i] =new float [m];

}

for(int i=0;i<n;i++){
    cout<<"enter temperature for day"<<i+1<<endl;
    for(int j=0;j<m;j++){
    cin>> temperature[i][j];}
}

float *avg =new float[n];
for(int i=0;i<n;i++){
    float sum=0;
    for(int j=0;j<m;j++){
        sum+=temperature[i][j];

    }
    avg[i]=sum/m;

}
cout<<"daily average tempretures"<<endl;
for(int i=0;i<n;i++){
    cout<<"day "<<i+1<<": "<<avg[i]<<endl;

}
  int hot = 0, cold = 0;
   for (int i = 1; i < n; i++) {
        if (avg[i] > avg[hot]) hot = i;
        if (avg[i] < avg[cold]) cold = i;
    }
    cout << "Hottest Day, Day " << hot + 1 << " with avg temp " << avg[hot] << endl;
    cout << "Coldest Day, Day " << cold + 1 << " with avg temp " << avg[cold] << endl;
for (int i = 0; i < n; i++) {
        delete[] temperature[i];
    }
    delete[] temperature;
    delete[] avg;

    return 0;
}
