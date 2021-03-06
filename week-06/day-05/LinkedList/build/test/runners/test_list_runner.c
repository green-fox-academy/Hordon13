/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#ifdef __WIN32__
#define UNITY_INCLUDE_SETUP_STUBS
#endif
#include "unity.h"
#ifndef UNITY_EXCLUDE_SETJMP_H
#include <setjmp.h>
#endif
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_insertEnd(void);
extern void test_insertBegin(void);
extern void test_insertAfter(void);
extern void test_size(void);
extern void test_emptyFalse(void);
extern void test_emptyTrue(void);
extern void test_delete(void);
extern void test_deleteValueInListOnce(void);
extern void test_deleteValueInListMultiple(void);
extern void test_deleteValueNotInList(void);
extern void test_search(void);


/*=======Suite Setup=====*/
static void suite_setup(void)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  suiteSetUp();
#endif
}

/*=======Suite Teardown=====*/
static int suite_teardown(int num_failures)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  return suiteTearDown(num_failures);
#else
  return num_failures;
#endif
}

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  suite_setup();
  UnityBegin("test_list.c");
  RUN_TEST(test_insertEnd, 5);
  RUN_TEST(test_insertBegin, 20);
  RUN_TEST(test_insertAfter, 37);
  RUN_TEST(test_size, 55);
  RUN_TEST(test_emptyFalse, 74);
  RUN_TEST(test_emptyTrue, 93);
  RUN_TEST(test_delete, 106);
  RUN_TEST(test_deleteValueInListOnce, 128);
  RUN_TEST(test_deleteValueInListMultiple, 150);
  RUN_TEST(test_deleteValueNotInList, 174);
  RUN_TEST(test_search, 198);

  return suite_teardown(UnityEnd());
}
