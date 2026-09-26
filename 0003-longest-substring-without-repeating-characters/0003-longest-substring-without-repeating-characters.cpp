class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int len = s.length();
        int max_len_sub = 0;
        unordered_map<char, int> mem;
        while (i < len) {
            if (mem.find(s[i]) != mem.end()) {
                while (s[j] != s[i]) {
                    mem.erase(s[j]);
                    j++;
                }

                mem.erase(s[j]);
                j++;
            }
            mem[s[i]]++;
            i++;

            max_len_sub=max(max_len_sub,(int)mem.size());
        }
        return max_len_sub;
    }
};