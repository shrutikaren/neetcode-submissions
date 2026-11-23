
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, bool> rowValueMap;
        unordered_map<int, bool> colValueMap;
        unordered_map<int, bool> squareValueMap;

        // checking all of the rows
        for (vector<char> rowInBoard: board){
            for (int i = 1; i < 10; i++){
                rowValueMap[i] = false;
            }

            for (char c: rowInBoard){
                if (c == '.') continue;

                int val = c - '0';
                if (rowValueMap[val] == true){
                    return false;
                }
                else {
                    rowValueMap[val] = true;
                }
            }
        }

        // checking all of the columns
        for (int i = 0; i < 9; i++){
            for (int k = 1; k < 10; k++){
                colValueMap[k] = false;
            }

            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;

                int val = board[j][i] - '0';
                if (colValueMap[val] == true){
                    return false;
                }
                else {
                    colValueMap[val] = true;
                }
            }
        }

        // checking all the squares
        for (int rowIndex = 0; rowIndex < 9; rowIndex += 3){
            for (int colIndex = 0; colIndex < 9; colIndex += 3){

                for (int k = 1; k < 10; k++){
                    squareValueMap[k] = false;
                }

                for (int i = rowIndex; i < rowIndex + 3; i++){
                    for (int j = colIndex; j < colIndex + 3; j++){
                        if (board[i][j] == '.') continue;

                        int val = board[i][j] - '0';
                        if (squareValueMap[val] == true){
                            return false;
                        }
                        else {
                            squareValueMap[val] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};
