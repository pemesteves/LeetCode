class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            vector<bool> nums(9);
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.'){
                    if(nums[board[i][j]-1])
                        return false;
                    nums[board[i][j]-1] = true;
                }
            }
        }
        
        for(int i = 0; i < board[0].size(); i++){
            vector<bool> nums(9);
            for(int j = 0; j < board.size(); j++){
                if(board[j][i] != '.'){
                    if(nums[board[j][i]-1])
                        return false;
                    nums[board[j][i]-1] = true;
                }
            }
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                vector<bool> nums(9);
                for(int k = i*3; k < i*3+3; k++){
                    for(int l = j*3; l < j*3+3; l++){
                        if(board[k][l] != '.'){
                            if(nums[board[k][l]-1])
                                return false;
                            nums[board[k][l]-1] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};