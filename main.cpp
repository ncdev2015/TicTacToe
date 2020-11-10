#include<iostream>

using namespace std;

//init board
void initBoard(char board[][3], int n, int m) {
	int i, j, position='0';
	
	for ( i=0; i<n; i++ )
		for (j=0; j<n; j++)
			board[i][j] = ++position;
}

//draw board
void drawBoard(char board[][3], int n, int m) {
	int i, j;
	
	cout<<"\n+---+---+---+"<<endl;
	
	for ( i=0; i<n; i++ ) {
		cout << "|";
		
		for (j=0; j<n; j++)
			cout<<" "<<board[i][j]<<" |";
		
		cout<<endl<<"+---+---+---+"<< endl;
	}	
}

//return if a board position is valid to enter a symbol
bool isValidPosition(int position, char board[][3], int n, int m) {
	int i, j, actualPosition=0;
	
	for (i=0; i<n; i++)
		for (j=0;j<m;j++)
			if (++actualPosition==position)
				return board[i][j]!='X' && board[i][j]!='O';
				
	return false;
}

// draw symbol in a position
void drawSymbolInBoard(char symbol, char board[][3], int n, int m, int positionChoosed) {
	int i, j, position=0;
	
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			if (++position==positionChoosed)
				board[i][j]=symbol;
}

// check if a player won the game
bool checkWinner(char board[][3], int n, int m, char symbol) {
	int i, j;
	bool hasWinner = false;
	
	// check by rows
	for (i=0; i<n && !hasWinner; i++) {
		hasWinner = board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol;		
	}
	
	// check by cols
	for (j=0; j<m && !hasWinner; j++) {
		hasWinner = board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol;		
	}
	
	// check by diagonal
	bool hasWinnerD1 = board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol;
	bool hasWinnerD2 = board[0][2]==symbol && board[1][1]==symbol && board[2][0]==symbol;
	
	return hasWinnerD1 || hasWinnerD2 || hasWinner;
}

//main
int main (int argc, char *argv[]) {
	
	//variables
	char board[3][3], player1, player2, actualPlayer;
	bool isGameOver=false, hasWinner=false;
	int positionChoosed, turn=0;
	
	player1='X';
	player2='O';
	
	//init board
	initBoard(board, 3, 3);
	
	//start game
	do {
		positionChoosed=0;
		
		do {
			//clear screen
			
			system("cls");
			
			//title
			cout<<"Tic Tac Toe:"<<endl;
			
			//draw board
			drawBoard(board, 3, 3);
			
			if (turn%2==0)
				actualPlayer=player1;
			else
				actualPlayer=player2;			
			
			// get symbol to enter
			cout << "\nActual player: " << actualPlayer << endl;
			cout << "Enter the new symbol position: ";
			cin >> positionChoosed;
			
			// while position entered !isValid
		} while( !isValidPosition(positionChoosed,board,3,3) || (positionChoosed < 1 && positionChoosed > 9) );
		
		drawSymbolInBoard(actualPlayer, board, 3, 3, positionChoosed);
		
		if (turn + 1 > 2 ) {
			hasWinner = checkWinner(board, 3, 3, actualPlayer);
			isGameOver = turn + 1 > 8 || hasWinner;
		}	
		
		turn++;	
	} while (!isGameOver);
	
	//clear screen
	system("cls");
	
	//title
	cout<<"Tic Tac Toe:"<<endl;
	
	drawBoard(board, 3, 3);
	
	if (hasWinner)
		cout << "\nThe Winner is: " << actualPlayer << endl;
	else
		cout << "\nDraw game!" << endl;
	
	return 0;
}
