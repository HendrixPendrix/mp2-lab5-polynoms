#include <polynom.h>
#include <gtest.h>

TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom p("x+y"));
}

TEST(Polynom, can_transform_coeff_to_string)
{
	Polynom q;
	EXPECT_EQ(q.Const("23"), 23);
}
TEST(Polynom, can_assign_polinoms)
{
	Polynom p1("x+y");
	Polynom p2("x+y+z");
	ASSERT_NO_THROW(p2 = p1);
}

TEST(Monom, can_add_monom)
{
	Monom m;
	ASSERT_NO_THROW(m + m);
}

