#include <jni.h>
#include <add.h>

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_apple_opencvtest_MainActivity_addFromCpp(JNIEnv *env, jobject instance, jint a,
                                                          jint b) {
    return add(a, b);

}