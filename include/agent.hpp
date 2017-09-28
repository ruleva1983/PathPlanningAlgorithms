#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

class AgentBase
{
public:
    virtual ~AgentBase(){}
 
    std::vector<double> getState() const {
        return state;
    }
    void setState(std::vector<double> newstate){
        assert (state.size() == newstate.size());
        std::copy(state.begin(), state.end(), newstate.begin());
    } 
    virtual void move(const std::vector<double>& actuators, double dt = 0) = 0;

protected:
    std::vector<double> state;

};

class Pedina : public AgentBase{
public:
  Pedina(int nx, int ny) {
    state.resize(2);
    state[0] = static_cast<double> (nx);
    state[1] = static_cast<double> (ny);
  }
  Pedina(std::vector<int> s){
    state.resize(2);
    std::copy( s.begin(), s.end(), state.begin() );
  }
  Pedina(std::vector<double> s){
    state = s;
  }
  
  void move(const std::vector<double>& actuators, double dt = 0){
        int dx = static_cast<int> (actuators[0]);
        int dy = static_cast<int> (actuators[1]);
        state[0] += dx;
        state[1] += dy;
  }
  
};


/*
class HeadedRobot : public AgentBase{
public:
  HeadedRobot(double x, double y, double theta, double v){
    state = std::vector<double> {x, y, theta, v};
  }
  HeadedRobot(std::vector<double> s) {
    state = s;
  }
  void move(const std::vector<double>& actuators, double dt){
    //double x = integrate(); use boost 
  }
private:
    
    double L = 1;
    void integrate(const std::vector<double>& actuators, double T){
        double delta = actuators[0];
        struct equations
        {
            equations(double d){delta = d;}
            void operator()( const std::vector<double> &state , std::vector<double> &statedot , double t ) const {
                        statedot[0] = state[3]*std::cos(state[2]);
                        statedot[1] = state[3]*std::sin(state[2]);
                        statedot[2] = state[3]*std::tan(delta);
                        statedot[3] = 0.0;
                }
            double delta;
        };
        
        equations dynamics(delta);
        
        controlled_runge_kutta< runge_kutta_dopri5< std::vector<double> > > stepper;
    
        const size_t max_attempts = 100;
        const char *error_string = "Integrate adaptive : Maximal number of iterations reached. A step size could not be found.";
    
        double start_time = 0, dt = T/10.0;
        while( start_time < T )
        {
        
            if( ( start_time + dt ) > T ){
                dt = T - start_time;
            }

            size_t trials = 0;
            controlled_step_result res = success;
            do {
                res = stepper.try_step( system , state , start_time , dt );
                ++trials;
            }
        while( ( res == fail ) && ( trials < max_attempts ) );
        if( trials == max_attempts ) throw std::overflow_error( error_string );
	
	
    }
    
    return start_state;
        
        
        
        
        
    }

};
*/



#endif
