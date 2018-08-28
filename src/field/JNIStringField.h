#pragma once
#include "../JNIField.h"

using namespace std;

class JNIStringField : JNIField
{
private:
	const char *SIG = "Ljava/lang/String;";

public:
	JNIStringField(jclass javaClass, const string &name) : JNIField(javaClass, name)
	{
		return;
	}

	void SetValue(JNIObject *pJniObject, const string &value)
	{
		SetValue(pJniObject->GetEnv(), pJniObject->GetJavaObject(), value);
	}

	void SetValue(JNIEnv *pEnv, jobject javaObject, const string &value)
	{
		SetJavaValue(pEnv, javaObject, JNIString::ToJavaString(pEnv, value));
	}

	void SetJavaValue(JNIObject *pJniObject, const jstring &value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), SIG, value);
	}

	void SetJavaValue(JNIEnv *pEnv, jobject javaObject, const jstring &value)
	{
		SetObjectField(pEnv, javaObject, SIG, value);
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