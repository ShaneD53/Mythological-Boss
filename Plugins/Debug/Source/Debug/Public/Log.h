// Copyright Overthrone Studios 2019

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Log.generated.h"

// Current class name and function name where this is called
#define CUR_CLASS_FUNC (FString(__FUNCTION__))

// Current class name and function name where this is called
#define CUR_CLASS_FUNC_WITH_LINE (CUR_CLASS_FUNC + ": " + CUR_LINE)

// Current class where this is called
#define CUR_CLASS (FString(__FUNCTION__).Left(FString(__FUNCTION__).Find(TEXT(":"))) )

// Current function name where this is called!
#define CUR_FUNC (FString(__FUNCTION__).Right(FString(__FUNCTION__).Len() - FString(__FUNCTION__).Find(TEXT("::")) - 2 ))
  
// Current line number in the code where this is called
#define CUR_LINE  ("Line " + FString::FromInt(__LINE__))

// Current function name and the line number in the code where this is called
#define CUR_FUNC_WITH_LINE  (CUR_FUNC + ": " + CUR_LINE)

// Current class and line number where this is called
#define CUR_CLASS_WITH_LINE (CUR_CLASS + "(" + CUR_LINE + ")")
  
// Current function signature where this is called
#define CUR_FUNC_SIG (FString(__FUNCSIG__))

UENUM()
enum ELogType
{
	INFO,
	SUCCESS,
	WARNING,
	ERROR,
	FATAL
};

/**
 * A library of log utility functions
 */
UCLASS()
class DEBUG_API ULog final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// Log whether the object is valid or not
	UFUNCTION(BlueprintCallable, Category = "Debug")
		static void ObjectValidity(UObject* ObjectRef, bool bLogInViewport = false);

	// Log a debug message to the console or viewport
	UFUNCTION(BlueprintCallable, Category = "Debug")
		static void DebugMessage(ELogType LogLevel, const FString& LogMessage, bool bLogInViewport = false, float TimeToDisplay = 5.0f);	

	// Log a hello message to the console or viewport
	UFUNCTION(BlueprintCallable, Category = "Debug")
		static void LogHello(bool bLogInViewport = false);
	
	// Log a yes message to the console or viewport
	UFUNCTION(BlueprintCallable, Category = "Debug")
		static void LogYes(bool bLogInViewport = false);

	// Log a no message to the console or viewport
	UFUNCTION(BlueprintCallable, Category = "Debug")
		static void LogNo(bool bLogInViewport = false);

	// Log a yes message to the console or viewport (with an optional prefix string)
	static void LogYes(const FString& Prefix, bool bLogInViewport = false);

	// Log a no message to the console or viewport (with an optional prefix string)
	static void LogNo(const FString& Prefix, bool bLogInViewport = false);

	// Log a number to the console or viewport (int8 version)
	static void LogNumber(int8 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (int16 version)
	static void LogNumber(int16 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (int32 version)
	static void LogNumber(int32 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (int64 version)
	static void LogNumber(int64 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (int8 version)
	static void LogNumber(uint8 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (int16 version)
	static void LogNumber(uint16 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (int32 version)
	static void LogNumber(uint32 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (int64 version)
	static void LogNumber(uint64 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (float version)
	static void LogNumber(float Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (double version)
	static void LogNumber(double Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (long version)
	static void LogNumber(long Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log a number to the console or viewport (long double version)
	static void LogNumber(long double Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

	// Log the given bool value to the console or viewport
	static void LogBool(bool bBoolToTest, bool bLogInViewport = false, float TimeToDisplay = 5.0f);

private:
	static void LogInt(int64 Number, bool bLogInViewport = false, float TimeToDisplay = 5.0f);
};
