class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool firstRow = false;
        bool firstCol = false;
        int sizeRow = matrix.size();
        int sizeCol = matrix[0].size();
        for(int i=0; i<sizeRow; ++i){
            if(matrix[i][0] == 0){
                firstCol = true;
                break;
            }
        }
        for(int i=0; i<sizeCol; ++i){
            if(matrix[0][i] == 0){
                firstRow = true;
                break;
            }
        }
        for(int i=1; i<sizeRow; ++i){
            for(int j=1; j<sizeCol; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<sizeRow; ++i){
            for(int j=1; j<sizeCol; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstRow){
            for(int i=0; i<sizeCol; ++i)
                matrix[0][i] = 0;
        }
        if(firstCol){
            for(int j=0; j<sizeRow; ++j)
                matrix[j][0] = 0;
        }
    }
};