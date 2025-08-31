class Solution {
    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> mpp = new HashMap<>();

        for(int i = 0; i < nums.length; i++) {
            int reqNum = target - nums[i];

            if(mpp.containsKey(reqNum)) {
                return new int []{mpp.get(reqNum), i};
            }
            mpp.put(nums[i], i);
        }
        return new int []{};
    }
}