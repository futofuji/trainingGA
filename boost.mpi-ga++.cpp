#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <string>
#include "ga++.h"
using namespace std;

int main(int argc, char* argv[])
{
   GA::Initialize(argc, argv);
   boost::mpi::communicator world;
   GA::GAServices gaServices;
   std::cout << "I am process " << world.rank() << " of " << world.size() << ". " 
             << "My node-id is " << gaServices.clusterNodeid() << std::endl;

   // test of global allocation
   {
      int ndim=1;
      int dims[]={50};
      char* arrayName = "array_name";
      boost::shared_ptr<GA::GlobalArray> ptrGA(new GA::GlobalArray(MT_C_DBL, ndim, dims, arrayName, NULL));
      ptrGA->zero();

      if(world.rank() == 2){
         int lo[] = {4};
         int hi[] ={12};
         double local3[20];
         for(int i=0; i<20; i++){
            local3[i] = (i+1.0)*3;
         }
         ptrGA->put(lo, hi, local3, NULL);
      }
      gaServices.sync();
      
      if(world.rank() == 7){
         int lo[] = {0};
         int hi[] ={49};
         double local4[50];
         ptrGA->get(lo, hi, local4, NULL);
         for(int i=0; i<50; i++){
            cout << "i=" << i << "\t" << local4[i] << endl;
         }
      }
      
   }
   GA::Terminate();
   return 0;
}
