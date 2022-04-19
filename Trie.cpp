#include "Trie.h"

TrieNode* getNewNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    pNode->freq = 1;
    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;
    return pNode;
}

void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';

        if (!node->children[index])
            node->children[index] = getNewNode();
        else
            (node->children[index]->freq)++;
        node = node->children[index];
    }
    
    node->isEndOfWord = true;
}

bool search(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr );
}

void autocomplete(TrieNode* root, string& word, string& res)
{
    if (!search(root, word))
    {
        cout << "Words aren't available\n";
        return;
    }

    struct TrieNode* node = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (!node->children[index])
            break;
        node = node->children[index];
    }
    
    string buf;
    res.resize(50);
    findWord(node, word, buf, res);
 }

void findWord(TrieNode* root, string& word, string& buf, string& res)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != nullptr) 
        {
            if (root->children[i]->isEndOfWord == true)
            {
                buf.push_back(static_cast<char>(i + 'a'));
                res += word;
                res += buf;
                res += " ";
                buf.pop_back();
            }
            else
            {
                buf.push_back(static_cast<char>(i + 'a'));
                findWord(root->children[i], word, buf, res);
                buf.pop_back();
            }
        }
    }
}

void variant(string& res, int var)
{
    for (int i = 0; i < res.length(); i++)
    {
        if (res[i] == ' ')
        {
            --var;
            cout << '\n';
        }
        else if (var == 0)
            break;
        else
            cout << res[i];
    }
    cout << endl;
}