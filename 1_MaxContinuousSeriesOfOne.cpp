vector<int> Solution::maxone(vector<int> &A, int B) {
    vector<int> zeroIndex;
    zeroIndex.push_back(-1);
    for(int i =0;i<A.size();i++){
        if(A[i] == 0){
            zeroIndex.push_back(i);
        }
    }
    
    
    zeroIndex.push_back(A.size());
    
    int max =0,start=0,end=A.size()-1;
    /*if(B>zeroIndex.size()-2){
        start = 0;
        end = A.size()-1;
    }*/
    for(int i =0;i+B+1<zeroIndex.size();i++){
        int x = zeroIndex[i+B+1]- zeroIndex[i]-1;
        if(x>max){
            start = zeroIndex[i]+1;
            end = zeroIndex[i+B+1]-1;
            max = x;
        }
    }
    vector<int> result;
    for(int i=start;i<=end;i++){
        result.push_back(i);
    }
    return result;
}
