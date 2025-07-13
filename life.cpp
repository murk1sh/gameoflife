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
};
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
    
    
    

    return 0;
}