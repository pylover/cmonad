# Valgrind, Profiling
set(VALGRIND_FLAGS
    --show-error-list=yes
    --tool=memcheck 
    --leak-check=yes 
    --show-reachable=yes 
    --num-callers=20 
    --track-fds=yes 
)
