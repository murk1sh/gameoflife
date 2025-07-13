#include <iostream>
#include <vector>
using namespace std;
const int BOARD_SIZE = 10;

class Cell {
public:
    int current_life = 0;
    int next_life = 0;
    
    void set_alive() {
        current_life = 1;
    }
    void set_die() {
        current_life = 0;
    }
    int get_life() const {
        return current_life;
    }
    void set_next_life_alive() {
        next_life = 1;
    }
    void set_next_life_die() {
        next_life = 0;
    }
    int get_next_life() const {
        return next_life;
    }
    void update() {
        current_life = next_life;
    }
};

int count_neighbors (const vector<vector<Cell>>& board, int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE) {
                if (board[nx][ny].get_life() == 1) {
                    ++count;
                }
            }
        }
    }
    return count;
}

void print_board (const vector<vector<Cell>>& board){
    cout << "-------------------------" << endl;
    cout << "current board state:" << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << (board[i][j].get_life() ? "#" : ".") << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<Cell>> board(BOARD_SIZE, vector<Cell>(BOARD_SIZE));
    string ans; int ex, wy;
    while (ans != "x") { // Initial board
        // Instruct
        cout << "Please enter the x and y coordinates of your desired spot in the format x,y" << endl;
        cout << "-------------------------" << endl;
        cout << "current board state:" << endl;
        cout << "-------------------------" << endl;
        // Print board
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j].get_life() == 0) { // Dead prints '.'
                    cout << "." << " ";
                } else { // Alive prints "#"
                    cout << "#" << " ";
                }
            }
        cout << endl;
        } 
        
                cin >> ans;
        
        if (ans == "x") {
            break;
        }
        auto pos = ans.find(",");
        ex = stoi(ans.substr(0, pos));
        wy = stoi(ans.substr(pos+1));
        cout << "X: " << ex << " || Y: " << wy << endl;
        board[ex][wy].set_alive();
    }
    
    int generations = 10;
    for (int i = 0; i < generations; ++i) {
        cout << "Generation: " << i << endl;
        // Compute next state for each cell
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                int neighbors = count_neighbors(board, i, j);
                if (board[i][j].get_life() == 1) {
                    // Rule 1 or 3
                    if (neighbors < 2 || neighbors > 3)
                        board[i][j].set_next_life_die();
                    else
                        board[i][j].set_next_life_alive();
                } else {
                    // Rule 4
                    if (neighbors == 3)
                        board[i][j].set_next_life_alive();
                    else
                        board[i][j].set_next_life_die();
                }
            }
        }
        // Update current state from next_life
        for (int i = 0; i < BOARD_SIZE; ++i)
            for (int j = 0; j < BOARD_SIZE; ++j)
                board[i][j].update();

        print_board(board);
    }
    return 0;
}