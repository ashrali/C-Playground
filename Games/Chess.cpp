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
    if ((piece1 >= 'A' && piece1 <= 'Z') && (piece2 >= 'A' && piece2 <= 'Z'))
        return true;
    if ((piece1 >= 'a' && piece1 <= 'z') && (piece2 >= 'a' && piece2 <= 'z'))
        return true;
    return false;
}

bool isPathClear(int x1, int y1, int x2, int y2)
{
    int dx = 0;
    int dy = 0;
    if (x2 > x1)
        dx = 1;
    else if (x2 < x1)
        dx = -1;
    if (y2 > y1)
        dy = 1;
    else if (y2 < y1)
        dy = -1;

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
    if (isSameColor(board[x1][y1], board[x2][y2]))
        return false;

    char piece = board[x1][y1];
    bool isWhite = (piece >= 'A' && piece <= 'Z');

    int dx = x2 - x1;
    int dy = y2 - y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;

    switch (piece)
    {
    case 'P':
    case 'p':
    {
        int dir;
        if (isWhite)
            dir = -1;
        else
            dir = 1;

        if (y1 == y2 && board[x2][y2] == '.' && (x2 - x1 == dir || (x1 == (isWhite ? 6 : 1) && x2 - x1 == 2 * dir)))
            return true;
        if (dy == 1 && x2 - x1 == dir && board[x2][y2] != '.')
            return true;
        return false;
    }
    case 'R':
    case 'r':
        return (x1 == x2 || y1 == y2) && isPathClear(x1, y1, x2, y2);
    case 'N':
    case 'n':
        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    case 'B':
    case 'b':
        return (dx == dy) && isPathClear(x1, y1, x2, y2);
    case 'Q':
    case 'q':
        return (x1 == x2 || y1 == y2 || dx == dy) && isPathClear(x1, y1, x2, y2);
    case 'K':
    case 'k':
        return dx <= 1 && dy <= 1;
    }
    return false;
}

bool isKingInCheck(bool isWhite)
{
    char king;
    if (isWhite)
        king = 'K';
    else
        king = 'k';

    int kingX, kingY;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == king)
            {
                kingX = i;
                kingY = j;
            }
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != '.' && isValidMove(i, j, kingX, kingY))
            {
                return true;
            }
        }
    }
    return false;
}

void movePiece(int x1, int y1, int x2, int y2)
{
    char piece = board[x1][y1];
    char captured = board[x2][y2];
    board[x2][y2] = piece;
    board[x1][y1] = '.';

    if (isKingInCheck(whiteTurn))
    {
        std::cout << "Invalid move! King is in check." << std::endl;
        board[x1][y1] = piece;
        board[x2][y2] = captured;
        return;
    }
    whiteTurn = !whiteTurn;
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

    if (isValidMove(x1, y1, x2, y2))
    {
        movePiece(x1, y1, x2, y2);
    }
    else
    {
        std::cout << "Invalid move. Try again." << std::endl;
    }
}

int main()
{
    initializeBoard();
    while (true)
    {
        printBoard();
        std::cout << (whiteTurn ? "White" : "Black") << "'s turn. Enter move: ";
        std::string move;
        std::cin >> move;
        if (move == "exit")
            break;
        parseAlgebraicMove(move);
    }
    return 0;
}