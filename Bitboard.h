#pragma once
#include<vector>

typedef unsigned char RankIndex;
typedef unsigned char FileIndex;
typedef unsigned char SquareIndex;
typedef unsigned char DiagIndex;
typedef unsigned long long U64;
typedef bool Bit;
typedef bool Turn;

// tkt
enum ChessPiece { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

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

    std::array<U64, 64> pieceAttacksBitboards_;
    std::array<ChessPiece, 64> pieceTypes_;

public:
    Board_Bitboards(std::array<U64, 6> wPBNRQK, std::array<U64, 6> bPBNRQK, Turn sideToMove); // Constructor
    ~Board_Bitboards(); // Destructor

    const std::array<U64, 6>& arrWhitePieces() const;
    const std::array<U64, 6>& arrBlackPieces() const;
    const Turn& turn    () const;
    const U64&  whiteBb () const;
    const U64&  blackBb () const;
    const U64&  occupied() const;
    const U64&  empty   () const;

    const std::array<U64, 64>&        pieceAttacksBitboards() const;
    const std::array<ChessPiece, 64>& pieceTypes           () const;

    // (side to move)'s
    std::array<U64, 6> playingPiecesBb();
    U64 playingBb();
    // (side that waits for its turn)'s
    std::array<U64, 6> waitingPiecesBb();
    U64 waitingBb();

    // Rotations
    // I think these will be useless
    U64 flipVertical(U64 bitboard);
    U64 flipDiagA1H8(U64 x);
    U64 rotation180(U64 bitboard);
    U64 rotationClockWise90(U64 bitboard);
    U64 rotationAntiClockWise90(U64 bitboard);
    

    // one square movements
    U64 southOne(U64 bitboard);
    U64 northOne(U64 bitboard);
    U64 eastOne(U64  bitboard);
    U64 northEastOne(U64 bitboard);
    U64 southEastOne(U64 bitboard);
    U64 westOne(U64 bitboard);
    U64 southWestOne(U64 bitboard);
    U64 northWestOne(U64 bitboard);

    // Unlimited moves functions

    /// @brief Gives the Unlimited Knight's moves indexes on the Bitboard. NOT Using knightOffsets.
    U64 getUKnightMovesBitboard(SquareIndex square);
    U64 getUKnightsMovesBitboard(U64 bitboard);

    /// @brief Gives the Unlimited King's moves indexes on the Bitboard. NOT Using kingOffsets. 
    U64 getUKingMovesBitboard(SquareIndex square);
    U64 getUKingsMovesBitboard(U64 bitboard);
    U64 getUQueenMovesBitboard(SquareIndex square);

    U64 uRookNorthRay(SquareIndex square);
    U64 uRookSouthRay(SquareIndex square);
    U64 uRookEastRay(SquareIndex square);
    U64 uRookWestRay (SquareIndex square);
    U64 getURookMovesBitboard(SquareIndex square);
    U64 getURooksMovesBitboard(U64 bitboard);
    
    U64 uBishopNorthEastRay(SquareIndex square);
    U64 uBishopNorthWestRay (SquareIndex square);
    U64 uBishopSouthEastRay(SquareIndex square);
    U64 uBishopSouthWestRay (SquareIndex square);
    U64 getUBishopMovesBitboard(SquareIndex square);
    U64 getUBishopsMovesBitboard(U64 bb);
    /// @brief Gives the Unlimited Pawn's moves indexes on the Bitboard. NOT including captures
    U64 getUPawnMovesBitboard(SquareIndex square, bool hasMoved, bool isWhite);
    U64 getUPawnsMovesBitboard(U64 bb, bool hasMoved, bool isWhite);


    bool isInCheck();
    bool isPinned();

    // moves that need to be checked by getLegalMoves(movesBitboard) to see if they are legal // not now, directly generating legal moves now using their attacks
    // https://peterellisjones.com/posts/generating-legal-chess-moves-efficiently/

    U64 getKingAttacksBitboard(SquareIndex square);
    U64 getKnightAttacksBitboard(SquareIndex square);

    U64 bishopNorthEastRay(SquareIndex square);
    U64 bishopNorthWestRay(SquareIndex square);
    U64 bishopSouthEastRay(SquareIndex square);
    U64 bishopSouthWestRay(SquareIndex square);
    U64 getBishopAttacksBitboard(SquareIndex square);

    U64 rookNorthRayAttack(SquareIndex square);
    U64 rookSouthRayAttack(SquareIndex square);
    U64 rookEastRayAttack(SquareIndex square);
    U64 rookWestRayAttack(SquareIndex square);
    U64 getRookAttacksBitboard(SquareIndex square);

    U64 getQueenAttacksBitboard(SquareIndex square);

    U64 getPawnAttacksBitboard(SquareIndex square);

    void changeBoard(std::array<U64, 6> wPNBRQK, std::array<U64, 6> bPNBRQK, Turn turn);
    Turn changeTurn();
};
