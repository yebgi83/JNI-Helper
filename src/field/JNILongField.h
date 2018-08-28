#pragma once
#include "../JNIField.h"

using namespace std;

class JNILongField : JNIField
{
private:
	const char *SIG = "J";

public:
	JNILongField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const jlong &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const jlong &value)
	{
		pEnv->SetLongField(javaObject, GetFieldID(pEnv, SIG), value);
	}

	jlong GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	jlong GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return pEnv->GetLongField(javaObject, GetFieldID(pEnv, SIG));
	}
};