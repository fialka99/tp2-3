#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

class SentenceFilter {
private:
    string source;
    bool isTextSource;

    void split_into_sent(const string& text, string*& sentences, int& sentenceCount) const;
    void display_dash_sentences(const string* sentences, int sentenceCount) const;

public:
    SentenceFilter();
    SentenceFilter(const string& filename);
    SentenceFilter(const string& text, bool isText);
    SentenceFilter(const SentenceFilter& other);
    ~SentenceFilter();
    void result() const;
};
