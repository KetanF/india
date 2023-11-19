#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>

using namespace std;

class NodeTree {
public:
    char data;
    int frequency;
    NodeTree* left;
    NodeTree* right;

    NodeTree(char d, int freq) : data(d), frequency(freq), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(NodeTree* left, NodeTree* right) {
        return left->frequency > right->frequency;
    }
};

unordered_map<char, string> huffmanCode;

void generateHuffmanCodes(NodeTree* root, string code = "") {
    if (root) {
        if (!root->left && !root->right) {
            huffmanCode[root->data] = code;
        }
        generateHuffmanCodes(root->left, code + "0");
        generateHuffmanCodes(root->right, code + "1");
    }
}

NodeTree* buildHuffmanTree(priority_queue<NodeTree*, vector<NodeTree*>, CompareNodes>& nodes) {
    while (nodes.size() > 1) {
        NodeTree* left = nodes.top();
        nodes.pop();
        NodeTree* right = nodes.top();
        nodes.pop();

        NodeTree* newNode = new NodeTree('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        nodes.push(newNode);
    }
    return nodes.top();
}

int main() {
    ifstream file("test.txt");
    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));

    unordered_map<char, int> frequency;
    for (char ch : content) {
        frequency[ch]++;
    }

    priority_queue<NodeTree*, vector<NodeTree*>, CompareNodes> nodes;
    for (auto& entry : frequency) {
        nodes.push(new NodeTree(entry.first, entry.second));
    }

    NodeTree* root = buildHuffmanTree(nodes);
    generateHuffmanCodes(root);

    for (auto& entry : huffmanCode) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}