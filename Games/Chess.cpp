#include <iostream>

const int BOARD_SIZE = 8;
char board[BOARD_SIZE][BOARD_SIZE];
bool whiteTurn = true;

void initializeBoard()
{
    const char *initial[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"};
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = initial[i][j];
        }
    }
}

void printBoard()
{
    std::cout << "  a b c d e f g h" << std::endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << 8 - i << " ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isSameColor(char piece1, char piece2)
{
    return ((piece1 >= 'A' && piece1 <= 'Z') && (piece2 >= 'A' && piece2 <= 'Z')) ||
           ((piece1 >= 'a' && piece1 <= 'z') && (piece2 >= 'a' && piece2 <= 'z'));
}

bool isPathClear(int x1, int y1, int x2, int y2)
{
    int dx = (x2 > x1) - (x2 < x1);
    int dy = (y2 > y1) - (y2 < y1);

    int x = x1 + dx, y = y1 + dy;
    while (x != x2 || y != y2)
    {
        if (board[x][y] != '.')
            return false;
        x += dx;
        y += dy;
    }
    return true;
}

bool isValidMove(int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
        x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE)
    {
        return false;
    }
    char piece = board[x1][y1];
    if (piece == '.')
        return false;
    if (isSameColor(piece, board[x2][y2]))
        return false;

    bool isWhite = (piece >= 'A' && piece <= 'Z');
    if ((whiteTurn && !isWhite) || (!whiteTurn && isWhite))
        return false;

    switch (piece)
    {
    case 'P':
    case 'p':
    {
        int dir = -1;
        if (!isWhite)
            dir = 1;
        if (y1 == y2)
        {
            if (board[x2][y2] == '.' && x2 - x1 == dir)
                return true;
            if (x1 == 6 && isWhite && x2 - x1 == 2 * dir && board[x1 + dir][y1] == '.' && board[x2][y2] == '.')
                return true;
            if (x1 == 1 && !isWhite && x2 - x1 == 2 * dir && board[x1 + dir][y1] == '.' && board[x2][y2] == '.')
                return true;
        }
        else if ((y2 - y1 == 1 || y1 - y2 == 1) && x2 - x1 == dir && board[x2][y2] != '.')
        {
            return true;
        }
        return false;
    }
    case 'R':
    case 'r':
        return (x1 == x2 || y1 == y2) && isPathClear(x1, y1, x2, y2);
    case 'N':
    case 'n':
    {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return (dx * dx + dy * dy == 5);
    }
    case 'B':
    case 'b':
    {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return (dx * dx == dy * dy) && isPathClear(x1, y1, x2, y2);
    }
    case 'Q':
    case 'q':
    {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return (x1 == x2 || y1 == y2 || dx * dx == dy * dy) && isPathClear(x1, y1, x2, y2);
    }
    case 'K':
    case 'k':
    {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return (dx * dx <= 1 && dy * dy <= 1);
    }
    }
    return false;
}

bool isKingCaptured()
{
    bool whiteKing = false, blackKing = false;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'K')
                whiteKing = true;
            if (board[i][j] == 'k')
                blackKing = true;
        }
    }
    if (!whiteKing)
    {
        std::cout << "Black wins!" << std::endl;
        return true;
    }
    if (!blackKing)
    {
        std::cout << "White wins!" << std::endl;
        return true;
    }
    return false;
}

void movePiece(int x1, int y1, int x2, int y2)
{
    if (isValidMove(x1, y1, x2, y2))
    {
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = '.';
        whiteTurn = !whiteTurn;
    }
    else
    {
        std::cout << "Invalid move. Try again." << std::endl;
    }
}

void parseAlgebraicMove(std::string move)
{
    if (move.length() != 4)
    {
        std::cout << "Invalid move format. Use format like e2e4." << std::endl;
        return;
    }
    int y1 = move[0] - 'a';
    int x1 = 8 - (move[1] - '0');
    int y2 = move[2] - 'a';
    int x2 = 8 - (move[3] - '0');
    movePiece(x1, y1, x2, y2);
}

void checkmate()
 {

}

int main()
{
    initializeBoard();
    while (true)
    {
        printBoard();
        if (isKingCaptured())
            break;
        std::cout << "White's";
        if (!whiteTurn)
            std::cout << "Black's";
        std::cout << " turn. Enter move (e.g., e2e4), or 'exit' to quit: ";
        std::string move;
        std::cin >> move;
        if (move == "exit")
            break;
        parseAlgebraicMove(move);
    }
    return 0;
}