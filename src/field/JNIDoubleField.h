#pragma once
#include "../JNIField.h"

using namespace std;

class JNIDoubleField : JNIField
{
private:
	const char *SIG = "D";

public:
	JNIDoubleField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const jdouble &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const jdouble &value)
	{
		pEnv->SetDoubleField(javaObject, GetFieldID(pEnv, SIG), value);
	}

	jdouble GetValue(JNIObject *pJniObject)
	{
		return GetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject());
	}

	jdouble GetValue(JNIEnv *pEnv, jobject javaObject)
	{
		return pEnv->GetDoubleField(javaObject, GetFieldID(pEnv, SIG));
	}
};