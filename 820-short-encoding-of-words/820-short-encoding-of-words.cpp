struct Node
{
    Node *links[26];
   

    bool containsKey(char ch)
    {
        if (links[ch - 'a'] == NULL)
            return false;
        return true;
    }
    
    void put(char ch, Node *&node)
    {
        links[ch - 'a'] = node;
    }
    
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                Node *newNode = new Node();
                node->put(word[i], newNode);
            }
            node = node->get(word[i]);
        }
        
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
        
    }

};

class Solution {
public:
    bool static cmp(string& a, string& b){
        return a.size() > b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        Trie trie;
        int result = 0;
        for(auto it: words){
            reverse(it.begin(),it.end());
            if(trie.search(it)) continue;
            trie.insert(it);
            result += it.size() + 1;
        }
        return result;
    }
};