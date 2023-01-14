// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// returns output in random order
// 1 <= nums.length <= 6
 
//  Using Recursion 
 void search(vector<int>& nums,vector<bool>& chosen,vector<vector<int>>&ans,vector<int>&permutation{
        if(permutation.size()==nums.size()){
            ans.push_back(permutation);
        }
        else{
            for(int i=0;i<nums.size();i++){

                if(chosen[i]){
                    continue;
                }
                chosen[i]=true;
                permutation.push_back(nums[i]);
                search(nums,chosen,ans,permutation);
                chosen[i]=false;
                permutation.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>permutation;
        vector<bool>chosen(n,false);
        search(nums,chosen,ans,permutation);
        return ans;
        
    }



// using inbuilt STL function
vector<vector<int>> permute(int n){
    
    vector<vector<int>>P;
    vector<int> permutation;
    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }
    do {
        // Process permutation
        P.push_back(permutation);
    } while (next_permutation(permutation.begin(),permutation.end()));
   
    return P;
}