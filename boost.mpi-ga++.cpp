#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include "ga++.h"

int main(int argc, char* argv[])
{
   GA::Initialize(argc, argv);
   boost::mpi::communicator world;
   GA::GAServices gaServices;
   std::cout << "I am process " << world.rank() << " of " << world.size() << ". " 
             << "My node-id is " << gaServices.clusterNodeid() << std::endl;

   int ndim=1;
   int dims[]={500};
   char* arrayName = "array_name";
   boost::shared_ptr<GA::GlobalArray> ptrGA(new GA::GlobalArray(MT_C_DBL, ndim, dims, arrayName, NULL));
   GA::Terminate();
   return 0;
}
