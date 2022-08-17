cmake_minimum_required(VERSION 3.22)
project(philo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(philo
        arg_processing.c
        arg_processing_utils.c
        philo.c
        philo.h
        simulation.c
        sim_utils.c
        arg_processing.c
        arg_processing_utils.c
        initializers.c
        unused_funcs.c
        )
