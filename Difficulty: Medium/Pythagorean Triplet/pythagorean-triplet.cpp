class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
       int n = arr.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(arr[i]);

  	// Iterate through all possible values of a and b
    for (int i = 0; i < n - 1; i++)  {
        for (int j = i + 1; j < n; j++) {
          	
          	int a = arr[i];
          	int b = arr[j];
          
            // calculate required value for 
          	// c to form Pythagorean triplet
            int c = sqrt(a * a + b * b);
            
            // First, verify if c^2 is a perfect square (indicating a 
			// valid c) and check if this c exists in the set.
            if (c*c == a*a + b*b && st.find(c) != st.end())
                return true;
        }
    }
  
  	// No Pythagorean triplet exists in the array
    return false;
    }
};


// class Solution {
//   public:
//     bool pythagoreanTriplet(vector<int>& arr) {
//         int n = arr.size();
        
//         for(int &x : arr) x = x*x;
        
//         sort(arr.begin(), arr.end());
        
//         for(int i = n-1; i >= 2; i--){
//             int l = 0, r = i-1;
            
//             while(l < r){
//                 if(arr[l] + arr[r] == arr[i])
//                     return true;
//                 else if(arr[l] + arr[r] < arr[i])
//                     l++;
//                 else
//                     r--;
//             }
//         }
//         return false;
//     }
// };