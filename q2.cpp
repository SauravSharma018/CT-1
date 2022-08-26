//Name:-Saurav Sharma
//Roll No:-2010991717
//Set:-05
// C++ program to print all subarrays
// in the array which has sum 0


#include <bits/stdc++.h>
#define ll long long 
using namespace std;


vector< pair<int, int> > findSubArrays(int arr[], int n){

    // if any one passes empty array then the exception will be called and
    //it will print this-

     if(n<=0) throw string("array size less than or equal to 0");
	
	unordered_map<int, vector<int> > map;

	
	vector <pair<int, int>> tp;

	// sum of elements so far
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		
		sum += arr[i];

		// if sum is 0, we found a subarray starting
		// from index 0 and ending at index i

		if (sum == 0)
			tp.push_back(make_pair(0, i));

		// If sum already exists in the map there exists
		// at-least one subarray ending at index i with
		// 0 sum

		if (map.find(sum) != map.end())
		{
			// map[sum] stores starting index of all subarrays
			vector<int> vc = map[sum];
			for (auto it = vc.begin(); it != vc.end(); it++)
				tp.push_back(make_pair(*it + 1, i));
		}

		
		map[sum].push_back(i);
	}

	
	return tp;
}

// function to print all subarrays with sum 0

void print(vector<pair<int, int>> tp)
{
	for (auto it = tp.begin(); it != tp.end(); it++)
		cout << "Subarray from Index " <<
			it->first << " to " << it->second << endl;
}


int main(){

    int n;cin>>n;


      try{

		 int arr[n];

    	for(int i=0;i<n;i++){
        cin>>arr[i];
    	}

        vector<pair<int, int> > out = findSubArrays(arr, n);

	// if we didn’t find any subarray with 0 sum,
	// then subarray doesn’t exists

	if (out.size() == 0)
		cout << "No subarray exists";
	else
		print(out);
         
    }

    catch (string &s){
        cout<<s;

    }

	

	return 0;
}
