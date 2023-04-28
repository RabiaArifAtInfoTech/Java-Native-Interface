# Java-Native-Interface


Step 1: Write the Java Code::::

```
class HelloWorld {
    public native void displayHelloWorld();

    static {
        System.loadLibrary("hello");
    }
    
    public static void main(String[] args) {
        new HelloWorld().displayHelloWorld();
    }
}
```
Step 2: Compile the Java Code:::: (cmd)

javac HelloWorld.java



Step 3: Create the .h File:::: (cmd)

javac -h C:\Users\rabia.arif\Desktop\JNI MainFile.java



Step 4: Write the Native Method Implementation :::: (its in c)

...
#include <jni.h>
#include "HelloWorld.h"
#include <stdio.h>

JNIEXPORT void JNICALL 
Java_HelloWorld_displayHelloWorld(JNIEnv *env, jobject obj) 
{
    printf("Hello world!\n");
    return;
}
...



Step 5: Create a Shared Library:::: (cmd)


x86_64-w64-mingw32-gcc -c -I"C:\Program Files\Java\jdk-16\include" -I"C:\Program Files\Java\jdk-16\include\win32" -o HelloWorld.o HelloWorld.c

x86_64-w64-mingw32-gcc -shared -o hello.dll HelloWorld.o



Step 6: Run the Program:::: (cmd)

java HelloWorld
