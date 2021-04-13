class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		
		vector<vector<int>>pascalTriangle(numRows);

		for(int row = 0; row < numRows; ++row){
			pascalTriangle[row].resize(row + 1);
			pascalTriangle[row][0] = pascalTriangle[row][row] = 1;
			for(int col = 1; col < row; ++col)
				pascalTriangle[row][col] = pascalTriangle[row-1][col-1] + pascalTriangle[row-1][col]; 
		}
		return pascalTriangle;
	}
}; 