#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Bitboard.h"


// Other Bitboards
const U64 Bitboard::emptyBitboard = 0ULL;
const U64 Bitboard::universalBitboard = 0b1111111111111111111111111111111111111111111111111111111111111111;

const U64 Bitboard::notAFile = 0b1111111011111110111111101111111011111110111111101111111011111110;
const U64 Bitboard::notHFile = 0b0111111101111111011111110111111101111111011111110111111101111111;
const U64 Bitboard::fileA = 0x0101010101010101;
const U64 Bitboard::fileB = 0x0202020202020202;
const U64 Bitboard::fileC = 0x0404040404040404;
const U64 Bitboard::fileD = 0x0808080808080808;
const U64 Bitboard::fileE = 0x1010101010101010;
const U64 Bitboard::fileF = 0x2020202020202020;
const U64 Bitboard::fileG = 0x4040404040404040;
const U64 Bitboard::fileH = 0x8080808080808080;

const U64 Bitboard::rank1 = 0x00000000000000FF;
const U64 Bitboard::rank2 = 0x000000000000FF00;
const U64 Bitboard::rank3 = 0x0000000000FF0000;
const U64 Bitboard::rank4 = 0x00000000FF000000;
const U64 Bitboard::rank5 = 0x000000FF00000000;
const U64 Bitboard::rank6 = 0x0000FF0000000000;
const U64 Bitboard::rank7 = 0x00FF000000000000;
const U64 Bitboard::rank8 = 0xFF00000000000000;

const std::array<U64, 8> Bitboard::ranks = { rank1, rank2, rank3, rank4, rank5, rank6, rank7, rank8 };
const std::array<U64, 8> Bitboard::files = { fileA, fileB, fileC, fileD, fileE, fileF, fileG, fileH };

const U64 Bitboard::diag0 = 0b1000000001000000001000000001000000001000000001000000001000000001;
const U64 Bitboard::diag1 = 0b0100000000100000000100000000100000000100000000100000000100000000;
const U64 Bitboard::diag2 = 0b0010000000010000000010000000010000000010000000010000000000000000;
const U64 Bitboard::diag3 = 0b0001000000001000000001000000001000000001000000000000000000000000;
const U64 Bitboard::diag4 = 0b0000100000000100000000100000000100000000000000000000000000000000;
const U64 Bitboard::diag5 = 0b0000010000000010000000010000000000000000000000000000000000000000;
const U64 Bitboard::diag6 = 0b0000001000000001000000000000000000000000000000000000000000000000;
const U64 Bitboard::diag7 = 0b0000000100000000000000000000000000000000000000000000000000000000;
const U64 Bitboard::diag9 = 0b0000000000000000000000000000000000000000000000000000000010000000;
const U64 Bitboard::diag10 = 0b0000000000000000000000000000000000000000000000001000000001000000;
const U64 Bitboard::diag11 = 0b0000000000000000000000000000000000000000100000000100000000100000;
const U64 Bitboard::diag12 = 0b0000000000000000000000000000000010000000010000000010000000010000;
const U64 Bitboard::diag13 = 0b0000000000000000000000001000000001000000001000000001000000001000;
const U64 Bitboard::diag14 = 0b0000000000000000100000000100000000100000000100000000100000000100;
const U64 Bitboard::diag15 = 0b0000000010000000010000000010000000010000000010000000010000000010;

const std::array<U64, 16> Bitboard::diags = { diag0, diag1, diag2, diag3, diag4, diag5, diag6, diag7, emptyBitboard, diag9, diag10, diag11, diag12, diag13, diag14, diag15 };


const U64 Bitboard::antiDiag0 = 0b0000000100000010000001000000100000010000001000000100000010000000;
const U64 Bitboard::antiDiag1 = 0b0000000000000001000000100000010000001000000100000010000001000000;
const U64 Bitboard::antiDiag2 = 0b0000000000000000000000010000001000000100000010000001000000100000;
const U64 Bitboard::antiDiag3 = 0b0000000000000000000000000000000100000010000001000000100000010000;
const U64 Bitboard::antiDiag4 = 0b0000000000000000000000000000000000000001000000100000010000001000;
const U64 Bitboard::antiDiag5 = 0b0000000000000000000000000000000000000000000000010000001000000100;
const U64 Bitboard::antiDiag6 = 0b0000000000000000000000000000000000000000000000000000000100000010;
const U64 Bitboard::antiDiag7 = 0b0000000000000000000000000000000000000000000000000000000000000001;
const U64 Bitboard::antiDiag9 = 0b1000000000000000000000000000000000000000000000000000000000000000;
const U64 Bitboard::antiDiag10 = 0b0100000010000000000000000000000000000000000000000000000000000000;
const U64 Bitboard::antiDiag11 = 0b0010000001000000100000000000000000000000000000000000000000000000;
const U64 Bitboard::antiDiag12 = 0b0001000000100000010000001000000000000000000000000000000000000000;
const U64 Bitboard::antiDiag13 = 0b0000100000010000001000000100000010000000000000000000000000000000;
const U64 Bitboard::antiDiag14 = 0b0000010000001000000100000010000001000000100000000000000000000000;
const U64 Bitboard::antiDiag15 = 0b0000001000000100000010000001000000100000010000001000000000000000;

const std::array<U64, 16> Bitboard::antiDiags = { antiDiag0, antiDiag1, antiDiag2, antiDiag3, antiDiag4, antiDiag5, antiDiag6, antiDiag7, emptyBitboard, antiDiag9, antiDiag10, antiDiag11, antiDiag12, antiDiag13, antiDiag14, antiDiag15 };



SquareIndex Bitboard::fileRankIndexToSquareIndex(FileIndex file, RankIndex rank) {
    return 8 * rank + file;
}

FileIndex Bitboard::squareIndexToFileIndex(SquareIndex square) {
    return square & 7;
}

RankIndex Bitboard::squareIndexToRankIndex(SquareIndex square) {
    return square >> 3;
}

DiagIndex Bitboard::squareIndexToDiagIndex(SquareIndex square) {
    return (squareIndexToRankIndex(square) - squareIndexToFileIndex(square)) & 15;
}

DiagIndex Bitboard::squareIndexToAntiDiagIndex(SquareIndex square) {
    return (squareIndexToRankIndex(square) + squareIndexToFileIndex(square)) ^ 7;
}


void Bitboard::clearBitboard(U64& bitboard) {
    bitboard ^= bitboard;
}

void Bitboard::setBitTo1(U64 &bitboard, SquareIndex square) {
    bitboard |=  squareIndexToBitboard(square);
}

Bit Bitboard::getBitValue(U64 bitboard, SquareIndex square) {
    return (bitboard >> square) & 1;
}

U64 Bitboard::squareIndexToBitboard(SquareIndex square) {
    return 1ULL << square;
}


#pragma warning(disable : 4146) // because the compiler thinks -(some unsigned int) is an error, which should only be a warning
U64 Bitboard::getIsolatedLeastSignificantSetBit(U64 bitboard) {
    return bitboard & -bitboard;

}
U64 Bitboard::getIsolatedMostSignificantSetBit(U64 x)
{
    if (!x) { return emptyBitboard; }

    x |= x >> 32;
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;
    return (x >> 1) + 1;

}

SquareIndex Bitboard::getIndexOfLeastSignificantSetBit(U64 bitboard) {
    if (!bitboard) { return -1; }
    int index = 0;
    while ((bitboard & 1) == 0) {
        bitboard >>= 1;
        index++;
    }
    return index;
}

void Bitboard::resetIsolatedLeastSignificantSetBit(U64& bitboard) {
    bitboard &= (bitboard - 1);
}
void Bitboard::resetIsolatedMostSignificantSetBit(U64& v) {
    U64 x = v;

    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v |= v >> 32;
    v = (v >> 1) & x;
}

int Bitboard::bitCount(U64 bb)
{
    if (!bb) { return 0; }
    int count = 0;
    for (SquareIndex index = 0; index < 64; index++) {
        if (bb >> index & 1) { count += 1; }
    }
    return count;
}

std::vector<SquareIndex> Bitboard::getSetBitsPositions(U64 b) {
    std::vector<SquareIndex> positions;
    while (b) {
        positions.push_back(getIndexOfLeastSignificantSetBit(b));
        resetIsolatedLeastSignificantSetBit(b);
    }
    return positions;
}

// Print board
void Bitboard::visualizeBitboard(U64 bitboard) {
    std::string rankString = "";
    for (RankIndex rank = 0; rank < 8; rank++) {
        for (FileIndex file = 0; file < 8; file++) {
            rankString += bitboard >> fileRankIndexToSquareIndex(file, 7 - rank) & 1 ? '1' : '.';
            rankString += ' ';
        }
        rankString += '\n';
    }
    std::cout << rankString << std::endl;
}


Board_Bitboards::Board_Bitboards(std::array<U64, 6> wPNBRQK, std::array<U64, 6> bPNBRQK, Turn sideToMove) {
    for (int i = 0; i < 6; ++i) {
        arrWhitePieces_[i] = wPNBRQK[i];
        arrBlackPieces_[i] = bPNBRQK[i];
    }

    whiteBb_ = wPNBRQK[PAWN] | wPNBRQK[KNIGHT] | wPNBRQK[BISHOP] | wPNBRQK[ROOK] | wPNBRQK[QUEEN] | wPNBRQK[KING];
    blackBb_ = bPNBRQK[PAWN] | bPNBRQK[KNIGHT] | bPNBRQK[BISHOP] | bPNBRQK[ROOK] | bPNBRQK[QUEEN] | bPNBRQK[KING];

    turn_ = sideToMove;

    occupied_ = whiteBb_ | blackBb_;
    empty_ = ~occupied_;

    whiteRayAttacks = Bitboard::emptyBitboard; // forgetting to initialize these things caused weird things -_-
    blackRayAttacks = Bitboard::emptyBitboard;
    whiteRayPastOneAttacks = Bitboard::emptyBitboard;
    blackRayPastOneAttacks = Bitboard::emptyBitboard;
    for (int s = 0; s < 63; s++) {
        pieceTypes_           [s] = EMPTYSQUARE;
        pieceAttacksBitboards_[s] = Bitboard::emptyBitboard;
    }

    U64 tmpB;
    int s;
    int cp = 0;
    if (sideToMove == BLACKTURN) { changeTurn(); }
    for (U64 b : arrWhitePieces_) { // same problem // fixed with the line above and below the loop but not great // I should really change the turn thingy...
        tmpB = b;
        while (tmpB) {
            s = Bitboard::getIndexOfLeastSignificantSetBit(tmpB);
            pieceTypes_[s] = static_cast<ChessPiece>(cp);
            switch (static_cast<ChessPiece>(cp)) {
            case PAWN:   pieceAttacksBitboards_[s] = getPawnAttacksBitboard  (s); break;
            case KNIGHT: pieceAttacksBitboards_[s] = getKnightAttacksBitboard(s); break;
            case BISHOP: pieceAttacksBitboards_[s] = getBishopAttacksBitboard(s); whiteRayAttacks |= getUBishopMovesBitboard(s); whiteRayPastOneAttacks |= bishopPastOneAttacks(s); break;
            case ROOK:   pieceAttacksBitboards_[s] = getRookAttacksBitboard  (s); whiteRayAttacks |= getURookMovesBitboard  (s); whiteRayPastOneAttacks |= rookPastOneAttacks  (s); break;
            case QUEEN:  pieceAttacksBitboards_[s] = getQueenAttacksBitboard (s); whiteRayAttacks |= getUQueenMovesBitboard (s); whiteRayPastOneAttacks |= queenPastOneAttacks (s); break;
            case KING:   pieceAttacksBitboards_[s] = getKingAttacksBitboard  (s); break;
            }
            Bitboard::resetIsolatedLeastSignificantSetBit(tmpB);
        }
        cp++;
    }
    if (sideToMove == BLACKTURN) { changeTurn(); }
    
    cp = 0;
    if (sideToMove == WHITETURN) { changeTurn(); }
    for (U64 b : arrBlackPieces_) { // problem because of turn with moves // same as above
        tmpB = b;
        while (tmpB) {
            s = Bitboard::getIndexOfLeastSignificantSetBit(tmpB);
            pieceTypes_[s] = static_cast<ChessPiece>(cp);
            switch (static_cast<ChessPiece>(cp)) {
            case PAWN:   pieceAttacksBitboards_[s] = getPawnAttacksBitboard  (s); break;
            case KNIGHT: pieceAttacksBitboards_[s] = getKnightAttacksBitboard(s); break;
            case BISHOP: pieceAttacksBitboards_[s] = getBishopAttacksBitboard(s); blackRayAttacks |= getUBishopMovesBitboard(s); blackRayPastOneAttacks |= bishopPastOneAttacks(s); break;
            case ROOK:   pieceAttacksBitboards_[s] = getRookAttacksBitboard  (s); blackRayAttacks |= getURookMovesBitboard  (s); blackRayPastOneAttacks |= rookPastOneAttacks  (s); break;
            case QUEEN:  pieceAttacksBitboards_[s] = getQueenAttacksBitboard (s); blackRayAttacks |= getUQueenMovesBitboard (s); blackRayPastOneAttacks |= queenPastOneAttacks (s); break;
            case KING:   pieceAttacksBitboards_[s] = getKingAttacksBitboard  (s); break;
            }
            Bitboard::resetIsolatedLeastSignificantSetBit(tmpB);
        }
        cp++;
    }
    if (sideToMove == WHITETURN) { changeTurn(); }
}


Board_Bitboards::~Board_Bitboards() {}

const std::array<U64, 6>&         Board_Bitboards::arrWhitePieces       () const { return this->arrWhitePieces_;        }
const std::array<U64, 6>&         Board_Bitboards::arrBlackPieces       () const { return this->arrBlackPieces_;        }
const Turn&                       Board_Bitboards::turn                 () const { return this->turn_;                  }
const U64&                        Board_Bitboards::whiteBb              () const { return this->whiteBb_;               }
const U64&                        Board_Bitboards::blackBb              () const { return this->blackBb_;               }
const U64&                        Board_Bitboards::occupied             () const { return this->occupied_;              }
const U64&                        Board_Bitboards::empty                () const { return this->empty_;                 }
const std::array<U64, 64>&        Board_Bitboards::pieceAttacksBitboards() const { return this->pieceAttacksBitboards_; }
const std::array<ChessPiece, 64>& Board_Bitboards::pieceTypes           () const { return this->pieceTypes_;            }


std::array<U64, 6> Board_Bitboards::playingPiecesBb() {
    return this->turn_ == WHITETURN ? this->arrWhitePieces_ : this->arrWhitePieces_;
}
std::array<U64, 6> Board_Bitboards::waitingPiecesBb() {
    return this->turn_ == BLACKTURN ? this->arrWhitePieces_ : this->arrBlackPieces_;
}
U64 Board_Bitboards::playingBb() {
    return this->turn_ == WHITETURN ? this->whiteBb_ : this->blackBb_;
}
U64 Board_Bitboards::waitingBb() {
    return this->turn_ == BLACKTURN ? this->whiteBb_ : this->blackBb_;
}

U64 Board_Bitboards::waitingRayAttacks(){
    return this->turn_ == BLACKTURN ? this->whiteRayAttacks : this->blackRayAttacks;
}

// Rotations
U64 Board_Bitboards::flipVertical(U64 bitboard) {
    return  ((bitboard << 56)) |
        ((bitboard << 40) & Bitboard::rank7) |
        ((bitboard << 24) & Bitboard::rank6) |
        ((bitboard << 8)  & Bitboard::rank5) |
        ((bitboard >> 8)  & Bitboard::rank4) |
        ((bitboard >> 24) & Bitboard::rank3) |
        ((bitboard >> 40) & Bitboard::rank2) |
        ((bitboard >> 56));
}
U64 Board_Bitboards::flipDiagA1H8(U64 x) {
    U64 t;
    const U64 k1 = 0x5500550055005500;
    const U64 k2 = 0x3333000033330000;
    const U64 k4 = 0x0f0f0f0f00000000;
    t = k4 & (x ^ (x << 28));
    x ^= t ^ (t >> 28);
    t = k2 & (x ^ (x << 14));
    x ^= t ^ (t >> 14);
    t = k1 & (x ^ (x << 7));
    x ^= t ^ (t >> 7);
    return x;
}

U64 Board_Bitboards::rotationClockWise90    (U64 bitboard) {
    return this->flipVertical(flipDiagA1H8(bitboard));
}
U64 Board_Bitboards::rotationAntiClockWise90(U64 bitboard) {
    return this->flipDiagA1H8(this->flipVertical(bitboard));
}
U64 Board_Bitboards::rotation180            (U64 bitboard) {
    return this->rotationClockWise90(this->rotationClockWise90(bitboard));
}


U64 Board_Bitboards::southOne    (U64 bitboard) { return  bitboard >> 8; }
U64 Board_Bitboards::northOne    (U64 bitboard) { return  bitboard << 8; }
U64 Board_Bitboards::eastOne     (U64 bitboard) { return (bitboard & Bitboard::notHFile) << 1; }
U64 Board_Bitboards::northEastOne(U64 bitboard) { return (bitboard & Bitboard::notHFile) << 9; }
U64 Board_Bitboards::southEastOne(U64 bitboard) { return (bitboard & Bitboard::notHFile) >> 7; }
U64 Board_Bitboards::westOne     (U64 bitboard) { return (bitboard & Bitboard::notAFile) >> 1; }
U64 Board_Bitboards::southWestOne(U64 bitboard) { return (bitboard & Bitboard::notAFile) >> 9; }
U64 Board_Bitboards::northWestOne(U64 bitboard) { return (bitboard & Bitboard::notAFile) << 7; }

U64 Board_Bitboards::getUKnightMovesBitboard (SquareIndex square) {
    U64 movesBitboard = Bitboard::emptyBitboard;
    U64 posBitboard   = Bitboard::squareIndexToBitboard(square);
    U64 partialMove;
    
    partialMove    = westOne(posBitboard);
    movesBitboard |= northWestOne(partialMove) | southWestOne(partialMove);
    
    partialMove    = eastOne(posBitboard);
    movesBitboard |= northEastOne(partialMove) | southEastOne(partialMove);
    
    movesBitboard |= ((posBitboard >> 17) & Bitboard::notHFile) | ((posBitboard >> 15) & Bitboard::notAFile) | 
                     ((posBitboard << 17) & Bitboard::notAFile) | ((posBitboard << 15) & Bitboard::notHFile);

    return movesBitboard;
}
U64 Board_Bitboards::getUKnightsMovesBitboard(U64 bitboard) {
    if (!bitboard) { return bitboard; }

    U64 movesBitboard = Bitboard::emptyBitboard;
    U64 partialMove;

    partialMove       = westOne(bitboard);
    movesBitboard    |= northWestOne(partialMove) | southWestOne(partialMove);
    
    partialMove       = eastOne(bitboard);
    movesBitboard    |= northEastOne(partialMove) | southEastOne(partialMove);
    
    movesBitboard    |= ((bitboard >> 17) & Bitboard::notHFile) | ((bitboard >> 15) & Bitboard::notAFile) | 
                        ((bitboard << 17) & Bitboard::notAFile) | ((bitboard << 15) & Bitboard::notHFile);

    return movesBitboard;
}

U64 Board_Bitboards::getUKingMovesBitboard (SquareIndex square) {
    U64 movesBitboard = Bitboard::emptyBitboard;
    U64 posBitboard   = Bitboard::squareIndexToBitboard(square);
    
    movesBitboard |= westOne(posBitboard)  | eastOne(posBitboard);
    posBitboard   |= movesBitboard;
    movesBitboard |= northOne(posBitboard) | southOne(posBitboard);
    
    return movesBitboard;
}
U64 Board_Bitboards::getUKingsMovesBitboard(U64 bitboard) {
    U64 movesBitboard = Bitboard::emptyBitboard;
    
    movesBitboard    |= westOne(bitboard)  | eastOne(bitboard);
    bitboard         |= movesBitboard;
    movesBitboard    |= northOne(bitboard) | southOne(bitboard);

    return movesBitboard;
}

U64 Board_Bitboards::uRayNorth    (SquareIndex square) {
    U64 file = Bitboard::files[Bitboard::squareIndexToFileIndex(square)];
    return file >> (square + 1) << (square + 1) ;
}
U64 Board_Bitboards::uRaySouth    (SquareIndex square) {
    U64 file = Bitboard::files[Bitboard::squareIndexToFileIndex(square)];
    return file << (64 - square) >> (64 - square);
}
U64 Board_Bitboards::uRayEast     (SquareIndex square) {
    U64 rank = Bitboard::ranks[Bitboard::squareIndexToRankIndex(square)];
    return rank >> (square + 1) << (square + 1);
}
U64 Board_Bitboards::uRayWest     (SquareIndex square) {
    U64 rank = Bitboard::ranks[Bitboard::squareIndexToRankIndex(square)];
    return rank << (64 - square) >> (64 - square);
}
U64 Board_Bitboards::uRayNorthEast(SquareIndex square) {
    U64 diag = Bitboard::diags[Bitboard::squareIndexToDiagIndex(square)];
    return diag >> (square + 1) << (square + 1);

}
U64 Board_Bitboards::uRayNorthWest(SquareIndex square) {
    U64 antiDiag = Bitboard::antiDiags[Bitboard::squareIndexToAntiDiagIndex(square)];
    return antiDiag >> (square + 1) << (square + 1);
}
U64 Board_Bitboards::uRaySouthEast(SquareIndex square) {
    U64 antiDiag = Bitboard::antiDiags[Bitboard::squareIndexToAntiDiagIndex(square)];
    return antiDiag << (64 - square) >> (64 - square);
}
U64 Board_Bitboards::uRaySouthWest(SquareIndex square) {
    U64 diag = Bitboard::diags[Bitboard::squareIndexToDiagIndex(square)];
    return diag << (64 - square) >> (64 - square);
}

U64 Board_Bitboards::getURookMovesBitboard (SquareIndex square) {
    if (square > 64) { return Bitboard::universalBitboard; }

    U64 horizontal = Bitboard::ranks[Bitboard::squareIndexToRankIndex(square)]; // horizontal
    U64 vertical   = Bitboard::files[Bitboard::squareIndexToFileIndex(square)]; // vertical

    return (horizontal | vertical);
}
U64 Board_Bitboards::getURooksMovesBitboard(U64 bitboard) {
    if (!bitboard) { return bitboard; }

    U64 movesBitboard  = Bitboard::emptyBitboard;
    SquareIndex square;

    while (bitboard) {
        square         = Bitboard::getIndexOfLeastSignificantSetBit(bitboard);
        movesBitboard |= getURookMovesBitboard(square);
        Bitboard::resetIsolatedLeastSignificantSetBit(bitboard);
    }

    return movesBitboard;
}

U64 Board_Bitboards::getUBishopMovesBitboard(SquareIndex square) {
    U64 diag     = Bitboard::diags[Bitboard::squareIndexToDiagIndex(square)];
    U64 antiDiag = Bitboard::antiDiags[Bitboard::squareIndexToAntiDiagIndex(square)];

    return (diag | antiDiag);
}
U64 Board_Bitboards::getUBishopsMovesBitboard(U64 bb) {
    U64         movesBb = Bitboard::emptyBitboard;
    U64         diag;
    U64         antiDiag;
    SquareIndex square;
    while (bb) {
        square   = Bitboard::getIndexOfLeastSignificantSetBit(bb);
        diag     = Bitboard::diags[Bitboard::squareIndexToDiagIndex(square)];
        antiDiag = Bitboard::antiDiags[Bitboard::squareIndexToAntiDiagIndex(square)];
        movesBb |= diag | antiDiag;
        
        Bitboard::resetIsolatedLeastSignificantSetBit(bb);
    }
    return movesBb;
}

U64 Board_Bitboards::getUQueenMovesBitboard(SquareIndex square) {
    return getURookMovesBitboard(square) | getUBishopMovesBitboard(square);
}

U64 Board_Bitboards::getUPawnMovesBitboard(SquareIndex square, bool hasMoved, bool isWhite) {
    U64 movesBitboard = Bitboard::emptyBitboard;
    int direction     = isWhite ? 1 : -1; // this->turn_ == WHITETURN ? 1 : -1;

    //not checking if the pawn's movesBitboard outside of range // nvm it's useless

    Bitboard::setBitTo1(movesBitboard, square + 8 * direction);
    if (!hasMoved) {
        Bitboard::setBitTo1(movesBitboard, square + 16 * direction);
    }
    return movesBitboard;
}

U64 Board_Bitboards::getUPawnsMovesBitboard(U64 bb, bool hasMoved, bool isWhite)
{
    U64 movesBb;

    if (isWhite) { movesBb = northEastOne(bb) | northWestOne(bb); if (!hasMoved) { movesBb = northOne(bb); } } 
    else { movesBb = southEastOne(bb) | southWestOne(bb); if (!hasMoved) { movesBb = southOne(bb); } }
    
    return movesBb;
}



// attacks limited

U64 Board_Bitboards::rayNorth(SquareIndex square){
    U64 ray = Bitboard::emptyBitboard;
    U64 oneSquareRay = northOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces = waitingBb();
    U64 ownPieces = playingBb();

    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            break;
        }
        oneSquareRay = northOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::raySouth(SquareIndex square) {
    U64 ray = Bitboard::emptyBitboard;
    U64 oneSquareRay = southOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces = waitingBb();
    U64 ownPieces = playingBb();

    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            break;
        }
        oneSquareRay = southOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::rayEast(SquareIndex square) {
    U64 ray = Bitboard::emptyBitboard;
    U64 oneSquareRay = eastOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces = waitingBb();
    U64 ownPieces = playingBb();

    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            break;
        }
        oneSquareRay = eastOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::rayWest(SquareIndex square) {
    U64 ray = Bitboard::emptyBitboard;
    U64 oneSquareRay = westOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces = waitingBb();
    U64 ownPieces = playingBb();

    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            break;
        }
        oneSquareRay = westOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::rayNorthEast(SquareIndex square) {
    U64 ray = Bitboard::emptyBitboard;
    U64 oneSquareRay = northEastOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces = waitingBb();
    U64 ownPieces = playingBb();

    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            break;
        }
        oneSquareRay = northEastOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::rayNorthWest(SquareIndex square) {
    U64 ray = Bitboard::emptyBitboard;
    U64 oneSquareRay = northWestOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces = waitingBb();
    U64 ownPieces = playingBb();

    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            break;
        }
        oneSquareRay = northWestOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::raySouthEast(SquareIndex square) {
    U64 ray = Bitboard::emptyBitboard;
    U64 oneSquareRay = southEastOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces = waitingBb();
    U64 ownPieces = playingBb();

    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            break;
        }
        oneSquareRay = southEastOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::raySouthWest(SquareIndex square) {
    U64 ray = Bitboard::emptyBitboard;
    U64 oneSquareRay = southWestOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces = waitingBb();
    U64 ownPieces = playingBb();

    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            break;
        }
        oneSquareRay = southWestOne(oneSquareRay);
    }
    return ray;
}

U64 Board_Bitboards::getKingAttacksBitboard(SquareIndex square) {
    return waitingBb() & Bitboard::squareIndexToBitboard(square); // ????
}

U64 Board_Bitboards::getKnightAttacksBitboard(SquareIndex square) {
    U64 movesBitboard = getUKnightMovesBitboard(square);

    return movesBitboard & ~playingBb();
}

U64 Board_Bitboards::getBishopAttacksBitboard(SquareIndex square){
    U64 rayNE, rayNW, raySE, raySW;
    rayNE = rayNorthEast(square);
    rayNW = rayNorthWest(square);
    raySE = raySouthEast(square);
    raySW = raySouthWest(square);

    return rayNE | rayNW | raySE | raySW;
}

U64 Board_Bitboards::getRookAttacksBitboard(SquareIndex square) {
    U64 rayN, rayS, rayE, rayW;
    rayN = rayNorth(square);
    rayS = raySouth(square);
    rayE = rayEast (square);
    rayW = rayWest (square);

    return rayN | rayS | rayE | rayW;
}

U64 Board_Bitboards::getQueenAttacksBitboard(SquareIndex square) {
    return getBishopAttacksBitboard(square) | getRookAttacksBitboard(square);
}

U64 Board_Bitboards::getPawnAttacksBitboard(SquareIndex square) {
    U64 b = Bitboard::squareIndexToBitboard(square);
    if (this->turn_ == WHITETURN) {
        return (northEastOne(b) | northWestOne(b)) & ~this->whiteBb_;
    }
    return (southEastOne(b) | southWestOne(b)) & ~this->blackBb_;
}

// why is this here

void Board_Bitboards::changeBoard(std::array<U64, 6> wPNBRQK, std::array<U64, 6> bPNBRQK, Turn turn) {
    for (int i = 0; i < 6; ++i) {
        this->arrWhitePieces_[i] = wPNBRQK[i];
        this->arrBlackPieces_[i] = bPNBRQK[i];
    }


    this->whiteBb_ = wPNBRQK[PAWN] | wPNBRQK[KNIGHT] | wPNBRQK[BISHOP] | wPNBRQK[ROOK] | wPNBRQK[QUEEN] | wPNBRQK[KING];
    this->blackBb_ = bPNBRQK[PAWN] | bPNBRQK[KNIGHT] | bPNBRQK[BISHOP] | bPNBRQK[ROOK] | bPNBRQK[QUEEN] | bPNBRQK[KING];


    this->turn_ = turn;

    this->occupied_ = this->whiteBb_ | this->blackBb_;
    this->empty_ = ~this->occupied_;

    U64 tmpB;
    int s;
    int cp = 0;
    for (U64 b : this->arrWhitePieces_) { // same problem
        tmpB = b;
        s = Bitboard::getIndexOfLeastSignificantSetBit(tmpB);
        while (tmpB) {
            this->pieceTypes_[s] = static_cast<ChessPiece>(cp);
            switch (static_cast<ChessPiece>(cp)) {
            case PAWN:   this->pieceAttacksBitboards_[s] = getPawnAttacksBitboard(s);
            case ROOK:   this->pieceAttacksBitboards_[s] = getRookAttacksBitboard(s);
            case KNIGHT: this->pieceAttacksBitboards_[s] = getKnightAttacksBitboard(s);
            case BISHOP: this->pieceAttacksBitboards_[s] = getBishopAttacksBitboard(s);
            case QUEEN:  this->pieceAttacksBitboards_[s] = getQueenAttacksBitboard(s);
            case KING:   this->pieceAttacksBitboards_[s] = getKingAttacksBitboard(s);
            }
            Bitboard::resetIsolatedLeastSignificantSetBit(tmpB);
        }
        cp++;
    }
    cp = 0;
    for (U64 b : this->arrBlackPieces_) { // problem because of turn with moves
        tmpB = b;
        s = Bitboard::getIndexOfLeastSignificantSetBit(tmpB);
        while (tmpB) {
            this->pieceTypes_[s] = static_cast<ChessPiece>(cp);
            switch (static_cast<ChessPiece>(cp)) {
            case PAWN:   this->pieceAttacksBitboards_[s] = getPawnAttacksBitboard(s);
            case ROOK:   this->pieceAttacksBitboards_[s] = getRookAttacksBitboard(s);
            case KNIGHT: this->pieceAttacksBitboards_[s] = getKnightAttacksBitboard(s);
            case BISHOP: this->pieceAttacksBitboards_[s] = getBishopAttacksBitboard(s);
            case QUEEN:  this->pieceAttacksBitboards_[s] = getQueenAttacksBitboard(s);
            case KING:   this->pieceAttacksBitboards_[s] = getKingAttacksBitboard(s);
            }
            Bitboard::resetIsolatedLeastSignificantSetBit(tmpB);
        }
        cp++;
    }
}

Turn Board_Bitboards::changeTurn() {
    this->turn_ = !this->turn_;

    return this->turn();
}

// necessary for pinned pieces

U64 Board_Bitboards::rayNorthPastOne(SquareIndex square) {
    U64 ray          = Bitboard::emptyBitboard;
    U64 oneSquareRay = northOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces    = waitingBb();
    U64 ownPieces    = playingBb();

    int oppPieceEncountered = 0;
    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            oppPieceEncountered += 1;
        }
        if (oppPieceEncountered == 2) {
            break;
        }
        oneSquareRay = northOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::raySouthPastOne(SquareIndex square) {
    U64 ray          = Bitboard::emptyBitboard;
    U64 oneSquareRay = southOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces    = waitingBb();
    U64 ownPieces    = playingBb();

    int oppPieceEncountered = 0;
    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            oppPieceEncountered += 1;
        }
        if (oppPieceEncountered == 2) {
            break;
        }
        oneSquareRay = southOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::rayEastPastOne(SquareIndex square) {
    U64 ray          = Bitboard::emptyBitboard;
    U64 oneSquareRay = eastOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces    = waitingBb();
    U64 ownPieces    = playingBb();

    int oppPieceEncountered = 0;
    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            oppPieceEncountered += 1;
        }
        if (oppPieceEncountered == 2) {
            break;
        }
        oneSquareRay = eastOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::rayWestPastOne(SquareIndex square) {
    U64 ray          = Bitboard::emptyBitboard;
    U64 oneSquareRay = westOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces    = waitingBb();
    U64 ownPieces    = playingBb();

    int oppPieceEncountered = 0;
    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            oppPieceEncountered += 1;
        }
        if (oppPieceEncountered == 2) {
            break;
        }
        oneSquareRay = westOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::rayNorthEastPastOne(SquareIndex square) {
    U64 ray          = Bitboard::emptyBitboard;
    U64 oneSquareRay = northEastOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces    = waitingBb();
    U64 ownPieces    = playingBb();

    int oppPieceEncountered = 0;
    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            oppPieceEncountered += 1;
        }
        if (oppPieceEncountered == 2) {
            break;
        }
        oneSquareRay = northEastOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::rayNorthWestPastOne(SquareIndex square) {
    U64 ray          = Bitboard::emptyBitboard;
    U64 oneSquareRay = northWestOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces    = waitingBb();
    U64 ownPieces    = playingBb();

    int oppPieceEncountered = 0;
    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            oppPieceEncountered += 1;
        }
        if (oppPieceEncountered == 2) {
            break;
        }
        oneSquareRay = northWestOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::raySouthEastPastOne(SquareIndex square) {
    U64 ray          = Bitboard::emptyBitboard;
    U64 oneSquareRay = southEastOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces    = waitingBb();
    U64 ownPieces    = playingBb();

    int oppPieceEncountered = 0;
    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            oppPieceEncountered += 1;
        }
        if (oppPieceEncountered == 2) {
            break;
        }
        oneSquareRay = southEastOne(oneSquareRay);
    }
    return ray;
}
U64 Board_Bitboards::raySouthWestPastOne(SquareIndex square) {
    U64 ray          = Bitboard::emptyBitboard;
    U64 oneSquareRay = southWestOne(Bitboard::squareIndexToBitboard(square));
    U64 oppPieces    = waitingBb();
    U64 ownPieces    = playingBb();

    int oppPieceEncountered = 0;
    while (oneSquareRay & ~ownPieces && oneSquareRay) {
        ray |= oneSquareRay;
        if (oneSquareRay & oppPieces) {
            oppPieceEncountered += 1;
        }
        if (oppPieceEncountered == 2) {
            break;
        }
        oneSquareRay = southWestOne(oneSquareRay);
    }
    return ray;
}

U64 Board_Bitboards::bishopPastOneAttacks(SquareIndex square) {
    U64 rayNE, rayNW, raySE, raySW;
    rayNE = rayNorthEastPastOne(square);
    rayNW = rayNorthWestPastOne(square);
    raySE = raySouthEastPastOne(square);
    raySW = raySouthWestPastOne(square);

    return rayNE | rayNW | raySE | raySW;
}

U64 Board_Bitboards::rookPastOneAttacks(SquareIndex square) {
    U64 rayN, rayS, rayE, rayW;
    rayN = rayNorthPastOne(square);
    rayS = raySouthPastOne(square);
    rayE = rayEastPastOne (square);
    rayW = rayWestPastOne (square);

    return rayN | rayS | rayE | rayW;
}

U64 Board_Bitboards::queenPastOneAttacks(SquareIndex square) {
    return bishopPastOneAttacks(square) | rookPastOneAttacks(square);
}

// should work
bool Board_Bitboards::isInCheck() {
    return bool(this->waitingRayAttacks() & this->playingPiecesBb()[KING]);
}

// _
bool Board_Bitboards::isPinned() {
    return false;
}

U64 Board_Bitboards::knightMoves(SquareIndex square) {
    U64 moves      = Bitboard::emptyBitboard;
    U64 rayAttacks = waitingRayAttacks();
    bool check = this->isInCheck();
    /*if not in check then      | sudden (genius) idea: make ray attacks while removing 1 piece ahead or code other ray functions that go past 1 opponent piece !!!!
      if not pinned*/
    moves |= pieceAttacksBitboards_[square];
    return 0ULL;
}
