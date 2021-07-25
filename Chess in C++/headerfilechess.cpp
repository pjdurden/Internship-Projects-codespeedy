#include "headerfilechess.h"

// input multiple numbers from single line
// string input;
// getline(cin, input);
// istringstream is(input);
// int num;
// while(is>>num) nums.push_back(num);

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
// #pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)

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

ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x*(y/gcd(x,y)); }
ll modd(ll a){return (a%mod + mod)%mod;}
double findMod(double a, double b)
{
    double mods;
    if (a < 0)
        mods = -a;
    else
        mods =  a;
    if (b < 0)
        b = -b;    
    while (mods >= b)
        mods = mods - b;
    if (a < 0)
        return -mods;
    return mods;
}
ll add(ll a,ll b){return modd(modd(a)+modd(b));}
ll mul(ll a,ll b){return modd(modd(a)*modd(b));}
int smask(int i,int pos){ return (i|(1<<pos)); }
int clmask(int i,int pos){return (i&(~(1<<pos))) ; }
bool chmask(int i,int pos){return (i&(1<<pos))!=0 ;}
double cordist(pair<double,double> a,pair<double,double> b)
{return sqrt(sq(a.first-b.first)+sq(a.second-b.second));}

long long binpow(long long a, long long b) {
    if (b <= 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return mul(mul(res, res), a);
    else
        return mul(res,res);
}

Square::Square()
{
	piece = EMPTY;
	color = NONE;
}

void Square::comeSpace(Square* space)
{
	color = space->goColor();
	piece = space->goPiece();
}

void Square::comeEmpty()
{
	color = NONE;
	piece = EMPTY;
}

Piece Square::goPiece()
{
	return piece;
}

Color Square::goColor()
{
	return color;
}

void Square::comePieceAndColor(Piece p, Color c)
{
	piece = p;
	color = c;

}


void Board::printBoard() {
	using namespace std;
	cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 8; j++)
		{
			Piece p = square[i][j].goPiece();
			Color c = square[i][j].goColor();

			switch (p)
			{
			case KING: (c == WHITE) ? cout << " K " : cout << " k ";
				break;

			case QUEEN: (c == WHITE) ? cout << " Q " : cout << " q ";
				break;
			case BISHOP:(c == WHITE) ? cout << " B " : cout << " b ";
				break;

			case KNIGHT:(c == WHITE) ? cout << " H " : cout << " h ";
				break;
			case ROOK: (c == WHITE) ? cout << " R " : cout << " r ";
				break;
			case PAWN: (c == WHITE) ? cout << " P " : cout << " p ";

				break;
			case EMPTY: cout << " " << "\21" << " ";
				break;
			default: cout << "XXX";
				break;
			}

		}
		cout << endl;
	}

}

bool Board::doMove() {
	using namespace std;
	string turn;
	int x1, x2, y1, y2;
	bool stop = false;
	while (!stop)
	{
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your turn as a single four character string. Use x-coordinates first in each pair." << endl;
		cin >> turn;
		x1 = turn[0] - 48;
		y1 = turn[1] - 48;
		x2 = turn[2] - 48;
		y2 = turn[3] - 48;
		if (goSquare(x1, y1)->goColor() == turn)
		{


			if (makeMove(x1, y1, x2, y2) == false)
			{
				cout << "Invalid turn, try again." << endl;
			}
			else
				stop = true;
		}
		else
			cout << "That's not your piece. Try again." << endl;
	}
	if (goSquare(x2, y2)->goPiece() == KING)
		if (goSquare(x1, y1)->goColor() == WHITE)
		{
			cout << "WHITE WINS" << endl;
			return false;
		}
		else

		{
			cout << "BLACK WINS" << endl;
			return false;
		}


	if (turn == BLACK)
		turn = WHITE;
	else
		turn = BLACK;

	return true;

}

void Board::comeBoard()
{
	square[0][0].comePieceAndColor(ROOK, WHITE);
	square[1][0].comePieceAndColor(KNIGHT, WHITE);
	square[2][0].comePieceAndColor(BISHOP, WHITE);
	square[3][0].comePieceAndColor(QUEEN, WHITE);
	square[4][0].comePieceAndColor(KING, WHITE);
	square[5][0].comePieceAndColor(BISHOP, WHITE);
	square[6][0].comePieceAndColor(KNIGHT, WHITE);
	square[7][0].comePieceAndColor(ROOK, WHITE);

	square[0][7].comePieceAndColor(ROOK, BLACK);
	square[1][7].comePieceAndColor(KNIGHT, BLACK);
	square[2][7].comePieceAndColor(BISHOP, BLACK);
	square[3][7].comePieceAndColor(QUEEN, BLACK);
	square[4][7].comePieceAndColor(KING, BLACK);
	square[5][7].comePieceAndColor(BISHOP, BLACK);
	square[6][7].comePieceAndColor(KNIGHT, BLACK);
	square[7][7].comePieceAndColor(ROOK, BLACK);

	for (int i = 0; i < 8; i++)
	{
		square[i][1].comePieceAndColor(PAWN, WHITE);
		square[i][6].comePieceAndColor(PAWN, BLACK);

	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			square[j][i].comePieceAndColor(EMPTY, NONE);

	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			square[i][j].comeX(i);
			square[i][j].comeY(j);
		}

}

bool Board::playGame()
{
	system("cls");
	printBoard();
	return doMove();

}

bool Board::turnKing(Square* thisKing, Square* thatSpace) {
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	if (abs(thatSpace->goX() - thisKing->goX()) == 1)
		if (abs(thatSpace->goY() - thisKing->goY()) == 1)
		{
			thatSpace->comeSpace(thisKing);
			thisKing->comeEmpty();
			return true;
		}
		else return false;
	else return false;
}
bool Board::turnQueen(Square* thisQueen, Square* thatSpace) { //there might be problems with numbers of brackets
													   //off board inputs should be handled elsewhere (before this)
													   //squares with same color should be handled elsewhere (before this)

	int queenX = thisQueen->goX();
	int queenY = thisQueen->goY();
	int thatX = thatSpace->goX();
	int thatY = thatSpace->goY();
	std::cout << "this";
	int yIncrement;
	int xIncrement;

	bool invalid = false;
	if (queenX != thatX || queenY != thatY)
	{

		if (queenX == thatX)
		{
			yIncrement = (thatY - queenY) / (abs(thatY - queenY));
			for (int i = queenY + yIncrement; i != thatY; i += yIncrement)
			{

				if (square[thatX][i].goColor() != NONE)
					return false;

			}
		}
		else
			if (queenY == thatY)
			{

				xIncrement = (thatX - queenX) / (abs(thatX - queenX));
				for (int i = queenX + xIncrement; i != thatX; i += xIncrement)
				{
					if (square[i][thatY].goColor() != NONE)
						return false;
				}
			}
			else
				if (abs(queenX - thatX) == abs(queenY - thatY))
				{
					xIncrement = (thatX - queenX) / (abs(thatX - queenX));
					yIncrement = (thatY - queenY) / (abs(thatY - queenY));

					for (int i = 1; i < abs(queenX - thatX); i++)
					{
						std::cout << "It got here somehow";
						if (square[queenX + xIncrement*i][queenY + yIncrement*i].goColor() != NONE)
							return false;

					}
				}
				else
					return false;
		//if()
	}



	if (invalid == false)
	{
		thatSpace->comeSpace(thisQueen);
		thisQueen->comeEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::turnBishop(Square* thisBishop, Square* thatSpace) { //there might be problems with number of brackets
	int bishopX = thisBishop->goX();
	int bishopY = thisBishop->goY();
	int thatX = thatSpace->goX();
	int thatY = thatSpace->goY();
	bool invalid = false;
	Square *s;
	if (abs(bishopX - thatX) == abs(bishopY - thatY))
	{
		int xIncrement = (thatX - bishopX) / (abs(thatX - bishopX));
		int yIncrement = (thatY - bishopY) / (abs(thatY - bishopY));

		for (int i = 1; i < abs(bishopX - thatX); i++)
		{
			std::cout << "It got here somehow";
			if (square[bishopX + xIncrement*i][bishopY + yIncrement*i].goColor() != NONE)
				return false;

		}
	}
	else
		return false;

	if (invalid == false)
	{
		thatSpace->comeSpace(thisBishop);
		thisBishop->comeEmpty();
		return true;
	}
	else
	{
		return false;
	}
}
bool Board::turnKnight(Square* thisKnight, Square* thatSpace)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int knightX = thisKnight->goX();
	int knightY = thisKnight->goY();
	int thatX = thatSpace->goX();
	int thatY = thatSpace->goY();

	if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
	{
		thatSpace->comeSpace(thisKnight);
		thisKnight->comeEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::turnRook(Square* thisRook, Square* thatSpace)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int rookX = thisRook->goX();
	int rookY = thisRook->goY();
	int thatX = thatSpace->goX();
	int thatY = thatSpace->goY();
	bool invalid = false;
	if (rookX != thatX || rookY != thatY)
	{

		if (rookX == thatX)
		{
			int yIncrement = (thatY - rookY) / (abs(thatY - rookY));
			for (int i = rookY + yIncrement; i != thatY; i += yIncrement)
			{

				if (square[thatX][i].goColor() != NONE)
					return false;

			}
		}
		else
			if (rookY == thatY)
			{

				int xIncrement = (thatX - rookX) / (abs(thatX - rookX));
				for (int i = rookX + xIncrement; i != thatX; i += xIncrement)
				{
					if (square[i][thatY].goColor() != NONE)
						return false;
				}
			}
			else
				return false;
	}
	if (invalid == false)
	{
		thatSpace->comeSpace(thisRook);
		thisRook->comeEmpty();
		return true;
	}
	else
	{//Return some erorr or something. Probably return false;
		std::cout << "That is an invalid turn for rook";
		return false;
	}
}

bool Board::turnPawn(Square* thisPawn, Square* thatSpace) {
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	using namespace std;
	bool invalid = false;
	int pawnX = thisPawn->goX();
	int pawnY = thisPawn->goY();
	int thatX = thatSpace->goX();
	int thatY = thatSpace->goY();


	if (thisPawn->goColor() == WHITE)
	{

		if (pawnX == thatX && thatY == pawnY + 1 && thatSpace->goColor() == NONE)
		{
			thatSpace->comeSpace(thisPawn);
			thisPawn->comeEmpty();
			return true;
		}
		else
			if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY  && thatSpace->goColor() == BLACK)
			{
				thatSpace->comeSpace(thisPawn);
				thisPawn->comeEmpty();
				return true;
			}
			else
				return false;
	}
	else
		if (thisPawn->goColor() == BLACK)
		{
			if (pawnX == thatX && thatY == pawnY - 1 && thatSpace->goColor() == NONE)
			{
				thatSpace->comeSpace(thisPawn);
				thisPawn->comeEmpty();
				return true;
			}
			else
				if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY  && thatSpace->goColor() == WHITE)
				{
					thatSpace->comeSpace(thisPawn);
					thisPawn->comeEmpty();
					return true;
				}
				else
					return false;
		}
		else
			return false;
}
bool Board::makeMove(int x1, int y1, int x2, int y2) {
	//Checking for turns will be done previous to this
	using namespace std;
	if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>8)
	{
		std::cout << "One of your inputs was our of bounds" << std::endl;
		return false;
	}
	Square* src = goSquare(x1, y1);
	Square* dest = goSquare(x2, y2);

	if (src->goColor() == dest->goColor() && dest->goColor() != NONE)
	{
		std::cout << "Invalid turn: cannot land on your own piece" << std::endl;
		return false;
	}

	switch (src->goPiece())
	{
	case KING: return turnKing(src, dest);
		break;
	case QUEEN: return turnQueen(src, dest);
		break;
	case BISHOP: return turnBishop(src, dest);
		break;
	case KNIGHT: return turnKnight(src, dest);
		break;
	case ROOK: return turnRook(src, dest);
		break;
	case PAWN: return turnPawn(src, dest);
		break;
	case EMPTY: std::cout << "You do not have a piece there" << std::endl;  return false;
		break;
	default: std::cerr << "Something went wrong in the switch statement in makeMove()" << std::endl;
		break;
	}
	return false;
}
