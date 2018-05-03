#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	int M,N;
	string x,y,z;
	vector<string> chefs[2] ;
	vector<string> votes;
	map<string, string> map1 ;
	map<string, int> mapcount;
	cin >> N >> M;
	
	for(int i = 0;i<N ;i++ ){
	    cin >> x >> y;
	    chefs[0].push_back(x);
	    chefs[1].push_back(y);
	    map1.insert(pair <string, string>(x,y));
	    mapcount.insert(pair<string,int>(y,0));
	}
	
	for(int i=0;i<M;i++){
	    cin >> z;
	    votes.push_back(z);
	    std::map<string, string>::iterator it1 = map1.find(z); 
	    std::map<string, int>::iterator it = mapcount.find(it1->second); 
        if (it != mapcount.end())
            it->second = it->second+1;
	}
	
	sort(votes.begin(),votes.end());
	string max = votes[0];
	int max_val= 1 , count =1;
	
	for(int i=0;i<M;i++){
	    if(votes[i] == votes[i+1]){
	        count++;
	    }
	    else{
	        if(count>max_val){
	            max_val =count;
	            max = votes[i];
	        }
	            count = 1;
	    }
	}
	std::map<string, int>::iterator it;
	it = mapcount.begin();
    string	max_country = chefs[1][0];
	int max_country_val = 0;
	count =0;
    while(it != mapcount.end()){
        //cout << it->first << " " << it->second<<endl;
        if(it->second > max_country_val){
            max_country = it->first;
            max_country_val = it->second ;
        }
        it= ++it;
    }
    cout << max_country << endl;
	cout <<max;
	return 0;
}
//l r r t t t 
