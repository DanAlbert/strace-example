#include <jni.h>
#include <string>

#include <mutex>

extern "C" JNIEXPORT jstring JNICALL
Java_com_android_samples_strace_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::mutex mutex;
    // Intentionally cause a deadlock so the strace output will show something
    // interesting to debug.
    std::lock_guard<std::mutex> lock1(mutex);
    std::lock_guard<std::mutex> lock2(mutex);
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}