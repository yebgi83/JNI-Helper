#pragma once
#include <string>

#include "JNIBase.h"
#include "JNIMethod.h"

class JNIObject : public JNIBase
{
private:
	va_list args;

	jclass	javaClass;
	jobject	javaObject;

protected:
	JNIObject(JNIEnv *pEnv, JNIMethod jniInit, ...) : JNIObject(pEnv, jniInit, (va_start(args, jniInit), args))
	{
	}

	JNIObject(JNIEnv *pEnv, JNIMethod jniInit, va_list args) : JNIObject(pEnv, pEnv->NewObjectV(jniInit.GetJavaClass(), jniInit.GetMethodID(pEnv), args))
	{
	}

	JNIObject(JNIEnv *pEnv, jobject javaObject) : JNIBase(pEnv) 
	{
		this->javaClass = pEnv->GetObjectClass(javaObject);
		this->javaObject = javaObject;
	}

public:
	jclass GetJavaClass()
	{
		return javaClass;
	}

	jobject GetJavaObject()
	{
		return javaObject;
	}
};