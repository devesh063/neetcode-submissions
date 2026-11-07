class Node {
public:
    vector<Node*> links;
    bool isEnd;

    Node() : links(26, nullptr), isEnd(false) {}
};

class WordDictionary {
private:
    Node* root;

    bool dfs(Node* node, const string& word, int index) {
        if (node == nullptr) {
            return false;
        }

        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];

        if (ch == '.') {
            // Try every possible letter
            for (Node* child : node->links) {
                if (child != nullptr &&
                    dfs(child, word, index + 1)) {
                    return true;
                }
            }

            return false;
        }

        int pos = ch - 'a';

        if (node->links[pos] == nullptr) {
            return false;
        }

        return dfs(node->links[pos], word, index + 1);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for (char ch : word) {
            int pos = ch - 'a';

            if (node->links[pos] == nullptr) {
                node->links[pos] = new Node();
            }

            node = node->links[pos];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};