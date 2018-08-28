#pragma once
#include "JNIObject.h"

template <typename T>
class JNIEnum : public JNIObject
{
protected:
	JNIEnum(JNIEnv *pEnv, jobject javaObject) : JNIObject(pEnv, javaObject)
	{
	}
};
