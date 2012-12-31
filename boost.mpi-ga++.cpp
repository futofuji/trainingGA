#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <iostream>
#include "ga++.h"

int main(int argc, char* argv[])
{
   GA::Initialize(argc, argv);
   boost::mpi::communicator world;
   GA::GAServices gaServices;
   std::cout << "I am process " << world.rank() << " of " << world.size() << ". " 
             << "My node-id is " << gaServices.clusterNodeid() << std::endl;
   GA::Terminate();
   return 0;
}
