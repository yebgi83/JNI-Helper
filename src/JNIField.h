#pragma once
#include "../JNIObject.h"

using namespace std;

class JNIField
{
private:
	jclass javaClass;
	string name;

public:
	JNIField(jclass javaClass, const string &name)
	{
		this->javaClass = javaClass;
		this->name = name;
	}

	jclass GetJavaClass()
	{
		return javaClass;
	}

	jfieldID GetFieldID(JNIEnv *pEnv, const string &sig)
	{
		return pEnv->GetFieldID(javaClass, name.c_str(), sig.c_str());
	}

	void SetObjectField(JNIObject *pJniObject, const string& sig, const jobject &value)
	{
		SetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), sig, value);
	}

	void SetObjectField(JNIEnv *pEnv, jobject javaObject, const string& sig, const jobject &value)
	{
		pEnv->SetObjectField(javaObject, GetFieldID(pEnv, sig), value);
	}

	jobject GetObjectField(JNIObject *pJniObject, const string& sig)
	{
		return GetObjectField(pJniObject->GetEnv(), pJniObject->GetJavaObject(), sig);
	}

	jobject GetObjectField(JNIEnv *pEnv, jobject javaObject, const string& sig)
	{
		return pEnv->GetObjectField(javaObject, GetFieldID(pEnv, sig));
	}
};