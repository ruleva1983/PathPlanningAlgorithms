#include <gtest/gtest.h>
#include <iostream>

#include "grid.hpp"

TEST(ToolsTest, Grid_Class)
{
    Grid grid;
    ASSERT_EQ(grid.size().first, 10);
    ASSERT_EQ(grid.size().second, 10);
    ASSERT_EQ(grid.dim().first, 1);
    ASSERT_EQ(grid.dim().second, 1);       
        
    double x = 0.11, y = 0.23;
    ASSERT_EQ(grid.locate_cell(x, y).first, 1);
    ASSERT_EQ(grid.locate_cell(x, y).second, 2);
}

    
TEST(ToolsTest, Maze_Class)
{
    Grid grid;
    Maze maze(grid, 0.2);
    
    maze(0,0) = 1;
    ASSERT_EQ(maze(0,0), 1);
    maze.reset_values();
    ASSERT_EQ(maze(0,0), 0);
    
    Maze maze2(grid, 0.2);
    int sum = 0;
    for (int i = 0 ; i < grid.size().first ; ++i){
        for (int j = 0 ; j < grid.size().second ; ++j)
            sum += maze2(i,j);
    }
    ASSERT_LE(sum, grid.size().first*grid.size().second * 0.4);
}
