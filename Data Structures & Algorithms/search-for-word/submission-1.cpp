class Solution {
public:
    bool backtrack(vector<vector<char>>& board,string & word,int row,int col,int index){
        if(index==word.length()){
            return true;
        }
        if(row<0 || row>=board.size()|| col<0|| col>=board[0].size()){
            return false;
        }
        if(board[row][col]!=word[index]){
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '#';

        bool found=backtrack(board,word,row+1,col,index+1) || backtrack(board,word,row-1,col,index+1) || backtrack(board,word,row,col-1,index+1) || backtrack(board,word,row,col+1,index+1);
        board[row][col]=temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(backtrack(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;

    }
};
