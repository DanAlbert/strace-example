#include <stdio.h>
#include <pthread.h>

#include <string>

#include <android/log.h>
#include <jni.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

extern "C" JNIEXPORT jstring JNICALL
Java_com_android_samples_strace_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    // Intentionally cause a deadlock so the strace output will show something
    // interesting to debug.
    __android_log_print(ANDROID_LOG_ERROR, "strace-example", "Attempting deadlock");
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}