#include "udf.h"
#include "dynamesh_tools.h"
#include "math.h"

DEFINE_CG_MOTION(Block, dt, vel, omega, time, dtime)
{
vel[0]=(-234.323052601298)*pow(time,3)+(55.9108212609859)*pow(time,2)+(-23.5756370736617)*(time)+14.1956033788805;
vel[1]=(3476.36964103615)*pow(time,3)+(-574.603655579159)*pow(time,2)+(-34.4055184122235)*(time)+10.9038852107775;
vel[2]=-((-193.043374776284)*pow(time,3)+(530.965473051554)*pow(time,2)+(-88.8557686000158)*(time)+0.457061577459640);
omega[0]=(491293671.790596)*pow(time,6)+(-162430989.709866)*pow(time,5)+(19453960.0064384)*pow(time,4)+(-1031385.66064108)*pow(time,3)+(25819.3659773867)*pow(time,2)+(-289.769368385192)*(time)-16.0237220926469;
omega[1]=(706655567.142820)*pow(time,6)+(-210303982.463198)*pow(time,5)+(22726441.3596278)*pow(time,4)+(-1083662.59348897)*pow(time,3)+(22947.2138140694)*pow(time,2)+(-115.701200157958)*(time)+6.73395816374934;
omega[2]=(-81203013.7427942)*pow(time,6)+(41621858.0875511)*pow(time,5)+(-6701325.19177792)*pow(time,4)+(421777.321392863)*pow(time,3)+(-10841.3908406258)*pow(time,2)+(320.858472970971)*(time)-5.16246233041932;
}
