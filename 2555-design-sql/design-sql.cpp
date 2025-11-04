class Table{
public:
    int id;
    int column;
    map<int,vector<string>> row;
public:
    Table(){
        id = 1;
    }
    Table(int column){
        id = 1;
        this->column = column;
    }
    bool insertRow(vector<string> arr){
        // row.insert({id,arr});
        // id += 1;
        if(arr.size() != column) return false;
        row[id++] = arr;
        return true;
    }
    void deleteRow(int id){
        row.erase(id);
    }
    string select(int id, int col){
        if(row.find(id) == row.end()) return "<null>";
        if(col - 1 < 0 || col - 1 >= row[id].size()) return "<null>";
        return row[id][col-1];
    }
    vector<string> exp(){
        vector<string> result;
        
        for(auto it: row){
            string temp = "";
            temp += to_string(it.first) + ",";
            for(auto i: it.second){
                temp += i +",";
            }
            temp.pop_back();
            result.push_back(temp);
        }
        return result;
    }
};
class SQL {
public:
    map<string,Table> tables;
    SQL(vector<string>& names, vector<int>& columns) {
        for(int i=0;i<names.size();i++){
            tables.insert({names[i],Table(columns[i])});
        }
       
    }
    
    bool ins(string name, vector<string> row) {
        if(tables.find(name) == tables.end()) return false;
        
        return tables[name].insertRow(row);
        
    }
    
    void rmv(string name, int rowId) {
        if(tables.find(name)== tables.end()) return;
        tables[name].deleteRow(rowId);
    }
    
    string sel(string name, int rowId, int columnId) {
        if(tables.find(name)== tables.end()) return "<null>";
        return tables[name].select(rowId,columnId);
    }
    
    vector<string> exp(string name) {
        return tables[name].exp();
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */