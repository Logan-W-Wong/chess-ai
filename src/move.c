/*
 * Author: Logan Wong
 * Date started: 12/30/2023
 * Last Modified: 1/3/2024
 * Purpose: Holds int representation of a Move and its functions
 */

int encodeMove(int to, int from, int flags)
{
    int move = ((flags & 0xf) << 12) | ((from & 0x3f) << 6) | (to & 0x3f);
    return move;
}
int getTo(int move)
{
    return move & 0x3f;
}

int getFrom(int move)
{
    return (move >> 6) & 0x3f;
}

int getFlags(int move)
{
    return (move >> 12) & 0xf;
}