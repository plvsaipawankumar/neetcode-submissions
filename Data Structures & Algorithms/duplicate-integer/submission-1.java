class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashMap<Integer,Integer> cache = new HashMap<>();
        int i,n=nums.length;
        for(i=0;i<n;i++){
            if(cache.getOrDefault(nums[i], 0)>0)
                return true;
            cache.put(nums[i], cache.getOrDefault(nums[i], 0)+1);
        }
        return false;
    }
}