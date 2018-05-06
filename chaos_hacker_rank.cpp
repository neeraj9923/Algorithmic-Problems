#include <bits/stdc++.h>

using namespace std;

void minimumBribes(vector <int> q) {
    // Complete this function
    int n = q.size();
    int count[n+1];
    for(int i =1;i<= n;i++){
        count[i] = 0;
    }
    for(int i=1; i<n ; i++){
        int j = i-1;
        int temp = q[i]; 
        while(j>=0  && q[j]>temp){
            count[q[j]] =  count[q[j]]+1;
            q[j+1] = q[j];
            j--;
        }
        q[j+1]  = temp;
    }
    int sum =0;
    for(int i =1;i<= q.size();i++){
       if(count[i] <= 2){
           sum = sum + count[i];
       }
        else{
            cout << "Too chaotic"<< endl;
            return;
        }
    }
    cout << sum<< endl;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0; q_i < n; q_i++){
           cin >> q[q_i];
        }
        minimumBribes(q);
    }
    return 0;
}
