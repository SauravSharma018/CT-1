//Name - Saurav Sharma 
//Roll No:-2010991717
//Set:-05



#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int Longest_Subarr(int arr[],int n,int k)
{
    // if any one passes empty array then the exception will be called and
    //it will print this-

    if(n<=0) throw string("array size less than or equal to 0");
 
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;
 
    
    for (int i = 0; i < n; i++) {
 
        // prefix sum
        sum += arr[i];
 
        
        if (sum == k)
            maxLen = i + 1;
 
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
 

        if (mp.find(sum - k) != mp.end()) {
 
            

            if (maxLen < (i - mp[sum - k]))
                maxLen = i - mp[sum - k];
        }
    }
 
  
    return maxLen;


   
}
int main(){


int n,k;cin>>n>>k;
    

    try{

        int arr[n];
        for(int i=0;i<n;i++){
        cin>>arr[i];
        }
        
         cout<< Longest_Subarr(arr, n, k);
    }

    catch (string &s){
        cout<<s;

    }

   
   

return 0;
}