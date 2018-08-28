#pragma once
#include "../JNIField.h"
#include "../array/JNIBooleanArray.h"

using namespace std;

class JNIBooleanArrayField : JNIField
{
private:
	const char *SIG = "[Z";

public:
	JNIBooleanArrayField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, JNIBooleanArray value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value.GetJavaObject());
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, JNIBooleanArray value)
	{
		SetObjectField(pEnv, javaObject, SIG, value.GetJavaObject());
	}

	JNIBooleanArray GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}
	
	JNIBooleanArray GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return JNIBooleanArray(pEnv, reinterpret_cast<jbooleanArray>(GetObjectField(pEnv, javaObject, SIG)));
	}
};