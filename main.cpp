#include <iostream>
#include <string>
#include "cpp_file.h"

#include <boost/python.hpp>
#include <python2.7/Python.h>

namespace bp = boost::python;
using namespace std;

int main(){
  Py_Initialize();
  bp::import("sys").attr("path").attr("append")(".");
  bp::object py_file = bp::import("py_file");  // Load the .py file that contains classes, functions etc...

  // Call python calss and its functions.
  double a = 0.5;
  bp::object MyClass_py = py_file.attr("MyClass")(a); // Call the classes contained in the .py file.
  bp::object num1 = MyClass_py.attr("func")(); // Call the functions of the calss.
  double n1 = bp::extract<double>(num1); // Convert the python object in c++ one.
  cout << "if (" << a  + 1 << "==" << n1 <<"): "<< "Number correctly returned from python class member function!" << endl;

  // Call python functions.
  bp::object num2 = py_file.attr("func2")(a); // Call the classes, functions etc contained in the .py file.
  double n2 = bp::extract<double>(num2); // Convert the python object in c++ one.
  cout << "if (" << a - 1 << "==" << n2 <<"): "<< "Number correctly returned from python function!" << endl;

  // Call c++ class and its functions.
  double x,y,z;
  x=y=z=1.1;
  CppClass T(x,y,z);
  double A = T.product(); 
  cout << "Some value from c++ class member function: " << A << endl;

  return 0;
}
