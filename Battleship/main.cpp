//Header Inclusion
#include "Battleship.h"
#include "Ai.h"
#include "MatrixWrite.h"
using namespace std;


//Main Loop
int main()
{
    vector<vector<int>> bruh =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> Garbage =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    /**battleshipGame::updateBoardString();
    cout << battleshipGame::boardString;**/

    /**while (!battleshipGame::gameOver)
    {
        battleshipGame::gameOver = true;
    }**/
    
    vector<vector<int>> newBruh = matrixwrite::matrixWriteInt(Garbage, bruh, 0, 0, 3);

    
    cout << "Entered vector is : " << endl;
    for (int i = 0; i < newBruh.size(); i++)
    {
        for (int j = 0; j < newBruh[0].size(); j++)
        {
            cout << newBruh[i][j] << ' ';
        }
        cout << endl;
    }
}