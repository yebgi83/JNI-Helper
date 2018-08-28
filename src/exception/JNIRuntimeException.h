#pragma once

#include "../JNIThrowable.h"

using namespace std;

class JNIRuntimeException : public JNIThrowable
{
public:
	JNIRuntimeException(JNIEnv *pEnv, const string &message) : JNIThrowable(pEnv, JNIClass(pEnv,  "java.lang.RuntimeException"), message)
	{
	}

	JNIRuntimeException(JNIEnv *pEnv, jobject javaObject) : JNIThrowable(pEnv, javaObject)
	{
	}
};