// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> ans;
        int n=nums.size();
        deque <int> q; //only indexes are stored
        for(int i=0;i<n;i++)
        {   
            while(!q.empty() && i-q.front()>=k)
                q.pop_front(); //only window size of k is allowed
            while(!q.empty() && nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);
            if(i>=k-1)ans.push_back(nums[q.front()]); //our max value in O(1)
        }
        return ans;
    }


// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [-1,-3,-3,-3,3,3]

vector<int> minSlidingWindow(vector<int>& nums, int k) {
        vector <int> ans;
        int n=nums.size();
        deque <int> q; //only indexes are stored
        for(int i=0;i<n;i++)
        {   
            while(!q.empty() && i-q.front()>=k)
                q.pop_front(); //only window size of k is allowed
            while(!q.empty() && nums[q.back()]>nums[i])
                q.pop_back();
            q.push_back(i);
            if(i>=k-1)ans.push_back(nums[q.front()]); //our min value in O(1)
        }
        return ans;
    }