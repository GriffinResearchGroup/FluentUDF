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
real Vx;
real Vy;
real Vz;
real Sep_Fx;
real Sep_Mz;
real cg[ND_ND]; /*initialise*/

DEFINE_SDOF_PROPERTIES(Missile, prop, dt, time, dtime)
{
FILE* fp;
   prop[SDOF_MASS]       = 330.6276009;
   prop[SDOF_IXX]        = 29.41645817;
   prop[SDOF_IYY]        = 767.7691132;
   prop[SDOF_IZZ]        = 759.7897809;
   prop[SDOF_IXY]        = 23.69652244;
   prop[SDOF_IXZ]        = 0.000635626;
   prop[SDOF_IYZ]        = 0;

   if (time <= 0.0471)
   {
      Sep_Fx = -130470150184*pow(time,5) + 20694827653.7812*pow(time,4) - 1229644001.3096*pow(time,3) + 30156210.2186*pow(time,2) - 30145.5238*time - 11633.9948;
      Sep_Mz = -(-16269627727.8125*pow(time,5) + 2580645008.4063*pow(time,4) - 153336606.963*pow(time,3) + 3760479.4142*pow(time,2) - 3759.1468*time - 1450.7592);
      prop[SDOF_LOAD_F_X] = Sep_Fx;
      prop[SDOF_LOAD_M_Z] = Sep_Mz;
   }

fp = fopen("M_Z.txt", "a");
fprintf(fp, "%g %g \n", time, prop[SDOF_LOAD_M_Z]);
fclose(fp);

wx = DT_OMEGA_CG(dt)[0];
wy = DT_OMEGA_CG(dt)[1];
wz = DT_OMEGA_CG(dt)[2];
Vx = DT_VEL_CG(dt)[0];
Vy = DT_VEL_CG(dt)[1];
Vz = DT_VEL_CG(dt)[2];


Domain *d1 = Get_Domain(1); /* for single phase flow*/
Thread *t_object1 = Lookup_Thread(d1, 138); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force1[ND_ND];
real moment1[ND_ND];
cg[0]=DT_CG(dt)[0];
cg[1]=DT_CG(dt)[1];
cg[2]=DT_CG(dt)[2];

Compute_Force_And_Moment (d1,t_object1,cg,force1,moment1,TRUE);

real fx_w = force1[0]; /* force components of surface "Boundary_ID" */
real fy_w = force1[1];
real fz_w = force1[2];
real mx_w = moment1[0]; /* moment components */
real my_w = moment1[1];
real mz_w = moment1[2];

Domain *d2 = Get_Domain(1); /* for single phase flow*/
Thread *t_object2 = Lookup_Thread(d2, 144); /* you get Boundary_ID from the boundary condition panel in Fluent*/
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
Thread *t_object3 = Lookup_Thread(d3, 146); /* you get Boundary_ID from the boundary condition panel in Fluent*/
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
Thread *t_object4 = Lookup_Thread(d4, 141); /* you get Boundary_ID from the boundary condition panel in Fluent*/
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
Thread *t_object5 = Lookup_Thread(d5, 140); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force5[ND_ND];
real moment5[ND_ND];

Compute_Force_And_Moment (d5,t_object5,cg,force5,moment5,TRUE);

real fx_f = force5[0]; /* force components of surface "Boundary_ID" */
real fy_f = force5[1];
real fz_f = force5[2];
real mx_f = moment5[0]; /* moment components */
real my_f = moment5[1];
real mz_f = moment5[2];

Domain *d6 = Get_Domain(1); /* for single phase flow*/
Thread *t_object6 = Lookup_Thread(d6, 142); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force6[ND_ND];
real moment6[ND_ND];

Compute_Force_And_Moment (d6,t_object6,cg,force6,moment6,TRUE);

real fx_fr = force6[0]; /* force components of surface "Boundary_ID" */
real fy_fr = force6[1];
real fz_fr = force6[2];
real mx_fr = moment6[0]; /* moment components */
real my_fr = moment6[1];
real mz_fr = moment6[2];

Domain *d7 = Get_Domain(1); /* for single phase flow*/
Thread *t_object7 = Lookup_Thread(d7, 145); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force7[ND_ND];
real moment7[ND_ND];

Compute_Force_And_Moment (d7,t_object7,cg,force7,moment7,TRUE);

real fx_ft = force7[0]; /* force components of surface "Boundary_ID" */
real fy_ft = force7[1];
real fz_ft = force7[2];
real mx_ft = moment7[0]; /* moment components */
real my_ft = moment7[1];
real mz_ft = moment7[2];

Domain *d8 = Get_Domain(1); /* for single phase flow*/
Thread *t_object8 = Lookup_Thread(d8, 139); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force8[ND_ND];
real moment8[ND_ND];

Compute_Force_And_Moment (d8,t_object8,cg,force8,moment8,TRUE);

real fx_wt = force8[0]; /* force components of surface "Boundary_ID" */
real fy_wt = force8[1];
real fz_wt = force8[2];
real mx_wt = moment8[0]; /* moment components */
real my_wt = moment8[1];
real mz_wt = moment8[2];

Domain *d9 = Get_Domain(1); /* for single phase flow*/
Thread *t_object9 = Lookup_Thread(d9, 143); /* you get Boundary_ID from the boundary condition panel in Fluent*/
real force9[ND_ND];
real moment9[ND_ND];

Compute_Force_And_Moment (d9,t_object9,cg,force9,moment9,TRUE);

real fx_s = force9[0]; /* force components of surface "Boundary_ID" */
real fy_s = force9[1];
real fz_s = force9[2];
real mx_s = moment9[0]; /* moment components */
real my_s = moment9[1];
real mz_s = moment9[2];

Fx=fx_w+fx_tf+fx_bt+fx_n+fx_f+fx_fr+fx_ft+fx_wt+fx_s;
Fy=fy_w+fy_tf+fy_bt+fy_n+fy_f+fy_fr+fy_ft+fy_wt+fy_s;
Fz=fz_w+fz_tf+fz_bt+fz_n+fz_f+fz_fr+fz_ft+fz_wt+fz_s;
Mx=mx_w+mx_tf+mx_bt+mx_n+mx_f+mx_fr+mx_ft+mx_wt+mx_s;
My=my_w+my_tf+my_bt+my_n+my_f+my_fr+my_ft+my_wt+my_s;
Mz=mz_w+mz_tf+mz_bt+mz_n+mz_f+mz_fr+mz_ft+mz_wt+mz_s;
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

DEFINE_REPORT_DEFINITION_FN(Velx)
{
return Vx;
}

DEFINE_REPORT_DEFINITION_FN(Vely)
{
return Vy;
}

DEFINE_REPORT_DEFINITION_FN(Velz)
{
return Vz;
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