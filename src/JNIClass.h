#pragma once

#include <algorithm>
#include <iostream>

#include "JNIBase.h"
#include "JNIField.h"
#include "JNIMethod.h"

class JNIClass : JNIBase
{
private:
	jclass javaClass;
	string javaClassName;

	string GetDisplayClassName()
	{
		string result = javaClassName;
		{
			replace(result.begin(), result.end(), '/', '.');
		}

		return result;
	}

	void OnError(const string &text) {
		stringstream messageBuilder;
		{
			messageBuilder << text << " (" << GetDisplayClassName() << ')';
		}

		throw messageBuilder.str();
	}
	
public:
	JNIClass(JNIEnv *pEnv, string javaClassName) : JNIBase(pEnv)
	{
		replace(javaClassName.begin(), javaClassName.end(), '.', '/');

		this->javaClass = pEnv->FindClass(javaClassName.c_str());
		this->javaClassName = javaClassName;

		if (this->javaClass == NULL) {
			OnError("Class not found");
		}
	}

	jclass GetJavaClass()
	{
		return javaClass;
	}

	string GetJavaClassName()
	{
		return javaClassName;
	}

	JNIMethod GetConstructor(const string &sig)
	{
		return GetMethod("<init>", sig);
	}

	JNIField GetField(const string &name)
	{
		return JNIField(javaClass, name);
	}

	JNIMethod GetMethod(const string &name, const string &sig)
	{
		return JNIMethod(javaClass, name, sig);
	}
};