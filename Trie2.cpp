#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *links[26];
    int endWith = 0;
    int cntPref = 0;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }

    void setPrefix(){
        cntPref += 1;
    }

    void setEndWith(){
        endWith +=1;
    }

    int getEndWith(){
        return endWith;
    }

    int getPrefix(){
        return cntPref;
    }

    void DecPrefix(){
        cntPref -= 1;
    }

    void DecEndWith(){
        endWith -= 1;
    }
};
class Trie{
    private:
    	Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *node = root;
        for(auto ch : word){
          if (!node->containsKey(ch)) {
            node->put(ch, new Node());
          }
          node = node->get(ch);
          node->setPrefix();
        }
        node->setEndWith();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(auto ch : word){
            if(!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->getEndWith();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(auto ch : word){
            if(!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node *node = root;
        for(auto ch : word){
            if(!node->containsKey(ch))
                return;
            node = node->get(ch);
            node->DecPrefix();
        }
        node->DecEndWith();
    }
};

int main() {
  Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  return 0;
}