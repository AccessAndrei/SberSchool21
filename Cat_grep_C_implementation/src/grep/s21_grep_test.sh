#!/bin/bash

make s21_grep

#1 test for several -e flags
./s21_grep -e line -e today mega_test.txt file.txt > my_grep.txt
grep -e today -e line mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
      echo "Grep -e test passed!"
  else
      echo "Grep -e test failed!"
fi


#2 tests for -i flag
./s21_grep -i BYE mega_test.txt file.txt > my_grep.txt
grep -i BYE mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
      echo "Grep 1st -i test passed!"
  else
      echo "Grep 1st -i test failed!"
fi

./s21_grep -i ENOUGH mega_test.txt file.txt > my_grep.txt
grep -i ENOUGH mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
      echo "Grep 2nd -i test passed!"
  else
      echo "Grep 2nd -i test failed!"
fi

#3 test for -v flag
./s21_grep -v "good weather" mega_test.txt file.txt > my_grep.txt
grep -v "good weather" mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
      echo "Grep -v test passed!"
  else
      echo "Grep -v test failed!"
fi

#4 test for -ci flag
./s21_grep -i BYE mega_test.txt file.txt > my_grep.txt
grep -i BYE mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
      echo "Grep -i test passed!"
  else
      echo "Grep -i test failed!"
fi

#5 test for -l flag
./s21_grep -l first mega_test.txt file.txt > my_grep.txt
grep -l first mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
      echo "Grep -l test passed!"
  else
      echo "Grep -l test failed!"
fi

#6 test for -ni flag
./s21_grep -i GonnA mega_test.txt file.txt > my_grep.txt
grep -i GonnA mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
      echo "Grep -i test passed!"
  else
      echo "Grep -i test failed!"
fi
#7 test for -h flag
./s21_grep -h "good weather" mega_test.txt file.txt > my_grep.txt
grep -h "good weather" mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
    echo "Grep -h test passed!"
else
    echo "Grep -h test failed!"
fi

#8 test for -n flag
./s21_grep -n "second" mega_test.txt file.txt > my_grep.txt
grep -n "second" mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
    echo "Grep -n test passed!"
else
    echo "Grep -n test failed!"
fi

#9 test for -f flag
echo "good weather" > pattern.txt
./s21_grep -f pattern.txt mega_test.txt file.txt > my_grep.txt
grep -f pattern.txt mega_test.txt file.txt > actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
    echo "Grep -f test passed!"
else
    echo "Grep -f test failed!"
fi

#10 test for -o flag
./s21_grep -o "the" mega_test.txt file.txt> my_grep.txt
grep -o "the" mega_test.txt file.txt> actual_grep.txt
diff actual_grep.txt my_grep.txt
if [ $? -eq 0 ]; then
    echo "Grep -o test passed!"
else
    echo "Grep -o test failed!"
fi

rm -rf actual_grep.txt my_grep.txt pattern.txt

