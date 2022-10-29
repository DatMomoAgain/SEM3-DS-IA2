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
    
    
    //--MAIN LOGIC--
    void solveSudoku(vector<vector<char>>& board) {
        int i1=0;
        int i2=0;
        vector<int> if1;
        vector<int> if2;
        int c=0;
        vector<char> preVal;
        while(!isFull(board))
        {
            if(board[i1][i2] == '.' || c!=0)
            {
                if(c==0){
                    for(char i='1'; i<='9'; i++)
                    {
                        board[i1][i2] = i;
                        if(isValid(board, i1, i2))
                        {
                            if1.push_back(i1);
                            if2.push_back(i2);
                            preVal.push_back(i);
                            break;
                        }
                        else if(i=='9')
                        {
                            board[i1][i2] = '.';
                            i1 = if1[if1.size()-1];
                            i2 = if2[if2.size()-1]-1;
                            if1.pop_back();
                            if2.pop_back();
                            c++;
                        }
                        else
                        {
                            board[i1][i2] = '.';
                        }
                    } //char i for loop
                } //if c==0
                else
                {
                    c =0;
                    for(char i=preVal[preVal.size()-1]; i<='9'; i++)
                    {
                        board[i1][i2] = i+1;
                        if(isValid(board, i1, i2) && board[i1][i2]<='9')
                        {
                            if1.push_back(i1);
                            if2.push_back(i2);
                            preVal.pop_back();
                            preVal.push_back(i+1);
                            break;
                        }
                        else if(i+1>='9')
                        {
                            board[i1][i2] = '.';
                            i1 = if1[if1.size()-1];
                            i2 = if2[if2.size()-1]-1;
                            if1.pop_back();
                            if2.pop_back();
                            preVal.pop_back();
                            c++;
                            break;
                        }
                        else
                        {
                            board[i1][i2] = '.';
                        }
                    }
                }
            } //main if condition
            
            //traversing board 
            i2++;
            if(i2==9)
            {
                i2 = 0;
                i1++;
            }
            if(i1==9)
            {
                i1=0;
                i2=0;
            }
            
        }
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

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
}
