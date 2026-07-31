class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> anagram = new ArrayList<List<String>>();
        HashMap<String,List<String>> store = new HashMap<String,List<String>> ();
        for(int i=0;i<strs.length;i++){
            int [] count = new int[26];
            for(char c : strs[i].toCharArray()){
                count[c-'a']++;
            }
            String key = Arrays.toString(count);
            store.putIfAbsent(key,new ArrayList<>());
            store.get(key).add(strs[i]);
        }
        return new ArrayList<>(store.values());
    }
}
