class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowcase(9, vector<int>(9, 0));
        vector<vector<int>> colcase(9, vector<int>(9, 0));
        vector<vector<int>> gridcase(9, vector<int>(9, 0));

        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                // If it is a number
                if(board[i][j] != '.') {
                    int number = board[i][j] - '0';

                    int k = i/3*3 + j/3;   // K denotes grid number


                    //check for the 3 cases
                    if(rowcase[i][number-1]++ || colcase[j][number-1]++ || gridcase[k][number-1]++) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
