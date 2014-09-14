#include <jni.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


JNIEXPORT jstring JNICALL Java_JniExample_getString
  (JNIEnv * env, jobject jobj, jstring name) {
	return (*env)->NewStringUTF(env,"Hello world!\n");
}

JNIEXPORT jfloat JNICALL Java_JniExample_getFloat
  (JNIEnv * env, jobject jobj, jstring name) {
	return 29.6f;
}
