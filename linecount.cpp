#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main() {
int test;
cin >> test;
for(int i=0;i<test;i++){
    int N,M;
    cin >> N;
    vector<int> vec;
    
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    
    cin >> M;
    int sum =0;
    for(int i=0;i<N;i++){
        cout<< i+1 << " ";
        sum =  sum + vec[i];
        while(sum + vec[i+1]+ 1< M){
            i++;
        }
        cout << i+1 << " ";
            sum =0;
    }
    cout << endl;
}
}
