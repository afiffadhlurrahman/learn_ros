#include<iostream>
#include<ctime>
#include<unistd.h>

using namespace std;

class PID{
    private:
        double _Kp;
        double _Kd;
        double _Ki;
        double _pre_error;
        double _integral;
        time_t current_time;
        double now_time;
        double prev_time;
        bool timeFlag;

    public:
        PID(double Kp, double Kd, double Ki);
        double calculate(double error);
};

PID::PID(double Kp, double Kd, double Ki){
    timeFlag = false;
    if(timeFlag == false){
        current_time = time(NULL);
        now_time = (double) current_time;
        timeFlag =  true;
    }

    _Kp = Kp;
    _Kd = Kd;
    _Ki = Ki;
    _pre_error = 0;
    _integral = 0;
    prev_time = now_time;
}

double PID::calculate(double error){
    timeFlag = false;
    if(timeFlag == false){
        current_time = time(NULL);
        now_time = (double) current_time;
        timeFlag =  true;
    }
    double dt = now_time-prev_time;
    // printf("%.3f \n",dt);

    if( dt <= 0.0f ){
        // printf("return zero\n");
        return 0;
    }
    

    // Calculate error
    double de = error - _pre_error;

    // Proportional term
    double Pout = _Kp * error;

    // Integral term
    _integral += error * dt;
    double Iout = _Ki * _integral;

    // Derivative term
    double derivative = de / dt;
    double Dout = _Kd * derivative;

    // Calculate total output
    double output = Pout + Iout + Dout;

    // Save error to previous error
    _pre_error = error;
    prev_time = now_time;

    return output;
}


int main(){
    PID mypid(0.6, 0.01, 0.5);
    double val = 20;
    double inc;
    // for(int i=0; i<5;i++){
    //     double inc = mypid.calculate(0, val);
    //     printf("val:% 7.3f inc:% 7.3f\n", val, inc);
    //     val += inc;
    // }

    for(int i=0;i<20;i++){
        inc = mypid.calculate(val);
        printf("val:% 7.3f inc:% 7.3f\n", val, inc);
        val -= inc;

        sleep(5);
    }

    return 0;
}
