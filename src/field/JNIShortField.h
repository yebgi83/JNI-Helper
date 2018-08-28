#pragma once
#include "../JNIField.h"

using namespace std;

class JNIShortField : JNIField
{
private:
	const char *SIG = "S";

public:
	JNIShortField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const jshort &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const jshort &value)
	{
		pEnv->SetShortField(javaObject, GetFieldID(pEnv, SIG), value);
	}

	jshort GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	jshort GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return pEnv->GetShortField(javaObject, GetFieldID(pEnv, SIG));
	}
};