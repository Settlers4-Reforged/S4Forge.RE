#ifndef TASKS_H
#define TASKS_H

#include "DefineTransformers.h"

#define TASKS                         \
    X(0, GO_VIRTUAL)                  \
    X(1, WORK_VIRTUAL)                \
    X(2, WAIT_VIRTUAL)                \
    X(3, PRODUCE_VIRTUAL)             \
    X(4, PUT_GOOD_VIRTUAL)            \
    X(5, GET_GOOD_VIRTUAL)            \
    X(6, GO)                          \
    X(7, GO_TO_POS)                   \
    X(33, GO_TO_POS_ROUGHLY)          \
    X(8, GO_TO_DESTINATION)           \
    X(9, GUARD_DESTINATION)           \
    X(10, GO_TO_TARGET)               \
    X(11, ENTER_TARGET)               \
    X(12, ATTACK_TARGET)              \
    X(13, RESOURCE_GATHERING)         \
    X(14, GO_HOME)                    \
    X(15, GO_TARGET_OFFSET)           \
    X(16, WORK)                       \
    X(17, WAIT)                       \
    X(18, GO_TO_SOURCE_PILE)          \
    X(19, GO_TO_DESTINATION_PILE)     \
    X(20, GET_GOOD_CHANGE_JOB)        \
    X(21, PUT_GOOD)                   \
    X(22, GET_GOOD)                   \
    X(23, LOAD_GOOD)                  \
    X(24, CHECKIN)                    \
    X(25, PLANT)                      \
    X(26, CHANGE_JOB)                 \
    X(27, IDLE)                       \
    X(28, WORK_ON_ENTITY)             \
    X(29, WORK_ON_ENTITY_VIRTUAL)     \
    X(30, RESOURCE_GATHERING_VIRTUAL) \
    X(31, SEARCH)                     \
    X(32, ATTACK_REACTION)            \
    X(34, HEAL_ENTITY)                \
    X(35, HEAL_ENTITY_VIRTUAL)        \
    X(37, GO_TO_TARGET_ROUGHLY)       \
    X(38, CHANGE_TYPE_AT_BARRACKS)    \
    X(39, CHANGE_JOB_COME_TO_WORK)

#define X TO_ENUM
enum T_S4_TASK {
    TASKS
};
#undef X

#endif // TASKS_H
