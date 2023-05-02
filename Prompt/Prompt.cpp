#include"jni.h"
#include"Prompt.h"
#include <string>
#include<iostream>
using namespace std;

//std::string jstringToString(JNIEnv* env, jstring jstr) {
//    const char* cstr = env->GetStringUTFChars(jstr, nullptr);
//    std::string str(cstr);
//    env->ReleaseStringUTFChars(jstr, cstr);
//    return str;
//}

JNIEXPORT jstring JNICALL Java_Prompt_getLine(JNIEnv* env, jobject obj, jstring prompt)
{
    char buf[128];
    const char* str = env->GetStringUTFChars(prompt, 0);
  // std::cout << "\n inside c++" << str;
    std::cout << str;
    env->ReleaseStringUTFChars(prompt, str);
    std::cin.getline(buf, 128);
    return env->NewStringUTF(buf);



 /*   char buf[128];
    const char* str = env->GetStringUTFChars(prompt, 0);
    cout << str;
    env->ReleaseStringUTFChars(prompt, str);
    cout << "\nEnter a string: ";

    cin >> buf;
    return env->NewStringUTF(buf);*/


    
    //std::string cppstr = jstringToString(env, jstr);

    //// get the console input handle
    //HANDLE consoleInput = GetStdHandle(STD_INPUT_HANDLE);

    //// read input from the console using the Windows API
    //const int MAX_INPUT_SIZE = 1024;
    //char inputBuffer[MAX_INPUT_SIZE];
    //DWORD numRead;
    //if (ReadConsole(consoleInput, inputBuffer, MAX_INPUT_SIZE, &numRead, nullptr)) {
    //    inputBuffer[numRead] = '\0';
    //    cppstr = inputBuffer;
    //}

    // convert the result back to a jstring and return it to Java
   // return env->NewStringUTF(cppstr.c_str());
}


//JNIEXPORT jstring JNICALL
//Java_Prompt_getLine(JNIEnv* env, jobject obj, jstring prompt)
//{
//    char buf[128];
//    const char* str = (*env)->GetStringUTFChars(env, prompt, 0);
//    printf("%s", str);
//    (*env)->ReleaseStringUTFChars(env, prompt, str);
//    scanf("%s", buf);
//    return (*env)->NewStringUTF(env, buf);
//}