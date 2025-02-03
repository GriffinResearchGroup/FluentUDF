The files posted are udf files to use in ANSYS Fluent 2021R2 or later. The codes are written in C and relate mostly to using the Dynamic mesh features in Fluent.

Blockudf_V10_ConFig2A.c	-This is a CFD-6DOF script that find the forces and moments on a body 				(ConFig2A) and also enables the use of the double overset technique.

Two_Body_Init.c		-This is the file to initialize the two bodies before separation during 			steady level flight at 0.7 Mach.

Two_Body_Sep.c		-This file is the full blown separation inputs and CFD-6DOF setup with the 			double overset technique and backed out forces and moments on each body.

UDF_Block_Launch_f.c	-Are Fluent files to initialize the motion of block flights over the first 			0.1 seconds of flight. It simply defines the motion in terms of 				translational and rotational velocities

udf_V10_UAVAJ.c		-This is the updated CFD-6DOF script that find the forces and moments on a 			body (UAVAJ) and also enables the use of the double overset technique. It 			incorporates an update for reducing round off error in backed out 				velocities.

udf_V10_UAVAJ_FandM_F2.c	-This is the linear force and moment vectors for a single body 					(UAVAJ) separation.	