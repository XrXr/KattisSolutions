#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

inline bool in(const unordered_set<string>& aSet, const string& aString) {
    return aSet.find(aString) != aSet.end();
}

int main() {
    int n;
    unordered_set<string> a, b, ori, mentioned;
    unordered_map<string, vector<string>> constraint;
    vector<pair<string, string>> rules;
    string word;
    cin >> n;
    const int lsize = n;
    while (n--) {
        cin >> word;

        ori.insert(word);

    }
    unordered_set<string> notMentioned(ori);

    cin >> n;
    while (n--) {
        string word2;
        cin >> word;
        cin >> word2;

        if (ori.find(word) == ori.end() || ori.find(word2) == ori.end()) continue;

        if (word == word2) {
            cout << "impossible" << endl;
            return 0;
        }

        rules.emplace_back(word, word2);

        constraint[word].push_back(word2);
        constraint[word2].push_back(word);

        mentioned.insert(word);
        mentioned.insert(word2);
        notMentioned.erase(word);
        notMentioned.erase(word2);
    }

    queue<pair<bool, string>> q;
    while (!mentioned.empty()) {
        q.emplace(false, move(*mentioned.begin()));
        mentioned.erase(mentioned.begin());
        while (!q.empty()) {
            const auto cur = move(q.front());
            q.pop();
            if (in(a, cur.second) || in(b, cur.second)) {
                continue;
            }

            auto target = &a;
            auto other = &b;

            if (cur.first) swap(a, b);

            target->insert(cur.second);
            const auto& opposing = constraint.find(cur.second)->second;
            other->insert(opposing.begin(), opposing.end());

            ori.erase(cur.second);
            for (const auto& e : opposing) {
                ori.erase(e);
                for (const auto& f : constraint.find(e)->second) {
                    if (!in(a, f) && !in(b, f)) q.emplace(false, f);
                }
            }
        }
    }

    for (const auto& r : rules) {
        if ((in(a, r.first) && in(a, r.second)) || in(b, r.first) && in(b, r.second)) {
            cout << "impossible" << endl;
            return 0;
        }
    }

    bool outputted = false;
    for (auto e : notMentioned) {
        if (outputted)
            cout << ' ';
        cout << e;
        outputted = true;
    }
    for (auto e : a) {
        if (outputted)
            cout << ' ';
        cout << e;
        outputted = true;
    }
    cout << endl;

    outputted = false;
    for (auto e : b) {
        if (outputted)
            cout << ' ';
        cout << e;
        outputted = true;
    }
    cout << endl;
}
