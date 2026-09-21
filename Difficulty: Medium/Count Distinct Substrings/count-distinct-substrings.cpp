struct Trienode {
    Trienode* child[26];

    // 1. Fixed: Initialize all pointers to nullptr
    Trienode() {
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }

    bool contains(char c){
        return child[c - 'a'] != nullptr;
    }

    void put(char c, Trienode* node){
        child[c - 'a'] = node;
    }

    Trienode* get(char c){
        return child[c - 'a'];
    }
};

class Solution {
public:
    int countSubs(string& s) {
        int cnt = 0;
        Trienode* root = new Trienode();

        for(int i = 0; i < s.size(); i++){
            Trienode* node = root;

            // 3. Fixed: j starts from i to form the substring s[i...j]
            for(int j = i; j < s.size(); j++){

                // 4. Fixed: We process s[j], not s[i]
                if(!node->contains(s[j])){
                    cnt++;
                    // 2. Fixed: put returns void. Just call it.
                    node->put(s[j], new Trienode());
                }

                // Move the pointer to the newly created (or already existing) node
                node = node->get(s[j]);    
            }
        }

        // cnt represents all distinct non-empty substrings. 
        // +1 accounts for the empty string "".
        return cnt ;    
    }
};