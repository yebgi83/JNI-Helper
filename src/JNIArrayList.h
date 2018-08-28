#pragma once
#include "JNIClass.h"
#include "JNIObject.h"

using namespace std;

template <typename T = jobject>
class JNIArrayList : public JNIObject
{
protected:
	JNIArrayList(JNIEnv *pEnv, JNIMethod jniInit) : JNIObject(pEnv, jniInit)
	{
	}

public:
	static JNIArrayList<T> CreateNew(JNIEnv *pEnv)
	{
		return JNIArrayList(pEnv, GetJNIClass(pEnv).GetConstructor("()V"));
	}

	static JNIClass GetJNIClass(JNIEnv *pEnv)
	{
		return JNIClass(pEnv, "java/util/ArrayList");
	}

	JNIArrayList(JNIEnv *pEnv, jobjectArray javaObject) : JNIObject(pEnv, javaObject)
	{
	}

	void Add(T value)
	{
		JNIMethod jniMethod(GetJavaClass(), "add", "(Ljava/lang/Object;)Z");
		jniMethod.CallVoidMethod(GetEnv(), GetJavaObject(), value);
	}

	T Get(int index)
	{
		JNIMethod jniMethod(GetJavaClass(), "get", "(I)Ljava/lang/Object;");
		return T(jniMethod.CallObjectMethod(GetEnv(), GetJavaObject(), index));
	}

	jsize GetSize()
	{
		JNIMethod jniMethod(GetJavaClass(), "size", "()I");
		return (GetJavaObject() != NULL) ? jniMethod.CallIntMethod(GetEnv(), GetJavaObject()) : 0;
	}

	vector<T> ToVector()
	{
		vector<T> result;

		for (int index = 0; index < GetSize(); index++) {
			result.push_back(Get(index));
		}

		return result;
	}
};
