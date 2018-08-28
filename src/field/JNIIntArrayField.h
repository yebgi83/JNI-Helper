#pragma once
#include "../JNIField.h"
#include "../array/JNIIntArray.h"

using namespace std;

class JNIIntArrayField : JNIField
{
private:
	const char *SIG = "[I";

public:
	JNIIntArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNIIntArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNIIntArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNIIntArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	JNIIntArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNIIntArray(pEnv, reinterpret_cast<jintArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};