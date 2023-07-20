
//Tic Tac Toe Game by Kushagra Singh//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function prototypes
void displayBoard(const vector<char>& board);
bool isMoveValid(const vector<char>& board, int move);
bool isBoardFull(const vector<char>& board);
char checkWinner(const vector<char>& board);
int getPlayerMove(const vector<char>& board);
int getComputerMove(const vector<char>& board);
void makeMove(vector<char>& board, int move, char player);

int main() {
    vector<char> board(9, ' '); // Tic Tac Toe board
    char currentPlayer = 'X';   // Starting player

    srand(time(0)); // Seed the random number generator

    // Game loop
    while (true) {
        displayBoard(board);

        // Check if the game is over
        if (checkWinner(board) == 'X') {
            cout << "Congratulations! You win!" << endl;
            break;
        } else if (checkWinner(board) == 'O') {
            cout << "Computer wins! Better luck next time." << endl;
            break;
        } else if (isBoardFull(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        int move;
        if (currentPlayer == 'X') {
            // Human's turn
            move = getPlayerMove(board);
        } else {
            // Computer's turn
            move = getComputerMove(board);
        }

        makeMove(board, move, currentPlayer);

        // Switch the current player for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Function to display the Tic Tac Toe board
void displayBoard(const vector<char>& board) {
    cout << "  1 | 2 | 3 " << endl;
    cout << " -----------" << endl;
    cout << "  4 | 5 | 6 " << endl;
    cout << " -----------" << endl;
    cout << "  7 | 8 | 9 " << endl;

    cout << "Current Board:" << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check if a move is valid
bool isMoveValid(const vector<char>& board, int move) {
    return (move >= 1 && move <= 9 && board[move - 1] == ' ');
}

// Function to check if the board is full
bool isBoardFull(const vector<char>& board) {
    return count(board.begin(), board.end(), ' ') == 0;
}

// Function to check the winner of the game
char checkWinner(const vector<char>& board) {
    // Winning combinations
    const vector<vector<int>> winningCombinations = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (const auto& combination : winningCombinations) {
        if (board[combination[0]] == board[combination[1]] &&
            board[combination[1]] == board[combination[2]] &&
            board[combination[0]] != ' ') {
            return board[combination[0]];
        }
    }

    // If no winner is found
    return ' ';
}

// Function to get the player's move
int getPlayerMove(const vector<char>& board) {
    int move;
    cout << "Your turn (X). Enter a move (1-9): ";
    cin >> move;

    // Check if the move is valid, else ask again
    while (!isMoveValid(board, move)) {
        cout << "Invalid move! Please try again: ";
        cin >> move;
    }

    return move;
}

// Function to get the computer's move
int getComputerMove(const vector<char>& board) {
    // Implement a simple computer AI
    // It will randomly choose an empty cell
    int move;
    do {
        move = rand() % 9 + 1;
    } while (!isMoveValid(board, move));

    cout << "Computer's turn (O). Computer chose: " << move << endl;

    return move;
}

// Function to make a move on the board
void makeMove(vector<char>& board, int move, char player) {
    board[move - 1] = player;
}
