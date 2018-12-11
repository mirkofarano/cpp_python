class MyClass:
    """A simple example class"""

    def __init__(self, a):
        self.a = a
        print("Constructor of the python class is called.")

    def func(self):
        print("I'm in python! This is a member function of the class.")
        return self.a + 1

def func2(a):
    print("I'm in python! This is a function.")
    return  a - 1
