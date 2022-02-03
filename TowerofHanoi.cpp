//
//  main.cpp

#include <iostream>
using namespace std;
/* Basic tower of Hanoi algorithm that is O to the n squared time complexity*/
void show(char H[3][3][8]);
int main(){
    char H[3][3][8];
    char f;
    char s;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            H[0][i][j] = H[1][i][j] = H[2][i][j] = ' ';
        }
    }
    H[0][0][0] = '1';
    H[0][1][0] = '3';
    H[0][2][0] = '5';
    
    H[0][0][4] = H[0][1][3] = H[0][1][4] = H[0][1][5] = H[0][2][2] = H[0][2][3] = H[0][2][4] = H[0][2][5] = H[0][2][6] = '*';
    
    show(H);
    cout << "What is your move? (give first the source stack (A, B, or C) and the Destination Stack, separated by 1 Space): ";
    cin >> f >> s;
    f = toupper(f);
    s = toupper(s);
    
    while(f != 'E' || s != 'E'){
        int c = -1;
        int x = (int)(f) - 65;
        int y = (int)(s) - 65;
        if(H[x][2][0] == ' ' || !(x >=  0 && x < 3) || !(y >= 0 && y < 3)){
            cout << "Invalid\n";
        }
        else{
            int x2 = (H[x][0][0] != ' ')  ? 0: (H[x][1][0] != ' ')?1:2;
            int y2 = (H[y][2][0] == ' ')  ? 2: (H[y][1][0] == ' ')?1:0;
            for(int i = 0; i < 8 ; i++){
                H[y][y2][i] = H[x][x2][i];
                H[x][x2][i] = ' ';
                c++;
            }
        if( (H[x][0][0] > H[x][1][0] || H[x][1][0] > H[x][2][0]) || H[y][0][0] > H[y][1][0] || H[y][1][0] > H[y][2][0] ){
            cout << "Cannot stack a larger disc on a smaller disc. " << endl;
            for(int i = 0; i < 8 ; i++){
                    H[x][x2][i] = H[y][y2][i];
                    H[y][y2][i] = ' ';
                    c--;
                }
            }
         if( H[2][0][4] == '*' && H[2][1][3] ==  '*' &&  H[2][1][5] == '*' && H[2][2][2] == '*' && H[2][2][6] == '*'){
        cout << "You won in " << c << " moves!" << endl;
             if(c <= 7){
                 cout << "You did it in the least amount of moves!" << endl;
             }
            
        exit(1);
                                     
        }
                

        }
           
           show(H);
           cin >> f >> s;
            f = toupper(f);
           s = toupper(s);
    }
}
//*************************************************************************************
//Name: show
//Precondition: The move is calulated but not show to the screen
//Postcondition:The current game and disc positions are shown
//Description: This takes the data and outputs it while showing the current disc positions
//
//
//*************************************************************************************
void show(char H[3][3][8]){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 8; j++)
                    cout << H[0][i][j];
                
                for(int j = 0; j < 8; j++)
                    cout << H[1][i][j];
                
                for(int j = 0; j < 8; j++)
                    cout << H[2][i][j];
                
                cout << endl;
            }
            cout << "    A       B      C\n" ;
}
