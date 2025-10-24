class TicTacToe {
vector<vector<int>> arr;
int n;
public:
    TicTacToe(int n) {
        arr.resize(n,vector<int>(n, -1));
        this->n = n;
    }
    bool isDiagonal(int row, int col){
        if((row == 0 and col == 0) ||( row == 0 and col == n-1) || (row == n-1 and col == 0) || (row == n-1 and col == n-1)) return true;
        return false; 
    }
    int move(int row, int col, int player) {
        arr[row][col]=player;
        // checking row;
        bool win = true;
        for(int i=0;i<n;i++){
            if(arr[row][i] != player){
                win = false;
                break;
            }
        }
        if(win) return player;

        // checking col
        win = true;
        for(int i=0;i<n;i++){
            if(arr[i][col] != player){
                win = false;
                break;
            }
        }

        if(win) return player;

        // checking diagonal
        if((row == col) || (row + col == n-1)){
            // right Diagonal
            if(row == col){
                win = true;
                int i = 0, j = 0;
                while(i < n and j < n){
                    // cout<<"HI"<<" "<<player<<" "<<arr[i][j]<<endl;
                    if(arr[i][j] != player){
                        win = false;
                        break;
                    }
                    i++,j++;
                }
                if(win) return player;
            }

            // left Diagonal
           
            if(row + col == n-1){
                win = true;
                int i = 0, j = n-1;
                while(i < n and j >= 0){
                    if(arr[i][j] != player){
                        win = false;
                        break;
                    }
                    i++,j--;
                }
                if(win) return player;
            }
            
        }
        // for(auto it: arr){
        //     for(auto i: it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */