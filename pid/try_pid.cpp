#include<iostream>
using namespace std;

class PID{
    private:
        double _dt;
        double _max;
        double _min;
        double _Kp;
        double _Kd;
        double _Ki;
        double _pre_error;
        double _integral;
    public:
        PID(double dt, double max, double min, double Kp, double Kd, double Ki);
        double calculate(double setpoint, double pv);
};

PID::PID(double dt, double max, double min, double Kp, double Kd, double Ki){
    _dt = dt;
    _max = max;
    _min = min;
    _Kp = Kp;
    _Kd = Kd;
    _Ki = Ki;
    _pre_error = 0;
    _integral = 0;

}

double PID::calculate(double setpoint, double pv){
    // Calculate error
    double error = setpoint - pv;

    // Proportional term
    double Pout = _Kp * error;

    // Integral term
    _integral += error * _dt;
    double Iout = _Ki * _integral;

    // Derivative term
    double derivative = (error - _pre_error) / _dt;
    double Dout = _Kd * derivative;

    // Calculate total output
    double output = Pout + Iout + Dout;

    // Restrict to max/min
    if( output > _max )
        output = _max;
    else if( output < _min )
        output = _min;

    // Save error to previous error
    _pre_error = error;

    return output;
}


int main(){
    PID mypid(0.1, 100, -100, 0.1, 0.01, 0.5);
    double val = 20;

    for(int i=0; i<100;i++){
        double inc = mypid.calculate(0, val);
        printf("val:% 7.3f inc:% 7.3f\n", val, inc);
        val += inc;
    }
    
    return 0;
}
