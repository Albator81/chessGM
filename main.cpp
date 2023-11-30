#include <iostream>
#include <sstream>
#include <cmath>
#include <array>
#include "Bitboard.h"

#include<chrono> // testing

// Global Variables
bool whiteToMove;
std::array<int, 4> castlingRights;
int enPassantSquare;
int halfMoveClock;
int fullMoveNumber;



// Constants
// Skull


// Function Declarations
Board_Bitboards use_FEN(std::string fen, bool& whiteToMove, std::array<int, 4>& castlingRights, int& enPassantSquare, int& halfMoveClock, int& fullMoveNumber);



// Main Function

int main() {
    std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::cout << fen << std::endl;
    std::cout << "Using FEN..." << std::endl;
    Board_Bitboards board = use_FEN(fen, whiteToMove, castlingRights, enPassantSquare, halfMoveClock, fullMoveNumber);
    
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // Calling the function


    // Stop measuring time
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate and print the time taken
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}


// Function Definitions

Board_Bitboards use_FEN(std::string fen, bool& whiteToMove, std::array<int, 4>& castlingRights, int& enPassantSquare, int& halfMoveClock, int& fullMoveNumber) {
    std::array<U64, 6> arrW;
    std::array<U64, 6> arrB;
    
    // Parse FEN string
    std::stringstream ss(fen);
    std::string positionStr, castlingStr;
    char sideToMoveStr, enPassantStr, halfMoveClockStr, fullMoveNumberStr;
    ss >> positionStr >> sideToMoveStr >> castlingStr >> enPassantStr >> halfMoveClockStr >> fullMoveNumberStr;

    // Process positionStr
    int x = -1;
    int y = 0;
    int square;
    for (char c : positionStr) {
        if (c == '/') {
            y += 1;
            x = -1;
            continue;
        }
        else {
            if (isdigit(c)) {
                x += c - '0';
                continue;
            }
            else {
                x += 1;
            }
        }
        square = Bitboard::fileRankIndexToSquareIndex(x, y);
        // Handle piece positions
        switch (c) {
        case 'P': arrW[PAWN] |= 1ULL << (63 - square); break;
        case 'p': arrB[PAWN] |= 1ULL << (63 - square); break;
        case 'B': arrW[BISHOP] |= 1ULL << (63 - square); break;
        case 'b': arrB[BISHOP] |= 1ULL << (63 - square); break;
        case 'N': arrW[KNIGHT] |= 1ULL << (63 - square); break;
        case 'n': arrB[KNIGHT] |= 1ULL << (63 - square); break;
        case 'R': arrW[ROOK] |= 1ULL << (63 - square); break;
        case 'r': arrB[ROOK] |= 1ULL << (63 - square); break;
        case 'Q': arrW[QUEEN] |= 1ULL << (63 - square); break;
        case 'q': arrB[QUEEN] |= 1ULL << (63 - square); break;
        case 'K': arrW[KING] |= 1ULL << (63 - square); break;
        case 'k': arrB[KING] |= 1ULL << (63 - square); break;
        default: std::cerr << "Incorrect position" << std::endl;
        }
    }

    // Process sideToMoveStr
    if (sideToMoveStr == 'w') whiteToMove = true;
    else if (sideToMoveStr == 'b') whiteToMove = false;
    else std::cerr << "Invalid side to move" << std::endl;

    // Process castlingStr
    for (char c : castlingStr) {
        switch (c) {
        case 'K': castlingRights[0] = true; break;
        case 'Q': castlingRights[1] = true; break;
        case 'k': castlingRights[2] = true; break;
        case 'q': castlingRights[3] = true; break;
        }
    }

    Board_Bitboards board(arrW, arrB, whiteToMove);

    return board;
}

