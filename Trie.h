#pragma once
#include <string>
#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    int freq;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool search(TrieNode*, string);
void autocomplete(TrieNode*, string&, string&);
void findWord(TrieNode* root, string& word, string& buf, string& res);
void variant(string& res, int var);