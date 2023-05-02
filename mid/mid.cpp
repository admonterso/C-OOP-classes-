#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> findWords(vector<string>& list, vector<vector<char>>& grid) {
    vector<string> result;
    int m = grid.size();
    int n = grid[0].size();
    for (string word : list) {
        bool found = false;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                if (dx != 0 && dy != 0) continue;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        int x = i, y = j;
                        found = true;
                        for (char c : word) {
                            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != c) {
                                found = false;
                                break;
                            }
                            x += dx;
                            y += dy;
                        }
                        if (found) {
                            result.push_back(word);
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) break;
            }
            if (found) break;
        }
    }
    return result;
}

int main() {
    vector<string> list;
    string word;
    getline(cin, word);
    stringstream ss(word);
    while (ss >> word) {
        list.push_back(word);
    }

    vector<vector<char>> grid;
    string line;
    while (getline(cin, line)) {
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }

    vector<string> result = findWords(list, grid);
    for (string word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
