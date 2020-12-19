//violence 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto temp=matrix;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                temp[j][n-i-1]=matrix[i][j];
            }
        }
        matrix=temp;
    }
};

//原地旋转
//row = col col = n-row-1
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n/2;++i)
        {
            for(int j=0;j<(n+1)/2;++j)
            {
                int temp = matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};

//先上下反转，再对角线反转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //上下翻转
        for(int i =0;i<n/2;++i)
        {
            for(int j =0;j<n;++j)
            {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
        //对角线反转
        for(int i=0;i<n;++i)
        {
            for(int j =i;j<n;++j)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
