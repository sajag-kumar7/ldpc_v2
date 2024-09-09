#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <memory>
#include <iterator>
#include <cmath> 

namespace ldpc::util{

std::vector<uint8_t> decimal_to_binary(int decimal_number,int binary_string_length, bool reverse=false)
{
   std::vector<uint8_t> binary_number;
   int divisor;
   int remainder;
   divisor=decimal_number;

   binary_number.resize(binary_string_length);

   for(int i=0; i<binary_string_length;i++)
   {
        remainder=divisor%2;
        if(reverse) binary_number[i]=remainder;
        else binary_number[binary_string_length-i-1]=remainder;
        divisor=divisor/2;
        if(divisor==0) break;
   }

   return  binary_number;
}

std::vector<int> decimal_to_binary_sparse(int decimal_number, int binary_string_length)
{
   std::vector<int> binary_number;
   int divisor;
   int remainder;
   divisor=decimal_number;


   for(int i=0; i<binary_string_length;i++)
   {
        remainder=divisor%2;
        if(remainder==1) binary_number.push_back(i);
        divisor=divisor/2;
        if(divisor==0) break;
   }

   return  binary_number;
}

std::vector<uint8_t> decimal_to_binary_reverse(int decimal_number,int binary_string_length)
{
   return decimal_to_binary(decimal_number,binary_string_length,true);
}

int binary_to_decimal(std::vector<uint8_t> binary_number)
{
    int decimal_number = 0;
    int power = 0;
    for(int i = binary_number.size()-1; i>=0; i--){
        decimal_number += binary_number[i] * pow(2,power);
        power++;
    }
    return decimal_number;
}


}//end namespace util

#endif