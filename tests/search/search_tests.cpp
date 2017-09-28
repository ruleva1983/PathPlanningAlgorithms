#include <gtest/gtest.h>
#include <iostream>

#include "search.hpp"

TEST(ToolsTest, ListElement)
    {
        List_Element list(0,0,0,0,10);
        ASSERT_EQ(list.x, 0);
        ASSERT_EQ(list.y, 0);
        ASSERT_EQ(list.cost, 10);
    }
