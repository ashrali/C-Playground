#include <iostream>
#include <conio.h>  // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;
const int MAX_ENEMIES = 20;
const int MAX_BULLETS = 10;

char grid[HEIGHT][WIDTH];
int playerPos = WIDTH / 2;
int playerLives = 3;

int enemies[MAX_ENEMIES][2]; // {row, col}
int bullets[MAX_BULLETS][2]; // {row, col}
int numEnemies = 0;
int numBullets = 0;

void initializeGrid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }
}

void drawGrid() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << "Lives: " << playerLives << endl;
}

void updateGrid() {
    initializeGrid();

    // Draw enemies
    for (int i = 0; i < numEnemies; i++) {
        if (enemies[i][0] >= 0 && enemies[i][0] < HEIGHT && enemies[i][1] >= 0 && enemies[i][1] < WIDTH) {
            grid[enemies[i][0]][enemies[i][1]] = 'X';
        }
    }

    // Draw bullets
    for (int i = 0; i < numBullets; i++) {
        if (bullets[i][0] >= 0 && bullets[i][0] < HEIGHT && bullets[i][1] >= 0 && bullets[i][1] < WIDTH) {
            grid[bullets[i][0]][bullets[i][1]] = '|';
        }
    }

    // Draw player
    grid[HEIGHT - 1][playerPos] = 'P';
}

void movePlayer(char dir) {
    if (dir == 'a' && playerPos > 0) playerPos--;
    if (dir == 'd' && playerPos < WIDTH - 1) playerPos++;
}

void shoot() {
    if (numBullets < MAX_BULLETS) {
        bullets[numBullets][0] = HEIGHT - 2; // Bullet starts above player
        bullets[numBullets][1] = playerPos;
        numBullets++;
    }
}

void moveBullets() {
    for (int i = 0; i < numBullets; i++) {
        bullets[i][0]--; // Move upward
        if (bullets[i][0] < 0) {
            // Remove out-of-bounds bullets
            numBullets--;
            bullets[i][0] = bullets[numBullets][0];
            bullets[i][1] = bullets[numBullets][1];
            i--; // Re-check current index
        }
    }
}

void moveEnemies(int frame) {
    if (frame % 5 != 0) return; // Slow down movement

    for (int i = 0; i < numEnemies; i++) {
        enemies[i][0]++; // Move downward

        // Check collision with player
        if (enemies[i][0] == HEIGHT - 1 && enemies[i][1] == playerPos) {
            playerLives--;
            // Remove the enemy
            numEnemies--;
            enemies[i][0] = enemies[numEnemies][0];
            enemies[i][1] = enemies[numEnemies][1];
            i--; // Re-check current index
        } else if (enemies[i][0] >= HEIGHT) {
            // Remove enemies that reach the bottom
            numEnemies--;
            enemies[i][0] = enemies[numEnemies][0];
            enemies[i][1] = enemies[numEnemies][1];
            i--;
        }
    }
}

void checkCollisions() {
    // Check bullet-enemy collisions
    for (int i = 0; i < numBullets; i++) {
        for (int j = 0; j < numEnemies; j++) {
            if (bullets[i][0] == enemies[j][0] && bullets[i][1] == enemies[j][1]) {
                // Remove bullet
                numBullets--;
                bullets[i][0] = bullets[numBullets][0];
                bullets[i][1] = bullets[numBullets][1];
                i--;

                // Remove enemy
                numEnemies--;
                enemies[j][0] = enemies[numEnemies][0];
                enemies[j][1] = enemies[numEnemies][1];
                j--;

                break;
            }
        }
    }
}

void spawnEnemy() {
    if (numEnemies < MAX_ENEMIES) {
        enemies[numEnemies][0] = 0;
        enemies[numEnemies][1] = rand() % WIDTH;
        numEnemies++;
    }
}

bool checkGameOver() {
    return playerLives <= 0;
}

int main() {
    initializeGrid();
    int frame = 0;
    bool gameOver = false;

    while (!gameOver) {
        if (_kbhit()) {
            char ch = _getch();
            while (_kbhit()) _getch(); // Clear buffer
            if (ch == 'a' || ch == 'd') movePlayer(ch);
            if (ch == ' ') shoot();
        }

        // Check collisions first to detect immediate hits
        checkCollisions();

        if (frame % 10 == 0) spawnEnemy();
        moveBullets();
        moveEnemies(frame);

        updateGrid();
        drawGrid();

        gameOver = checkGameOver();
        Sleep(50);
        frame++;
    }

    cout << "Game Over! You were hit 3 times." << endl;
    return 0;
}