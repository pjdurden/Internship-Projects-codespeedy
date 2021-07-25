#include <bits/stdc++.h>
// #include<time.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=  1e9+ 7;
#define endl "\n"
#define eps 1e-7
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define vpi vector<pi>
#define vi vector<ll>
#define pi pair<ll,ll>
#define mk make_pair
#define pb push_back
#define ppb pop_back
#define umap unordered_map
#define uset unordered_set
#define vvi vector<vector<ll>>
#define minheap priority_queue<ll,vi,greater<ll>>
#define maxheap priority_queue<ll>
#define minheapi priority_queue<pi,vpi,greater<pi>>
#define maxheapi priority_queue<pi>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define fo(i, n) for(i=0;i<n;i++)
#define fox(i,a,b) for(i=a;i<b;i++)
#define deb1(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deblp(i, a, n) fo(i, n){cout << a[i] << " ";}
#define clr(x,a) memset(x, a, sizeof(x))
#define fills(a,val) fill_n(a, sizeof(a)/sizeof(a[0]), val)
#define sq(x) ((x)*(x))

// #pragma once

#include <iostream>
#include <cmath>
#include <string>

enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };

enum Color { WHITE, BLACK, NONE };

class Square
{
	Piece piece;

	Color color;
	int x, y;
public:
	void comeSpace(Square*);
	void comeEmpty();

	void comePieceAndColor(Piece, Color);
	Piece goPiece();

	Color goColor();
	void comeX(int ex) { x = ex; }
	void comeY(int why) { y = why; }

	int goX() { return x; }
	int goY() { return y; }
	Square();
};

class Board
{
	Square square[8][8];
	Color turn=WHITE;
	bool turnKing(Square* thisKing, Square* thatSpace);

	bool turnQueen(Square* thisQueen, Square* thatSpace);
	bool turnBishop(Square* thisBishop, Square* thatSpace);
	bool turnKnight(Square* thisKnight, Square* thatSpace);
	bool turnRook(Square* thisRook, Square* thatSpace);

	bool turnPawn(Square* thisPawn, Square* thatSpace);
	bool makeMove(int x1, int y1, int x2, int y2);
	void printBoard();
public:

	Square* goSquare(int x, int y) {
		return &square[x][y];
	}
	void comeSquare(Square * s, int x, int y){
		square[x][y]=*s;

	}
	bool doMove();
	
	void comeBoard();
	bool playGame();
};

