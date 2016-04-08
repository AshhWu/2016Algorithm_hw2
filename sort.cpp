#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <msgpack.hpp>
#include <cassert>
using namespace std;

int main()
{
    FILE *fpIn, *fpOut;             //file input/ouput pointer
    
    msgpack::unpacked result;     //unpacked input
    fopen("input.txt","rb");//open with read only/binary mode

    if(fpIn!=NULL)
        cout<<"File open error!"<<endl;
    
    long fileLength=0;
    fseek(fpIn, 0, SEEK_END);       //move pointer to the eof
    fileLength = ftell(fpIn);         //get the size of file
    rewind(fpIn);                   //move back to the biginning
    
    char buf[fileLength];           //buffer of file input
    fread(buf,fileLength,1,fpIn);   //read file
    fclose(fpIn);
    
    int num_tests;                  //number of test
    size_t off=0;
    msgpack::unpack(result,buf,fileLength,off);
    result.get().convert(&num_tests);
    
    vector<int> numbers;
    msgpack::sbuffer sbuf; 
    for(int i=0;i<num_tests;i++)
    {
        msgpack::unpack(result,buf,fileLength,off);
        result.get().convert(&numbers);
        sort(numbers.begin(),numbers.end());
        msgpack::pack(&sbuf,numbers);
    }
    
    assert(off == fileLength);
    
    fpOut = fopen("output.txt","wb");
        cout<<"File open error!"<<endl;
    fwrite(sbuf.data(),sbuf.size(),1,fpOut);
    fclose(fpOut);
    
    return 0;
}

