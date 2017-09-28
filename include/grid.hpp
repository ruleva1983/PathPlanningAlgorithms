#ifndef GRID_H_
#define GRID_H_

#include <utility>
#include <string>
#include <vector>
#include <random>
#include <cassert>
#include <cmath>

using namespace std;

class Grid{
public:
  Grid(int nx=10, int ny=10, float lx=1, float ly=1) : n_x(nx), n_y(ny), l_x(lx), l_y(ly){
    dx = l_x/static_cast<float>(n_x);
    dy = l_x/static_cast<float>(n_y);
  }
  
  std::pair< int, int > size() const{
    return std::make_pair( n_x, n_y );
    }
    
  std::pair< double, double > dim() const{
    return std::make_pair( l_x, l_y );
    }
  //void draw(std::string filename) const;
 
  std::pair<double, double> locate_cell(double x, double y) const{
    assert(x < l_x);
    assert(x > 0);
    assert(y < l_y);
    assert(y > 0);
    int nx = std::floor(x/l_x*n_x);
    int ny = std::floor(y/l_y*n_y);
    return {nx, ny};
    }
  
  
private:
  int n_x;
  int n_y;
  float l_x;
  float l_y;
  float dx;
  float dy;
};

class Maze{
public:
  Maze(Grid grid, std::string filename) : grid(grid){
      reset_values();
      read_maze(filename);
  }
  Maze(Grid grid, float filling = 0.1) : grid(grid){
      reset_values();
      random_maze(filling);
      
  }
  
  void reset_values(){
    int nx = grid.size().first;
    int ny = grid.size().second;
    grid_values.resize(nx);
    for (int i = 0 ; i < nx ; ++i){
        grid_values[i].resize(ny);
        for (int j = 0 ; j < ny ; ++j)
             grid_values[i][j] = 0.0;
        }
       
    }
    

    int& operator()(int i, int j){
        return grid_values[i][j];
    }


private:
  void read_maze(std::string filename);
  void random_maze(float filling){
  
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);
  
    int nx = grid.size().first;
    int ny = grid.size().second;
    for (int i = 0 ;  i < nx ; ++i){
        for (int j = 0; j < ny ; ++j){
        if(distribution(generator) < filling)
        grid_values[i][j] = 1;
        }
  }
}
  Grid grid;
  std::vector<std::vector<int>> grid_values;
};


#endif
