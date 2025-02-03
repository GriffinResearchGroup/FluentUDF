#include "udf.h"
#include "dynamesh_tools.h"
#include "math.h"

DEFINE_CG_MOTION(Block, dt, vel, omega, time, dtime)
{
vel[0]=238.21;
vel[1]=0;
vel[2]=0;
omega[0]=0;
omega[1]=0;
omega[2]=0;
}
