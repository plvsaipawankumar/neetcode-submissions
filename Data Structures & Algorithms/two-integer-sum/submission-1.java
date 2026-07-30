class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> store = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(store.getOrDefault((target-nums[i]),-1)!=-1){
                return new int[]{store.get(target-nums[i]),i};
            }
            store.put(nums[i], i);
        }
        return new int[]{};
    }
}
