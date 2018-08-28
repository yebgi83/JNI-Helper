#pragma once
#include "../JNIField.h"
#include "../array/JNIStringArray.h"

using namespace std;

class JNIStringArrayField : JNIField
{
private:
	const char *SIG = "[Ljava/lang/String;";

public:
	JNIStringArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNIStringArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNIDoubleArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNIStringArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	JNIStringArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNIStringArray(pEnv, reinterpret_cast<jobjectArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};