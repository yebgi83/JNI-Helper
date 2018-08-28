#pragma once
#include <string>
#include <jni.h>

using namespace std;

class JNIMethod
{
private:
	jclass javaClass;
	string name;
	string sig;

public:
	JNIMethod(jclass javaClass, const char *pName, const char *pSig) : JNIMethod(javaClass, string(pName), string(pSig)) {
	}

	JNIMethod(jclass javaClass, const string &name, const string &sig)
	{
		this->javaClass = javaClass;
		this->name = name;
		this->sig = sig;
	}

	const jclass GetJavaClass()
	{
		return javaClass;
	}

	const jmethodID GetMethodID(JNIEnv *pEnv)
	{
		return pEnv->GetMethodID(GetJavaClass(), name.c_str(), sig.c_str());
	}

	void CallVoidMethod(JNIEnv *pEnv, jobject javaObject, ...)
	{
		va_list args;
		va_start(args, javaObject);
		pEnv->CallVoidMethodV(javaObject, GetMethodID(pEnv), args);
	}

	const jint CallIntMethod(JNIEnv *pEnv, jobject javaObject, ...)
	{
		va_list args;
		va_start(args, javaObject);
		return pEnv->CallIntMethodV(javaObject, GetMethodID(pEnv), args);
	}

	const jlong CallLongMethod(JNIEnv *pEnv, jobject javaObject, ...)
	{
		va_list args;
		va_start(args, javaObject);
		return pEnv->CallLongMethodV(javaObject, GetMethodID(pEnv), args);
	}

	const jfloat CallFloatMethod(JNIEnv *pEnv, jobject javaObject, ...)
	{
		va_list args;
		va_start(args, javaObject);
		return pEnv->CallFloatMethodV(javaObject, GetMethodID(pEnv), args);
	}

	const jdouble CallDoubleMethod(JNIEnv *pEnv, jobject javaObject, ...)
	{
		va_list args;
		va_start(args, javaObject);
		return pEnv->CallDoubleMethodV(javaObject, GetMethodID(pEnv), args);
	}

	bool CallBooleanMethod(JNIEnv *pEnv, jobject javaObject, ...)
	{
		va_list args;
		va_start(args, javaObject);
		return pEnv->CallBooleanMethodV(javaObject, GetMethodID(pEnv), args) == JNI_TRUE;
	}

	jobject CallObjectMethod(JNIEnv *pEnv, jobject javaObject, ...)
	{
		va_list args;
		va_start(args, javaObject);
		return pEnv->CallObjectMethodV(javaObject, GetMethodID(pEnv), args);
	}
};
