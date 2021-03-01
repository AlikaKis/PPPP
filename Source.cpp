#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function for hand filling matrix
int** InputMatrixOnHand(int** Matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			cin >> Matrix[i][j];
	return Matrix;
}

//Function for random filling matrix
int** RandomInputMatrix(int** Matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			Matrix[i][j] = rand() % 10;
	return Matrix;
}

//Function for print matrix
void MatrixOutput(int** Matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}
}

//Function for decomposition matrix to submatrix
void DecompositiontoSubMatrix(int** subMatrix1, int** subMatrix2, int** subMatrix3, int** subMatrix4, int** ReductionMatrix, int length_required_matrix) {
	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		subMatrix1[i] = new int[length_required_matrix / 2];
		for (int j = 0; j < length_required_matrix / 2; j++)
			subMatrix1[i][j] = ReductionMatrix[i][j];
	}
	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		subMatrix2[i] = new int[length_required_matrix / 2];
		for (int j = 0; j < length_required_matrix / 2; j++)
			subMatrix2[i][j] = ReductionMatrix[i][j + length_required_matrix / 2];
	}

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		subMatrix3[i] = new int[length_required_matrix / 2];
		for (int j = 0; j < length_required_matrix / 2; j++)
			subMatrix3[i][j] = ReductionMatrix[i + length_required_matrix / 2][j];
	}
	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		subMatrix4[i] = new int[length_required_matrix / 2];
		for (int j = 0; j < length_required_matrix / 2; j++)
			subMatrix4[i][j] = ReductionMatrix[i + length_required_matrix / 2][j + length_required_matrix / 2];
	}
}

//Function for balancing matrix size (length and width)
int LengthWidthEqual(int** Result_matrix, int length_or_width, int length_required_matrix) {
	int x = 0;
	for (int i = 0; i < length_required_matrix; i++)
	{
		x = 0;
		for (int j = 0; j < length_required_matrix; j++)
		{
			if (Result_matrix[i][j] != 0)
			{
				x++;
				length_or_width = 100;
			}
		}
		if (x == 0 && i < length_or_width)
		{
			length_or_width = i;
		}
	}
	return length_or_width;
}


int main()
{
	int rows1, columns1, rows2, columns2, switch_counter, length_required_matrix = 2;

	srand(time(NULL));


	system("chcp 1251");
	cout << "You are welcomed by the program" << endl <<
		"fast matrix multiplication by the Strassen method\n\n";

	//input matrix size
	do
	{
		cout << "Input size of first matrix\n";
		cin >> rows1 >> columns1;
	} while (rows1 <= 0 || columns1 <= 0);
	do
	{
		cout << "Input size of second matrix\n";
		cin >> rows2 >> columns2;
	} while (rows2 <= 0 || columns2 <= 0);


	int** Matrix1 = new int* [rows1];
	for (int i = 0; i < rows1; i++)
		Matrix1[i] = new int[columns1];
	int** Matrix2 = new int* [rows2];
	for (int i = 0; i < rows2; i++)
		Matrix2[i] = new int[columns2];

	//Filling matrix with selected method(hand or authomatic)
	do
	{
		cout << "Choose a method for filling in the matrices\n" <<
			"1 - On hand \n2 - Randomly generated\n";
		cin >> switch_counter;
	} while (switch_counter < 1 || switch_counter > 2);
	switch (switch_counter)
	{
	case 1:
		Matrix1 = InputMatrixOnHand(Matrix1, rows1, columns1);
		Matrix2 = InputMatrixOnHand(Matrix2, rows2, columns2);
		cout << "\nMatrix 1\n\n";
		MatrixOutput(Matrix1, rows1, columns1);
		cout << "\nMatrix 2\n\n";
		MatrixOutput(Matrix2, rows2, columns2);
		break;
	case 2:
		Matrix1 = RandomInputMatrix(Matrix1, rows1, columns1);
		Matrix2 = RandomInputMatrix(Matrix2, rows2, columns2);
		cout << "\nMatrix 1\n\n";
		MatrixOutput(Matrix1, rows1, columns1);
		cout << "\nMatrix 2\n\n";
		MatrixOutput(Matrix2, rows2, columns2);
		break;
	}

	//Reduction matrix to required size
	while (length_required_matrix < rows1 || length_required_matrix < rows2 || length_required_matrix < columns1 || length_required_matrix < columns2)
		length_required_matrix *= 2;
	int** ReductionMatrix1 = new int* [length_required_matrix];
	for (int i = 0; i < length_required_matrix; i++)
	{
		ReductionMatrix1[i] = new int[length_required_matrix];
		for (int j = 0; j < length_required_matrix; j++)
			ReductionMatrix1[i][j] = 0;
	}
	int** ReductionMatrix2 = new int* [length_required_matrix];
	for (int i = 0; i < length_required_matrix; i++)
	{
		ReductionMatrix2[i] = new int[length_required_matrix];
		for (int j = 0; j < length_required_matrix; j++)
			ReductionMatrix2[i][j] = 0;
	}
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < columns1; j++)
			ReductionMatrix1[i][j] = Matrix1[i][j];
	}
	for (int i = 0; i < rows2; i++)
	{
		for (int j = 0; j < columns2; j++)
			ReductionMatrix2[i][j] = Matrix2[i][j];
	}
	cout << "Reduction matrix\n";
	cout << "\nMatrix 1\n\n";
	MatrixOutput(ReductionMatrix1, length_required_matrix, length_required_matrix);
	cout << "\nMatrix 2\n\n";
	MatrixOutput(ReductionMatrix2, length_required_matrix, length_required_matrix);

	//Decomposition matrix to submatrix and filling

	int** SubMat1 = new int* [length_required_matrix / 2];
	int** SubMat2 = new int* [length_required_matrix / 2];
	int** SubMat3 = new int* [length_required_matrix / 2];
	int** SubMat4 = new int* [length_required_matrix / 2];
	int** SubMat5 = new int* [length_required_matrix / 2];
	int** SubMat6 = new int* [length_required_matrix / 2];
	int** SubMat7 = new int* [length_required_matrix / 2];
	int** SubMat8 = new int* [length_required_matrix / 2];

	DecompositiontoSubMatrix(SubMat1, SubMat2, SubMat3, SubMat4, ReductionMatrix1, length_required_matrix);
	DecompositiontoSubMatrix(SubMat5, SubMat6, SubMat7, SubMat8, ReductionMatrix2, length_required_matrix);

	//Creation intermediate matrices
	int** intermediate_matrix_1 = new int* [length_required_matrix / 2];
	int** intermediate_matrix_2 = new int* [length_required_matrix / 2];
	int** intermediate_matrix_3 = new int* [length_required_matrix / 2];
	int** intermediate_matrix_4 = new int* [length_required_matrix / 2];
	int** intermediate_matrix_5 = new int* [length_required_matrix / 2];
	int** intermediate_matrix_6 = new int* [length_required_matrix / 2];
	int** intermediate_matrix_7 = new int* [length_required_matrix / 2];

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		intermediate_matrix_1[i] = new int[length_required_matrix / 2];
		intermediate_matrix_2[i] = new int[length_required_matrix / 2];
		intermediate_matrix_3[i] = new int[length_required_matrix / 2];
		intermediate_matrix_4[i] = new int[length_required_matrix / 2];
		intermediate_matrix_5[i] = new int[length_required_matrix / 2];
		intermediate_matrix_6[i] = new int[length_required_matrix / 2];
		intermediate_matrix_7[i] = new int[length_required_matrix / 2];
	}

	//Calculation values for intermediate matrices

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		for (int j = 0; j < length_required_matrix / 2; j++)
		{

			intermediate_matrix_1[i][j] = 0;
			intermediate_matrix_2[i][j] = 0;
			intermediate_matrix_3[i][j] = 0;
			intermediate_matrix_4[i][j] = 0;
			intermediate_matrix_5[i][j] = 0;
			intermediate_matrix_6[i][j] = 0;
			intermediate_matrix_7[i][j] = 0;

			for (int z = 0; z < length_required_matrix / 2; z++)
			{
				intermediate_matrix_1[i][j] += (SubMat1[i][z] + SubMat4[i][z]) * (SubMat5[z][j] + SubMat8[z][j]);
				intermediate_matrix_2[i][j] += (SubMat3[i][z] + SubMat4[i][z]) * SubMat5[z][j];
				intermediate_matrix_3[i][j] += SubMat1[i][z] * (SubMat6[z][j] - SubMat8[z][j]);
				intermediate_matrix_4[i][j] += SubMat4[i][z] * (SubMat7[z][j] - SubMat5[z][j]);
				intermediate_matrix_5[i][j] += (SubMat1[i][z] + SubMat2[i][z]) * SubMat8[z][j];
				intermediate_matrix_6[i][j] += (SubMat3[i][z] - SubMat1[i][z]) * (SubMat5[z][j] + SubMat6[z][j]);
				intermediate_matrix_7[i][j] += (SubMat2[i][z] - SubMat4[i][z]) * (SubMat7[z][j] + SubMat8[z][j]);
			}


		}
	}

	//Creation supplementary matrices

	int** SupplementaryMatrix_1 = new int* [length_required_matrix / 2];
	int** SupplementaryMatrix_2 = new int* [length_required_matrix / 2];
	int** SupplementaryMatrix_3 = new int* [length_required_matrix / 2];
	int** SupplementaryMatrix_4 = new int* [length_required_matrix / 2];

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		SupplementaryMatrix_1[i] = new int[length_required_matrix / 2];
		SupplementaryMatrix_2[i] = new int[length_required_matrix / 2];
		SupplementaryMatrix_3[i] = new int[length_required_matrix / 2];
		SupplementaryMatrix_4[i] = new int[length_required_matrix / 2];
	}
	//Calculation values of supplementary matrices from intermediate matrices

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		for (int j = 0; j < length_required_matrix / 2; j++)
		{
			SupplementaryMatrix_1[i][j] = intermediate_matrix_1[i][j] + intermediate_matrix_4[i][j] - intermediate_matrix_5[i][j] + intermediate_matrix_7[i][j];
			SupplementaryMatrix_2[i][j] = intermediate_matrix_3[i][j] + intermediate_matrix_5[i][j];
			SupplementaryMatrix_3[i][j] = intermediate_matrix_2[i][j] + intermediate_matrix_4[i][j];
			SupplementaryMatrix_4[i][j] = intermediate_matrix_1[i][j] - intermediate_matrix_2[i][j] + intermediate_matrix_3[i][j] + intermediate_matrix_6[i][j];
		}
	}

	//Creation resulting matrix

	int** Result_matrix = new int* [length_required_matrix];
	for (int i = 0; i < length_required_matrix; i++)
	{
		Result_matrix[i] = new int[length_required_matrix];
	}

	//Entering info from supplementary matrices into the resulting matrix

	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		for (int j = 0; j < length_required_matrix / 2; j++)
		{
			Result_matrix[i][j] = SupplementaryMatrix_1[i][j];
			Result_matrix[i][j + length_required_matrix / 2] = SupplementaryMatrix_2[i][j];
			Result_matrix[i + length_required_matrix / 2][j] = SupplementaryMatrix_3[i][j];
			Result_matrix[i + length_required_matrix / 2][j + length_required_matrix / 2] = SupplementaryMatrix_4[i][j];
		}
	}

	// The balancing of boundaries of the matrix
	int length = 100, width = 100;
	length = LengthWidthEqual(Result_matrix, length, length_required_matrix);
	width = LengthWidthEqual(Result_matrix, width, length_required_matrix);
	int** End_matrix = new int* [length];
	for (int i = 0; i < length; i++)
	{
		End_matrix[i] = new int[width];
		for (int j = 0; j < width; j++)
			End_matrix[i][j] = Result_matrix[i][j];
	}

	//Output resulting matrix
	cout << "\nResulting matrix\n\n";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
			cout << End_matrix[i][j] << " ";
		cout << endl;
	}

	system("pause");

	//Clearing dynamic memory

	for (int i = 0; i < rows1; i++)
		delete[] Matrix1[i];
	for (int i = 0; i < rows2; i++)
		delete[] Matrix2[i];
	for (int i = 0; i < length_required_matrix; i++)
	{
		delete[] ReductionMatrix1[i];
		delete[] ReductionMatrix2[i];
		delete[] Result_matrix[i];
	}
	for (int i = 0; i < length; i++)
		delete[] End_matrix[i];
	for (int i = 0; i < length_required_matrix / 2; i++)
	{
		delete[] SubMat1[i];
		delete[] SubMat2[i];
		delete[] SubMat3[i];
		delete[] SubMat4[i];
		delete[] SubMat5[i];
		delete[] SubMat6[i];
		delete[] SubMat7[i];
		delete[] SubMat8[i];
		delete[] SupplementaryMatrix_1[i];
		delete[] SupplementaryMatrix_2[i];
		delete[] SupplementaryMatrix_3[i];
		delete[] SupplementaryMatrix_4[i];
		delete[] intermediate_matrix_1[i];
		delete[] intermediate_matrix_2[i];
		delete[] intermediate_matrix_3[i];
		delete[] intermediate_matrix_4[i];
		delete[] intermediate_matrix_5[i];
		delete[] intermediate_matrix_6[i];
		delete[] intermediate_matrix_7[i];
	}
	delete[]Matrix1, Matrix1, ReductionMatrix1, ReductionMatrix2, Result_matrix, End_matrix;
	delete[] SupplementaryMatrix_1, SupplementaryMatrix_2, SupplementaryMatrix_3, SupplementaryMatrix_4,
		delete[] SubMat1, SubMat2, SubMat3, SubMat4, SubMat5, SubMat6, SubMat7, SubMat8;
	delete[] intermediate_matrix_1, intermediate_matrix_2, intermediate_matrix_3, intermediate_matrix_4, intermediate_matrix_5, intermediate_matrix_6, intermediate_matrix_7;
	return 0;
}