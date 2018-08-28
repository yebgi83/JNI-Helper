#pragma once
#include "../JNIField.h"
#include "../array/JNIDoubleArray.h"

using namespace std;

class JNIDoubleArrayField : JNIField
{
private:
	const char *SIG = "[D";

public:
	JNIDoubleArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNIDoubleArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNIDoubleArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNIDoubleArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	JNIDoubleArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNIDoubleArray(pEnv, reinterpret_cast<jdoubleArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};