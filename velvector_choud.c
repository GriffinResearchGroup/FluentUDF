/**********************************************************************
   choud_pu.c                                                         
   UDF for Choudhuri Pitchup Case
   written by Christopher Griffin
   1-1-2011
***********************************************************************/

#include "udf.h"

/* Define constants in SI units */
static real Re = 80000;
static real visc = 1.7894E-5;       /* N*s/m^2 */ 
static real dens = 1.225;           /* kg/m^3 */
static real chord = 0.2921;           /* m */
static real ndprate = 0.047;

DEFINE_PROFILE(x_velocity, thread, position) 
{
  face_t f;
  real t = CURRENT_TIME;
  real aprate, prate, Vmag, aoa, t_o;

/* Define the important pitching rate in rad/s */
  Vmag = (Re*visc)/(dens*chord);
  aprate = (ndprate*Vmag)/chord; /*Asymptotic pitching rate*/
  t_o = (0.5*chord)/Vmag; /*Time at which the pitch rate has reach 99% of asymptotic pitching rate*/
  prate = aprate*(1-exp((-4.6*t)/t_o)); /*Pitch rate that varies with time*/

/* Calculate current aoa */
  aoa = t*prate;

/* Loop through the inlet boundary and assign x velocity component */
  begin_f_loop(f, thread)
    {
      F_PROFILE(f, thread, position) = sqrt((Vmag*Vmag)/(1+(tan(aoa))));
    }
  end_f_loop(f, thread)
}

DEFINE_PROFILE(y_velocity, thread, position) 
{
  face_t f;
  real t = CURRENT_TIME;
  real aprate,prate, Vmag, aoa, t_o;

/* Define the important pitching rate in rad/s */
  Vmag = (Re*visc)/(dens*chord);
  aprate = (ndprate*Vmag)/chord; /*Asymptotic pitching rate*/
  t_o = (0.5*chord)/Vmag; /*Time at which the pitch rate has reach 99% of asymptotic pitching rate*/
  prate = aprate*(1-exp((-4.6*t)/t_o)); /*Pitch rate that varies with time*/

/* Calculate current aoa */
  aoa = t*prate;

/* Loop through the inlet boundary and assign y velocity component */
  begin_f_loop(f, thread)
    {   
      F_PROFILE(f, thread, position) = tan(aoa)*sqrt((Vmag*Vmag)/(1+(tan(aoa))));
    }
  end_f_loop(f, thread)
}
