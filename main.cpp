#include "Trie.h"

int main()
{
	string keys[] = { "apple", "approach", "application", "animal", "answer", "animation", "ant",
                    "ball", "book", "boot", "body", "bottom", "bottle", "boy",
                    "cool", "core", "corner", "correct", "correspondence",
                     "day", "data", "date", "dog", "dogma", "doll", "dollar"};
   
    struct TrieNode* root = getNewNode();
        for (int i = 0; i < (sizeof(keys) / sizeof(keys[0])); i++)
        insert(root, keys[i]);
    
    bool flag = false;
    while (flag == false)
    {
        cout << "Autocomplete | Enter '0' for exit" << endl;
        
        cout << "Enter word: ";
        string word, res;
        cin >> word;
        if (word[0] == '0')
            break;

        cout << "Enter number of variants: ";
        int var;
        cin >> var;

        autocomplete(root, word, res);
        variant(res, var);
    }
    return 0;
}