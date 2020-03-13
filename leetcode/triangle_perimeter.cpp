class Solution {
public:
    
    bool check_triangle_property(int a, int b, int c)
    {
        if (((a + b) > c) && ((b + c) > a) && ((a + c) > b))
            return true;
        return false;
    }
    
     static int comp(const void* a, const void* b) 
    { 
         return *(int*)a > *(int*)b ; 
     } 
  
    
    int largestPerimeter(vector<int>& A) {
        int n = A.size();
       // qsort(&arr, n, sizeof( arr[0] ), comp); 
        multiset<int> sec1(A.begin(), A.end());
        int* arr = new int[n];
        int count = 0;
        for (set<int> :: iterator it = sec1.begin(); it != sec1.end(); it++) {
            arr[count++] = *it;
        }
   // int count = 0; 
    
    multiset<int> sec;
    int sum = 0;
    for (int i = 0; i < n-2; i++) 
    {          
        int k = i+2;   
        for (int j = i+1; j < n - 1; j++) 
        {            
            while (k < n && arr[i] + arr[j] > arr[k]){
                    
                if (((i != j && j != k && i != k) && (arr[i] + arr[j] + arr[k]) > sum)) {
                    if (sec.size() != 0)
                        sec.clear();
                    sec.insert(arr[i]);
                    sec.insert(arr[j]);
                    sec.insert(arr[k]);
                    
                    sum = arr[i] + arr[j] + arr[k];
                    cout << i << " " << j << " " << k << " " << sum << endl;
                } 
                ++k; 
            }
            if(k>j) {
                   
                count += k - j - 1; 
            }
        } 
    }  
    return sum; 
}
        
};
