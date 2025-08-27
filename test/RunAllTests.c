#include "unity.h"
#include "unity_fixture.h"
#include <stddef.h>
#include <stdio.h>


static void RunAllTests(void)
{

    RUN_TEST_GROUP(GENERAL_GROUP);

}
int main(int argc, const char *argv[])
{

    return UnityMain(argc, argv, RunAllTests);
}
