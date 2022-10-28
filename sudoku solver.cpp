#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c)
    {
        bool ans = true;
        
        //--CHECK ROW--
        vector<char> row = board[r];
        sort(row.begin(),row.end());
        int index = -1;
        
        //check index at which '.' end
        for(int j=0; j<9; j++)
        {
            if(row[j] != '.')
            {
                index = j;
                break;
            }
        }
        
        //check for duplicates
        for(int j=index; j<8; j++)
        {
            if(row[j] == row[j+1])
            {
                return false;
            }
        }
        
        
        //--CHECK COLUMN--
        vector<char> col;
        
        //adding column to col
        for(int j=0; j<9; j++)
        {
            if(board[j][c] != '.')
            {
                col.push_back(board[j][c]);
            }
        }
        
        sort(col.begin(), col.end()); 
        
        for(int j=0; j<col.size()-1; j++)
        {
            if(col[j] == col[j+1])
            {
                return false;
            }
        }
        
        
        //--CHECK BOX--
        vector<char> box;
        
        //adding elements to box
        //q and w represent start of box
        int q = r - r%3;
        int w = c - c%3;
        
        for(int j=0; j<9; j++)
        {
            if(board[q][w]!='.')
                box.push_back(board[q][w]);
            w++;
            if(w==3 || w==6 || w==9)
            {
                w -= 3;
                q++;
            }
        }
        
        
        sort(box.begin(),box.end());
        
        //checking for duplicates
        for(int j=0; j<box.size()-1;j++)
        {
            if (box[j]==box[j+1])
            {
                return false;
            }
        }
        
        
        return ans;
    }
    
    bool isFull(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> temp = board;

    }
};

int main()
{
    vector<vector<string>> board1
    {
        {"9",".",".",".",".","1",".",".","."},
        {".","1",".",".","4","9",".",".","6"},
        {".",".","7",".",".",".",".",".","."},
        {"2",".",".","7",".",".","3",".","."},
        {".","4",".","5","9",".",".",".","."},
        {".",".","8",".",".",".","7","4","."},
        {".",".","6",".","2",".",".","9","."},
        {"3","2",".",".",".",".",".",".","."},
        {".",".",".",".","8",".","5",".","."}
    };
    
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<board1[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<vector<char>> board(9);
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            string s = board1[i][j];
            char c = s[0];
            board[i].push_back(c);
        }
    }
    Solution a;    
    a.solveSudoku(board);
}
