class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> characters_s;
        map<char, int> characters_t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        bool same = false;

        if (s.length() != t.length()){
            return false;
        }

        // putting the letters into the map for each string s and t 
        for (int i = 0; i < s.length(); i++){
            characters_s[s[i]]+=1;
            characters_t[t[i]]+=1;
        }
        
        return characters_s == characters_t;
    }
};
