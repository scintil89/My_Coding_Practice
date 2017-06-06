#include <iostream>

int arr[9][9] = { 0, };
int count = 1;

void print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf_s(" %2d", arr[i][j]);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void spiral(int col, int row, int s_col, int s_row) //start col, start row
{
	if (col > s_col && row > s_row)
	{
		for (int i = s_row; i < row; i++)
		{
			arr[s_col][i] = count++;
			print();
		}
		s_col++;

		for (int i = s_col; i < col; i++)
		{
			arr[i][row-1] = count++;
			print();
		}
		row--;
		
		for (int i = row-1; i >= s_row; i--)
		{
			arr[col-1][i] = count++;
			print();
		}
		col--;
		
		for (int i = col-1; i >= s_col; i--)
		{
			arr[i][s_row] = count++;
			print();
		}
		s_row++;
		
		spiral(col, row, s_col, s_row);
	}
}

int main(void)
{
	int col = 9;
	int row = 9;
	int* count = new int();

	*count = 1;

	spiral(col, row, 0, 0);

	print();

	getchar();

	return 0;
}