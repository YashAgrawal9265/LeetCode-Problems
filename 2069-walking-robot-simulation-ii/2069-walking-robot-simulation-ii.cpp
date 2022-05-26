class Robot {
private:
    string dir;
    int row;
    int col;
    int x;
    int y;
    int mod;
public:
    Robot(int width, int height) {
        col = height;
        row = width;
        dir = "East";
        x = 0;
        y = 0;
        mod = (row-1) + (col-1);
        mod *= 2;
        
    }
    
    void step(int num) {
//         if(x == 0 and y == 0) dir = "East";
//         if(x == 0 and y == col-1) dir = "North";
//         if(x == row-1 and y == col-1) dir = "West";
//         if(x == row-1 and y == 0) dir = "South";
        
//         if(dir == "East") x+=num;
//         else if(dir == "North") y+=num;
//         else if(dir == "West") x-=num;
//         else if(dir == "South") y-=num;
        num = num % mod;
        while(num){
            if(dir == "East"){
                int t = min(num,row-x-1);
                x += t;
                num -= t;
                if(num > 0) dir = "North";
            }
            else if(dir == "North"){
                int t = min(num,col-y-1);
                y += t;
                num -= t;
                if(num > 0) dir = "West";
            }
            else if(dir == "West"){
                int t = min(num,x);
                x -= t;
                num -= t;
                if(num > 0) dir = "South";
            }
            else if(dir == "South"){
                int t = min(num,y);
                y -= t;
                num -= t;
                if(num > 0) dir = "East";
            }
        }
        if(x == 0 and y == 0) dir = "South";
    }
    
    vector<int> getPos() {
        vector<int> result;
        result.push_back(x);
        result.push_back(y);
        return result;
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */