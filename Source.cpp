#include "Tube.h"
#include "relation.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

struct State {
    vector<vector<char>> tubes;
    bool operator==( State& other)  { return tubes == other.tubes; }
};

struct Move {
    int from, to;
};

// Function declarations after State is defined
string stateToString( State& s);
bool isWinningState( State& s, size_t capacity);

pair<bool, vector<Move>> solve( Relation& initial) {
    queue<pair<State, vector<Move>>> q;
    unordered_set<string> visited;

    State start;
    for (size_t i = 0; i < initial.size(); i++) {
        start.tubes.push_back(initial.getTube(i).getdata());
    }
    q.push({ start, {} });
    visited.insert(stateToString(start));

    while (!q.empty()) {
        auto [current, moves] = q.front();
        q.pop();

        if (isWinningState(current, initial.getTubecapacity())) {
            return { true, moves };
        }

        for (int i = 0; i < current.tubes.size(); i++) {
            if (current.tubes[i].empty()) continue;
            char top = current.tubes[i].back();
            for (int j = 0; j < current.tubes.size(); j++) {
                if (i == j) continue;
                if (current.tubes[j].empty() ||
                    (current.tubes[j].size() < initial.getTubecapacity() &&
                        current.tubes[j].back() == top)) {
                    State next = current;
                    next.tubes[j].push_back(top);
                    next.tubes[i].pop_back();
                    string stateStr = stateToString(next);
                    if (visited.find(stateStr) == visited.end()) {
                        visited.insert(stateStr);
                        vector<Move> nextMoves = moves;
                        nextMoves.push_back({ i, j });
                        q.push({ next, nextMoves });
                    }
                }
            }
        }
    }
    return { false, {} };
}

string stateToString( State& s) {
    string str;
    for ( auto& tube : s.tubes) {
        str += "|";
        for (char c : tube) str += c;
    }
    return str;
}

bool isWinningState( State& s, size_t capacity) {
    for ( auto& tube : s.tubes) {
        if (!tube.empty()) {
            if (tube.size() != capacity) return false;
            char first = tube[0];
            for (char c : tube) {
                if (c != first) return false;
            }
        }
    }
    return true;
}

int main() {
    Relation game(3);
    game.Create();
    game.print_all();

    cout << "Try to solve the puzzle yourself! Enter 'solve' to use the bot, or 'quit' to exit.\n";

    string command;
    while (true) {
        cout << "Enter command (move/solve/quit): ";
        cin >> command;

        if (command == "solve") {
            auto [solvable, moves] = solve(game);
            if (solvable) {
                cout << "Solvable! Moves:\n";
                for (auto m : moves) {
                    cout << m.from << " -> " << m.to << "\n";
                }
            }
            else {
                cout << "No solution exists.\n";
            }
            break;
        }
        else if (command == "quit") {
            cout << "Exiting game.\n";
            break;
        }
        else {
            game.moveLetter();
        }
    }

    return 0;
}