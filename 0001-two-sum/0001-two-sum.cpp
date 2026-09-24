class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> jetha;

        for(int i=0; i<nums.size(); i++){
            int j=target-nums[i];
            auto it=jetha.find(j);
            if(it!=jetha.end()){
                ans.push_back(i);
                ans.push_back(jetha[j]);
                break;

            }
            jetha[nums[i]]=i;
        }
        return ans;
        
    }
};