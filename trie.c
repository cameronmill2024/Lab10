struct Trie {
    struct Trie *children[26];
    bool isEndOfWord;
    int count;
};

void insert(struct Trie **ppTrie, char *word) {
    struct Trie *pTrie = *ppTrie;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (pTrie->children[index] == NULL) {
            pTrie->children[index] = (struct Trie *)malloc(sizeof(struct Trie));
            for (int j = 0; j < 26; j++) {
                pTrie->children[index]->children[j] = NULL;
            }
            pTrie->children[index]->isEndOfWord = false;
            pTrie->children[index]->count = 0;
        }
        pTrie = pTrie->children[index];
    }
    pTrie->isEndOfWord = true;
    pTrie->count++;
}

int numberOfOccurrences(struct Trie *pTrie, char *word) {
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (pTrie->children[index] == NULL) {
            return 0;
        }
        pTrie = pTrie->children[index];
    }
    if (pTrie->isEndOfWord) {
        return pTrie->count;
    } else {
        return 0;
    }
}
