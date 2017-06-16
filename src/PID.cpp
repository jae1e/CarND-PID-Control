#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;

	i_error_ = 0.0;
	p_error_ = 0.0;
	d_error_ = 0.0;

	prev_cte_ = 0.0;
	int_cte_ = 0.0;

	error_ = 0.0;
}

void PID::UpdateError(double cte) {
	double diff_cte = cte - prev_cte_;
	prev_cte_ = cte;
	int_cte_ += cte;
	error_ = Kp_ * cte + Kd_ * diff_cte + Ki_ * int_cte_;
}

double PID::TotalError() {
	return error_;
}

