#!/bin/sh

#SBATCH --job-name=Full-Scale

# Specify the resources need for the job
# Walltime is specified as hh:mm:ss (hours:minutes:seconds)
#SBATCH --nodes=3
#SBATCH --ntasks-per-node=40
#SBATCH -t 168:00:00

#SBATCH --mail-type=BEGIN
#SBATCH --mail-type=END

#SBATCH --mail-user=hjd0004@mix.wvu.edu

#SBATCH -p comm_small_week

cd /scratch/hjd0004/UAVAJ/SRR_CFD_6DOF/Full_Scale

nodelist=$(scontrol show hostname $SLURM_NODELIST)
echo "$nodelist" > Fluent.txt

module load ansys/2021R2

fluent 3ddp -t120 -mpi=intel -ssh -cnf=Fluent.txt -g -scheduler_tight_coupling -i FullScale.jou>outfile5e-5


