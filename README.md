When you run each code, it will iterate through the set of problem sizes predefined inside benchmark.cpp

# Building and running the codes on Perlmutter@NERSC

`Use: ssh username@saul-p1.nersc.gov`
to log into Perlmutter

After [logging in to perlmutter at NERSC,](https://docs.nersc.gov/systems/perlmutter/), either pull the code directly from git or [transfer a copy from your local machine to NERSC](https://docs.nersc.gov/services/scp/).

Transferring files: 
`rsync -a /mnt/Downloads username@saul-p1.nersc.gov:rsync`

`% module load PrgEnv-nvidia`

Then follow the build instructions above.

Once you have built the codes, you may request interactive access to a Perlmutter CPU node by using this command:

`% salloc --nodes 1 --qos interactive --time 00:30:00 --constraint gpu --gpus 1 --account=m3930`

Once you are on an interactive CPU node, run each of the codes using these commands:

`% nvcc vecadd_gpu_1t.cu -o vecadd_gpu_1t`
`% srun nsys nvprof ./vecadd_gpu_1t`
`% nvcc vecadd_gpu_256t.cu -o vecadd_gpu_256t`
`% srun nsys nvprof ./vecadd_gpu_256t`
`% nvcc vecadd_gpu_256t_manyblocks.cu -o vecadd_gpu_256t_manyblocks`
`% srun nsys nvprof ./vecadd_gpu_256t_manyblocks`
`% nvcc vecadd_gpu_256t_manyblocks_prefetch.cu -o vecadd_gpu_256t_manyblocks_prefetch`
`% srun nsys nvprof ./vecadd_gpu_256t_manyblocks_prefetch`


# EOF
