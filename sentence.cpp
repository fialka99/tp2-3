#include "sentence.h"

SentenceFilter::SentenceFilter() : source(""), isTextSource(false) { cout << "Constructor called without parameters for SentenceFilter class\n"; }

SentenceFilter::SentenceFilter(const string& filename) : source(filename), isTextSource(false) { cout << "Constructor called with parameters for SentenceFilter class\n"; }

SentenceFilter::SentenceFilter(const string& text, bool isText) : source(text), isTextSource(isText) { cout << "Constructor called with parameters for SentenceFilter class\n"; }

SentenceFilter::SentenceFilter(const SentenceFilter& other) : source(other.source), isTextSource(other.isTextSource) { cout << "The copy constructor for the SentenceFilter class has been called\n"; }

SentenceFilter::~SentenceFilter() { cout << "The destructor for the SentenceFilter class has been called\n"; }

void SentenceFilter::result() const {
    string text;

    if (isTextSource) {
        text = source;
    }
    else {
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "The file couldn't be opened: " << source << endl;
            return;
        }
        ostringstream buffer;
        buffer << file.rdbuf();
        text = buffer.str();
        file.close();
    }

    cout << "The text:\n" << text << "\n\n";

    string* sentences = nullptr;
    int sentenceCount = 0;
    split_into_sent(text, sentences, sentenceCount);
    display_dash_sentences(sentences, sentenceCount);

    delete[] sentences;
}

void SentenceFilter::split_into_sent(const string& text, string*& sentences, int& sentenceCount) const {
    const int maxSentences = 100;
    sentences = new string[maxSentences];
    sentenceCount = 0;
    ostringstream sentenceStream;

    for (char ch : text) {
        sentenceStream << ch;
        if (ch == '.' || ch == '!' || ch == '?') {
            if (sentenceCount < maxSentences) {
                sentences[sentenceCount++] = sentenceStream.str();
                sentenceStream.str("");
                sentenceStream.clear();
            }
        }
    }
    if (!sentenceStream.str().empty() && sentenceCount < maxSentences) {
        sentences[sentenceCount++] = sentenceStream.str();
    }
}

void SentenceFilter::display_dash_sentences(const string* sentences, int sentenceCount) const {
    cout << "Sentences starting with a dash:\n";
    for (int i = 0; i < sentenceCount; ++i) {
        const string& sentence = sentences[i];
        size_t dashPosition = sentence.find('-');

        if (dashPosition != string::npos) {
            string beforeDash = sentence.substr(0, dashPosition);

            if (beforeDash.find_first_not_of(" \t\n") == string::npos) {
                cout << sentence << endl;
            }
        }
    }
}
