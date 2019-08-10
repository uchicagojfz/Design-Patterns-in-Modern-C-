#include<vector>
#include<unordered_map>
#include<sstream>
#include<iostream>
#include <string>
#include <iterator>
using namespace std;

struct Sentence {
    
  struct WordToken {
    bool capitalize;
  };
  
  vector<string> words;
  unordered_map<int, WordToken> tokens;

  // Convert sentence string to vector of words, separated by white space
  Sentence(const string& text) {
    istringstream iss(text);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));
  }

  WordToken& operator[](size_t index) {
    if (tokens.find(index) == tokens.end())
        tokens[index] = WordToken{};
    return tokens[index];
  }

  string str() const {
    string res;
    for (size_t i=0; i<words.size(); i++) {
        string word = words[i];
        auto it = tokens.find(i);
        // Case 1. found from unordered_map, and it's lower-case
        if (it != tokens.end() && it->second.capitalize) {
            for (auto c : word)
                res += toupper(c);
        }
        // Case 2. either not found in map, or it's already upper-case
        else {
            res += word;
        }
        // Add additional space if not last word
        if (i < words.size() - 1) {
            res += " ";
        }
    }
    return res;
  }
};
