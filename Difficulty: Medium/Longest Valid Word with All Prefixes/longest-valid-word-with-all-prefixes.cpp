class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool checkIfAllPrefixesExist(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            curr = curr->children[index];

            if (curr->isEnd == false) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:    
    string longestValidWord(vector<string>& words) {
        Trie trie; 

        for(auto &it : words){
            trie.insert(it);
        }

        string longest = "";

        for(auto &word : words){
            if(trie.checkIfAllPrefixesExist(word)){

                if(word.length() > longest.length()){
                    longest = word;
                }
               
                else if(word.length() == longest.length() && word < longest){
                    longest = word;
                }
            }
        }

        return longest;
    }
};