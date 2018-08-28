#pragma once
#include "../JNIField.h"
#include "../array/JNIByteArray.h"

using namespace std;

class JNIByteArrayField : JNIField
{
private:
	const char *SIG = "[B";

public:
	JNIByteArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNIByteArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNIByteArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNIByteArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	JNIByteArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNIByteArray(pEnv, reinterpret_cast<jbyteArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};