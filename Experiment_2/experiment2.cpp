#include<bits/stdc++.h>
using namespace std;
struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c,int f) : ch(c), freq(f), left(NULL), right(NULL){}
};
struct Compare{
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};
void generateCodes(Node* root, string code, unordered_map<char,string>& HuffmanCode){
    if(!root) return;
    if(!root->left && !root->right){
        HuffmanCode[root->ch] = code;
    }
    generateCodes(root->left, code+'0', HuffmanCode);
    generateCodes(root->right, code+'1', HuffmanCode);
}
string decodeString(Node* root, string encoded){
    string decoded = "";
    Node* curr = root;
    for(char bit : encoded){
        if(bit == '0') curr = curr->left;
        else curr = curr->right;
        if(!curr->left && !curr->right){
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}
void HuffmanCoding(string text){
    unordered_map<char,int> freq;
    for(char c : text) freq[c]++;
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(auto pair : freq){
        pq.push(new Node(pair.first, pair.second));
    }
    while(pq.size() > 1){
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    Node* root = pq.top();
    unordered_map<char,string> HuffmanCode;
    generateCodes(root, "", HuffmanCode);
    string encoded = "";
    for(char c : text) encoded += HuffmanCode[c];
    string decoded = decodeString(root, encoded);
    cout << "Original string: " << text << "\n";
    cout << "Encoded string: " << encoded << "\n";
    cout << "Decoded string: " << decoded << "\n";
}
int main(){
    string s;
    cout<<"Enter Input String : ";
    cin >> s;
    HuffmanCoding(s);
    return 0;
}
