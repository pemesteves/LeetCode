class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow, currentRow;
        currentRow.push_back(1);
        
        for(int i = 1; i <= rowIndex; i++){
            lastRow = currentRow;
            currentRow.clear();
            currentRow.push_back(1);
            for(int j = 1; j < i; j++){
                currentRow.push_back(lastRow[j-1] + lastRow[j]);
            }
            currentRow.push_back(1);
        }
        return currentRow;
    }
};