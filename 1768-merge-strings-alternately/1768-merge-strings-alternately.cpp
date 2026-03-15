class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string finalMergeString = ""; 
        int left = 0, right = 0;

        while(left < word1.length() && right < word2.length()) {

            finalMergeString += word1[left++];
            finalMergeString += word2[right++];

            //finalMergeString = "ap" "bq" "cr" = "apbqcr"
        }
        while(left < word1.length()) {
            finalMergeString += word1[left++];
        }
        while(right < word2.length()) {
            finalMergeString += word2[right++];
        }
        return finalMergeString;
    }
};