#pragma once
#include "../JNIField.h"
#include "../array/JNICharArray.h"

using namespace std;

class JNICharArrayField : JNIField
{
private:
	const char *SIG = "[C";

public:
	JNICharArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNICharArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNICharArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNICharArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	JNICharArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNICharArray(pEnv, reinterpret_cast<jcharArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};