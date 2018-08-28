#pragma once
#include <string>

#include "JNIBase.h"
#include "JNIMethod.h"

using namespace std;

class JNIString : public JNIBase
{
private:
	jstring javaString;
	const char *sharedChars;

	const char *GetChars(jboolean isCopy)
	{
		if (javaString != NULL) {
			return GetEnv()->GetStringUTFChars(javaString, &isCopy);
		}
		else {
			return NULL;
		}
	}
	
public:
	static jstring ToJavaString(JNIEnv *pEnv, const string &string)
	{
		if (string.empty()) {
			return NULL;
		}
		else {
			return pEnv->NewStringUTF(string.c_str());
		}
	}

	static jstring ToJavaString(JNIEnv *pEnv, jobject javaObject)
	{
		if (typeid(javaObject) == typeid(jstring)) {
			return jstring(javaObject);
		}
		else {
			jclass javaClass = (javaObject != NULL) ? pEnv->GetObjectClass(javaObject) : NULL;

			if (javaClass != NULL) {
				static jmethodID methodID = pEnv->GetMethodID(javaClass, "toString", "()Ljava/lang/String;");
				return jstring(pEnv->CallObjectMethod(javaObject, methodID));
			}
			else {
				return NULL;
			}
		}
	}

	JNIString(JNIEnv *pEnv, const string &string) : JNIString(pEnv, ToJavaString(pEnv, string))
	{
	}

	JNIString(JNIEnv *pEnv, jobject javaObject) : JNIString(pEnv, ToJavaString(pEnv, javaObject))
	{
	}

	JNIString(JNIEnv *pEnv, jstring javaString) : JNIBase(pEnv)
	{
		this->javaString = javaString;
		this->sharedChars = NULL;
	}

	inline jstring GetJavaString() 
	{
		return javaString;
	}

	inline jsize GetLength()
	{
		return GetEnv()->GetStringLength(javaString);
	}

	~JNIString() 
	{
		if (sharedChars != NULL) {
			GetEnv()->ReleaseStringUTFChars(javaString, sharedChars);
			sharedChars = NULL;
		}
	}

	string GetString()
	{
		if (sharedChars == NULL) {
			sharedChars = GetChars(JNI_FALSE);
		}

		return string((sharedChars != NULL) ? sharedChars : "");
	}
};