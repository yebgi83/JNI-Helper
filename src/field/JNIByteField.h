#pragma once
#include "../JNIField.h"

using namespace std;

class JNIByteField : JNIField
{
private:
	const char *SIG = "B";

public:
	JNIByteField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const jbyte &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const jbyte &value)
	{
		pEnv->SetByteField(javaObject, GetFieldID(pEnv, SIG), value);
	}

	jbyte GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	jbyte GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return pEnv->GetByteField(javaObject, GetFieldID(pEnv, SIG));
	}
};