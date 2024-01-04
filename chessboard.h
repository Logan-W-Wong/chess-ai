/*
 * Author: Logan Wong
 * Date started: 12/30/2023
 * Last Modified: 12/30/2023
 */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// 64 bit word
typedef unsigned long QWORD;
// 64 bit bitboard
typedef QWORD bitboard;

// Holds all pieces on the chessboard
typedef struct ChessBoard
{
    bitboard white;
    bitboard black;
    bitboard pawns;
    bitboard knights;
    bitboard bishops;
    bitboard rooks;
    bitboard queens;
    bitboard kings;
} Board, *BoardPointer;

/*function prototypes*/

Board setBoard();

bitboard getEmpty(Board);

bitboard getOccupied(Board);

void printBoard(bitboard);

#endif