#pragma once
#include "../JNIField.h"

using namespace std;

class JNIIntField : JNIField
{
private:
	const char *SIG = "I";

public:
	JNIIntField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const jint &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const jint &value)
	{
		pEnv->SetIntField(javaObject, GetFieldID(pEnv, SIG), value);
	}

	jint GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	jint GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return pEnv->GetIntField(javaObject, GetFieldID(pEnv, SIG));
	}
};