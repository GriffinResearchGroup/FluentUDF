#include "udf.h"
#include "dynamesh_tools.h"
#include "math.h"

real wx;
real wy;
real wz;
real Fx;
real Fy;
real Fz;
real Mx;
real My;
real Mz;
real cg[ND_ND]; /*initialise*/

DEFINE_SDOF_PROPERTIES(Missile, prop, dt, time, dtime)
{
   prop[SDOF_MASS]       = 1.131775;
   prop[SDOF_IXX]        = 0.00204472;
   prop[SDOF_IYY]        = 0.0540954;
   prop[SDOF_IZZ]        = 0.052804;
   prop[SDOF_IXY]        = 0.0022241;
   prop[SDOF_IXZ]        = 0.000093268;
   prop[SDOF_IYZ]        = 0;

wx = DT_OMEGA_CG(dt)[0];
wy = DT_OMEGA_CG(dt)[1];
wz = DT_OMEGA_CG(dt)[2];


Domain *d1 = Get_Domain(1); /* for single phase flow*/
Thread *t_object1 = Lookup_Thread(d1, 28); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force1[ND_ND];
real moment1[ND_ND];
cg[0]=DT_CG(dt)[0];
cg[1]=DT_CG(dt)[1];
cg[2]=DT_CG(dt)[2];

Compute_Force_And_Moment (d1,t_object1,cg,force1,moment1,TRUE);

real fx_bf = force1[0]; /* force components of surface "Boundary_ID" */
real fy_bf = force1[1];
real fz_bf = force1[2];
real mx_bf = moment1[0]; /* moment components */
real my_bf = moment1[1];
real mz_bf = moment1[2];

Domain *d2 = Get_Domain(1); /* for single phase flow*/
Thread *t_object2 = Lookup_Thread(d2, 29); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force2[ND_ND];
real moment2[ND_ND];

Compute_Force_And_Moment (d2,t_object2,cg,force2,moment2,TRUE);

real fx_tf = force2[0]; /* force components of surface "Boundary_ID" */
real fy_tf = force2[1];
real fz_tf = force2[2];
real mx_tf = moment2[0]; /* moment components */
real my_tf = moment2[1];
real mz_tf = moment2[2];

Domain *d3 = Get_Domain(1); /* for single phase flow*/
Thread *t_object3 = Lookup_Thread(d3, 30); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force3[ND_ND];
real moment3[ND_ND];

Compute_Force_And_Moment (d3,t_object3,cg,force3,moment3,TRUE);

real fx_bt = force3[0]; /* force components of surface "Boundary_ID" */
real fy_bt = force3[1];
real fz_bt = force3[2];
real mx_bt = moment3[0]; /* moment components */
real my_bt = moment3[1];
real mz_bt = moment3[2];

Domain *d4 = Get_Domain(1); /* for single phase flow*/
Thread *t_object4 = Lookup_Thread(d4, 31); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force4[ND_ND];
real moment4[ND_ND];

Compute_Force_And_Moment (d4,t_object4,cg,force4,moment4,TRUE);

real fx_n = force4[0]; /* force components of surface "Boundary_ID" */
real fy_n = force4[1];
real fz_n = force4[2];
real mx_n = moment4[0]; /* moment components */
real my_n = moment4[1];
real mz_n = moment4[2];

Domain *d5 = Get_Domain(1); /* for single phase flow*/
Thread *t_object5 = Lookup_Thread(d5, 32); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force5[ND_ND];
real moment5[ND_ND];

Compute_Force_And_Moment (d5,t_object5,cg,force5,moment5,TRUE);

real fx_f = force5[0]; /* force components of surface "Boundary_ID" */
real fy_f = force5[1];
real fz_f = force5[2];
real mx_f = moment5[0]; /* moment components */
real my_f = moment5[1];
real mz_f = moment5[2];

Fx=fx_bf+fx_tf+fx_bt+fx_n+fx_f;
Fy=fy_bf+fy_tf+fy_bt+fy_n+fy_f;
Fz=fz_bf+fz_tf+fz_bt+fz_n+fz_f;
Mx=mx_bf+mx_tf+mx_bt+mx_n+mx_f;
My=my_bf+my_tf+my_bt+my_n+my_f;
Mz=mz_bf+mz_tf+mz_bt+mz_n+mz_f;
}

DEFINE_REPORT_DEFINITION_FN(Forcex)
{
return Fx;
}

DEFINE_REPORT_DEFINITION_FN(Forcey)
{
return Fy;
}
DEFINE_REPORT_DEFINITION_FN(Forcez)
{
return Fz;
}
DEFINE_REPORT_DEFINITION_FN(Momentx)
{
return Mx;
}
DEFINE_REPORT_DEFINITION_FN(Momenty)
{
return My;
}
DEFINE_REPORT_DEFINITION_FN(Momentz)
{
return Mz;
}

DEFINE_CG_MOTION(Follower_Fluid,dt,vel,omega,time,dtime)
{
NV_S (vel, = , 0.0);
NV_S (omega, = , 0.0);
vel[0]=0;
vel[1]=0;
vel[2]=0;
omega[0]=-wx;
omega[1]=-wy;
omega[2]=-wz;
}