#include <iostream>
#include <cstdlib>
#include <ctime>

class Piece {
protected:
    int life;
    int damage;
    char character;

public:
    Piece(int life, int damage, char character) : life(life), damage(damage), character(character) {}

    virtual ~Piece() {}

    int getLife() const {
        return life;
    }

    void setLife(int newLife) {
        life = newLife;
    }

    int getDamage() const {
        return damage;
    }

    void setDamage(int newDamage) {
        damage = newDamage;
    }

    char getCharacter() const {
        return character;
    }

    virtual void performAttack() = 0;
};

class Ranged : public Piece {
public:
    using Piece::Piece;

    void performAttack() override {}
};

class Bowman : public Ranged {
public:
    Bowman() : Ranged(12, 3, 'B') {}
};

class Elf : public Ranged {
    int usageCount;

public:
    Elf() : Ranged(8, 6, 'E'), usageCount(3) {}

    void performAttack() override {
        usageCount--;
    }

    int getUsageCount() const {
        return usageCount;
    }
};

class Mage : public Ranged {
    int usageCount;

public:
    Mage() : Ranged(4, 8, 'M'), usageCount(2) {}

    void performAttack() override {
        usageCount--;
    }

    int getUsageCount() const {
        return usageCount;
    }
};

class Melee : public Piece {
public:
    using Piece::Piece;

    void performAttack() override {}
};

class Spearman : public Melee {
public:
    Spearman() : Melee(6, 3, 'S') {}
};

class Ranger : public Melee {
    int usageCount;

public:
    Ranger() : Melee(8, 6, 'R'), usageCount(2) {}

    void performAttack() override {
        usageCount--;
    }

    int getUsageCount() const {
        return usageCount;
    }
};

class Swordsman : public Melee {
public:
    Swordsman() : Melee(6, 4, 'W') {}
};

class Knight : public Melee {
public:
    Knight() : Melee(10, 10, 'K') {}
};

class Board {
    Piece* pieces[4][3];

public:
    Board() {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                pieces[row][col] = nullptr;
            }
        }
    }

    ~Board() {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                delete pieces[row][col];
            }
        }
    }

    Piece* getPiece(int row, int col) const {
        return pieces[row][col];
    }

    void setPiece(int row, int col, Piece* piece)  {
        pieces[row][col] = piece;
    }
};

class Game {
    Board boardX;
    Board boardY;
    int playerXHealth;
    int playerYHealth;
    bool playerXTurn;
    bool knightBonusApplied;
    bool mageBonusApplied;

public:
    Game() : playerXHealth(100), playerYHealth(100), playerXTurn(true), knightBonusApplied(false), mageBonusApplied(false) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    void play() {
        while (playerXHealth > 0 && playerYHealth > 0) {
            printBoards();

            if (playerXTurn) {
                std::cout << "Player X's turn:" << std::endl;
                takeTurn(boardX, boardY);
                applyBonuses(boardX, boardY);
                playerXTurn = false;
            } else {
                std::cout << "Player Y's turn:" << std::endl;
                takeTurn(boardY, boardX);
                applyBonuses(boardY, boardX);
                playerXTurn = true;
            }

            performAttacks(boardX, boardY);
            performAttacks(boardY, boardX);
            updateHealth();
            std::cout << std::endl;
        }

        std::cout << "Player X Health: " << playerXHealth << std::endl;
        std::cout << "Player Y Health: " << playerYHealth << std::endl;
        std::cout << "Game Over!" << std::endl;
    }

private:
    void takeTurn(Board& playerBoard, const Board& opponentBoard) {
        std::cout << "Enter the row (A, B, C, D): ";
        char rowChar;
        std::cin >> rowChar;

        int row = rowChar - 'A';

        std::cout << "Enter the column (1, 2, 3): ";
        int col;
        std::cin >> col;

        if (playerBoard.getPiece(row, col - 1) != nullptr) {
            std::cout << "Invalid move! Cell already occupied." << std::endl;
            takeTurn(playerBoard, opponentBoard);
            return;
        }

        Piece* piece = nullptr;

        if (col == 1 || col == 2) {
            std::cout << "Choose a piece to add:" << std::endl;
            std::cout << "1. Bowman" << std::endl;
            std::cout << "2. Elf" << std::endl;
            std::cout << "3. Mage" << std::endl;
            int choice;
            std::cin >> choice;

            if (choice == 1) {
                piece = new Bowman();
            } else if (choice == 2) {
                piece = new Elf();
            } else if (choice == 3) {
                piece = new Mage();
            } else {
                std::cout << "Invalid choice! Try again." << std::endl;
                takeTurn(playerBoard, opponentBoard);
                return;
            }
        } else if (col == 3) {
            std::cout << "Choose a piece to add:" << std::endl;
            std::cout << "1. Spearman" << std::endl;
            std::cout << "2. Ranger" << std::endl;
            std::cout << "3. Swordsman" << std::endl;
            std::cout << "4. Knight" << std::endl;
            int choice;
            std::cin >> choice;

            if (choice == 1) {
                piece = new Spearman();
            } else if (choice == 2) {
                piece = new Ranger();
            } else if (choice == 3) {
                piece = new Swordsman();
            } else if (choice == 4) {
                piece = new Knight();
            } else {
                std::cout << "Invalid choice! Try again." << std::endl;
                takeTurn(playerBoard, opponentBoard);
                return;
            }
        } else {
            std::cout << "Invalid column! Try again." << std::endl;
            takeTurn(playerBoard, opponentBoard);
            return;
        }

        playerBoard.setPiece(row, col - 1, piece);
    }

    void applyBonuses(Board& playerBoard, const Board& opponentBoard) {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                Piece* piece = playerBoard.getPiece(row, col);

                if (piece != nullptr) {
                    if (piece->getCharacter() == 'K' && !knightBonusApplied) {
                        applyAttackBonus(playerBoard, opponentBoard);
                        knightBonusApplied = true;
                    }

                    if (piece->getCharacter() == 'M' && !mageBonusApplied) {
                        applyLifeBonus(playerBoard);
                        mageBonusApplied = true;
                    }
                }
            }
        }
    }

    void applyAttackBonus(Board& playerBoard, const Board& opponentBoard) {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                Piece* piece = playerBoard.getPiece(row, col);

                if (piece != nullptr && piece->getCharacter() != 'K') {
                    piece->setDamage(piece->getDamage() + 1);
                }
            }
        }
    }

    void applyLifeBonus(Board& playerBoard) {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                Piece* piece = playerBoard.getPiece(row, col);

                if (piece != nullptr && piece->getCharacter() != 'M') {
                    piece->setLife(piece->getLife() + 1);
                }
            }
        }
    }

    void performAttacks(Board& attackingBoard, Board defendingBoard) {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                Piece* attacker = attackingBoard.getPiece(row, col);

                if (attacker != nullptr) {
                    attacker->performAttack();

                    if (attacker->getCharacter() == 'K' && attacker->getLife() <= 0) {
                        removeAttackBonus(attackingBoard);
                        knightBonusApplied = false;
                    }

                    if (attacker->getCharacter() == 'M' && attacker->getLife() <= 0) {
                        removeLifeBonus(attackingBoard);
                        mageBonusApplied = false;
                    }

                    if (col < 2) {
                        Piece* defender = defendingBoard.getPiece(row, col + 1);

                        if (defender != nullptr) {
                            defender->setLife(defender->getLife() - attacker->getDamage());

                            if (defender->getLife() <= 0) {
                                delete defender;
                                 defendingBoard.setPiece(row, col + 1, nullptr);
                            }
                        } else {
                            if (defendingBoard.getPiece(row, col + 2) == nullptr) {
                                playerYHealth -= attacker->getDamage();
                            }
                        }
                    } else {
                        if (defendingBoard.getPiece(row, col - 1) == nullptr) {
                            playerYHealth -= attacker->getDamage();
                        }
                    }
                }
            }
        }
    }

    void removeAttackBonus(Board& playerBoard) {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                Piece* piece = playerBoard.getPiece(row, col);

                if (piece != nullptr && piece->getCharacter() != 'K') {
                    piece->setDamage(piece->getDamage() - 1);
                }
            }
        }
    }

    void removeLifeBonus(Board& playerBoard) {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                Piece* piece = playerBoard.getPiece(row, col);

                if (piece != nullptr && piece->getCharacter() != 'M') {
                    piece->setLife(piece->getLife() - 1);
                }
            }
        }
    }

    void updateHealth() {
        if (playerXHealth < 0) {
            playerXHealth = 0;
        }

        if (playerYHealth < 0) {
            playerYHealth = 0;
        }
    }

    void printBoards() const {
        std::cout << "Player X Health: " << playerXHealth << std::endl;
        std::cout << "Player Y Health: " << playerYHealth << std::endl;

        std::cout << "   1   2   3" << std::endl;
        for (int row = 0; row < 4; row++) {
            std::cout << static_cast<char>('A' + row) << " ";
            for (int col = 0; col < 3; col++) {
                const Piece* pieceX = boardX.getPiece(row, col);
                const Piece* pieceY = boardY.getPiece(row, col);

                if (pieceX != nullptr) {
                    std::cout << " " << pieceX->getCharacter() << "X ";
                } else {
                    std::cout << "   ";
                }

                std::cout << "|";

                if (pieceY != nullptr) {
                    std::cout << " " << pieceY->getCharacter() << "Y ";
                } else {
                    std::cout << "   ";
                }

                std::cout << "|";
            }
            std::cout << std::endl;
            std::cout << "  -----------" << std::endl;
        }
    }
};


