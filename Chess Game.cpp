# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;
void start();
void game1();
void game2();
void position(int row, int col, char ch, char chessBoard[8][8], int turn, int positions[][2]);
void displayPosition(char chessBoard[8][8]);
void boundaryCheck(int nextRow, int nextCol, int positions[][2], int& count, char chessBoard[8][8], int turn);
bool rookCollision(int row1, int  col1, int  row2, int  col2, char chessBoard[8][8]);
bool checkKing(int row, int col, char ch, char chessBoard[8][8], int turn, int positions[][2]);

int main()
{
	start();
	return 0;
}
void start()
{
	int choice;
	cout << "1) Your next move.\n2) Save the King (2 players game)\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		game1();
		break;
	case 2:
		game2();
		break;
	default:
		cout << "Invalid input.";
	}

}


void game1() 
{
	bool exit = false;
	int row, col;
	char ch;
	int turn = 0;
	char chessBoard[8][8] = {};
	int positions[50][2] = {};
	while(exit==false)
	{
		cout << "\n'K' or 'k' for King\n'Q' or 'q' for Queen\n'B' or 'b' for Bishop\n'R' or 'r' for Rook\n'N' or 'n' for Knight\n'E' or 'e' for Exit menu.\n";
		cin >> ch;
		if (ch == 'E' || ch == 'e')
			exit = true;
		else
		{
			cout << "Enter initial position. (row, column).\n";
			cin >> row;
			cin >> col;
			chessBoard[row - 1][col - 1] = ch;
			// Display the existing position
			cout << "Existing position: " << col << " " << row << endl;
			position(row, col, ch, chessBoard, turn, positions);
			displayPosition(chessBoard);
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					chessBoard[i][j] = 0;
		}
	}
}


void position(int row, int col, char ch, char chessBoard[8][8], int turn, int positions[][2])
{
	int count = 0;
	switch (ch)
	{
	case 'K': case 'k': // king
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0)
					continue;
				int nextRow = row + i;
				int nextCol = col + j;
				boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
			}
		}
		break;
	case 'Q': case 'q': // queen
		for (int i = 1; i <= 8; i++)
		{
			if (i != row)
			{
				if (turn == 1)
				{
					if ((chessBoard[i - 1][col - 1] != 'k') && (chessBoard[i - 1][col - 1] != 'K') && (chessBoard[i - 1][col - 1] != 'Q') && (chessBoard[i - 1][col - 1] != 'B') && (chessBoard[i - 1][col - 1] != 'N') && (chessBoard[i - 1][col - 1] != 'R') && (chessBoard[i - 1][col - 1] != 'S') && (chessBoard[i - 1][col - 1] != 'T') && (chessBoard[i - 1][col - 1] != 'O'))
					{
						positions[count][0] = i;
						positions[count][1] = col;
					}
				}
				else if (turn == 2)
				{
					if ((chessBoard[i - 1][col - 1] != 'k') && (chessBoard[i - 1][col - 1] != 'q') && (chessBoard[i - 1][col - 1] != 'b') && (chessBoard[i - 1][col - 1] != 'n') && (chessBoard[i - 1][col - 1] != 'r') && (chessBoard[i - 1][col - 1] != 's') && (chessBoard[i - 1][col - 1] != 't') && (chessBoard[i - 1][col - 1] != 'o') && (chessBoard[i - 1][col - 1] != 'K'))
					{
						positions[count][0] = i;
						positions[count][1] = col;
					}
				}
				else
				{
					if ((chessBoard[i - 1][col - 1] != 'k') && (chessBoard[i - 1][col - 1] != 'q') && (chessBoard[i - 1][col - 1] != 'b') && (chessBoard[i - 1][col - 1] != 'n') && (chessBoard[i - 1][col - 1] != 'r' && (chessBoard[i - 1][col - 1] != 's') && (chessBoard[i - 1][col - 1] != 't') && (chessBoard[i - 1][col - 1] != 'o')) && (chessBoard[i - 1][col - 1] != 'K') && (chessBoard[i - 1][col - 1] != 'Q') && (chessBoard[i - 1][col - 1] != 'B') && (chessBoard[i - 1][col - 1] != 'N') && (chessBoard[i - 1][col - 1] != 'R') && (chessBoard[i - 1][col - 1] != 'S') && (chessBoard[i - 1][col - 1] != 'T') && (chessBoard[i - 1][col - 1] != 'O'))
					{
						positions[count][0] = i;
						positions[count][1] = col;
					}
				}
				//collision detection
			//	rookCollision(row, col, i, col, chessBoard);
				if (chessBoard[i - 1][col - 1] == 0)
					chessBoard[i - 1][col - 1] = 'x';
				count++;
			}
			if (i != col)
			{
				if (turn == 1)
				{
					if ((chessBoard[row - 1][i - 1] != 'k') && (chessBoard[row - 1][i - 1] != 'K') && (chessBoard[row - 1][i - 1] != 'Q') && (chessBoard[row - 1][i - 1] != 'B') && (chessBoard[row - 1][i - 1] != 'N') && (chessBoard[row - 1][i - 1] != 'R') && (chessBoard[row - 1][i - 1] != 'S') && (chessBoard[row - 1][i - 1] != 'T') && (chessBoard[row - 1][i - 1] != 'O'))
					{
						positions[count][0] = row;
						positions[count][1] = i;
					}
				}
				else if (turn == 2)
				{
					if ((chessBoard[row - 1][i - 1] != 'k') && (chessBoard[row - 1][i - 1] != 'q') && (chessBoard[row - 1][i - 1] != 'b') && (chessBoard[row - 1][i - 1] != 'n') && (chessBoard[row - 1][i - 1] != 'r') && (chessBoard[row - 1][i - 1] != 's') && (chessBoard[row - 1][i - 1] != 't') && (chessBoard[row - 1][i - 1] != 'o') && (chessBoard[row - 1][i - 1] != 'K'))
					{
						positions[count][0] = row;
						positions[count][1] = i;
					}
				}
				else
				{
					if ((chessBoard[row - 1][i - 1] != 'k') && (chessBoard[row - 1][i - 1] != 'q') && (chessBoard[row - 1][i - 1] != 'b') && (chessBoard[row - 1][i - 1] != 'n') && (chessBoard[row - 1][i - 1] != 'r') && (chessBoard[row - 1][i - 1] != 's') && (chessBoard[row - 1][i - 1] != 't') && (chessBoard[row - 1][i - 1] != 'o') && (chessBoard[row - 1][i - 1] != 'K') && (chessBoard[row - 1][i - 1] != 'Q') && (chessBoard[row - 1][i - 1] != 'B') && (chessBoard[row - 1][i - 1] != 'N') && (chessBoard[row - 1][i - 1] != 'R') && (chessBoard[row - 1][i - 1] != 'S') && (chessBoard[row - 1][i - 1] != 'T') && (chessBoard[row - 1][i - 1] != 'O'))
					{
						positions[count][0] = row;
						positions[count][1] = i;
					}
				}
				if (chessBoard[row - 1][i - 1] == 0)
					chessBoard[row - 1][i - 1] = 'x';
				count++;
			}
		}
		// Diagonal moves
		for (int i = -7; i <= 7; i++)
		{
			if (i == 0) continue;
			int nextRow1 = row + i;
			int nextCol1 = col + i;
			int nextRow2 = row - i;
			int nextCol2 = col + i;
			boundaryCheck(nextRow1, nextCol1, positions, count, chessBoard, turn);
			boundaryCheck(nextRow2, nextCol2, positions, count, chessBoard, turn);
		}
		break;
	case 'b': case 'B': case 's': case 'S': // bishop
		for (int i = -7; i <= 7; i++)
		{
			if (i == 0)
				continue;
			int nextRow1 = row + i;
			int nextCol1 = col + i;
			int nextRow2 = row - i;
			int nextCol2 = col + i;
			boundaryCheck(nextRow1, nextCol1, positions, count, chessBoard, turn);
			boundaryCheck(nextRow2, nextCol2, positions, count, chessBoard, turn);
		}
		break;
	case 'R': case 'r': case 'o': case 'O': // rook
		for (int i = 1; i <= 8; i++)
		{
			if (i != row)
			{
				if (turn == 1)
				{
					if ((chessBoard[i - 1][col - 1] != 'k') && (chessBoard[i - 1][col - 1] != 'K') && (chessBoard[i - 1][col - 1] != 'Q') && (chessBoard[i - 1][col - 1] != 'B') && (chessBoard[i - 1][col - 1] != 'N') && (chessBoard[i - 1][col - 1] != 'R') && (chessBoard[i - 1][col - 1] != 'S') && (chessBoard[i - 1][col - 1] != 'T') && (chessBoard[i - 1][col - 1] != 'O'))
					{
						positions[count][0] = i;
						positions[count][1] = col;
					}
				}
				else if (turn == 2)
				{
					if ((chessBoard[i - 1][col - 1] != 'k') && (chessBoard[i - 1][col - 1] != 'q') && (chessBoard[i - 1][col - 1] != 'b') && (chessBoard[i - 1][col - 1] != 'n') && (chessBoard[i - 1][col - 1] != 'r') && (chessBoard[i - 1][col - 1] != 's') && (chessBoard[i - 1][col - 1] != 't') && (chessBoard[i - 1][col - 1] != 'o') && (chessBoard[i - 1][col - 1] != 'K'))
					{
						positions[count][0] = i;
						positions[count][1] = col;
					}
				}
				else
				{
					if ((chessBoard[i - 1][col - 1] != 'k') && (chessBoard[i - 1][col - 1] != 'q') && (chessBoard[i - 1][col - 1] != 'b') && (chessBoard[i - 1][col - 1] != 'n') && (chessBoard[i - 1][col - 1] != 'r' && (chessBoard[i - 1][col - 1] != 's') && (chessBoard[i - 1][col - 1] != 't') && (chessBoard[i - 1][col - 1] != 'o')) && (chessBoard[i - 1][col - 1] != 'K') && (chessBoard[i - 1][col - 1] != 'Q') && (chessBoard[i - 1][col - 1] != 'B') && (chessBoard[i - 1][col - 1] != 'N') && (chessBoard[i - 1][col - 1] != 'R') && (chessBoard[i - 1][col - 1] != 'S') && (chessBoard[i - 1][col - 1] != 'T') && (chessBoard[i - 1][col - 1] != 'O'))
					{
						positions[count][0] = i;
						positions[count][1] = col;
					}
				}
				//collision detection
			//	rookCollision(row, col, i, col, chessBoard);
				if (chessBoard[i - 1][col - 1] == 0)
					chessBoard[i - 1][col - 1] = 'x';
				count++;
			}
			if (i != col)
			{
				if (turn == 1)
				{
					if ((chessBoard[row - 1][i - 1] != 'k') && (chessBoard[row - 1][i - 1] != 'K') && (chessBoard[row - 1][i - 1] != 'Q') && (chessBoard[row - 1][i - 1] != 'B') && (chessBoard[row - 1][i - 1] != 'N') && (chessBoard[row - 1][i - 1] != 'R') && (chessBoard[row - 1][i - 1] != 'S') && (chessBoard[row - 1][i - 1] != 'T') && (chessBoard[row - 1][i - 1] != 'O'))
					{
						positions[count][0] = row;
						positions[count][1] = i;
					}
				}
				else if (turn == 2)
				{
					if ((chessBoard[row - 1][i - 1] != 'k') && (chessBoard[row - 1][i - 1] != 'q') && (chessBoard[row - 1][i - 1] != 'b') && (chessBoard[row - 1][i - 1] != 'n') && (chessBoard[row - 1][i - 1] != 'r') && (chessBoard[row - 1][i - 1] != 's') && (chessBoard[row - 1][i - 1] != 't') && (chessBoard[row - 1][i - 1] != 'o') && (chessBoard[row - 1][i - 1] != 'K'))
					{
						positions[count][0] = row;
						positions[count][1] = i;
					}
				}
				else
				{
					if ((chessBoard[row - 1][i - 1] != 'k') && (chessBoard[row - 1][i - 1] != 'q') && (chessBoard[row - 1][i - 1] != 'b') && (chessBoard[row - 1][i - 1] != 'n') && (chessBoard[row - 1][i - 1] != 'r') && (chessBoard[row - 1][i - 1] != 's') && (chessBoard[row - 1][i - 1] != 't') && (chessBoard[row - 1][i - 1] != 'o') && (chessBoard[row - 1][i - 1] != 'K') && (chessBoard[row - 1][i - 1] != 'Q') && (chessBoard[row - 1][i - 1] != 'B') && (chessBoard[row - 1][i - 1] != 'N') && (chessBoard[row - 1][i - 1] != 'R') && (chessBoard[row - 1][i - 1] != 'S') && (chessBoard[row - 1][i - 1] != 'T') && (chessBoard[row - 1][i - 1] != 'O'))
					{
						positions[count][0] = row;
						positions[count][1] = i;
					}
				}
				if (chessBoard[row - 1][i - 1] == 0)
					chessBoard[row - 1][i - 1] = 'x';
				count++;
			}
		}
		break;
	case 'N': case 'n': case 't': case 'T': // knight
		int nextRow, nextCol;
		nextRow = row - 1; nextCol = col - 2;
		boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
		nextRow = row - 2; nextCol = col - 1;
		boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
		nextRow = row - 2; nextCol = col + 1;
		boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
		nextRow = row - 1; nextCol = col + 2;
		boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
		nextRow = row + 1; nextCol = col + 2;
		boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
		nextRow = row + 2; nextCol = col + 1;
		boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
		nextRow = row + 2; nextCol = col - 1;
		boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
		nextRow = row + 1; nextCol = col - 2;
		boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
		break;
	default:
		cout << "Invalid input.\n";
	}
	// Display the next positions
	cout << "Next positions: ";
	for (int i = 0; i < count; i++)
	{
		if (positions[i][0] != 0 && positions[i][1] != 0)
		{
			cout << "[" << positions[i][0] << " " << positions[i][1] << "]";
			if (i != count - 1)
			{
				cout << ",";
			}
		}
	}
}

void boundaryCheck(int nextRow, int nextCol, int positions[][2], int& count, char chessBoard[8][8], int turn)
{
	if (nextRow >= 1 && nextRow <= 8 && nextCol >= 1 && nextCol <= 8) 
	{
		if (turn == 1)
		{
			if ((chessBoard[nextRow - 1][nextCol - 1] != 'k') && (chessBoard[nextRow - 1][nextCol - 1] != 'K') && (chessBoard[nextRow - 1][nextCol - 1] != 'Q') && (chessBoard[nextRow - 1][nextCol - 1] != 'B') && (chessBoard[nextRow - 1][nextCol - 1] != 'N') && (chessBoard[nextRow - 1][nextCol - 1] != 'R') && (chessBoard[nextRow - 1][nextCol - 1] != 'S') && (chessBoard[nextRow - 1][nextCol - 1] != 'T') && (chessBoard[nextRow - 1][nextCol - 1] != 'O'))
			{
				positions[count][0] = nextRow;
				positions[count][1] = nextCol;
			}
		}
		else if (turn == 2)
		{
			if ((chessBoard[nextRow - 1][nextCol - 1] != 'k') && (chessBoard[nextRow - 1][nextCol - 1] != 'q') && (chessBoard[nextRow - 1][nextCol - 1] != 'b') && (chessBoard[nextRow - 1][nextCol - 1] != 'n') && (chessBoard[nextRow - 1][nextCol - 1] != 'r') && (chessBoard[nextRow - 1][nextCol - 1] != 's') && (chessBoard[nextRow - 1][nextCol - 1] != 't') && (chessBoard[nextRow - 1][nextCol - 1] != 'o') && (chessBoard[nextRow - 1][nextCol - 1] != 'K'))
			{
				positions[count][0] = nextRow;
				positions[count][1] = nextCol;
			}
		}
		else
		{
			if ((chessBoard[nextRow - 1][nextCol - 1] != 'k') && (chessBoard[nextRow - 1][nextCol - 1] != 'q') && (chessBoard[nextRow - 1][nextCol - 1] != 'b') && (chessBoard[nextRow - 1][nextCol - 1] != 'n') && (chessBoard[nextRow - 1][nextCol - 1] != 'r') && (chessBoard[nextRow - 1][nextCol - 1] != 's') && (chessBoard[nextRow - 1][nextCol - 1] != 't') && (chessBoard[nextRow - 1][nextCol - 1] != 'o') && (chessBoard[nextRow - 1][nextCol - 1] != 'K') && (chessBoard[nextRow - 1][nextCol - 1] != 'Q') && (chessBoard[nextRow - 1][nextCol - 1] != 'B') && (chessBoard[nextRow - 1][nextCol - 1] != 'N') && (chessBoard[nextRow - 1][nextCol - 1] != 'R') && (chessBoard[nextRow - 1][nextCol - 1] != 'S') && (chessBoard[nextRow - 1][nextCol - 1] != 'T') && (chessBoard[nextRow - 1][nextCol - 1] != 'O'))
			{
				positions[count][0] = nextRow;
				positions[count][1] = nextCol;
			}
		}
		if (chessBoard[nextRow - 1][nextCol - 1] == 0)
			chessBoard[nextRow-1][nextCol-1] = 'x';
		count++;
	}
}


void displayPosition(char chessBoard[8][8])
{
	cout << "\n   _______________________________________________\n";
	for (int i = 0; i < 8; i++)
	{
		cout << " ";
		for (int s = 0; s < 8; s++)
		{
			cout << " |    ";
		}
		cout << " |";
		if (i == 1)
			cout << "  'K' and 'k' for King";
		if (i == 2)
			cout << "  'Q' and 'q' for Queen";
		if (i == 3)
			cout << "  'B' and 'b' for left Bishop";
		if (i == 4)
			cout << "  'R' and 'r' for left Rock";
		if (i == 5)
			cout << "  'N' and 'n' for left Knight";
		if (i == 6)
			cout << "  'S' and 's' for Right Bishop";
		if (i == 7)
			cout << "  'O' and 'o' for Right Rock";
		if (i == 8)
			cout << "  'T' and 't' for Right Knight";
		cout << "\n" << i + 1;
		cout << " ";
		for (int j = 0; j < 8; j++)
		{
			if (chessBoard[i][j] == 0)
			{
				cout << "|     ";
			}
			else
			{
				cout << "|  " << chessBoard[i][j] << "  ";
			}
		}
		cout << "|" << endl;
		cout << "  ";
		for (int b = 0; b < 8; b++)
		{
			cout << "|_____";
		}
		cout << "|\n";

	}
	cout << " ";
	for (int k = 1; k <= 8; k++)
	{
		cout << "    " << k << " ";
	}
}

void game2()
{
	char chessBoard[8][8] = {
		{'r', 'n', 'b', 'k', 'q', 's', 't', 'o'},
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 },
		{'R', 'N', 'B', 'K', 'Q', 'S', 'T', 'O'}
	};
	int positions[50][2] = {};
	char ch;
	bool checkmate = false, check = false, valid = false;
	int row1, col1, row2, col2;
	displayPosition(chessBoard);
	srand(time(0));
	int turn = 1 + (rand() % 2);
	if (turn == 1)
		cout << "\nPlayer 1 plays white (Capital letters).";
	else
		cout << "\nPlayer 2 plays black (Small letters).";
	while (!checkmate)
	{
		if (turn == 1)
		{
			cout << "\nIts player 1's turn.";
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (chessBoard[i][j] == 'K')
					{
						row1 = i + 1;
						col1 = j + 1;
						position(row1, col1, ch, chessBoard, turn, positions);
					}
			//		for (int i = -1; i <= 1; i++)
			//		{
			//			for (int j = -1; j <= 1; j++)
			//			{
			//				if (i == 0 && j == 0)
			//					continue;
			//				if(chessBoard[i][j]!=)
			//				//boundaryCheck(nextRow, nextCol, positions, count, chessBoard, turn);
			//			}
			//		}
				}
			}
			//displayPosition(chessBoard);
			//position(row1, col1, ch, chessBoard, turn, positions);
			//check = checkKing(row1, col1, ch, chessBoard, turn, positions);
		}
		else
		{
			cout << "\nIts player 2's turn.";
			//check = checkKing(row1, col1, ch, chessBoard, turn, positions);
		}


		if (check == true)
			cout << "\nYou King is in check! Avoid the attack if possible or you will lose.";

		if (turn == 1)
		{
			do
			{
				valid = false;
				cout << "\n'K' for King\n'Q' for Queen\n'B' for left Bishop\n'S' for right Bishop\n'R' for left Rook\n'O' for right Rook\n'N' for left Knight\n'T' for right Knight\n";
				cin >> ch;
				//checking if the selected piece is on the chess board and finding out its row and column
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chessBoard[i][j] == ch)
						{
							row1 = i + 1;
							col1 = j + 1;
							valid = true;
							break;
						}
						else 
							valid = false;
					}
					if (valid == true)
						break;
				}
				if (valid == true)
				{
					if ((ch != 'K') && (ch != 'Q') && (ch != 'B') && (ch != 'R') && (ch != 'N') && (ch != 'S') && (ch != 'T') && (ch != 'O'))
					{
						cout << "Invalid input. Try again.";
						valid = false;
					}
					else
						valid = true;
				}
				else
					cout << "Invalid input. Try again.";
			} while (valid == false);

		}
		else
		{
			do
			{
				valid = false;
				cout << "\n'k' for King\n'q' for Queen\n'b' for left Bishop\n's' for right Bishop\n'r' for left Rook\n'o' for right Rook\n'n' for left Knight\n't' for right Knight\n";
				cin >> ch;
				//checking if the selected piece is on the chess board and finding out its row and column
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chessBoard[i][j] == ch)
						{
							row1 = i + 1;
							col1 = j + 1;
							valid = true;
							break;
						}
						else
							valid = false;
					}
					if (valid == true)
						break;
				}
				if (valid == true)
				{
					if ((ch != 'k') && (ch != 'q') && (ch != 'b') && (ch != 'r') && (ch != 'n') && (ch != 's') && (ch != 't') && (ch != 'o'))
					{
						cout << "Invalid input. Try again.";
						valid = false;
					}
					else
						valid = true;
				}
				else
					cout << "Invalid input. Try again.";
			} while (valid == false);
		}

		position(row1, col1, ch, chessBoard, turn, positions);
		displayPosition(chessBoard);
		chessBoard[row1 - 1][col1 - 1] = 0;
		do
		{
			do
			{
				valid = false;
				cout << "\nEnter next location for selected piece. (row, column).\n";
				cin >> row2;
				cin >> col2;
				for (int i = 0; i < 50; i++)
				{
					if ((row2) == positions[i][0] && (col2) == positions[i][1])
					{
						valid = true;
						break;
					}
					else
						valid = false;
				}
				if (valid == false)
					cout << "Invalid move. Try again.";
			} while (valid == false);
			if (turn == 1)
			{
				if ((chessBoard[row2 - 1][col2 - 1] == 'x') || (chessBoard[row2 - 1][col2 - 1] == 'q') || (chessBoard[row2 - 1][col2 - 1] == 'b') || (chessBoard[row2 - 1][col2 - 1] == 'n') || (chessBoard[row2 - 1][col2 - 1] == 'r') || (chessBoard[row2 - 1][col2 - 1] == 's') || (chessBoard[row2 - 1][col2 - 1] == 't') || (chessBoard[row2 - 1][col2 - 1] == 'o'))
					chessBoard[row2 - 1][col2 - 1] = ch;
				else
					cout << "Invalid move";
			}
			else
			{
				if ((chessBoard[row2 - 1][col2 - 1] == 'x') || (chessBoard[row2 - 1][col2 - 1] == 'Q') || (chessBoard[row2 - 1][col2 - 1] == 'B') || (chessBoard[row2 - 1][col2 - 1] == 'N') || (chessBoard[row2 - 1][col2 - 1] == 'R') || (chessBoard[row2 - 1][col2 - 1] == 'S') || (chessBoard[row2 - 1][col2 - 1] == 'T') || (chessBoard[row2 - 1][col2 - 1] == 'O'))
					chessBoard[row2 - 1][col2 - 1] = ch;
				else
					cout << "Invalid move";
			}
		} while (chessBoard[row2 - 1][col2 - 1] != ch);
		//removes 'x' from the chess board 
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (chessBoard[i][j] == 'x')
				{
					chessBoard[i][j] = 0;
				}
			}
		}
		displayPosition(chessBoard);
		if (turn == 1)
			turn = 2;
		else
			turn = 1;

		if (check == true)
			checkmate = true;
	}
	if (turn == 2)
		cout << "\nCheckmate! Player 2 won.";
	else
		cout << "\nCHeckmate! Player 1 won.";
}

bool checkKing(int row, int col, char ch, char chessBoard[8][8], int turn, int positions[][2])
{
	return 0;
}



bool rookCollision(int row1, int  col1, int  row2, int  col2, char chessBoard[8][8])
{
	if (row1 == row2)
	{
		//moving rightwards
		if (col1 < col2)
		{
			for (int i = col1 + 2; i <= col2; i++)
			{
				if (chessBoard[row1 - 1][i] != 0)
					return true;
			}
		}
		//moving leftwards
		else
		{
			for (int i = col1 - 2; i >= col2; i--)
			{
				if (chessBoard[row1 - 1][i] != 0)
					return true;
			}
		}
		if (chessBoard[row2 - 1][col2 - 1] == 0)
			chessBoard[row2 - 1][col2 - 1] = 'x';
	}
	if (col1 == col2)
	{
		//moving downwards
		if (row1 < row2)
		{
			for (int i = row1 + 2; i <= row2; i++)
			{
				if (chessBoard[i][col1 - 1] != 0)
					return true;
			}
		}
		//moving upwards
		else
		{
			for (int i = row1 - 2; i >= row2; i--)
			{
				if (chessBoard[i][col1 - 1] != 0)
					return true;
			}
		}
	}
	if (chessBoard[row2 - 1][col2 - 1] == 0)
		chessBoard[row2 - 1][col2 - 1] = 'x';
	return 0; // 
}
