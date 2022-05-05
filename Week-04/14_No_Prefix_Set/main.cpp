#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

 // Trie Data Structure (Prefix Tree)
struct trieNode {
    unordered_map<char, trieNode*> character;
    bool terminal;

    trieNode() {
        terminal = false;
    }
};

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(trieNode* root, string key) {
    struct trieNode* current = root;

    for (int i = 0; i < key.length(); i++) {
        // create a new node if the path doesn't exist
        if (current->character.find(key[i]) == current->character.end())
            current->character[key[i]] = new trieNode();

        current = current->character[key[i]];
    }
    // mark last node as leaf
    current->terminal = true;
}

// Returns true if key presents in trie, else
// false
string search(trieNode* root, string key) {
    trieNode* current = root;
    string result;

    if (current->character[key[0]]) {
        for (int i = 0; i < key.length(); i++) {

                // get an iterator to the only child
                auto it = current->character.begin();
                result += it->first;
                if (i + 1 == key.length()) {
                    current = it->second;
                    while(!current->terminal) {
                        auto it = current->character.begin();
                        result += it->first;
                        current = it->second;
                    }
                    if(result.compare(0, key.length(), key) == 0)
                    return result;
                    else
                        return "0";
                }
                // update current pointer to the child node
                current = it->second;

        }
    }
    return "0";
}


void noPrefix(vector<string> words) {
    struct trieNode* root = new trieNode;
    string word;

    for (int i = 0; i < words.size(); i++)
        insert(root, words[i]);

    for (int i = 0; i < words.size(); i++) {
        word = search(root, words[i]);
        if (word.compare("0") != 0) {
            cout << "BAD SET\n" << word << endl;
            return;
        }
    }
    cout << "GOOD SET\n" << word << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
