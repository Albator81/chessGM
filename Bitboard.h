#pragma once
#include<vector>

typedef unsigned char RankIndex;
typedef unsigned char FileIndex;
typedef unsigned char SquareIndex;
typedef unsigned char DiagIndex;
typedef unsigned long long U64;
typedef bool Bit;
typedef bool Turn;

// yeah now there are 7 types of pieces in chess, including empty square !
enum ChessPiece { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, EMPTYSQUARE };

const Turn WHITETURN = true;
const Turn BLACKTURN = false;



// Other Bitboards
namespace Bitboard {
    extern const U64 emptyBitboard;
    extern const U64 universalBitboard;

    extern const U64 notAFile;
    extern const U64 notHFile;
    extern const U64 fileA;
    extern const U64 fileB;
    extern const U64 fileC;
    extern const U64 fileD;
    extern const U64 fileE;
    extern const U64 fileF;
    extern const U64 fileG;
    extern const U64 fileH;

    extern const U64 rank1;
    extern const U64 rank2;
    extern const U64 rank3;
    extern const U64 rank4;
    extern const U64 rank5;
    extern const U64 rank6;
    extern const U64 rank7;
    extern const U64 rank8;

    extern const std::array<U64, 8> ranks;
    extern const std::array<U64, 8> files;

    extern const U64 diag0;
    extern const U64 diag1;
    extern const U64 diag2;
    extern const U64 diag3;
    extern const U64 diag4;
    extern const U64 diag5;
    extern const U64 diag6;
    extern const U64 diag7;
    extern const U64 diag8;
    extern const U64 diag9;
    extern const U64 diag10;
    extern const U64 diag11;
    extern const U64 diag12;
    extern const U64 diag13;
    extern const U64 diag14;
    extern const U64 diag15;

    extern const std::array<U64, 16> diags;

    extern const U64 antiDiag0;
    extern const U64 antiDiag1;
    extern const U64 antiDiag2;
    extern const U64 antiDiag3;
    extern const U64 antiDiag4;
    extern const U64 antiDiag5;
    extern const U64 antiDiag6;
    extern const U64 antiDiag7;
    extern const U64 antiDiag8;
    extern const U64 antiDiag9;
    extern const U64 antiDiag10;
    extern const U64 antiDiag11;
    extern const U64 antiDiag12;
    extern const U64 antiDiag13;
    extern const U64 antiDiag14;
    extern const U64 antiDiag15;

    extern const std::array<U64, 16> antiDiags;

    SquareIndex fileRankIndexToSquareIndex(FileIndex file, RankIndex rank); // thiss
    FileIndex squareIndexToFileIndex(SquareIndex square);
    RankIndex squareIndexToRankIndex(SquareIndex square);
    DiagIndex squareIndexToDiagIndex(SquareIndex square);
    DiagIndex squareIndexToAntiDiagIndex(SquareIndex square);

    void clearBitboard(U64& bitboard);

    void setBitTo1(U64& bitboard, SquareIndex square);
    Bit getBitValue(U64 bitboard, SquareIndex square);

    U64 squareIndexToBitboard(SquareIndex square);

    U64 getIsolatedLeastSignificantSetBit(U64 bitboard);
    U64 getIsolatedMostSignificantSetBit(U64 bitboard);

    SquareIndex getIndexOfLeastSignificantSetBit(U64 bitboard);

    void resetIsolatedLeastSignificantSetBit(U64& bitboard);
    void resetIsolatedMostSignificantSetBit(U64& v);
    int bitCount(U64 bb);
    std::vector<SquareIndex> getSetBitsPositions(U64 b);

    // visualize
    void visualizeBitboard(U64 bitboard);
}


/// <summary>
/// It's the bitboards required to make the board.
/// This is gettings worse
/// </summary>
class Board_Bitboards {
private:
    std::array<U64, 6> arrWhitePieces_;
    std::array<U64, 6> arrBlackPieces_;

    Turn turn_;
    U64  whiteBb_;
    U64  blackBb_;
    U64  occupied_;
    U64  empty_;

    std::array<ChessPiece, 64> pieceTypes_;
    std::array<U64, 64>        pieceAttacksBitboards_;

    // THINGS I NEED TO MAKE LEGAL MOVES FASTER
    U64 whiteRayAttacks;
    U64 blackRayAttacks;
    U64 whiteRayPastOneAttacks;
    U64 blackRayPastOneAttacks;

public:
    Board_Bitboards(std::array<U64, 6> wPBNRQK, std::array<U64, 6> bPBNRQK, Turn sideToMove); // Constructor
    ~Board_Bitboards(); // Destructor

    const std::array<U64, 6>&         arrWhitePieces       () const;
    const std::array<U64, 6>&         arrBlackPieces       () const;
    const Turn&                       turn                 () const;
    const U64&                        whiteBb              () const;
    const U64&                        blackBb              () const;
    const U64&                        occupied             () const;
    const U64&                        empty                () const;
    const std::array<U64, 64>&        pieceAttacksBitboards() const;
    const std::array<ChessPiece, 64>& pieceTypes           () const;

    // (side to move)'s
    std::array<U64, 6> playingPiecesBb();
    U64 playingBb();
    // (side that waits for its turn)'s
    std::array<U64, 6> waitingPiecesBb();
    U64 waitingBb();

    U64 waitingRayAttacks();

    // Rotations
    // I think these will be useless
    U64 flipVertical(U64 bitboard);
    U64 flipDiagA1H8(U64 x);
    U64 rotation180(U64 bitboard);
    U64 rotationClockWise90(U64 bitboard);
    U64 rotationAntiClockWise90(U64 bitboard);
    

    // one square movements
    U64 northOne    (U64 bitboard);
    U64 southOne    (U64 bitboard);
    U64 eastOne     (U64 bitboard);
    U64 westOne     (U64 bitboard);
    U64 northEastOne(U64 bitboard);
    U64 northWestOne(U64 bitboard);
    U64 southEastOne(U64 bitboard);
    U64 southWestOne(U64 bitboard);

    // Unlimited moves functions

    U64 uRayNorth    (SquareIndex square);
    U64 uRaySouth    (SquareIndex square);
    U64 uRayEast     (SquareIndex square);
    U64 uRayWest     (SquareIndex square);
    U64 uRayNorthEast(SquareIndex square);
    U64 uRayNorthWest(SquareIndex square);
    U64 uRaySouthEast(SquareIndex square);
    U64 uRaySouthWest(SquareIndex square);

    U64 getUKnightMovesBitboard (SquareIndex square);
    U64 getUKnightsMovesBitboard(U64 bitboard);

    U64 getUKingMovesBitboard (SquareIndex square);
    U64 getUKingsMovesBitboard(U64 bitboard);

    U64 getURookMovesBitboard(SquareIndex square);
    U64 getURooksMovesBitboard(U64 bitboard);
    
    U64 getUBishopMovesBitboard(SquareIndex square);
    U64 getUBishopsMovesBitboard(U64 bb);

    U64 getUQueenMovesBitboard(SquareIndex square);

    /// @brief Gives the Unlimited Pawn's moves indexes on the Bitboard. NOT including captures
    U64 getUPawnMovesBitboard(SquareIndex square, bool hasMoved, bool isWhite);
    U64 getUPawnsMovesBitboard(U64 bb, bool hasMoved, bool isWhite);


    // https://peterellisjones.com/posts/generating-legal-chess-moves-efficiently/

    // attacks, limited by pieces on squares

    U64 rayNorth    (SquareIndex square);
    U64 raySouth    (SquareIndex square);
    U64 rayEast     (SquareIndex square);
    U64 rayWest     (SquareIndex square);
    U64 rayNorthEast(SquareIndex square);
    U64 rayNorthWest(SquareIndex square);
    U64 raySouthEast(SquareIndex square);
    U64 raySouthWest(SquareIndex square);

    U64 getKingAttacksBitboard(SquareIndex square);
    U64 getKnightAttacksBitboard(SquareIndex square);

    U64 getBishopAttacksBitboard(SquareIndex square);

    U64 getRookAttacksBitboard(SquareIndex square);

    U64 getQueenAttacksBitboard(SquareIndex square);

    U64 getPawnAttacksBitboard(SquareIndex square);

    void changeBoard(std::array<U64, 6> wPNBRQK, std::array<U64, 6> bPNBRQK, Turn turn);
    Turn changeTurn();

// pinned pieces necessary functions

    U64 rayNorthPastOne    (SquareIndex square);
    U64 raySouthPastOne    (SquareIndex square);
    U64 rayEastPastOne     (SquareIndex square);
    U64 rayWestPastOne     (SquareIndex square);
    U64 rayNorthEastPastOne(SquareIndex square);
    U64 rayNorthWestPastOne(SquareIndex square);
    U64 raySouthEastPastOne(SquareIndex square);
    U64 raySouthWestPastOne(SquareIndex square);

    U64 bishopPastOneAttacks(SquareIndex square);
    U64 rookPastOneAttacks(SquareIndex square);
    U64 queenPastOneAttacks(SquareIndex square);

    bool isPinned();

    bool isInCheck();

    // FINALLY DOING LEGAL MOVES
    U64 knightMoves(SquareIndex square);
};
