#pragma once
#include "../JNIField.h"
#include "../array/JNILongArray.h"

using namespace std;

class JNILongArrayField : JNIField
{
private:
	const char *SIG = "[J";

public:
	JNILongArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNILongArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNIIntArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNILongArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	JNILongArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNILongArray(pEnv, reinterpret_cast<jlongArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};