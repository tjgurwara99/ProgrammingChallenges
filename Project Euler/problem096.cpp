/* Correct answer in 9ms!! */
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

#define FILE_NAME "p096_sudoku.txt"

class BoardState {
public:
    int value[9][9];
    int numBlocked[9][9];
    bool blocked[9][9][9];

    BoardState() { 
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 10; k++) blocked[i][j][k] = false;
                value[i][j] = numBlocked[i][j] = 0;
            }
        }
    }

    void setTo(const BoardState& other) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 10; k++) blocked[i][j][k] = other.blocked[i][j][k];
                numBlocked[i][j] = other.numBlocked[i][j];
                value[i][j] = other.value[i][j];
            }
        }
    }

    bool isInvalid() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (value[i][j] == 0 && numBlocked[i][j] == 9) return true;
            }
        }
        return false;
    }

    bool isComplete() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (value[i][j] == 0) return false;
            }
        }
        return true;
    }

    void setValue(int r, int c, int v) {
        //printf("%d %d %d\n", r, c, v);
        assert(value[r][c] == 0);
        assert(!blocked[r][c][v]);

        // Affected rows and columns
        for (int i = 0; i < 9; i++) {
            blockAt(r, i, v);
            blockAt(i, c, v);
        }

        // Affected square
        int sr = (r / 3);
        int sc = (c / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                blockAt(sr*3+i, sc*3+j, v);
            }
        }

        value[r][c] = v;
    }

    void blockAt(int r, int c, int v) {
        assert(value[r][c] != v);
        if (!blocked[r][c][v]) {
            blocked[r][c][v] = true;
            numBlocked[r][c]++;
        }
    }

    void print() {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) printf("%d", value[r][c]);
            printf("\n");
        }
    }
};

class PreviousState {
public:
    BoardState state;
    int rowChanged, colChanged, lastTested;

    PreviousState(BoardState oldState, int row, int col, int num)
        : rowChanged(row), colChanged(col), lastTested(num) {
            state.setTo(oldState);
        }
};

BoardState solveBoard(BoardState& initialState) {

    vector<PreviousState> previous;
    BoardState currentState;
    currentState.setTo(initialState);

    while (!currentState.isComplete()) {

        if (currentState.isInvalid()) {

            while (true) {
                PreviousState& pstate = previous[previous.size()-1];
                currentState.setTo(pstate.state);

                int num = pstate.lastTested+1;
                for (; num < 10; num++) {
                    if (!currentState.blocked[pstate.rowChanged][pstate.colChanged][num]) break;
                }

                if (num != 10) {
                    pstate.lastTested = num;
                    currentState.setValue(pstate.rowChanged, pstate.colChanged, num);
                    break;
                }
                previous.pop_back();
            }

            continue;
        }

        int r = -1, c = -1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (currentState.value[i][j] == 0 &&
                        ( r== -1 || currentState.numBlocked[i][j] > currentState.numBlocked[r][c])) {
                    r = i;
                    c = j;
                }
            }
        }

        if (currentState.numBlocked[r][c] == 8) {
            int v = 1;
            while (currentState.blocked[r][c][v]) v++;
            currentState.setValue(r, c, v);
        } else {
            int v = 1;
            for (; v <= 9 && currentState.blocked[r][c][v]; v++) ;
            previous.push_back(PreviousState(currentState, r, c, v));
            currentState.setValue(r, c, v);
        }
    }

    return currentState;
}

vector<BoardState> parseBoards() {

    FILE* fin = fopen(FILE_NAME, "r");
    char *line = NULL;
    size_t len = 0;
    vector<BoardState> boards;


    for (int i = 0; i < 50; i++) {
        BoardState board;
        getline(&line, &len, fin);

        for (int r = 0; r < 9; r++) {
            getline(&line, &len, fin);
            for (int c = 0; c < 9; c++) {
                int v = line[c]-'0';
                if (v != 0) board.setValue(r, c, v);
            }
        }

        boards.push_back(board);
    }

    fclose(fin);

    return boards;
}

int main() {

    vector<BoardState> boards = parseBoards();

    int total = 0;

    for (BoardState& board: boards) {
        BoardState solved = solveBoard(board);
        total += solved.value[0][0]*100+solved.value[0][1]*10+solved.value[0][2];
    }

    printf("%d\n", total);

    return 0;
}
