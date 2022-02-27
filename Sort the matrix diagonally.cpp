class Solution {
public:
    
    void sorting(int r,int c,vector<vector<int>>& mat)
    {
        int row=mat.size();
        int col=mat[0].size();
        vector<int> temp;
        
        int i=r;
        int j=c;
        while(i<row && j<col)
        {
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }
        
        sort(temp.begin(),temp.end());
        int ptr=0;
        
        i=r;
        j=c;
        while(i<row && j<col)
        {
            mat[i][j]=temp[ptr++];
            i++;
            j++;
        }
        
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        
        for(int i=0 ; i<row ; i++)
        {
            sorting(i,0,mat);
        }
        
        for(int j=0 ; j<col ; j++)
        {
            sorting(0,j,mat);
        }
        
        return mat;
    }
};
