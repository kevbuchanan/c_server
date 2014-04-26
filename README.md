# C Project Template

## Writing Tests

* Create a test file in the test directory
* ```#include <check.h>```
* ```#include "test_suite.h"```
* Create a test case
* Add the test case to ```include/test/test_suite.h```
* Add the test case to the runner in ```test/test_runner.c```
* Write tests using [Check](http://check.sourceforge.net/)

## Using Mocks

* Add the mock in ```test/mocks/```
* Add the mocked file to ```MOCKED``` in the Makefile

## Running

If you don't have [Check](http://check.sourceforge.net/) installed:

```
$ brew install check
```

Then:

```bash
$ make
```

```bash
$ ./spec
```

```bash
$ ./main
```
