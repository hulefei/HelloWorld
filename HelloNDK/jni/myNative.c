/*
 * myNative.c
 *
 *  Created on: 2014-1-21
 *      Author: hanson
 */

#include <jni.h>
#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>

jstring Java_com_hulefei_hellondk_MainActivity_stringFromJNI( JNIEnv* env, jobject thiz ){
	return (*env)->NewStringUTF(env, "Hello from JNI aa!");
}
