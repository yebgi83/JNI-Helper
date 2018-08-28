#pragma once
#include "./base/jni.h"

class JNIBase
{
private:
	JNIEnv *pEnv;

protected:
	JNIBase(JNIEnv *pEnv)
	{
		this->pEnv = pEnv;
	}

public:
	JNIEnv *GetEnv() 
	{ 
		return pEnv;
	}
};