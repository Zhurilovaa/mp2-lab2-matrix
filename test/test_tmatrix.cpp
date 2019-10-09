#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(3);//создали матрицу

	for (int i = 0; i < 3; ++i)//заполнили её единицами
		for (int j = i; j < 3; ++j)
			m1[i][j] = 1;

	TMatrix<int> m2 = m1;//вызвали конструктор копирования
	EXPECT_EQ(m1, m2);//ожидание равенства
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(2);//создали матрицу
	m1[0][0] = 1; m1[0][1] = 2; m1[1][1] = 3;//присвоили значение её элементам

	TMatrix<int> m2 = m1;//вызвали конструктор копирования

	EXPECT_NE(&(m2[0]), &(m1[0]));//ожидание неравенства
	EXPECT_NE(&(m2[1]), &(m1[1]));//ожидание неравенства
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(3);//создали матрицу

	ASSERT_NO_THROW(m.GetSize());//ожидание отсутствия исключений
	EXPECT_EQ(3, m.GetSize());//ожидание равенства
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(2);//создали матрицу

	ASSERT_NO_THROW(m[0][1] = 3);// ожидание отсутствия исключений
	m[0][1] = 3;//установили элемент
	EXPECT_EQ(3, m[0][1]);//ожидание равенства
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(2);//создали матрицу
	ASSERT_ANY_THROW(m[0][-1] = 1);//ожидание исключений
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(2);//создали матрицу
	ASSERT_ANY_THROW(m[20][10] = 2);//ожидание исключений
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(2);//создали матрицу
	m[0][0] = m[0][1] = m[1][1] = 3;//присвоили значение её элементам

	ASSERT_NO_THROW(m = m);//ожидание отсутствия исключений
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(2);//создали матрицу
	m[0][0] = 1; m[0][1] = 2; m[1][1] = 3;//присвоили значение её элементам

	TMatrix<int> m1(2);//создали матрицу

	ASSERT_NO_THROW(m1 = m);//ожидание отсутствия исключений
	EXPECT_EQ(1, m1[0][0]);//ожидание равенства
	EXPECT_EQ(2, m1[0][1]);//ожидание равенства
	EXPECT_EQ(3, m1[1][1]);//ожидание равенства
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(2);//создали матрицу
	m[0][0] = 1; m[0][1] = 2; m[1][1] = 3;//присвоили значение её элементам

	TMatrix<int> m1(10);//создали матрицу
	m1 = m;//выполнили присваивание

	EXPECT_EQ(2, m1.GetSize());//ожидание равенства
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(2);//создали матрицу
	m[0][0] = 1; m[0][1] = 2; m[1][1] = 3;//присвоили значение её элементам

	TMatrix<int> m1(10);//создали матрицу
	ASSERT_NO_THROW(m1 = m);//ожидание отсутствия исключений

	EXPECT_EQ(1, m1[0][0]);//ожидание равенства
	EXPECT_EQ(2, m1[0][1]);//ожидание равенства
	EXPECT_EQ(3, m1[1][1]);//ожидание равенства
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(2);//создали матрицу
	m1[0][0] = 10; m1[0][1] = 10; m1[1][1] = 10;//присвоили значение её элементам

	TMatrix<int> m2(2);//создали матрицу
	m2[0][0] = 10; m2[0][1] = 10; m2[1][1] = 10;//присвоили значение её элементам

	EXPECT_TRUE(m1 == m2);//ожидание истины(матрицы одинаковые)
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(2);//создали матрицу
	m[0][0] = 1; m[0][1] = 1; m[1][1] = 1;//присвоили значение её элементам

	EXPECT_TRUE(m == m);//ожидание истины(сравнение с собой)
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(2);//создали матрицу
	TMatrix<int> m2(3);//создали матрицу

	EXPECT_TRUE(m1 != m2);//ожидание истины(матрица разных размеров)
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(2);//создали матрицу
	m1[0][0] = 1; m1[0][1] = 1; m1[1][1] = 1;//присвоили значение её элементам

	TMatrix<int> m2(2);//создали матрицу
	m2[0][0] = 10; m2[0][1] = 10; m2[1][1] = 10;//присвоили значение её элементам

	TMatrix<int> m(4);//создали матрицу

	ASSERT_NO_THROW(m1 + m2);//ожидание отсутствия исключений
	m = m1 + m2;//выполнили сложение матриц

	EXPECT_EQ(11, m[0][0]);//ожидание равенства
	EXPECT_EQ(11, m[0][1]);//ожидание равенства
	EXPECT_EQ(11, m[1][1]);//ожидание равенства
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(2);//создали матрицу
	TMatrix<int> m2(3);//создали матрицу

	ASSERT_ANY_THROW(m1 + m2);//ожидание исключений
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(2);//создали матрицу
	m1[0][0] = 1; m1[0][1] = 1; m1[1][1] = 1;//присвоили значение её элементам

	TMatrix<int> m2(2);//создали матрицу
	m2[0][0] = 10; m2[0][1] = 10; m2[1][1] = 10;//присвоили значение её элементам

	TMatrix<int> m(4);//создали матрицу

	ASSERT_NO_THROW(m1 - m2);//ожидание отсутствия исключений
	m = m1 - m2;//выполнили вычитание

	EXPECT_EQ(-9, m[0][0]);//ожидание равенства
	EXPECT_EQ(-9, m[0][1]);//ожидание равенства
	EXPECT_EQ(-9, m[1][1]);//ожидание равенства
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(2);//создали матрицу
	TMatrix<int> m2(3);//создали матрицу

	ASSERT_ANY_THROW(m1 - m2);//ожидание исключений
}

