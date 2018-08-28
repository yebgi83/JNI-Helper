#pragma once
#include "../JNIField.h"

using namespace std;

class JNIBooleanField : JNIField
{
private:
	const char *SIG = "Z";

public:
	JNIBooleanField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const bool &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const bool &value)
	{
		pEnv->SetBooleanField(javaObject, GetFieldID(pEnv, SIG), value ? JNI_TRUE : JNI_FALSE);
	}

	bool GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	bool GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return pEnv->GetBooleanField(javaObject, GetFieldID(pEnv, SIG)) == JNI_TRUE;
	}
};