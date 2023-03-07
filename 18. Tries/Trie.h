#include <bits/stdc++.h>
#include "TrieNode.h"
using namespace std;
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
            return root->isTerminal;

        if (root->children[word[0] - 'a'] == NULL)
            return false;
        else
            return search(root->children[word[0] - 'a'], word.substr(1));
    }

    // For user
    bool search(string word)
    {
        return search(root, word);
    }

    void removeWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return;

        removeWord(child, word.substr(1));

        // Remove child Node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                    return;
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    // For user
    void removeWord(string word)
    {
        removeWord(root, word);
    }
};