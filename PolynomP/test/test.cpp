#include <gtest/gtest.h>
#include "Polynom.h"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(PolynomTest, EmptyPolynomsEqual) {
	Polynom A, B;
	EXPECT_TRUE(A == B);
}

TEST(PolynomTest, AddMonomBasic) {
	Polynom A;
	A.addMonom(2, 100);

	Polynom expected;
	expected.addMonom(2, 100);

	EXPECT_TRUE(A == expected);
}

TEST(PolynomTest, AddMonomCombineLikeTerms) {
	Polynom A;
	A.addMonom(2, 100);
	A.addMonom(3, 100);

	Polynom expected;
	expected.addMonom(5, 100);

	EXPECT_TRUE(A == expected);
}

TEST(PolynomTest, AddMonomRemoveZero) {
	Polynom A;
	A.addMonom(2, 100);
	A.addMonom(-2, 100);

	Polynom empty;
	EXPECT_TRUE(A == empty);
}

TEST(PolynomTest, AdditionSimple) {
	Polynom A;
	A.addMonom(2, 100);

	Polynom B;
	B.addMonom(3, 100);

	Polynom expected;
	expected.addMonom(5, 100);

	EXPECT_TRUE((A + B) == expected);
}

TEST(PolynomTest, AdditionDifferentDegrees) {
	Polynom A;
	A.addMonom(2, 100);

	Polynom B;
	B.addMonom(3, 10);

	Polynom expected;
	expected.addMonom(2, 100);
	expected.addMonom(3, 10);

	EXPECT_TRUE((A + B) == expected);
}

TEST(PolynomTest, AdditionCancelTerms) {
	Polynom A;
	A.addMonom(2, 100);

	Polynom B;
	B.addMonom(-2, 100);

	Polynom expected;
	EXPECT_TRUE((A + B) == expected);
}

TEST(PolynomTest, SubtractionBasic) {
	Polynom A;
	A.addMonom(5, 100);

	Polynom B;
	B.addMonom(3, 100);

	Polynom expected;
	expected.addMonom(2, 100);

	EXPECT_TRUE((A - B) == expected);
}

TEST(PolynomTest, SubtractionNegativeResult) {
	Polynom A;
	A.addMonom(2, 100);

	Polynom B;
	B.addMonom(5, 100);

	Polynom expected;
	expected.addMonom(-3, 100);

	EXPECT_TRUE((A - B) == expected);
}

TEST(PolynomTest, MultiplyByScalar) {
	Polynom A;
	A.addMonom(2, 100);

	Polynom expected;
	expected.addMonom(4, 100);

	EXPECT_TRUE((A * 2.0) == expected);
}

TEST(PolynomTest, MultiplyByZero) {
	Polynom A;
	A.addMonom(2, 100);

	Polynom expected;
	EXPECT_TRUE((A * 0.0) == expected);
}

TEST(PolynomTest, MultiplySimple) {
	Polynom A;
	A.addMonom(2, 100);

	Polynom B;
	B.addMonom(3, 10);

	Polynom expected;
	expected.addMonom(6, 110);

	EXPECT_TRUE((A * B) == expected);
}

TEST(PolynomTest, MultiplyCombineLikeTerms) {
	Polynom A;
	A.addMonom(1, 100);
	A.addMonom(1, 100);

	Polynom B;
	B.addMonom(1, 0);

	Polynom expected;
	expected.addMonom(2, 100);

	EXPECT_TRUE((A * B) == expected);
}

TEST(PolynomTest, MultiplyMultipleTerms) {
	Polynom A;
	A.addMonom(2, 100);
	A.addMonom(1, 10);

	Polynom B;
	B.addMonom(3, 10);

	Polynom expected;
	expected.addMonom(6, 110);
	expected.addMonom(3, 20);

	EXPECT_TRUE((A * B) == expected);
}

TEST(PolynomTest, MultiplyWithZero) {
	Polynom A;
	Polynom B;
	B.addMonom(3, 100);

	Polynom expected;
	EXPECT_TRUE((A * B) == expected);
}

TEST(PolynomTest, DegreeOverflow) {
	Polynom A;
	A.addMonom(1, 900);

	Polynom B;
	B.addMonom(1, 200);

	EXPECT_THROW(A * B, std::runtime_error);
}

TEST(PolynomTest, UnsortedInputBecomesSorted) {
	Polynom A;
	A.addMonom(1, 10);
	A.addMonom(1, 100);

	Polynom expected;
	expected.addMonom(1, 100);
	expected.addMonom(1, 10);
	EXPECT_TRUE(A == expected);
}