// input: [1,2,3]
// output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// total subsets=2^n
// generate all possible subsets of given array



// for vector of nums
vector<vector<int>> findSubsets(vector<int>&nums){
    int n=nums.size();
    vector<vector<int>>ans;
    for(int num=0;num < (1<<n);num++){
        vector<int>subset;
        for(int i=0;i<n;i++){
            if(num & (1<<i)){
                subset.push_back(nums[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}

// for generating all subsets of range 0-n-1
vector<vector<int>> findSubsets(int n){

    vector<vector<int>>ans;
    for(int num=0;num < (1<<n);num++){
        vector<int>subset;
        for(int i=0;i<n;i++){
            if(num & (1<<i)){
                subset.push_back(i);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}