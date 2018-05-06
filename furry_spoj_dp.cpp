#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int memory[1001];

int  fillValues(int n){

if( memory[n] != 10000){
    return memory[n];
}

long double  x = sqrt(n);
int y = floor(x);
if( x == y ){
    return 1;
}
else{
    int z = 10000;
    for(int i=1;i<=n/2;i++){
        if(fillValues(i)+fillValues(n-i) < z){
            z = fillValues(i)+fillValues(n-i);
        }
    }
    memory[n] = z;
}
return memory[n];
}



int main(){
    for(int i=0; i<1001 ; i++){
        memory[i] = 10000;
    }
    memory[1] = 1;
    int test;
    cin >> test;
    int n;
    for(int i=0 ;i<test;i++){
        cin >> n;
        cout <<  fillValues(n) << endl;
    }
    return 0;
}
