# Simple-Cpp-timer
just a simple c++ timer to measure performance  
place the header file in your project or copy the code in the cpp file and done.

<br/><br/>
### usage:
<b>STimer (scoped timer)</b>: used for scoped code like loops or functions  
timer starts when the scope begins and ends when scope is exited
```cpp
while(true){
  STimer ST;
  //your code
}
```

<b>Timer</b>: used for more detailed timing  
start the timer with tic() and measure time passed at toc()
```cpp
Timer T;
T.tic(); //0ms
//your code
T.toc(); //outputs: 20ms
//more code
T.toc(); //outputs: 40ms
```

<br/><br/>
### Example code
```cpp
#include "Timer.h"

//once the function finishes excution the timer will display how long the function took to excute
void someFunc() {
	STimer ST;//starts timer
	for (int i = 0; i < 5000; i++) {
		int* x = new int; delete x;
	}
}

int main() {
	someFunc();

	//for more specific measuring use Timer
	Timer T;
	T.tic();//starts timer

	for (int i = 0; i < 5000; i++) {
		int* x = new int; delete x;
	}

	T.toc();//ends timer

	return 0;
}
```
