class SQL {
private:
    // {tableName -> {columns,rowCounter}}
    map<string,pair<int,int>> tableMap;

    // {tableName,rowId -> row detaisl}
    map<pair<string,int>,vector<string>> rowMap;
public:
    SQL(vector<string>& names, vector<int>& columns) {
        int n = names.size();
        for(int i=0;i<n;i++){
            tableMap[names[i]] = {columns[i],1};
        }
    }
    
    bool ins(string name, vector<string> row) {
        if(tableMap.find(name) == tableMap.end()) return false;
        if(row.size() != tableMap[name].first) return false;
        int counter = tableMap[name].second;
        rowMap[{name,counter}] = row;
        tableMap[name].second += 1;
        return true;
    }
    
    void rmv(string name, int rowId) {
        if(tableMap.find(name) == tableMap.end()) return;
        if(rowMap.find({name,rowId}) == rowMap.end()) return;
        rowMap.erase({name,rowId});
    }
    
    string sel(string name, int rowId, int columnId) {
        if(tableMap.find(name) == tableMap.end()) return "<null>";

        if(rowMap.find({name,rowId}) == rowMap.end()) return "<null>";
        if(columnId <= 0 || columnId - 1 >= tableMap[name].first) return "<null>";
        string result = rowMap[{name,rowId}][columnId - 1];
        return result;
    }
    
    vector<string> exp(string name) {
        if(tableMap.find(name) == tableMap.end()) return {};
        int counter = tableMap[name].second;
        vector<string> result;
        for(int i=1;i<counter;i++){
            string temp = "";
            if(rowMap.find({name,i}) != rowMap.end()){
                temp += to_string(i) + ",";
                for(auto it: rowMap[{name,i}]){
                    temp += it + ",";
                }
                temp.pop_back();
                result.push_back(temp);
            }
        }
        return result;
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