trainingGA
==========

These sources are for the training of the Global Arrays Toolkit.


===================== Compile and run on the let's note ==================
$ mpicxx boost.mpi-ga++.cpp -o boost.mpi-ga++.out -I/usr/local/boost1.48.0_intel12.1.0_openmpi1.4.5/include/ -L/usr/local/boost1.48.0_intel12.1.0_openmpi1.4.5/lib -lboost_mpi -lboost_serialization -Wl,-rpath=/usr/local/boost1.48.0_intel12.1.0_openmpi1.4.5/lib -I/usr/local/ga5.1.1_intel12.1.0_openmpi1.4.5/include -L/usr/local/ga5.1.1_intel12.1.0_openmpi1.4.5/lib -lga++ -lga -larmci -lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -DMKL_ILP64 -lmpi_f90 -lmpi_f77

$ mpirun -np 2 boost.mpi-ga++.out
