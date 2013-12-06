#!/bin/tcsh

###########################
# build and run all tests #
###########################

echo "building tests ..."
make alltests

echo "running tests ..."

# test 1
echo "test 1 data1"     >  test1.data1.out
echo "------------"     >> test1.data1.out
stattest1.x data1       >> test1.data1.out
echo "------------"     >> test1.data1.out
echo "test 1 data2"     >  test1.data2.out
echo "------------"     >> test1.data2.out
stattest1.x data2       >> test1.data2.out
echo "------------"     >> test1.data2.out
echo "test 1 data3"     >  test1.data3.out
echo "------------"     >> test1.data3.out
stattest1.x data3       >> test1.data3.out
echo "------------"     >> test1.data3.out
echo "test 1 data4"     >  test1.data4.out
echo "------------"     >> test1.data4.out
stattest1.x data4       >> test1.data4.out
echo "------------"     >> test1.data4.out

# test 2
echo "test 2 data1"     >  test2.data1.out
echo "------------"     >> test2.data1.out
stattest2.x data1       >> test2.data1.out
echo "------------"     >> test2.data1.out
echo "test 2 data2"     >  test2.data2.out
echo "------------"     >> test2.data2.out
stattest2.x data2       >> test2.data2.out
echo "------------"     >> test2.data2.out
echo "test 2 data3"     >  test2.data3.out
echo "------------"     >> test2.data3.out
stattest2.x data3       >> test2.data3.out
echo "------------"     >> test2.data3.out
echo "test 2 data4"     >  test2.data4.out
echo "------------"     >> test2.data4.out
stattest2.x data4       >> test2.data4.out
echo "------------"     >> test2.data4.out

# test 3
echo "test 3 data1"     >  test3.data1.out
echo "------------"     >> test3.data1.out
stattest3.x data1       >> test3.data1.out
echo "------------"     >> test3.data1.out
echo "test 3 data2"     >  test3.data2.out
echo "------------"     >> test3.data2.out
stattest3.x data2       >> test3.data2.out
echo "------------"     >> test3.data2.out
echo "test 3 data3"     >  test3.data3.out
echo "------------"     >> test3.data3.out
stattest3.x data3       >> test3.data3.out
echo "------------"     >> test3.data3.out
echo "test 3 data4"     >  test3.data4.out
echo "------------"     >> test3.data4.out
stattest3.x data4       >> test3.data4.out
echo "------------"     >> test3.data4.out

# test 4
echo "test 4 data1"     >  test4.data1.out
echo "------------"     >> test4.data1.out
stattest4.x data1       >> test4.data1.out
echo "------------"     >> test4.data1.out
echo "test 4 data2"     >  test4.data2.out
echo "------------"     >> test4.data2.out
stattest4.x data2       >> test4.data2.out
echo "------------"     >> test4.data2.out
echo "test 4 data3"     >  test4.data3.out
echo "------------"     >> test4.data3.out
stattest4.x data3       >> test4.data3.out
echo "------------"     >> test4.data3.out
echo "test 4 data4"     >  test4.data4.out
echo "------------"     >> test4.data4.out
stattest4.x data4       >> test4.data4.out
echo "------------"     >> test4.data4.out

# test 5
echo "test 5 data1"     >  test5.data1.out
echo "------------"     >> test5.data1.out
stattest5.x data1       >> test5.data1.out
echo "------------"     >> test5.data1.out
echo "test 5 data2"     >  test5.data2.out
echo "------------"     >> test5.data2.out
stattest5.x data2       >> test5.data2.out
echo "------------"     >> test5.data2.out
echo "test 5 data3"     >  test5.data3.out
echo "------------"     >> test5.data3.out
stattest5.x data3       >> test5.data3.out
echo "------------"     >> test5.data3.out
echo "test 5 data4"     >  test5.data4.out
echo "------------"     >> test5.data4.out
stattest5.x data4       >> test5.data4.out
echo "------------"     >> test5.data4.out

# test 6
echo "test 6 data1"     >  test6.data1.out
echo "------------"     >> test6.data1.out
stattest6.x data1       >> test6.data1.out
echo "------------"     >> test6.data1.out
echo "test 6 data2"     >  test6.data2.out
echo "------------"     >> test6.data2.out
stattest6.x data2       >> test6.data2.out
echo "------------"     >> test6.data2.out
echo "test 6 data3"     >  test6.data3.out
echo "------------"     >> test6.data3.out
stattest6.x data3       >> test6.data3.out
echo "------------"     >> test6.data3.out
echo "test 6 data4"     >  test6.data4.out
echo "------------"     >> test6.data4.out
stattest6.x data4       >> test6.data4.out
echo "------------"     >> test6.data4.out

# test 7
echo "test 7 data1"     >  test7.data1.out
echo "------------"     >> test7.data1.out
stattest7.x data1       >> test7.data1.out
echo "------------"     >> test7.data1.out
echo "test 7 data2"     >  test7.data2.out
echo "------------"     >> test7.data2.out
stattest7.x data2       >> test7.data2.out
echo "------------"     >> test7.data2.out
echo "test 7 data3"     >  test7.data3.out
echo "------------"     >> test7.data3.out
stattest7.x data3       >> test7.data3.out
echo "------------"     >> test7.data3.out
echo "test 7 data4"     >  test7.data4.out
echo "------------"     >> test7.data4.out
stattest7.x data4       >> test7.data4.out
echo "------------"     >> test7.data4.out

# test 8
echo "test 8 data1"     >  test8.data1.out
echo "------------"     >> test8.data1.out
stattest8.x data1       >> test8.data1.out
echo "------------"     >> test8.data1.out
echo "test 8 data2"     >  test8.data2.out
echo "------------"     >> test8.data2.out
stattest8.x data2       >> test8.data2.out
echo "------------"     >> test8.data2.out
echo "test 8 data3"     >  test8.data3.out
echo "------------"     >> test8.data3.out
stattest8.x data3       >> test8.data3.out
echo "------------"     >> test8.data3.out
echo "test 8 data4"     >  test8.data4.out
echo "------------"     >> test8.data4.out
stattest8.x data4       >> test8.data4.out
echo "------------"     >> test8.data4.out

# test 9
echo "test 9 data1"     >  test9.data1.out
echo "------------"     >> test9.data1.out
stattest9.x data1       >> test9.data1.out
echo "------------"     >> test9.data1.out
echo "test 9 data2"     >  test9.data2.out
echo "------------"     >> test9.data2.out
stattest9.x data2       >> test9.data2.out
echo "------------"     >> test9.data2.out
echo "test 9 data3"     >  test9.data3.out
echo "------------"     >> test9.data3.out
stattest9.x data3       >> test9.data3.out
echo "------------"     >> test9.data3.out
echo "test 9 data4"     >  test9.data4.out
echo "------------"     >> test9.data4.out
stattest9.x data4       >> test9.data4.out
echo "------------"     >> test9.data4.out

# test 10
echo "test 10 data1"     >  test10.data1.out
echo "------------"      >> test10.data1.out
stattest10.x data1       >> test10.data1.out
echo "------------"     >> test10.data1.out
echo "test 10 data2"     >  test10.data2.out
echo "------------"      >> test10.data2.out
stattest10.x data2       >> test10.data2.out
echo "------------"     >> test10.data2.out
echo "test 10 data3"     >  test10.data3.out
echo "------------"      >> test10.data3.out
stattest10.x data3       >> test10.data3.out
echo "------------"     >> test10.data3.out
echo "test 10 data4"     >  test10.data4.out
echo "------------"      >> test10.data4.out
stattest10.x data4       >> test10.data4.out
echo "------------"     >> test10.data4.out

# test 11
echo "test 11 data1"     >  test11.data1.out
echo "------------"      >> test11.data1.out
stattest11.x data1       >> test11.data1.out
echo "------------"     >> test11.data1.out
echo "test 11 data2"     >  test11.data2.out
echo "------------"      >> test11.data2.out
stattest11.x data2       >> test11.data2.out
echo "------------"     >> test11.data2.out
echo "test 11 data3"     >  test11.data3.out
echo "------------"      >> test11.data3.out
stattest11.x data3       >> test11.data3.out
echo "------------"     >> test11.data3.out
echo "test 11 data4"     >  test11.data4.out
echo "------------"      >> test11.data4.out
stattest11.x data4       >> test11.data4.out
echo "------------"     >> test11.data4.out

###########################
# copy and run benchmarks #
###########################

echo "copying benchmarks ..."

cp ~cop3330p/fall13/area51/stattest*_i.x .
chmod 700 *.x

echo "running benchmarks ..."

# test 1
echo "test 1 data1"     >  test1.data1.correct
echo "------------"     >> test1.data1.correct
stattest1_i.x data1       >> test1.data1.correct
echo "------------"     >> test1.data1.correct
echo "test 1 data2"     >  test1.data2.correct
echo "------------"     >> test1.data2.correct
stattest1_i.x data2       >> test1.data2.correct
echo "------------"     >> test1.data2.correct
echo "test 1 data3"     >  test1.data3.correct
echo "------------"     >> test1.data3.correct
stattest1_i.x data3       >> test1.data3.correct
echo "------------"     >> test1.data3.correct
echo "test 1 data4"     >  test1.data4.correct
echo "------------"     >> test1.data4.correct
stattest1_i.x data4       >> test1.data4.correct
echo "------------"     >> test1.data4.correct

# test 2
echo "test 2 data1"     >  test2.data1.correct
echo "------------"     >> test2.data1.correct
stattest2_i.x data1       >> test2.data1.correct
echo "------------"     >> test2.data1.correct
echo "test 2 data2"     >  test2.data2.correct
echo "------------"     >> test2.data2.correct
stattest2_i.x data2       >> test2.data2.correct
echo "------------"     >> test2.data2.correct
echo "test 2 data3"     >  test2.data3.correct
echo "------------"     >> test2.data3.correct
stattest2_i.x data3       >> test2.data3.correct
echo "------------"     >> test2.data3.correct
echo "test 2 data4"     >  test2.data4.correct
echo "------------"     >> test2.data4.correct
stattest2_i.x data4       >> test2.data4.correct
echo "------------"     >> test2.data4.correct

# test 3
echo "test 3 data1"     >  test3.data1.correct
echo "------------"     >> test3.data1.correct
stattest3_i.x data1       >> test3.data1.correct
echo "------------"     >> test3.data1.correct
echo "test 3 data2"     >  test3.data2.correct
echo "------------"     >> test3.data2.correct
stattest3_i.x data2       >> test3.data2.correct
echo "------------"     >> test3.data2.correct
echo "test 3 data3"     >  test3.data3.correct
echo "------------"     >> test3.data3.correct
stattest3_i.x data3       >> test3.data3.correct
echo "------------"     >> test3.data3.correct
echo "test 3 data4"     >  test3.data4.correct
echo "------------"     >> test3.data4.correct
stattest3_i.x data4       >> test3.data4.correct
echo "------------"     >> test3.data4.correct

# test 4
echo "test 4 data1"     >  test4.data1.correct
echo "------------"     >> test4.data1.correct
stattest4_i.x data1       >> test4.data1.correct
echo "------------"     >> test4.data1.correct
echo "test 4 data2"     >  test4.data2.correct
echo "------------"     >> test4.data2.correct
stattest4_i.x data2       >> test4.data2.correct
echo "------------"     >> test4.data2.correct
echo "test 4 data3"     >  test4.data3.correct
echo "------------"     >> test4.data3.correct
stattest4_i.x data3       >> test4.data3.correct
echo "------------"     >> test4.data3.correct
echo "test 4 data4"     >  test4.data4.correct
echo "------------"     >> test4.data4.correct
stattest4_i.x data4       >> test4.data4.correct
echo "------------"     >> test4.data4.correct

# test 5
echo "test 5 data1"     >  test5.data1.correct
echo "------------"     >> test5.data1.correct
stattest5_i.x data1       >> test5.data1.correct
echo "------------"     >> test5.data1.correct
echo "test 5 data2"     >  test5.data2.correct
echo "------------"     >> test5.data2.correct
stattest5_i.x data2       >> test5.data2.correct
echo "------------"     >> test5.data2.correct
echo "test 5 data3"     >  test5.data3.correct
echo "------------"     >> test5.data3.correct
stattest5_i.x data3       >> test5.data3.correct
echo "------------"     >> test5.data3.correct
echo "test 5 data4"     >  test5.data4.correct
echo "------------"     >> test5.data4.correct
stattest5_i.x data4       >> test5.data4.correct
echo "------------"     >> test5.data4.correct

# test 6
echo "test 6 data1"     >  test6.data1.correct
echo "------------"     >> test6.data1.correct
stattest6_i.x data1       >> test6.data1.correct
echo "------------"     >> test6.data1.correct
echo "test 6 data2"     >  test6.data2.correct
echo "------------"     >> test6.data2.correct
stattest6_i.x data2       >> test6.data2.correct
echo "------------"     >> test6.data2.correct
echo "test 6 data3"     >  test6.data3.correct
echo "------------"     >> test6.data3.correct
stattest6_i.x data3       >> test6.data3.correct
echo "------------"     >> test6.data3.correct
echo "test 6 data4"     >  test6.data4.correct
echo "------------"     >> test6.data4.correct
stattest6_i.x data4       >> test6.data4.correct
echo "------------"     >> test6.data4.correct

# test 7
echo "test 7 data1"     >  test7.data1.correct
echo "------------"     >> test7.data1.correct
stattest7_i.x data1       >> test7.data1.correct
echo "------------"     >> test7.data1.correct
echo "test 7 data2"     >  test7.data2.correct
echo "------------"     >> test7.data2.correct
stattest7_i.x data2       >> test7.data2.correct
echo "------------"     >> test7.data2.correct
echo "test 7 data3"     >  test7.data3.correct
echo "------------"     >> test7.data3.correct
stattest7_i.x data3       >> test7.data3.correct
echo "------------"     >> test7.data3.correct
echo "test 7 data4"     >  test7.data4.correct
echo "------------"     >> test7.data4.correct
stattest7_i.x data4       >> test7.data4.correct
echo "------------"     >> test7.data4.correct

# test 8
echo "test 8 data1"     >  test8.data1.correct
echo "------------"     >> test8.data1.correct
stattest8_i.x data1       >> test8.data1.correct
echo "------------"     >> test8.data1.correct
echo "test 8 data2"     >  test8.data2.correct
echo "------------"     >> test8.data2.correct
stattest8_i.x data2       >> test8.data2.correct
echo "------------"     >> test8.data2.correct
echo "test 8 data3"     >  test8.data3.correct
echo "------------"     >> test8.data3.correct
stattest8_i.x data3       >> test8.data3.correct
echo "------------"     >> test8.data3.correct
echo "test 8 data4"     >  test8.data4.correct
echo "------------"     >> test8.data4.correct
stattest8_i.x data4       >> test8.data4.correct
echo "------------"     >> test8.data4.correct

# test 9
echo "test 9 data1"     >  test9.data1.correct
echo "------------"     >> test9.data1.correct
stattest9_i.x data1       >> test9.data1.correct
echo "------------"     >> test9.data1.correct
echo "test 9 data2"     >  test9.data2.correct
echo "------------"     >> test9.data2.correct
stattest9_i.x data2       >> test9.data2.correct
echo "------------"     >> test9.data2.correct
echo "test 9 data3"     >  test9.data3.correct
echo "------------"     >> test9.data3.correct
stattest9_i.x data3       >> test9.data3.correct
echo "------------"     >> test9.data3.correct
echo "test 9 data4"     >  test9.data4.correct
echo "------------"     >> test9.data4.correct
stattest9_i.x data4       >> test9.data4.correct
echo "------------"     >> test9.data4.correct

# test 10
echo "test 10 data1"     >  test10.data1.correct
echo "------------"      >> test10.data1.correct
stattest10_i.x data1       >> test10.data1.correct
echo "------------"     >> test10.data1.correct
echo "test 10 data2"     >  test10.data2.correct
echo "------------"      >> test10.data2.correct
stattest10_i.x data2       >> test10.data2.correct
echo "------------"     >> test10.data2.correct
echo "test 10 data3"     >  test10.data3.correct
echo "------------"      >> test10.data3.correct
stattest10_i.x data3       >> test10.data3.correct
echo "------------"     >> test10.data3.correct
echo "test 10 data4"     >  test10.data4.correct
echo "------------"      >> test10.data4.correct
stattest10_i.x data4       >> test10.data4.correct
echo "------------"     >> test10.data4.correct

# test 11
echo "test 11 data1"     >  test11.data1.correct
echo "------------"      >> test11.data1.correct
stattest11_i.x data1       >> test11.data1.correct
echo "------------"     >> test11.data1.correct
echo "test 11 data2"     >  test11.data2.correct
echo "------------"      >> test11.data2.correct
stattest11_i.x data2       >> test11.data2.correct
echo "------------"     >> test11.data2.correct
echo "test 11 data3"     >  test11.data3.correct
echo "------------"      >> test11.data3.correct
stattest11_i.x data3       >> test11.data3.correct
echo "------------"     >> test11.data3.correct
echo "test 11 data4"     >  test11.data4.correct
echo "------------"      >> test11.data4.correct
stattest11_i.x data4       >> test11.data4.correct
echo "------------"     >> test11.data4.correct

echo " "
echo "##############################"
echo "#    results comparisons     #"
echo "##############################"
echo " "

###########################
# compare results         #
###########################

# test 1
echo "test 1 data 1 (correct on left <):"
diff test1.data1.correct test1.data1.out 
echo "test 1 data 2 (correct on left <):"
diff test1.data2.correct test1.data2.out 
echo "test 1 data 3 (correct on left <):"
diff test1.data3.correct test1.data3.out 
echo "test 1 data 4 (correct on left <):"
diff test1.data4.correct test1.data4.out 

# test 2
echo "test 2 data 1 (correct on left <):"
diff test2.data1.correct test2.data1.out 
echo "test 2 data 2 (correct on left <):"
diff test2.data2.correct test2.data2.out 
echo "test 2 data 3 (correct on left <):"
diff test2.data3.correct test2.data3.out 
echo "test 2 data 4 (correct on left <):"
diff test2.data4.correct test2.data4.out 

# test 3
echo "test 3 data 1 (correct on left <):"
diff test3.data1.correct test3.data1.out 
echo "test 3 data 2 (correct on left <):"
diff test3.data2.correct test3.data2.out 
echo "test 3 data 3 (correct on left <):"
diff test3.data3.correct test3.data3.out 
echo "test 3 data 4 (correct on left <):"
diff test3.data4.correct test3.data4.out 

# test 4
echo "test 4 data 1 (correct on left <):"
diff test4.data1.correct test4.data1.out 
echo "test 4 data 2 (correct on left <):"
diff test4.data2.correct test4.data2.out 
echo "test 4 data 3 (correct on left <):"
diff test4.data3.correct test4.data3.out 
echo "test 4 data 4 (correct on left <):"
diff test4.data4.correct test4.data4.out 

# test 5
echo "test 5 data 1 (correct on left <):"
diff test5.data1.correct test5.data1.out 
echo "test 5 data 2 (correct on left <):"
diff test5.data2.correct test5.data2.out 
echo "test 5 data 3 (correct on left <):"
diff test5.data3.correct test5.data3.out 
echo "test 5 data 4 (correct on left <):"
diff test5.data4.correct test5.data4.out 

# test 6
echo "test 6 data 1 (correct on left <):"
diff test6.data1.correct test6.data1.out 
echo "test 6 data 2 (correct on left <):"
diff test6.data2.correct test6.data2.out 
echo "test 6 data 3 (correct on left <):"
diff test6.data3.correct test6.data3.out 
echo "test 6 data 4 (correct on left <):"
diff test6.data4.correct test6.data4.out 

# test 7
echo "test 7 data 1 (correct on left <):"
diff test7.data1.correct test7.data1.out 
echo "test 7 data 2 (correct on left <):"
diff test7.data2.correct test7.data2.out 
echo "test 7 data 3 (correct on left <):"
diff test7.data3.correct test7.data3.out 
echo "test 7 data 4 (correct on left <):"
diff test7.data4.correct test7.data4.out 

# test 8
echo "test 8 data 1 (correct on left <):"
diff test8.data1.correct test8.data1.out 
echo "test 8 data 2 (correct on left <):"
diff test8.data2.correct test8.data2.out 
echo "test 8 data 3 (correct on left <):"
diff test8.data3.correct test8.data3.out 
echo "test 8 data 4 (correct on left <):"
diff test8.data4.correct test8.data4.out 

# test 9
echo "test 9 data 1 (correct on left <):"
diff test9.data1.correct test9.data1.out 
echo "test 9 data 2 (correct on left <):"
diff test9.data2.correct test9.data2.out 
echo "test 9 data 3 (correct on left <):"
diff test9.data3.correct test9.data3.out 
echo "test 9 data 4 (correct on left <):"
diff test9.data4.correct test9.data4.out 

# test 10
echo "test 10 data 1 (correct on left <):"
diff test10.data1.correct test10.data1.out 
echo "test 10 data 2 (correct on left <):"
diff test10.data2.correct test10.data2.out 
echo "test 10 data 3 (correct on left <):"
diff test10.data3.correct test10.data3.out 
echo "test 10 data 4 (correct on left <):"
diff test10.data4.correct test10.data4.out 

# test 11
echo "test 11 data 1 (correct on left <):"
diff test11.data1.correct test11.data1.out 
echo "test 11 data 2 (correct on left <):"
diff test11.data2.correct test11.data2.out 
echo "test 11 data 3 (correct on left <):"
diff test11.data3.correct test11.data3.out 
echo "test 11 data 4 (correct on left <):"
diff test11.data4.correct test11.data4.out 

