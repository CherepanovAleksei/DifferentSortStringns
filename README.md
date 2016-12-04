# sort
strings sorting algorithm

#Bubble sort




Each sample counts as 0.01 seconds.

Flat  profile
------ | ------ | ------ | ------ | ------ | ------ | ------ 
   time | cumulative seconds | self seconds | calls | self s/call | total s/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 99.64 |  53.62 |  53.62 |  1 |  53.62 |  53.62 |  bubble_sort 
 0.69 |  53.99 |  0.37 |  |  |  |  main 


Call graph





granularity: each sample hit covers 2 byte(s) for 0.02% of 53.99 seconds


 index | % time | self | children | called | name <spontaneous> 
------ | ------ | ------ | ------ | ------ | ------ 
 [1] |  |  100.0 |  0.37 |  53.62 |  main  [1]
 |  |  53.62 |  0.00 |  1/1 |  bubble_sort  [2]
 |  |  53.62 |  0.00 |  1/1 |  main  [1]
 [2] |  99.3 |  53.62 |  0.00 |  1 |  bubble_sort  [2]



Insert sort
Flat  profile:



Each sample counts as 0.01 seconds.

   time | cumulative seconds | self seconds | calls | self s/call | total s/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 97.25 |  10.12 |  10.12 |  1 |  10.12 |  10.12 |  insert_sort 
 3.08 |  10.44 |  0.32 |  |  |  |  main 


Call graph





granularity: each sample hit covers 2 byte(s) for 0.10% of 10.44 seconds


 index | % time | self | children | called | name <spontaneous> 
------ | ------ | ------ | ------ | ------ | ------ 
 [1] |  |  100.0 |  0.32 |  10.12 |  main  [1]
 |  |  10.12 |  0.00 |  1/1 |  insert_sort  [2]
 |  |  10.12 |  0.00 |  1/1 |  main  [1]
 [2] |  96.9 |  10.12 |  0.00 |  1 |  insert_sort  [2]



Merge sort

Flat  profile:



Each sample counts as 0.01 seconds.

   time | cumulative seconds | self seconds | calls | self ms/call | total ms/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 88.87 |  0.31 |  0.31 |  |  |  |  main 
 11.47 |  0.35 |  0.04 |  1 |  40.13 |  40.13 |  merge_sort 


Call graph





granularity: each sample hit covers 2 byte(s) for 2.85% of 0.35 seconds


 index | % time | self | children | called | name <spontaneous> 
------ | ------ | ------ | ------ | ------ | ------ 
 [1] |  |  100.0 |  0.31 |  0.04 |  main  [1]
 |  |  0.04 |  0.00 |  1/1 |  merge_sort  [2]
 |  |  |  |  199998 |  merge_sort  [2]
 |  |  0.04 |  0.00 |  1/1 |  main  [1]
 [2] |  11.4 |  0.04 |  0.00 |  1+199998 |  merge_sort  [2]
 |  |  |  |  199998 |  merge_sort  [2]


Flat  profile:



Each sample counts as 0.01 seconds.

   time | cumulative seconds | self seconds | calls | self Ts/call | total Ts/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 96.32 |  0.24 |  0.24 |  |  |  |  main 
 4.01 |  0.25 |  0.01 |  |  |  |  comparator 
 0.00 |  0.25 |  0.00 |  1 |  0.00 |  0.00 |  quick_sort 


Call graph





granularity: each sample hit covers 2 byte(s) for 3.99% of 0.25 seconds


 index | % time | self | children | called | name <spontaneous> 
------ | ------ | ------ | ------ | ------ | ------ 
 [1] |  |  96.0 |  0.24 |  0.00 |  main  [1]
 |  |  0.00 |  0.00 |  1/1 |  quick_sort  [3]
 |  |  |  |  |  <spontaneous>  [2]
 |  |  4.0 |  0.01 |  0.00 |  comparator  [2]
 |  |  0.00 |  0.00 |  1/1 |  main  [1]
 [3] |  0.0 |  0.00 |  0.00 |  1 |  quick_sort  [3]

==3109== 
==3109== HEAP SUMMARY:
==3109==     in use at exit: 4,140 bytes in 1 blocks
==3109==   total heap usage: 100,008 allocs, 100,007 frees, 35,021,506 bytes allocated
==3109== 
==3109== LEAK SUMMARY:
==3109==    definitely lost: 0 bytes in 0 blocks
==3109==    indirectly lost: 0 bytes in 0 blocks
==3109==      possibly lost: 0 bytes in 0 blocks
==3109==    still reachable: 4,140 bytes in 1 blocks
==3109==         suppressed: 0 bytes in 0 blocks
==3109== Rerun with --leak-check=full to see details of leaked memory
==3109== 
==3109== For counts of detected and suppressed errors, rerun with: -v
==3109== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


