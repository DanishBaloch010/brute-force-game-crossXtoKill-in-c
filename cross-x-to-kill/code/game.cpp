//CS182019
//Muhammad Danish
//6B

// suppose
// 0 isempty 
// 1 is red
// 2 is blue
#include <iostream>
using namespace std;
int board[3][3];
int red = 1;
int blue = 2;
int turn =1;
int placement =0;
int sum = 0;
int eightCheck = 0;
char turnCheck=' ';
char play = 'y';
char boardFull = 'n';
int player1coins = 4 ;
int player2coins = 4 ;
int player1blocked = 0 ;
int player2blocked = 0;

void startGame()
{
	for (int i = 0; i < 3; i++)
	{
        for (int j = 0; j < 3; j++)
		{        	
            board[i][j]=0;
        }
	}
}
void printBoard()
{
	cout << "x--- Current Board ---x\n" ;
	for (int i = 0; i < 3; i++) 
	{
    	for (int j = 0; j < 3; j++)
		{        	
            cout << board[i][j] << " " ;
        }
        cout << endl;
	}
	cout << "--------------------------\n";
}
int movement()
{
	// finding the empty space
//	int i , j =0;
//	
//	for (i = 0; i < 3; i++) 
//	{
//    	for (j = 0; j < 3; j++)
//		{        	
//			if(board[i][j] == 0)
//			{
//				int row = i ;
//				int column = j; 
//			}
//        }
//	}
//	cout << "empty location -- > [ " << i << " ]" << "[ " << j << " ]" <<endl; 
	
	turn = 1;
	while(player1coins > 0 && player2coins > 0 )
	{
		cout << "Movement TURN --> " << turn << endl;
		
		player1blocked = 0;
		player2blocked = 0;
		// checking the block condition
		while(player1blocked != 4 && player2blocked != 4 )
		{
		for (int i = 0; i < 3; i++) 
		{
    		for (int j = 0; j < 3; j++)
			{   
				if(board[i][j] == 1 && turn == 1 )
				{
					if(i == 0 && j==0 )
					{
						if(board[0][1] != 0 && board[1][0] != 0 && board[2][0] != 0 && board[0][2] != 0)  
						{
							player1blocked++;
						}
					}
					else if(i == 0 && j==1 )
					{
						if(board[0][0] != 0 && board[0][2] != 0 && board[1][1] != 0 && board[2][1] != 0)
						{
							player1blocked++;
						}
						
					}
					else if(i == 0 && j==2 )
					{
						if(board[0][1] != 0 && board[1][2] != 0 && board[0][0] != 0 && board[2][2] != 0)
						{
							player1blocked++;
						}
					}
					else if(i == 1 && j==0 )
					{
						if(board[0][0] != 0 && board[2][0] != 0 && board[1][1] != 0 && board[1][2] != 0)
						{
							player1blocked++;
						}
					}
					else if(i == 1 && j==1 )
					{
						if(board[0][1] != 0 && board[2][1] != 0 && board[1][0] != 0 && board[1][2] != 0)
						{
							player1blocked++;
						}
					}
					else if(i == 1 && j==2 )
					{
						if(board[0][2] != 0 && board[2][2] != 0 && board[1][1] != 0 && board[1][0] != 0)
						{
							player1blocked++;
						}
					}
					else if(i == 2 && j==0 )
					{
						if(board[1][0] != 0 && board[2][1] != 0 && board[0][0] != 0 && board[2][2] != 0)
						{
							player1blocked++;
						}
					}
					else if(i == 2 && j==1 )
					{
						if(board[1][1] != 0 && board[2][0] != 0 && board[2][2] != 0 && board[0][1] != 0)
						{
							player1blocked++;
						}
					}
					else if(i == 2 && j==2 )
					{
						if(board[1][2] != 0 && board[2][1] != 0 && board[0][2] != 0 && board[2][0] != 0)
						{
							player1blocked++;
							
						}
					}
					
				}
				
				else if(board[i][j] == 2 && turn == 2)
				{
					if(i == 0 && j==0 )
					{
						if(board[0][1] != 0 && board[1][0] != 0 && board[2][0] != 0 && board[0][2] != 0)  
						{
							player2blocked++;
						}
					}
					else if(i == 0 && j==1 )
					{
						if(board[0][0] != 0 && board[0][2] != 0 && board[1][1] != 0 && board[2][1] != 0)
						{
							player2blocked++;
						}
						
					}
					else if(i == 0 && j==2 )
					{
						if(board[0][1] != 0 && board[1][2] != 0 && board[0][0] != 0 && board[2][2] != 0)
						{
							player2blocked++;
						}
					}
					else if(i == 1 && j==0 )
					{
						if(board[0][0] != 0 && board[2][0] != 0 && board[1][1] != 0 && board[1][2] != 0)
						{
							player2blocked++;
						}
					}
					else if(i == 1 && j==1 )
					{
						if(board[0][1] != 0 && board[2][1] != 0 && board[1][0] != 0 && board[1][2] != 0)
						{
							player2blocked++;
						}
					}
					else if(i == 1 && j==2 )
					{
						if(board[0][2] != 0 && board[2][2] != 0 && board[1][1] != 0 && board[1][0] != 0)
						{
							player2blocked++;
						}
					}
					else if(i == 2 && j==0 )
					{
						if(board[1][0] != 0 && board[2][1] != 0 && board[0][0] != 0 && board[2][2] != 0)
						{
							player2blocked++;
						}
					}
					else if(i == 2 && j==1 )
					{
						if(board[1][1] != 0 && board[2][0] != 0 && board[2][2] != 0 && board[0][1] != 0)
						{
							player2blocked++;
						}
					}
					else if(i == 2 && j==2 )
					{
						if(board[1][2] != 0 && board[2][1] != 0 && board[0][2] != 0 && board[2][0] != 0)
						{
						
							player2blocked++;
						}
					}
				}
			}
		}
	}
    	
		if(player1blocked == 4)
		{
			cout << "player 1 is blocked. PLAYER 2 WON." <<endl;
			return 0;
		}
		else if(player2blocked == 4)
		{
			cout << "player 2 is blocked. PLAYER 1 WON." <<endl;
			return 0;
		}
		cout<<"Enter the coin location which you have to move ? ";
		int location = 0;
		cin >> location;
		
		cout <<"Enter the coin destination location --> " ;
		int destination = 0;
		cin >> destination;
		
		
			
		if(turn == 1)
		{
			switch(location)
			{
				case 1:
					if(board[0][0] == 1)
					{
						// 1 only = right , down and cross to 3 and 7.
						if(board[0][0] == 1 && destination == 2 && board[0][1] == 0 )
						{
							swap (board[0][0],board[0][1]);
							turn = 2;
						}
						// down
						else if(board[0][0] == 1 && destination == 4 && board[1][0] == 0 )
						{
							swap (board[0][0],board[1][0]);
							turn = 2;
						}
						//cross movement to 3
						else if(board[0][0] == 1 && board[0][1] == 2 && destination == 3 && board[0][2] == 0 )
						{
							// swap 1 and 3
							swap (board[0][0],board[0][2]);
							//eliminate from 2.
							board[0][1] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 2."<<endl;
						}
						//cross movement to 7
						else if(board[0][0] == 1 && board[1][0] == 2 && destination == 7 && board[2][0] == 0 )
						{
							// swap 1 and 7
							swap (board[0][0],board[2][0]);
							//eliminate from 4.
							board[1][0] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 4."<<endl;
						}
						else
						{
							player1blocked++;
						}
						
					}
					break;
			
				case 2:
					if(board[0][1] == 1)
					{
						// 2 only = left , right , down , and cross to 8
						// left
						if(board[0][1] == 1 && destination == 1 && board[0][0] == 0 )
						{
							swap (board[0][1],board[0][0]);
							turn = 2;
						}
						//right
						else if(board[0][1] == 1 && destination == 3 && board[0][2] == 0 )
						{
							swap (board[0][1],board[0][2]);
							turn = 2;
						}
						// down
						else if(board[0][1] == 1 && destination == 5 && board[1][1] == 0 )
						{
							swap (board[0][1],board[1][1]);
							turn = 2;
						}
					
						//cross movement to 8
						else if(board[0][1] == 1 && board[1][1] == 2 && destination == 8 && board[2][1] == 0 )
						{
							// swap 2 and 8
							swap (board[0][1],board[2][1]);
							//eliminate from 5.
							board[1][1] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 5."<<endl;
						}
						else
						{
							player1blocked++;
						}
					}
				
					break;
				
				case 3:
					if(board[0][2] == 1)
					{
						// 3 only = left , down and cross to 1 and 9
						//left
						if(board[0][2] == 1 && destination == 2 && board[0][1] == 0 )
						{
							swap (board[0][2],board[0][1]);
							turn = 2;
						}
						// down
						else if(board[0][2] == 1 && destination == 6 && board[1][2] == 0 )
						{
							swap (board[0][2],board[1][2]);
							turn = 2;
						}
				
						//cross movement to 1
						else if(board[0][2] == 1 && board[0][1] == 2 && destination == 1 && board[0][0] == 0 )
						{
							// swap 3 and 1
							swap (board[0][2],board[0][0]);
							//eliminate from 2.
							board[0][1] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 2."<<endl;
						}
						//cross movement to 9
						else if(board[0][2] == 1 && board[1][2] == 2 && destination == 9 && board[2][2] == 0 )
						{
							// swap 3 and 9
							swap (board[0][2],board[2][2]);
							//eliminate from 6.
							board[1][2] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 6."<<endl;
						}
						else
						{
							player1blocked++;
						}
					}
					else
					{
						cout <<"illegal move" <<endl;
					}
					break;
					
				case 4:
					if(board[1][0] == 1)
					{
						// 4 only = up , down , right and cross to 6
						//up
						if(board[1][0] == 1 && destination == 1 && board[0][0] == 0 )
						{
							swap (board[1][0],board[0][0]);
							turn = 2;
						}
						// down
						else if(board[1][0] == 1 && destination == 7 && board[2][0] == 0 )
						{
							swap (board[1][0],board[2][0]);
							turn = 2;
						}
						
						// right
						else if(board[1][0] == 1 && destination == 5 && board[1][1] == 0 )
						{
							swap (board[1][0],board[1][1]);
							turn = 2;
						}
						
						// cross to 6
						else if(board[1][0] == 1 && board[1][1] == 2 && destination == 6 && board[1][2] == 0 )
						{
							// swap 4 and 6
							swap (board[1][0],board[1][2]);
							//eliminate from 5.
							board[1][1] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 5."<<endl;
						}
						else
						{
							player1blocked++;
						}
					}
					else
					{
						cout <<"illegal move" <<endl;
					}
					break;
				
				case 5:
					if(board[1][1] == 1)
					{
						// 5 only = up , down , left, right
						//up
						if(board[1][1] == 1 && destination == 2 && board[0][1] == 0 )
						{
							swap (board[1][1],board[0][1]);
							turn = 2;
						}
						// down
						else if(board[1][1] == 1 && destination == 8 && board[2][1] == 0 )
						{
							swap (board[1][1],board[2][1]);
							turn = 2;
						}
						//left
						else if(board[1][1] == 1 && destination == 4 && board[1][0] == 0 )
						{
							swap (board[1][1],board[1][0]);
							turn = 2;
						}
						// right
						else if(board[1][1] == 1 && destination == 6 && board[1][2] == 0 )
						{
							swap (board[1][1],board[1][2]);
							turn = 2;
						}
						else
						{
							player1blocked++;
						}
					}
					else
					{
						cout <<"illegal move" <<endl;
					}
					
					break;
				
				case 6:
					if(board[1][2] == 1)
					{
						// 6 only = up , down, left and cross to 4.
						//up
						if(board[1][2] == 1 && destination == 3 && board[0][2] == 0 )
						{
							swap (board[1][2],board[0][2]);
							turn = 2;
						}
						// down
						else if(board[1][2] == 1 && destination == 9 && board[2][2] == 0 )
						{
							swap (board[1][2],board[2][2]);
							turn = 2;
						}
						//left
						else if(board[1][2] == 1 && destination == 5 && board[1][1] == 0 )
						{
							swap (board[1][2],board[1][1]);
							turn = 2;
						}
						// cross to 4.
						else if(board[1][2] == 1 && board[1][1] == 2 && destination == 4 && board[1][0] == 0 )
						{
							// swap 6 and 4
							swap (board[1][2],board[1][0]);
							//eliminate from 5.
							board[1][1] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 5."<<endl;
						}
						else
						{
							player1blocked++;
						}
					}
					else
					{
						cout <<"illegal move" <<endl;	
					}
				
					break;
				
				case 7:
					if(board[2][0] == 1)
					{
						// 7 only = up , right and cross to 1 and 9
						//up
						if(board[2][0] == 1 && destination == 4 && board[1][0] == 0 )
						{
							swap (board[2][0],board[1][0]);
							turn = 2;
						}
						// right
						else if(board[2][0] == 1 && destination == 8 && board[2][1] == 0 )
						{
							swap (board[2][0], board[2][1]);
							turn = 2;
						}
						// cross to 1.
						else if(board[2][0] == 1 && board[1][0] == 2 && destination == 1 && board[0][0] == 0 )
						{
							// swap 7 and 1
							swap (board[2][0],board[0][0]);
							//eliminate from 4.
							board[1][0] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 4."<<endl;
						}
						// cross to 9.
						else if(board[2][0] == 1 && board[2][1] == 2 && destination == 9 && board[2][2] == 0 )
						{
							// swap 2 and 9
							swap (board[2][0],board[2][2]);
							//eliminate from 8.
							board[2][1] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 8."<<endl;
						}
						else
						{
							player1blocked++;
						}
					}
					else
					{
						cout <<"illegal move" <<endl;
					}
					
					break;
					
				case 8:
					
					if(board[2][1] == 1)
					{
						// 8 only = up, left, right and cross to 2.
						//up
						if(board[2][1] == 1 && destination == 5 && board[1][1] == 0 )
						{
							swap (board[2][1],board[1][1]);
							turn = 2;
						}
						//left
						else if(board[2][1] == 1 && destination == 7 && board[2][0] == 0 )
						{
							swap (board[2][1],board[2][0]);
							turn = 2;
						}
						//right
						else if(board[2][1] == 1 && destination == 9 && board[2][2] == 0 )
						{
							swap (board[2][1],board[2][2]);
							turn = 2;
						}
						// cross to 2.
						else if(board[2][1] == 1 && board[1][1] == 2 && destination == 2 && board[0][1] == 0 )
						{
							// swap 8 and 2
							swap (board[2][1],board[0][1]);
							//eliminate from 5.
							board[1][1] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 5."<<endl;
						}
						else
						{
							player1blocked++;
						}
					}
					else
					{
						cout <<"illegal move" <<endl;
					}
	
					break;
			
				case 9:
					if(board[2][2] == 1)
					{
						// 9 only = up, left and cross to 7 and 3
						//up
						if(board[2][2] == 1 && destination == 6 && board[1][2] == 0 )
						{
							swap (board[2][2],board[1][2]);
							turn = 2;
						}
						//left
						else if(board[2][2] == 1 && destination == 8 && board[2][1] == 0 )
						{
							swap (board[2][2],board[2][1]);
							turn = 2;
						}
						// cross to 7.
						else if(board[2][2] == 1 && board[2][1] == 2 && destination == 7 && board[2][0] == 0 )
						{
							// swap 9 and 7
							swap (board[2][2],board[2][0]);
							//eliminate from 8.
							board[2][1] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 8."<<endl;
						}
						// cross to 3.
						else if(board[2][2] == 1 && board[1][2] == 2 && destination == 3 && board[0][2] == 0 )
						{
							// swap 9 and 3
							swap (board[2][2],board[0][2]);
							//eliminate from 6.
							board[1][2] = 0;
							turn = 2;
							player2coins--;
							cout << "Player Number(02) is eleminated from position = 6."<<endl;
						}
						else
						{
							player1blocked++;
						}
					}
					else
					{
						cout <<"illegal move" <<endl;
					}
					
					break;
					
					default:
						cout<<"illegal location !!"<<endl;
					
			}
			printBoard();
		}
		else if(turn ==2)
		{
			switch(location)
			{
				case 1:
					// 1 only = right , down and cross to 3 and 7.
					//right
					if(board[0][0] == 2 && destination == 2 && board[0][1] == 0 )
					{
						swap (board[0][0],board[0][1]);
						turn = 1;
					}
					// down
					else if(board[0][0] == 2 && destination == 4 && board[1][0] == 0 )
					{
						swap (board[0][0],board[1][0]);
						turn = 1;
					}
					//cross movement to 3
					else if(board[0][0] == 2 && board[0][1] == 1 && destination == 3 && board[0][2] == 0 )
					{
						// swap 1 and 3
						swap (board[0][0],board[0][2]);
						//eliminate from 2.
						board[0][1] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 2."<<endl;
					}
					//cross movement to 7
					else if(board[0][0] == 2 && board[1][0] == 1 && destination == 7 && board[2][0] == 0 )
					{
						// swap 1 and 7
						swap (board[0][0],board[2][0]);
						//eliminate from 4.
						board[1][0] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 4."<<endl;
					}
					else
					{
						cout <<"illegal move" <<endl;
					}
					break;	
					
				case 2:
					// 2 only = left , right , down , and cross to 8
					// left
					if(board[0][1] == 2 && destination == 1 && board[0][0] == 0 )
					{
						swap (board[0][1],board[0][0]);
						turn = 1;
					}
					//right
					else if(board[0][1] == 2 && destination == 3 && board[0][2] == 0 )
					{
						swap (board[0][1],board[0][2]);
						turn = 1;
					}
					// down
					else if(board[0][1] == 2 && destination == 5 && board[1][1] == 0 )
					{
						swap (board[0][1],board[1][1]);
						turn = 1;
					}
					
					//cross movement to 8
					else if(board[0][1] == 2 && board[1][1] == 1 && destination == 8 && board[2][1] == 0 )
					{
						// swap 2 and 8
						swap (board[0][1],board[2][1]);
						//eliminate from 5.
						board[1][1] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 5."<<endl;
					}
					
					else
					{
						cout <<"illegal move" <<endl;
					}
					break;
				
				case 3:
					// 3 only = left , down and cross to 1 and 9
					//left
					if(board[0][2] == 2 && destination == 2 && board[0][1] == 0 )
					{
						swap (board[0][2],board[0][1]);
						turn = 1;
					}
					// down
					else if(board[0][2] == 2 && destination == 6 && board[1][2] == 0 )
					{
						swap (board[0][2],board[1][2]);
						turn = 1;
					}
				
					//cross movement to 1
					else if(board[0][2] == 2 && board[0][1] == 1 && destination == 1 && board[0][0] == 0 )
					{
						// swap 3 and 1
						swap (board[0][2],board[0][0]);
						//eliminate from 2.
						board[0][1] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 2."<<endl;
					}
					//cross movement to 9
					else if(board[0][2] == 2 && board[1][2] == 1 && destination == 9 && board[2][2] == 0 )
					{
						// swap 3 and 9
						swap (board[0][2],board[2][2]);
						//eliminate from 6.
						board[1][2] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 6."<<endl;
					}
					
					else
					{
						cout <<"illegal move" <<endl;
					}
					break;
					
				case 4:
					// 4 only = up , down , right and cross to 6
					//up
					if(board[1][0] == 2 && destination == 1 && board[0][0] == 0 )
					{
						swap (board[1][0],board[0][0]);
						turn = 1;
					}
					// down
					else if(board[1][0] == 2 && destination == 7 && board[2][0] == 0 )
					{
						swap (board[1][0],board[2][0]);
						turn = 1;
					}
					
					// right
					else if(board[1][0] == 2 && destination == 5 && board[1][1] == 0 )
					{
						swap (board[1][0],board[1][1]);
						turn = 1;
					}
					
					// cross to 6
					else if(board[1][0] == 2 && board[1][1] == 1 && destination == 6 && board[1][2] == 0 )
					{
						// swap 4 and 6
						swap (board[1][0],board[1][2]);
						//eliminate from 5.
						board[1][1] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 5."<<endl;
					}
					break;
					
				case 5:
					// 5 only = up , down , left, right
					//up
					if(board[1][1] == 2 && destination == 2 && board[0][1] == 0 )
					{
						swap (board[1][1],board[0][1]);
						turn = 1;
					}
					// down
					else if(board[1][1] == 2 && destination == 8 && board[2][1] == 0 )
					{
						swap (board[1][1],board[2][1]);
						turn = 1;
					}
					//left
					else if(board[1][1] == 2 && destination == 4 && board[1][0] == 0 )
					{
						swap (board[1][1],board[1][0]);
						turn = 1;
					}
					// right
					else if(board[1][1] == 2 && destination == 6 && board[1][2] == 0 )
					{
						swap (board[1][1],board[1][2]);
						turn = 1;
					}
					break;
				
				case 6:
					// 6 only = up , down, left and cross to 4.
					//up
					if(board[1][2] == 2 && destination == 3 && board[0][2] == 0 )
					{
						swap (board[1][2],board[0][2]);
						turn = 1;
					}
					// down
					else if(board[1][2] == 2 && destination == 9 && board[2][2] == 0 )
					{
						swap (board[1][2],board[2][2]);
						turn = 1;
					}
					//left
					else if(board[1][2] == 2 && destination == 5 && board[1][1] == 0 )
					{
						swap (board[1][2],board[1][1]);
						turn = 1;
					}
					// cross to 4.
					else if(board[1][2] == 2 && board[1][1] == 1 && destination == 4 && board[1][0] == 0 )
					{
						// swap 6 and 4
						swap (board[1][2],board[1][0]);
						//eliminate from 5.
						board[1][1] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 5."<<endl;
					}
					break;
				
				case 7:
					// 7 only = up , right and cross to 1 and 9
					//up
					if(board[2][0] == 2 && destination == 4 && board[1][0] == 0 )
					{
						swap (board[2][0],board[1][0]);
						turn = 1;
					}
					// right
					else if(board[2][0] == 2 && destination == 8 && board[2][1] == 0 )
					{
						swap (board[2][0], board[2][1]);
						turn = 1;
					}
					// cross to 1.
					else if(board[2][0] == 2 && board[1][0] == 1 && destination == 1 && board[0][0] == 0 )
					{
						// swap 7 and 1
						swap (board[2][0],board[0][0]);
						//eliminate from 4.
						board[1][0] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 4."<<endl;
					}
					// cross to 9.
					else if(board[2][0] == 2 && board[2][1] == 1 && destination == 9 && board[2][2] == 0 )
					{
						// swap 2 and 9
						swap (board[2][0],board[2][2]);
						//eliminate from 8.
						board[2][1] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 8."<<endl;
					}
					break;
				
				case 8:
					// 8 only = up, left, right and cross to 2.
					//up
					if(board[2][1] == 2 && destination == 5 && board[1][1] == 0 )
					{
						swap (board[2][1],board[1][1]);
						turn = 1;
					}
					//left
					else if(board[2][1] == 2 && destination == 7 && board[2][0] == 0 )
					{
						swap (board[2][1],board[2][0]);
						turn = 1;
					}
					//right
					else if(board[2][1] == 2 && destination == 9 && board[2][2] == 0 )
					{
						swap (board[2][1],board[2][2]);
						turn = 1;
					}
					// cross to 2.
					else if(board[2][1] == 2 && board[1][1] == 1 && destination == 2 && board[0][1] == 0 )
					{
						// swap 8 and 2
						swap (board[2][1],board[0][1]);
						//eliminate from 5.
						board[1][1] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 5."<<endl;
					}
					break;
				
				case 9:
					// 9 only = up, left and cross to 7 and 3
					//up
					if(board[2][2] == 2 && destination == 6 && board[1][2] == 0 )
					{
						swap (board[2][2],board[1][2]);
						turn = 1;
					}
					//left
					else if(board[2][2] == 2 && destination == 8 && board[2][1] == 0 )
					{
						swap (board[2][2],board[2][1]);
						turn = 1;
					}
					// cross to 7.
					else if(board[2][2] == 2 && board[2][1] == 1 && destination == 7 && board[2][0] == 0 )
					{
						// swap 9 and 7
						swap (board[2][2],board[2][0]);
						//eliminate from 8.
						board[2][1] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 8."<<endl;
					}
					// cross to 3.
					else if(board[2][2] == 2 && board[1][2] == 1 && destination == 3 && board[0][2] == 0 )
					{
						// swap 9 and 3
						swap (board[2][2],board[0][2]);
						//eliminate from 6.
						board[1][2] = 0;
						turn = 1;
						player1coins--;
						cout << "Player Number(01) is eleminated from position = 6."<<endl;
					}
					
					break;
					
					default:
						cout << "illegal location !!!" <<endl;
			}
			printBoard();
		}
	}
	// while ends
	if(player1coins == 0)
	{
		cout << "player 2 have won." <<endl;
		return 0;
	}
	else if(player2coins == 0)
	{
		cout << "player 1 have won." <<endl;
		return 0;
	}
}
int main()
{
	startGame();
	
	while( play =='y' || play == 'Y' )
	{
		// Counting empty spaces on board.
		sum =0;
		for (int i = 0; i < 3; i++) 
		{
    		for (int j = 0; j < 3; j++)
			{        	
				if(board[i][j] == 0)
				{
					sum++;
				}
    	    }
		}
		cout <<"--------\n";
		cout << "Empty Spaces ---> " << sum << "\n";
		cout <<"-------\n";
		
		// printing the board.
		printBoard();
		
		cout << "TURN ==> " << turn << "\n" ;
		cout << "where do you want to place your move ?\n";
		cout << "choose from position [1 -> 9]\n";
	
		cin >> placement;
	
		// continue placements if there is more than 1 empty space on board 
		if(sum != 1)
  		{
			switch (placement)
			{
			    case 1:
			    	if(board[0][0] == 0)
			    	{
			    		if(turn == 1)
			    		{
			    			board[0][0] = red;
			    			turn = 2;
			    			break;
						}
					
			   			else if(turn == 2)
			   			{
			   				board[0][0] = blue;
			   				turn = 1;
		    				break;
						}
						
					}
					else
					{
						cout << "This Placement Is Taken !! \n";	
						break;
					}
					
					break;	
					
				case 2:
					if(board[0][1] == 0)
					{
						if(turn == 1)
						{
							board[0][1] = red;
							turn = 2;
			    	    	break;	
						}
						else if(turn == 2)
						{
							board[0][1] = blue;
							turn = 1;
							break;
						}
					}
					else
					{
						cout << "This Placement Is Taken !! \n";	
						break;	
					}
					break;
				
		    	case 3:
		    		if(board[0][2] == 0)
		    		{
		    			if(turn == 1)
						{
							board[0][2] = red;
							turn = 2;
		    				break;	
						}
						else if(turn == 2)
						{
							board[0][2] = blue;
							turn = 1;
							break;
						}
					}
					else
					{
						cout << "This Placement Is Taken !! \n";	
						break;
					}
					
					break;
	    	
			    case 4:
			    	if(board[1][0] == 0)
			    	{
			    		
					
			    		if(turn == 1)
						{
							board[1][0] = red;
							turn = 2;
		    				break;	
						}
						else if(turn == 2)
						{
							board[1][0] = blue;
							turn = 1;
							break;
						}
					}
					else
					{
						cout << "This Placement Is Taken !! \n";	
						break;
					}
					break;
			
	    
	    		case 5:
	    			if(board[1][1]==0)
	    			{
	    				if(turn == 1)
						{
							board[1][1] = red;
							turn = 2;
	    					break;	
						}
						else if(turn == 2)
						{
							board[1][1] = blue;
							turn = 1;
							break;
						}
					}
					else
					{
						cout << "This Placement Is Taken !! \n";	
						break;
					}
					break;
			
	    		case 6:
	    			if(board[1][2] ==0)
	    			{
					
	    				if(turn == 1)
						{
							board[1][2] = red;
							turn = 2;
	    					break;	
						}
						else if(turn == 2)
						{
							board[1][2] = blue;
							turn = 1;
							break;
						}
					}
					else
					{
						cout << "This Placement Is Taken !! \n";	
						break;
					}
					break;
			
    
	    		case 7:
	    			if(board[2][0]==0)
	    			{
	    				if(turn == 1)
						{
							board[2][0] = red;
							turn = 2;
	   				 		break;	
						}
						else if(turn == 2)
						{
							board[2][0] = blue;
							turn = 1;
							break;
						}
					}
					else
					{
						cout << "This Placement Is Taken !! \n";	
						break;
					}
					break;
			
	 	   		case 8:
	 	   			if(board[2][1]==0)
	 	   			{		
	 	   				if(turn == 1)
						{
							board[2][1] = red;
							turn = 2;
		    				break;	
						}
						else if(turn == 2)
						{
							board[2][1] = blue;
							turn = 1;
							break;
						}
					}
					else
					{
						cout << "This Placement Is Taken !! \n";	
							break;
					}
					break;
			
		   	 	case 9:
		   	 		if(board[2][2] == 0)
		   	 		{
		    			if(turn == 1)
						{
							board[2][2] = red;
							turn = 2;
		    				break;	
						}
						else if(turn == 2)
						{
							board[2][2] = blue;
							turn = 1;
							break;
						}
					}
					else
					{
							cout << "This Placement Is Taken !! \n";	
							break;
					}
					break;
				        
	    		default:
	    		    cout << "Error! The Placement Is Not Correct\n";
//	    		    break;
			}
			
			cout << "Continue YES or NO ??\n";
			cin >> play;
		}
		else
		{
			cout <<"Board is FULL !!\n";
			play = 'n';
			boardFull = 'y';
			
//			movement();
		}
	
	}
	if(boardFull == 'n')
	{
		if( play != 'y' || play != 'Y' )
		{
			if(turn == 1)
			{
				cout << "player 1 quitted . PLAYER 2 WON\n";
				
			}
			else if(turn == 2)
			{
				cout << "player 2 quitted . PLAYER 1 WON\n";
			
			}
			printBoard();
			cout << "game terminated.\n";
			return 0;
		}
	}
	else
	{
		movement();
	}

	
	return 0;
}
