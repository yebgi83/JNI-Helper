#pragma once

#include "JNIMethod.h"
#include "JNIString.h"
#include "JNIObject.h"

using namespace std;

class JNIThrowable : public JNIObject
{
protected:
	JNIThrowable(JNIEnv *pEnv, JNIClass jniClass, const string &message) : JNIObject(pEnv, jniClass.GetConstructor("(Ljava/lang/String;)V"), JNIString::ToJavaString(pEnv, message))
	{
	}

public:
	JNIThrowable(JNIEnv *pEnv, const string &message) : JNIThrowable(pEnv, JNIClass(pEnv, "java/lang/Throwable"), message)
	{
	}

	JNIThrowable(JNIEnv *pEnv, jobject javaObject) : JNIObject(pEnv, javaObject)
	{
	}

	void Throw() 
	{
		GetEnv()->Throw(static_cast<jthrowable>(GetJavaObject()));
	}
};