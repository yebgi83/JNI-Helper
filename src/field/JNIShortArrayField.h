#pragma once
#include "../JNIField.h"
#include "../array/JNIShortArray.h"

using namespace std;

class JNIShortArrayField : JNIField
{
private:
	const char *SIG = "[S";

public:
	JNIShortArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNIShortArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNIShortArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNIShortArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	JNIShortArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNIShortArray(pEnv, reinterpret_cast<jshortArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};