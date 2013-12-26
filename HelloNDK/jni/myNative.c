#include <string.h>
#include <jni.h>

private static final String = "xxxxx";

jstring Java_com_hulefei_hellondk_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
	const char* a =  "Hello NDK";
//	return (*env)->NewStringUTF(env,  "Hello Worlds of NDK!");
	return (*env)->NewStringUTF(env,  a);
}
