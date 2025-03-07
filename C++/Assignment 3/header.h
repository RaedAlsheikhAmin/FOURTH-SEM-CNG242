/* Raed Alsheikh Amin - 2528271, Farnaz Rezaei Noey 2551406
I read and accept the submission rules and the important section
specified in assignment file. This is my own work that is done by myself
and my team-mate only, and I want to declare that this work is done by working together on the entire code so there is no seperate function that one person did it by him/her self so the final mark out of 200 can be divided equally for us*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstring>
#include<limits>//it helps us to clear the buffer using clear and ignore, I just learnt it form The internet.
using namespace std;

// Base abstract class for all pieces that has members of life and damage and the character to represent the piece.
class Piece {
protected:
    int life;
    int damage;
    char character;

public://constructor to assign the values of the pieces directly.
    Piece(int life, int damage, char character) : life(life), damage(damage), character(character) {}
    virtual ~Piece() {}
    //getters.
    int getLife() const { return life; }
    int getDamage() const { return damage; }
    char getCharacter() const { return character; }

    virtual void performAttack() = 0;//abstract function
    virtual void reduceLife(int amount) { life -= amount; }
};

// Derived class for Ranged pieces that is going to have maxuses and remininguses to keep track of how many times we are using the pieces.
class Ranged : public Piece {
protected:
    int maxUses;
    int remainingUses;

public:
    Ranged(int life, int damage, char character, int maxUses) : Piece(life, damage, character), maxUses(maxUses), remainingUses(maxUses) {}

    int getRemainingUses() const { return remainingUses; }

    virtual void performAttack() {
        if (remainingUses > 0) {//that if i send -1 i will be setting them to unlimated uses.
            remainingUses--;
        }
    }
};

// Derived classes for Ranged pieces and -1 refers to unlimited usage.
class Bowman : public Ranged {
public:
    Bowman() : Ranged(12, 3, 'B', -1) {}
};

class Elf : public Ranged {
public:
    Elf() : Ranged(8, 6, 'E', 3) {}
};

class Mage : public Ranged {
public:
    Mage() : Ranged(4, 8, 'M', 2) {}

    void performAttack() {
        if (remainingUses > 0) {
            remainingUses--;
            // +1 life bonus to all teammates
        }

    }
};

// Derived class for Melee pieces
class Melee : public Piece {
protected:
    int maxUses;
    int remainingUses;

public:
    Melee(int life, int damage, char character, int maxUses)
            : Piece(life, damage, character), maxUses(maxUses), remainingUses(maxUses) {}

    int getRemainingUses() const { return remainingUses; }

    virtual void performAttack() {
        if (remainingUses > 0) {
            remainingUses--;
        }
    }
};

// Derived classes for Melee pieces
class Spearman : public Melee {
public:
    Spearman() : Melee(6, 3, 'S', -1) {}
};

class Ranger : public Melee {
public:
    Ranger() : Melee(8, 6, 'R', 2) {}
};

class Swordsman : public Melee {
public:
    Swordsman() : Melee(6, 4, 'W', -1) {}
};

class Knight : public Melee {
public:
    Knight() : Melee(10, 10, 'K', 1) {}

    void performAttack() {
        if (remainingUses > 0) {
            remainingUses--;
            // +1 attack bonus to all teammates
        }
    }
};

// Class for the board
class Board {//defining the table which is our board to be (4,3) size and it is going to be pointer of pieces.
private:
    Piece* table[4][3];

public://equality checking operator, we will use it later.
    bool operator==(const Board& other) const {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (table[i][j] != other.table[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Board& other) const {//using the top function we can just invert it to create this.
        return !(*this == other);
    }


// ...

    Board() {//default constructor
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                table[i][j] = nullptr; //using nullptr rather than NULL because it is less problamatic as I read about it.
            }
        }
    }

    ~Board() {//destructor
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                delete table[i][j];
            }
        }
    }

    void printBoard() const {
        cout << "    A   B   C" << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << " | ";
            for (int j = 0; j < 3; j++) {
                if (table[i][j] == nullptr) {//checking if it is empty.
                    cout << "  | ";
                } else {
                    cout << table[i][j]->getCharacter() << " | ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isCellEmpty(int row, int col) const {//checking if the location is empty
        return table[row][col] == nullptr;
    }

    void setPieceX(int row, int col, Piece* piece) {//is going to take the location and the type of piece.
        if (table[row][col] == nullptr) {
            char colchar;
            //cout<<"the column is : "<<col<<"this piece type is : "<<piece->getCharacter();
            if(piece->getCharacter()=='E' || piece->getCharacter()=='M' || piece->getCharacter()=='B'){
                while(col==2)
                {
                cout<<"Ranged pieces can only placed in the first or second column that means either A OR B"<<endl;
                cout<<"Please enter your column in the range (A-C): ";
                cin>>colchar;
                col=colchar-'A';

                 }
            }
            else {
                while(col==0)
                {
                    cout<<"Melee pieces can only placed in the second or third column that means either B OR C"<<endl;
                    cout<<"Please enter your column in the range (A-C): ";
                    cin>>colchar;
                    col=colchar-'A';

                }
            }
            table[row][col] = piece;
        }
    }
    void setPieceY(int row, int col, Piece* piece) {//is going to take the location and the type of piece.
        if (table[row][col] == nullptr) {
            char colchar;
            //cout<<"the column is : "<<col<<"this piece type is : "<<piece->getCharacter();
            if(piece->getCharacter()=='E' || piece->getCharacter()=='M' || piece->getCharacter()=='B') {
                while (col == 0) {
                    cout << "Ranged pieces can only placed in the first or second column that means either A OR B"
                         << endl;
                    cout << "Please enter the column in the range (C-A): ";
                    cin >> colchar;
                    col = 'C' - colchar;
                }
            }
                else{
                    while(col==2)
                    {
                        cout<<"Melee pieces can only placed in the second or third column that means either B OR C"<<endl;
                        cout<<"Please enter your column in the range (C-A): ";
                        cin>>colchar;
                        col='C'-colchar;

                    }
                }

            table[row][col] = piece;
        }
    }

    Piece* getPiece(int row, int col) const {
        return table[row][col];
    }


    void clearCell(int row, int col) {//to deleted the piece from the board.
        if (table[row][col] != nullptr) {
            delete table[row][col];
            table[row][col] = nullptr;
        }
    }
};

// Game class
class Game {//we have two boards, and each player has health, for each player i am keeping track of the limited pieces.
private:
    Board boardX;
    Board boardY;
    int healthX;
    int healthY;

    //to check the usage of each one.
    int elfUsageX;
    int elfUsageY;
    int rangerUsageX;
    int rangerUsageY;
    int mageUsageX;
    int mageUsageY;
    int knightUsageX;
    int knightUsageY;


    //TO COUNT THE HOW MANY TIMES THEY ARE USED AND DISPLAY THEM.
    int bowmanCountX;
    int elfCountX;
    int mageCountX;
    int spearmanCountX;
    int rangerCountX;
    int swordsmanCountX;
    int knightCountX;

    int bowmanCountY;
    int elfCountY;
    int mageCountY;
    int spearmanCountY;
    int rangerCountY;
    int swordsmanCountY;
    int knightCountY;

public://default constructor to initialize the members.
    Game() : healthX(100), healthY(100), elfUsageX(0), elfUsageY(0), rangerUsageX(0), rangerUsageY(0),
             mageUsageX(0), mageUsageY(0), knightUsageX(0), knightUsageY(0),bowmanCountX(0), elfCountX(0), mageCountX(0),
             spearmanCountX(0),rangerCountX(0), swordsmanCountX(0), knightCountX(0),
             bowmanCountY(0), elfCountY(0), mageCountY(0), spearmanCountY(0),
             rangerCountY(0), swordsmanCountY(0), knightCountY(0) {}


    void play() {
        srand(time(nullptr));//to start the game randomly.
        bool playerXTurn = rand() % 2 == 0;
        printBoards();//to print the board when the game starts.

        while (healthX > 0 && healthY > 0) {

            int row, col;
            Piece *piece = nullptr;

            if (playerXTurn) {
                cout << "Player X's turn" << endl;
                cout << "Enter the row (1-4): ";
                cin >> row;
                while (row != 1 && row != 2 && row != 3 && row != 4) {
                    cout << "please Enter the row in range(1-4): ";
                    fflush(stdin);
                    cin >> row;
                }
                cout << "Enter the column (A-C): ";
                char colChar;
                cin >> colChar;
                while (colChar != 'A' && colChar != 'B' && colChar != 'C') {
                    cout << "please Enter the column in range(A-C): ";
                    cin >> colChar;
                }
                col = colChar - 'A';

                piece = choosePieceX();
            } else {
                cout << "Player Y's turn" << endl;
                cout << "Enter the row (1-4): ";
                cin >> row;
                while (row != 1 && row != 2 && row != 3 && row != 4) {
                    printf("please Enter the row in range(1-4): ");
                    fflush(stdin);
                    cin >> row;
                }
                cout << "Enter the column (C-A): ";
                char colChar;
                cin >> colChar;
                while (colChar != 'A' && colChar != 'B' && colChar != 'C') {
                    cout << "please Enter the column in range(A-C): ";
                    cin >> colChar;

                }
                col = 'C' - colChar;

                piece = choosePieceY();
            }

            if (row < 1 || row > 4 || col < 0 || col > 2) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            if (playerXTurn) {
                if (boardX.isCellEmpty(row - 1, col)) {
                    boardX.setPieceX(row - 1, col, piece);
                    piece->performAttack();
                    performAttackOnBoard(boardX, boardY, healthY);
                    cout << "Player X's health: " << healthX << endl;
                    cout << "Player Y's health: " << healthY << endl;
                    printBoards();// keep printing after each round
                } else {
                    cout << "Invalid move. Try again." << endl;
                    continue;
                }
            } else {
                if (boardY.isCellEmpty(row - 1, col)) {
                    boardY.setPieceY(row - 1, col, piece);
                    piece->performAttack();
                    performAttackOnBoard(boardY, boardX, healthX);
                    cout << "Player X's health: " << healthX << endl;
                    cout << "Player Y's health: " << healthY << endl;
                    printBoards();// keep printing after each round
                } else {
                    cout << "Invalid move. Try again." << endl;
                    continue;
                }
            }
            playerXTurn = !playerXTurn;

        }
        cout << "Game over!" << endl;
        if(healthX>healthY)
            cout<<"Player X wins";
        else
            cout<<"player Y wins";
        cout << "Player X's health: " << healthX << endl;
        cout << "Player Y's health: " << healthY << endl;
//this info down will help me to count the kills performed by each player, the number we counted minus the number left on the board.
        cout << "The number of pieces that Player X used :" << endl;
        cout << "Bowman: " << bowmanCountX << endl;
        cout << "Elf: " << elfCountX << endl;
        cout << "Mage: " << mageCountX << endl;
        cout << "Spearman: " << spearmanCountX << endl;
        cout << "Ranger: " << rangerCountX << endl;
        cout << "Swordsman: " << swordsmanCountX << endl;
        cout << "Knight: " << knightCountX << endl;

        cout << "The number of pieces that Player Y used:" << endl;
        cout << "Bowman: " << bowmanCountY << endl;
        cout << "Elf: " << elfCountY << endl;
        cout << "Mage: " << mageCountY << endl;
        cout << "Spearman: " << spearmanCountY << endl;
        cout << "Ranger: " << rangerCountY << endl;
        cout << "Swordsman: " << swordsmanCountY << endl;
        cout << "Knight: " << knightCountY << endl;

        /*for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                switch(boardX.getPiece(i,j)->getCharacter()){

                    case 'B':
                        bowmanCountX--;
                        break;
                    case 'E':
                        elfCountX--;
                        break;
                    case 'M':
                        mageCountX--;
                        break;
                    case 'S':
                        spearmanCountX--;
                        break;
                    case 'R':
                        rangerCountX--;
                        break;
                    case 'W':
                        swordsmanCountX--;
                        break;
                    case 'K':
                        knightCountX--;
                        break;
                    default:
                        continue;
                }
                switch(boardY.getPiece(i,j)->getCharacter()){

                    case 'B':
                        bowmanCountY--;
                        break;
                    case 'E':
                        elfCountY--;
                        break;
                    case 'M':
                        mageCountY--;
                        break;
                    case 'S':
                        spearmanCountY--;
                        break;
                    case 'R':
                        rangerCountY--;
                        break;
                    case 'W':
                        swordsmanCountY--;
                        break;
                    case 'K':
                        knightCountY--;
                        break;
                    default:
                        continue;
                }


            }
        }

        cout << "The number of pieces that got killed for Player X  in the game :" << endl;
        cout << "Bowman: " << bowmanCountX << endl;
        cout << "Elf: " << elfCountX << endl;
        cout << "Mage: " << mageCountX << endl;
        cout << "Spearman: " << spearmanCountX << endl;
        cout << "Ranger: " << rangerCountX << endl;
        cout << "Swordsman: " << swordsmanCountX << endl;
        cout << "Knight: " << knightCountX << endl;

         cout << "The number of pieces that got killed for Player Y  in the game :" << endl;
        cout << "Bowman: " << bowmanCountY << endl;
        cout << "Elf: " << elfCountY << endl;
        cout << "Mage: " << mageCountY << endl;
        cout << "Spearman: " << spearmanCountY << endl;
        cout << "Ranger: " << rangerCountY << endl;
        cout << "Swordsman: " << swordsmanCountY << endl;
        cout << "Knight: " << knightCountY << endl;

         //the idea of this commented code is as I mentioned before, I already counted each pieced used for each player so i was going to substract the pieced left on the board to count the performed kills.
         but the code at some point is crushing because of boardX and boardY.

*/

    }

private:
    void printBoards() const {
        cout << "Player X's Board:\t\tPlayer Y's Board:" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (boardX.getPiece(i, j) == nullptr) {
                    cout << "  | ";
                } else {
                    Piece *pieceX = boardX.getPiece(i, j);
                    cout << pieceX->getCharacter() << "(" << pieceX->getLife() << ")";
                }
            }
            cout << "\t\t\t";
            for (int j = 0; j < 3; j++) {
                if (boardY.getPiece(i, j) == nullptr) {
                    cout << "  | ";
                } else {
                    Piece *pieceY = boardY.getPiece(i, j);
                    cout << pieceY->getCharacter() << "(" << pieceY->getLife() << ")";
                }
            }
            cout << endl;
        }
        cout << endl;
    }


    Piece *choosePieceX() {
        cout << "Choose a piece for Player X:\n\t\tLife\tdamage"<< endl;
        cout << "1. Bowman\t 12\t 3" <<endl;
        cout << "2. Elf\t\t 8\t 6" << endl;
        cout << "3. Mage\t\t 4\t 8" << endl;
        cout << "4. Spearman\t 6\t 3" << endl;
        cout << "5. Ranger\t 8\t 6" << endl;
        cout << "6. Swordsman\t 6\t 4" << endl;
        cout << "7. Knight\t 10\t 10" << endl;

        int choice;
        cin >> choice;
        while (!(cin >>choice) || (choice < 1 || choice >7)) {//to handle character input problems, I learnt this from chatGPT , I couldn't do it by myself.
            cout << "Invalid input. Please enter a number between 1 and 7: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        int valid = 1;
        int check = 0;
        while (valid) {
            switch (choice) {
                case 1:
                    bowmanCountX++;
                    return new Bowman();
                case 2:
                    if (elfUsageX < 3) {
                        elfUsageX++;
                        elfCountX++;
                        return new Elf();
                    } else check = 1;

                    break;
                case 3:
                    if (mageUsageX < 2) {
                        mageCountX++;
                        mageUsageX++;
                        return new Mage();
                    } else check = 1;
                    break;
                case 4:
                    spearmanCountX++;
                    return new Spearman();
                case 5:
                    if (rangerUsageX < 2) {
                        rangerUsageX++;
                        rangerCountX++;
                        return new Ranger();
                    } else check = 1;
                    break;
                case 6:
                    swordsmanCountX++;
                    return new Swordsman();
                case 7:
                    if (knightUsageX < 1) {
                        knightUsageX++;
                        knightCountX++;
                        return new Knight();
                    } else check = 1;
                    break;
                default:
                    cout << "The number you entered is not in the menu " << endl;
                    cout << "please enter another valid piece number: ";
                    cin >> choice;
                    check = 0;
            }
            if (check) {
                cout << "Please enter another piece because you reached your limit of using this piece: ";
                cin >> choice;
            }
        }
    }

    Piece *choosePieceY() {
        cout << "Choose a piece for Player Y:\n\t\tLife\tdamage"<< endl;
        cout << "1. Bowman\t 12\t 3" <<endl;
        cout << "2. Elf\t\t 8\t 6" << endl;
        cout << "3. Mage\t\t 4\t 8" << endl;
        cout << "4. Spearman\t 6\t 3" << endl;
        cout << "5. Ranger\t 8\t 6" << endl;
        cout << "6. Swordsman\t 6\t 4" << endl;
        cout << "7. Knight\t 10\t 10" << endl;

        int choice;
        cin >> choice;
        while (!(cin >>choice) || (choice < 1 || choice >7)) {//to handle character input problems, I learnt this from chatGPT , I couldn't do it by myself.//but when entering the number of the piece you have to enter it twice :(.
            cout << "Invalid input. Please enter a number between 1 and 7: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //To ensure that we will not enter infinite loop.
        }
        int valid = 1;
        int check = 0;
        while (valid) {

            switch (choice) {
                case 1:
                    bowmanCountY++;
                    return new Bowman();
                case 2:
                    if (elfUsageY < 3) {
                        elfUsageY++;
                        elfCountY++;
                        return new Elf();
                    } else check = 1;
                    break;
                case 3:
                    if (mageUsageY < 2) {
                        mageUsageY++;
                        mageCountY++;
                        return new Mage();
                    } else check = 1;
                    break;
                case 4:
                    spearmanCountY++;
                    return new Spearman();
                case 5:
                    if (rangerUsageY < 2) {
                        rangerUsageY++;
                        rangerCountY++;
                        return new Ranger();
                    } else check = 1;
                    break;
                case 6:
                    swordsmanCountY++;
                    return new Swordsman();
                case 7:
                    if (knightUsageY < 1) {
                        knightUsageY++;
                        knightCountY++;
                        return new Knight();
                    } else check = 1;
                    break;

                default:
                    cout << "The number you entered is not in the menu " << endl;
                    cout << "please enter another valid piece number: ";
                    cin >> choice;
                    check = 0;
            }
            if (valid) {
                cout << "please enter another piece because you reached your limit of using this piece: ";
                cin >> choice;
            }

        }
    }

    void performAttackOnBoard(Board& boardA, Board& boardD, int& opponentHealth) {//this is the most important function that is gonna perform the attack.
        for (int row = 0; row < 4; row++) {//loop to go over the rows
            for (int colA = 2; colA >= 0; colA--) {//loop to go over the attacker columns
                Piece* attackingPiece = boardA.getPiece(row, colA);//get the piece of the attacker in specific column

                // Flag to track if the attacking piece has attacked
                bool hasAttacked = false;

                for (int colD = 0; colD < 3; colD++) {//loop to go over the defender columns
                    Piece* defendingPiece = boardD.getPiece(row, colD);

                    if (attackingPiece != nullptr && defendingPiece != nullptr) {//check if the places are not empty.
                        int damage = attackingPiece->getDamage();//get the damage from the attacker piece
                        defendingPiece->reduceLife(damage);// reduce the defender's piece life by the damage taken.

                        if (defendingPiece->getLife() <= 0) {//if the defenders' piece life reaches 0, or less, it dies.
                            boardD.clearCell(row, colD);//delete the piece from the board.
                        }

                        // Set the hasAttacked flag to true
                        hasAttacked = true;//to check if the piece attacked or not, that doesn't attack again.
                        break;//if a defender piece dies, the attacker will not attack the health directly.
                    } else if (attackingPiece != nullptr && !hasAttacked && defendingPiece == nullptr) {//check if the piece didn't attack and the row infront of it is empty
                        int damage = attackingPiece->getDamage();//get the damage from the attacking piece.
                        opponentHealth -= damage;//reduce the life directly.

                        // Set the hasAttacked flag to true
                        hasAttacked = true;//to make sure the piece won't attack again
                        break;
                    }
                }
            }
        }
    }



};


