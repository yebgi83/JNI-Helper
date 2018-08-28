#pragma once
#include "../JNIField.h"

using namespace std;

class JNICharField : JNIField
{
private:
	const char *SIG = "C";

public:
	JNICharField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const jchar &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const jchar &value)
	{
		pEnv->SetCharField(javaObject, GetFieldID(pEnv, SIG), value);
	}

	jchar GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	jchar GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return pEnv->GetCharField(javaObject, GetFieldID(pEnv, SIG));
	}
};