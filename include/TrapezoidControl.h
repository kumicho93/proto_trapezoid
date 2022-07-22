
#ifndef TARPEZOID_HEADER
#define TARPEZOID_HEADER

#include "../system/system.h"
#include "AccelerationDesigner.h"
//#include <iostream> //コンパイルエラーした
#include <ostream>
#include <cstdio>
#include <fstream>

using namespace std;

#define DEBUG_EV3
//#define DEBUG_SPIKE

#define JERK_MAX		(  100.0f)	
#define ACCEL_MAX		(  200.0f)	
#define VELOCITY_MAX	(  100.0f)	
#define VELOCITY_MIN	(    0.0f)	
#define EXECTION_COUNT	(   0.01f)	

#define PI				(3.141592653589793f)	

#ifdef DEBUG_EV3
#define RPS				(   2.31f)	
#define WHEEL_WIDTH		(	90.33f)	
#define V_MAX_WHEEL		(RPS * WHEEL_WIDTH * PI)	
#endif

#ifdef DEBUG_SPIKE
#define RPS				(   2.25f)
#define WHEEL_WIDTH		(100.0f)
#define V_MAX_WHEEL		(RPS * WHEEL_WIDTH * PI)	
#endif

class TrapezoidControl {
public:
	TrapezoidControl();
	~TrapezoidControl();

	TrapezoidControl( const TrapezoidControl &x );
	TrapezoidControl&operator=( const TrapezoidControl & ) { return *this; };

	float run(float input);
	int8_t setVelocity(float velocity);

	static TrapezoidControl &getInstance()
	{
		static TrapezoidControl TrapezoidControl_;
		return TrapezoidControl_;
	}

private:
	AccelDesigner ad;
	float run_time;
	float start;
	float target;
	float distance;
	float motor_revision;
	float pre_deviation;
	float pre_target;

	int8_t calc(void);

	float conversion();
};

#endif