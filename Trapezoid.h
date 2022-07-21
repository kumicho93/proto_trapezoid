///
/// @file 台形制御クラス
/// @note 台形式による速度制御クラス
/// @date 2022/06/29 谷口拓海
///
#include "mainHeader.h"
#include "AccelerationDesigner.h"

#ifndef TARPEZOID_HEADER
#define TARPEZOID_HEADER

#include <iostream>
#include <ostream>
#include <cstdio>
#include <fstream>

using namespace std;

#define DEBUG_EV3
//#define DEBUG_SPIKE

#define JERK_MAX		(  100.0f)				/* 最大躍度					 */
#define ACCEL_MAX		(  200.0f)				/* 最大加速度				 */
#define VELOCITY_MAX	(  100.0f)				/* 最大速度					 */
#define VELOCITY_MIN	(    0.0f)				/* 最低速度					 */
#define EXECTION_COUNT	(   0.01f)				/* 経過時間					 */

#define PI				(3.141592653589793f)	/* 円周率					 */

#ifdef DEBUG_EV3
#define RPS				(   2.31f)				/* モーターの回転速度 [r/s]	 */
#define WHEEL_WIDTH		(	90.33f)				/* 車輪の直径(mm)			 */
#define V_MAX_WHEEL		(RPS * WHEEL_WIDTH * PI)	
												/* 最大回転速度				 */
#endif

#ifdef DEBUG_SPIKE
#define RPS				(   2.25f)				/* モーターの回転速度 [r/s]	 */
#define WHEEL_WIDTH		(100.0f)				/* 車輪の直径(mm)			 */
#define V_MAX_WHEEL		(RPS * WHEEL_WIDTH * PI)	
												/* 最大回転速度				 */
#endif



class Trapezoid {
public:
	Trapezoid();
	~Trapezoid();

	float run(float input);
	int8_t setVelocity(float velocity);

	static Trapezoid& getInstance()
	{
		static Trapezoid Trapezoid_;	// インスタンスの生成
		return Trapezoid_;
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