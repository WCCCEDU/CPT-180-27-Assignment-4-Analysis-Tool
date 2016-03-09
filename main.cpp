#include <iostream>

const int SIZE = 20;
int unsorted[SIZE] = {3,5,7,2,1,9,4,6,8,0,19,16,12,10,18,11,17,14,13,15};

int main(int argc, char *argv[])
{
  std::string datafile = "";
  if (argv[1] != nullptr)
   {
   std::string arg = static_cast<std::string>(argv[1]);

   }
    std::string arg2 = static_cast<std::string>(argv[2]);


 if (arg2 = "sort" )    {

    std::cout << "Please use ascending (asc) or descending (desc)" << std::endl;
    //Should I use a 3rd argument here or what? ^


    for (int i = 0; i < SIZE - 1; i++){
        for ( int j = 0; j < SIZE - i - 1; j++){
            if ( unsorted[j] > unsorted [j + 1]){
                int temp = unsorted[j];
                unsorted[j] = unsorted[j + 1];
                unsorted[j+1] = temp;


            }
        }
    }
    //for (int i = 0; int < SIZE; int++)
     {
       // std::cout << unsorted[i] << std::endl;

    }
}

else if (arg2 = "search" ) {

     for(int  i = 0; i < SIZE; i++){
         int curpos = i;
         for( int j )
     }


}

else {
    std::cout << "Please enter a valid argument to continue" << std::endl;

}


}




