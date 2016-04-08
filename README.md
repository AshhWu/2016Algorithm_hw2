# 2016Algorithm part2
**Handle the input/output data with the MessagePack deserialization / serialization APIs.**

The problem to be solved in this homework is exactly the same as Part1.

**But this is so mush faster than the Part1!**

##Init version

Analysis result:

||result|
|---|:---:|
|I_refs|24756803|
|check|1.000000|
|cpu_time|12090|
|flt|1854|
|gcc|0|
|heap_lost|500010|
|illegal_func|0|
|illegal_header|0|
|m_error|0|
|m_peak|60805120|
|maxrss|3592192|
@lang=cpp

##Second version

Simply replace for loop into five seperately 
Analysis result:

||result|
|---|:---:|
|I_refs|24713243|
|check|1.000000|
|cpu_time|11420|
|flt|1808|
|gcc|0|
|heap_lost|500010|
|illegal_func|0|
|illegal_header|0|
|m_error|0|
|m_peak|60801024|
|maxrss|3411968|
@lang=cpp

###Compared with [Part1](https://github.com/AshhWu/Algorithm_sorting_part1), Part2 is 54% faster!###

It shows that processing of the binary data is more efficient than processing of the text data.

And for the comparison of Init version and Second version, I've learned from the Computer Orginization class that when it comes to for loop, it will take much more instructions in the assembly language.

So I came up with the idea that I could seperate the for loop and just post the same code for five times (there is 5 test input). **And it works!**

Second version has lower flt, maxrss and m_peak. It shows that it has fewer instructions and memory load.
