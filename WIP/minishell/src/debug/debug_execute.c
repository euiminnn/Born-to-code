#include "debug/debug_execute.h"
#include "debug/debug_utils.h"

int    print_proc(t_proc *proc, int depth)
{
    print_space(depth);
    printf("{\n");
    print_space(depth + 1);
    printf("argv : \n");
    print_strings(proc->argv, depth + 2);
    print_space(depth + 1);
    printf("argc : %d\n", proc->argc);
    print_space(depth + 1);
    printf("env : %p\n", proc->env);
    print_space(depth + 1);
    printf("fd_in : %d\n", proc->fd_in);
    print_space(depth + 1);
    printf("fd_out : %d\n", proc->fd_out);
    print_space(depth);
    printf("}\n");
    return (OK);
}