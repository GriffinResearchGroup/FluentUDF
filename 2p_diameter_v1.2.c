/*********************************************************************/
/*  true sine hump UDF by Pete Gall                                  */
/*  Modified by Chris Griffin 12-10-2010                             */
/*  This UDF creates humps that vary with time                       */
/*********************************************************************/

#include "udf.h"

#define  omega      1.0          /* rotational speed, rad/sec        */

static real chord = 0.2921;         /* chord length in meters           */
static real amp = 0.0005;       /* amplitude in meters              */

DEFINE_GRID_MOTION(moving_arc_a01, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.00300587;
  y1 = chord * 0.00953755;
  x2 = chord * 0.01817429;
  y2 = chord * 0.02257284;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
	  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
	      /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x = NODE_X (node_p);
              y = NODE_Y (node_p);
              lp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh = amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              x = x1 + lp * cos(phi);
              y = y1 + lp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a02, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.01817429;
  y1 = chord * 0.02257284;
  x2 = chord * 0.03633963;
  y2=  chord * 0.03094065;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
          /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a03, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.03633963;
  y1 = chord * 0.03094065;
  x2 = chord * 0.05536385;
  y2 = chord * 0.03711148;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
		  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a04, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.05536385;
  y1 = chord * 0.03711148;
  x2 = chord * 0.07477014;
  y2 = chord * 0.04194842;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
		  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a05, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.07477014;
  y1 = chord * 0.04194842;
  x2 = chord * 0.09438549;
  y2 = chord * 0.04585201;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
		  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a06, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.09438549;
  y1 = chord * 0.04585201;
  x2 = chord * 0.11412847;
  y2 = chord * 0.04904807;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
		  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a07, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.11412847;
  y1 = chord * 0.04904807;
  x2 = chord * 0.133955;
  y2 = chord * 0.05167652;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
		  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a08, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.133955;
  y1 = chord * 0.05167652;
  x2 = chord * 0.15383831;
  y2 = chord * 0.05383385;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
		  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a09, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.15383831;
  y1 = chord * 0.05383385;
  x2 = chord * 0.17376109;
  y2 = chord * 0.05558957;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
		  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
DEFINE_GRID_MOTION(moving_arc_a10, domain, dt, time, dtime)
{
  Thread *tf = DT_THREAD (dt);
  face_t f;
  Node *node_p;
  real alpha, theta, x, phi, gamma, y, x1, x2, y1, y2, lpln, yfh, ln, rp;
  real ymag, lp, dx, dy;
  int n;
  
/* Set/activate the deforming flag on adjacent cell zone, which      */
/* means that the cells adjacent to the deforming wall will also be  */
/* deformed, in order to avoid skewness.                             */
  SET_DEFORMING_THREAD_FLAG (THREAD_T0 (tf));

/* Compute the angles:                                               */
  alpha = 2.0 * omega * 94.0 * CURRENT_TIME;
  x1 = chord * 0.17376109;
  y1 = chord * 0.05558957;
  x2 = chord * 0.19371159;
  y2 = chord * 0.0569959;
  dx = x2-x1;
  dy = y2-y1;
  ln = sqrt((dx)*(dx)+(dy)*(dy)); /*straight line length */
  gamma = atan(dy/dx);
/* Loop over the deforming boundary zone's faces;                    */
/* inner loop loops over all nodes of a given face;                  */
/* Thus, since one node can belong to several faces, one must guard  */
/* against operating on a given node more than once:                 */

  begin_f_loop (f, tf)
    {
      f_node_loop (f, tf, n)
        {
          node_p = F_NODE (f, tf, n);

          /* Update the current node only if it has not been         */
		  /* previously visited:                                     */
          if (NODE_POS_NEED_UPDATE (node_p))
            {
              /* Set flag to indicate that the current node's        */
              /* position has been updated, so that it will not be   */
              /* updated during a future pass through the loop:      */
              NODE_POS_UPDATED (node_p);

              x     = NODE_X (node_p);
              y     = NODE_Y (node_p);
              lp= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              lpln= sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1))/ln;
              yfh= amp*((sin((6.2834*lpln) - 1.5708) + 1.0) * 0.5);
              ymag = yfh*sqrt(sin(alpha)*sin(alpha));
              theta = atan(ymag/lp);
              phi = gamma + theta;
              rp = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
              x = x1 + rp * cos(phi);
              y = y1 + rp * sin(phi);
              NODE_X (node_p) = x;
              NODE_Y (node_p) = y;
            }
        }
    }
  end_f_loop (f, tf);
}
/*********************************************************************/
/*					                             */
/*	End of the UDF.   		                             */
/*					                             */
/*********************************************************************/
