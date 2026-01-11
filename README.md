# fem-2D-heat

### C program that implements FEM for 2D heat problem.

## How to use?

To build and run the program, You can use scripts included in `scripts/` directory. It's important to run those scripts from the root of the project.

Example:

```
cd fem-2D-heat/
./scripts/configure_debug.sh
./scripts/build.sh
./scripts/run.sh
```

Alternatively you can just use the provided `CMakeLists.txt` (included scripts just automate choosing the target and configuration).

[!CAUTION]
Debug and Release not only differ in compiler optimizations. Debug version exports more data that is calculated during the program runtime. If You want or need additional info about results of the program compile it in Debug mode. 

