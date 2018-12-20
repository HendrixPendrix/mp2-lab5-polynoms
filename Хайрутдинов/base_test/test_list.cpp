#include "list.h"
#include <gtest.h>

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List <char> p);
}
TEST(List, can_push_element_with_negative_index)
{
	List <int> tmp;
	ASSERT_ANY_THROW(tmp.PushThis(5,-3));
}
TEST(List, can_delete_begin_element_when_list_is_empty)
{
	List <int> tmp;
	ASSERT_ANY_THROW(tmp.DelBegin());
}
TEST(List, can_delete_this_element_with_negative_index)
{
	List <int> tmp;
	ASSERT_ANY_THROW(tmp.DelThis(-3));
}