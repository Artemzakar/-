if(EXISTS "C:/Users/artem/Downloads/OOP/lab7/build/balagur_tests[1]_tests.cmake")
  include("C:/Users/artem/Downloads/OOP/lab7/build/balagur_tests[1]_tests.cmake")
else()
  add_test(balagur_tests_NOT_BUILT balagur_tests_NOT_BUILT)
endif()
