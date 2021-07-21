class Solution {
public:
	int titleToNumber(string columnTitle) {

		int column_number = 0;

		for(int col = columnTitle.size() - 1, position = 0; col >= 0; --col)
			column_number += (columnTitle[col] - 64) * pow(26, position++);

		return column_number;
	}
};