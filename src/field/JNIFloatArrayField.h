#pragma once
#include "../JNIField.h"
#include "../array/JNIFloatArray.h"

using namespace std;

class JNIFloatArrayField : JNIField
{
private:
	const char *SIG = "[F";

public:
	JNIFloatArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNIFloatArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNIIntArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNIFloatArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	JNIFloatArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNIFloatArray(pEnv, reinterpret_cast<jfloatArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};