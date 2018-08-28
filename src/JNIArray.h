#pragma once
#include "../JNIObject.h"

using namespace std;

template <typename T = jobjectArray>
class JNIArray : public JNIObject
{
public:
	static JNIArray CreateNew(JNIEnv *pEnv, jsize len, JNIMethod jniInit, ...)
	{
		va_list args;
		va_start(args, jniInit);
		jclass javaClass = jniInit.GetJavaClass();
		return JNIArray(pEnv, pEnv->NewObjectArray(len, javaClass, pEnv->NewObjectV(javaClass, jniInit.GetMethodID(pEnv), args)));
	}

	JNIArray(JNIEnv *pEnv, jobject javaObject) : JNIObject(pEnv, javaObject)
	{
		return;
	}

	T GetJavaObject()
	{
		return reinterpret_cast<T>(JNIObject::GetJavaObject());
	}

	void Set(int index, jobject value)
	{
		GetEnv()->SetObjectArrayElement(GetJavaObject(), index, value);
	}

	jobject Get(int index)
	{
		return GetEnv()->GetObjectArrayElement(GetJavaObject(), index);
	}

	int GetSize() 
	{
		return static_cast<int>(GetEnv()->GetArrayLength(GetJavaObject()));
	}
};