struct Node
{
    Node *links[26];
    vector<string> arr;

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
            if(node->arr.size() < 3)
                node->arr.push_back(word);
        }
        
    }

    vector<string> search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return {};
            }
            node = node->get(word[i]);
        }
        return node->arr;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        sort(products.begin(),products.end());
        for(auto it: products) trie.insert(it);
        string temp = "";
        vector<vector<string>> result;
        for(int i=0;i<searchWord.size();i++){
            temp += searchWord[i];
            result.push_back(trie.search(temp));
        }
        return result;
    }
};