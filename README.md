trainingGA
==========

These sources are for the training of the Global Arrays Toolkit.


===================== Compile and run on the lets note ==================
$ mpicxx boost.mpi-ga++.cpp -o boost.mpi-ga++.out -I/usr/local/boost1.48.0_intel12.1.0_openmpi1.4.5/include/ -L/usr/local/boost1.48.0_intel12.1.0_openmpi1.4.5/lib -lboost_mpi -lboost_serialization -Wl,-rpath=/usr/local/boost1.48.0_intel12.1.0_openmpi1.4.5/lib -I/usr/local/ga5.1.1_intel12.1.0_openmpi1.4.5/include -L/usr/local/ga5.1.1_intel12.1.0_openmpi1.4.5/lib -lga++ -lga -larmci -lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -DMKL_ILP64 -lmpi_f90 -lmpi_f77

$ mpirun -np 2 boost.mpi-ga++.out

===================== Compile and run on the london-series ==================
$ mpicxx boost.mpi-ga++.cpp -o boost.mpi-ga++.out -I/home/tcl/boost1.48.0_openmpi-1.4.2_intel64-12.1.3/include -L/home/tcl/boost1.48.0_openmpi-1.4.2_intel64-12.1.3/lib/ -lboost_mpi -lboost_serialization -Wl,-rpath=/home/tcl/boost1.48.0_openmpi-1.4.2_intel64-12.1.3/lib  -I/home/fujii/ga5.1.1_intel12.1.3_openmpi1.4.2_IB/include  -L/home/fujii/ga5.1.1_intel12.1.3_openmpi1.4.2_IB/lib -lga++ -lga -larmci -lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -DMKL_ILP64 -lmpi_f90 -lmpi_f77 -lrdmacm -libverbs -lrt -lnsl -lutil -ldl -lm -lrt -lnsl -lutil

$ vi nodes
london07
london07
london07
london07
london08
london08
london08
london08

$ mpirun -machinefile nodes -np 8 boost.mpi-ga++-2.out

 I am process 7 of 8. My node-id is 1
 I am process 1 of 8. My node-id is 0
 I am process 2 of 8. My node-id is 0
 I am process 0 of 8. My node-id is 0
 I am process 3 of 8. My node-id is 0
 I am process 6 of 8. My node-id is 1
 I am process 4 of 8. My node-id is 1
 I am process 5 of 8. My node-id is 1

