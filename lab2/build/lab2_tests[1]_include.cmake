if(EXISTS "C:/Users/artem/Downloads/OOP/lab2/build/lab2_tests[1]_tests.cmake")
  include("C:/Users/artem/Downloads/OOP/lab2/build/lab2_tests[1]_tests.cmake")
else()
  add_test(lab2_tests_NOT_BUILT lab2_tests_NOT_BUILT)
endif()
