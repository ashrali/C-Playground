#include <iostream>
#include <string>
#include <algorithm>

struct TrieNode {
	TrieNode* children[52] = {nullptr}; 
	bool isEndOfWord = false;
};

class Trie {
private:
	TrieNode* root;
	int charToIndex(char c) {
		if (c >= 'a' && c <= 'z') return c - 'a';
		if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
		return -1; 
	}
public:
	Trie() {
		root = new TrieNode();
	}
	void insert(const std::string& word) {
		TrieNode* current = root;
		for (char c : word) {
			int index = charToIndex(c);
			if (index == -1) continue; 
			if (!current->children[index]) {
				current->children[index] = new TrieNode();
			}
			current = current->children[index];
		}
		current->isEndOfWord = true;
	}
	bool search(const std::string& word) {
		TrieNode* current = root;
		for (char c : word) {
			int index = charToIndex(c);
			if (index == -1) return false; 
			if (!current->children[index]) {
				return false;
			}
			current = current->children[index];
		}
		return current->isEndOfWord;
	}

	void deleteTrie(TrieNode* node) {
		if (!node) return;
		for (int i = 0; i < 52; ++i) {
			deleteTrie(node->children[i]);
		}
		delete node;
	}
	~Trie() {
		deleteTrie(root);
	}
};

int main() {
	Trie trie;
	trie.insert("hello");
	trie.insert("hello");
	trie.insert("world");
	trie.insert("Hello");
	trie.insert("World");

	std::string word;
	std::cout << "Enter words to search (type 'exit' to quit):" << std::endl;
	while (true) {
		std::cout << "Word: ";
		std::cin >> word;
		if (word == "exit") break;
		if (trie.search(word)) {
			std::cout << "Searching for '" << word << "': Found" << std::endl;
		} else {
			std::cout << "Searching for '" << word << "': Not Found. Adding to Trie." << std::endl;
			trie.insert(word);
		}
	}
	return 0;
}