if(EXISTS "C:/Users/artem/Downloads/OOP/lab4/build/lab4_tests[1]_tests.cmake")
  include("C:/Users/artem/Downloads/OOP/lab4/build/lab4_tests[1]_tests.cmake")
else()
  add_test(lab4_tests_NOT_BUILT lab4_tests_NOT_BUILT)
endif()
