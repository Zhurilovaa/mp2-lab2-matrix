#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//присвоили значение элементам
	TVector<int> v2 = v1;//создаем копию
	EXPECT_EQ(v1, v2);
 }

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//присвоили значение элементам
	TVector<int> v2 = v1;//создаем копию
	EXPECT_NE(&(v2[0]), &(v1[0]));
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(3);//создали вектор
	ASSERT_ANY_THROW(v[-3] = 3);//ожидание исключений
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(3);//создали вектор
	ASSERT_ANY_THROW(v[100000] = 3);//ожидание исключений
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(3);//создали вектор
	v[0] = 1; v[1] = 2; v[2] = 3;//заполнили поля
	ASSERT_NO_THROW(v = v);//ожидание исключений
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(3), v2(3);//создали вектора
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля первого вектора

	ASSERT_NO_THROW(v2 = v1);//ожидание отсутствия исключений
	v2 = v1;//присваиваем

	EXPECT_EQ(v1, v2);//ожидание равенства
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(3), v2(10);//создали вектора
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля первого вектора

	v2 = v1;//присваиваем
	EXPECT_EQ(3, v2.GetSize());//ожидание равенства
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(3), v2(10);//создали вектора
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля первого вектора

	ASSERT_NO_THROW(v2 = v1);//ожидание отсутствия исключений
	EXPECT_EQ(v1, v2);//ожидание равенства
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля первого вектора

	TVector<int> v2(3);//создали вектор
	v2[0] = 1; v2[1] = 2; v2[2] = 3;//заполнили поля второго вектора

	EXPECT_TRUE(v1 == v2);//ожидание истины (вектора одинаковые)
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(3);//создали вектор
	v[0] = 1; v[1] = 2; v[2] = 3;//заполнили поля вектора

	EXPECT_TRUE(v == v);//ожидание истины (вектора одинаковые)
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля первого вектора

	TVector<int> v2(4);//создали вектор
	v2[0] = 1; v2[1] = 2; v2[2] = 3; v2[3] = 4;//заполнили поля второго вектора

	EXPECT_TRUE(v1 != v2);//ожидание истины (вектора разные)
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(3);//создали вектор
	v[0] = 1; v[1] = 2; v[2] = 3;//заполнили поля вектора

	int scalar = 2;//создали скаляр

	ASSERT_NO_THROW(v + scalar);//ожидание отсутствия исключений
	v = v + scalar;//выполнили сложение

	EXPECT_EQ(3, v[0]);//ожидание равенства
	EXPECT_EQ(4, v[1]);//ожидание равенства
	EXPECT_EQ(5, v[2]);//ожидание равенства
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3);//создали вектор
	v[0] = 1; v[1] = 2; v[2] = 3;//заполнили поля вектора

	int scalar = 2;//создали скаляр

	ASSERT_NO_THROW(v - scalar);//ожидание отсутствия исключений
	v = v - scalar;//выполнили вычитание

	EXPECT_EQ(-1, v[0]);//ожидание равенства
	EXPECT_EQ(0, v[1]);//ожидание равенства
	EXPECT_EQ(1, v[2]);//ожидание равенства
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3);//создали вектор
	v[0] = 1; v[1] = 2; v[2] = 3;//заполнили поля вектора

	int scalar = 2;//создали скаляр

	ASSERT_NO_THROW(v * scalar);//ожидание отсутствия исключений
	v = v * scalar;//выполнили умножение

	EXPECT_EQ(2, v[0]);//ожидание равенства
	EXPECT_EQ(4, v[1]);//ожидание равенства
	EXPECT_EQ(6, v[2]);//ожидание равенства
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля вектора

	TVector<int> v2(3);//создали вектор
	v2[0] = v2[1] = v2[2] = 3;//заполнили поля вектора

	TVector<int> v(3);//создали вектор

	ASSERT_NO_THROW(v1 + v2);//ожидание отсутствия исключений
	v = v1 + v2;//выполнили сложение

	EXPECT_EQ(4, v[0]);//ожидание равенства
	EXPECT_EQ(5, v[1]);//ожидание равенства
	EXPECT_EQ(6, v[2]);//ожидание отсутствия исключений
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля вектора

	TVector<int> v2(4);//создали вектор
	v2[0] = v2[1] = v2[2] = v2[3] = 3;//заполнили поля вектора

	ASSERT_ANY_THROW(v1 + v2);//ожидание отсутствия исключений
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля вектора

	TVector<int> v2(3);//создали вектор
	v2[0] = v2[1] = v2[2] = 3;//заполнили поля вектора

	TVector<int> v(3);//создали вектор

	ASSERT_NO_THROW(v1 - v2);//ожидание отсутствия исключений
	v = v1 - v2;//выполнили вычитание

	EXPECT_EQ(-2, v[0]);//ожидание равенства
	EXPECT_EQ(-1, v[1]);//ожидание равенства
	EXPECT_EQ(0, v[2]);//ожидание равенства
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[0] = 2; v1[0] = 3;//заполнили поля вектора

	TVector<int> v2(4);//создали вектор
	v2[0] = v2[1] = v2[2] = v2[3] = 0;//заполнили поля вектора

	ASSERT_ANY_THROW(v1 - v2);//ожидание отсутствия исключений
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля вектора

	TVector<int> v2(3);//создали вектор
	v2[0] = v2[1] = v2[2] = 2;//заполнили поля вектора

	int scalar;//создали скаляр(результат скалярного произведения)

	ASSERT_NO_THROW(v1 * v2);//ожидание отсутствия исключений
	scalar = v1 * v2;//скалярно умножили вектора

	EXPECT_EQ(12, scalar);//ожидание равенства
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(3);//создали вектор
	v1[0] = 1; v1[1] = 2; v1[2] = 3;//заполнили поля вектора

	TVector<int> v2(4);//создали вектор
	v2[0] = v2[1] = v2[2] = v2[3] = 2;//заполнили поля вектора

	ASSERT_ANY_THROW(v1 * v2);//ожидание отсутствия исключений
}

