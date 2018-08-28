#pragma once
#include "../JNIField.h"

using namespace std;

class JNIFloatField : JNIField
{
private:
	const char *SIG = "F";

public:
	JNIFloatField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const jfloat &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const jfloat &value)
	{
		pEnv->SetFloatField(javaObject, GetFieldID(pEnv, SIG), value);
	}

	jfloat GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	jfloat GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return pEnv->GetFloatField(javaObject, GetFieldID(pEnv, SIG));
	}
};