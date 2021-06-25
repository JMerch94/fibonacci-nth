### Screenshot:
![Fibonacci-Nth Screenshot](https://github.com/JMerch94/fibonacci-nth/blob/master/screenshot.png?raw=true)

### Docker
Compile with Clang and run fibonacci-nth on Ubuntu.

> sudo docker build . -t fibonacci-nth

> sudo docker run --rm -it fibonacci-nth

### Generate a Build Using CMake
https://cmake.org/download/

Navigate to the root of the project and execute the following commands.

> cmake -H. -Bbuild

> cmake --build build -- -j3 

> bin/fibonacci-nth   
